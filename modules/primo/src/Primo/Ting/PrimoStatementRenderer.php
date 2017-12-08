<?php

namespace Primo\Ting;

use Ting\Search\BooleanStatementGroup;
use Ting\Search\BooleanStatementInterface;
use Ting\Search\SearchProviderException;
use Ting\Search\TingSearchCommonFields;
use Ting\Search\TingSearchFieldFilter;
use Ting\Search\UnsupportedSearchQueryException;

/**
 * Renders a list of statements into primo queries.
 *
 * @package Primo\Ting
 */
class PrimoStatementRenderer {
  protected $mapping = NULL;

  /**
   * PrimoStatementRenderer constructor.
   *
   * @param array $mapping
   *   Mapping between common fields and primo fields.
   */
  public function __construct(array $mapping) {
    $this->mapping = $mapping;
  }

  /**
   * Renders a list of statements into primo briefsearch queries.
   *
   * @param array $statements
   *   List of statements.
   *
   * @return array
   *   The rendered statements as a list of <key> => query where key is a valid
   *   Primo briefsearch query parameter.
   *
   * @throws \Ting\Search\UnsupportedSearchQueryException
   *   If Primo cannot support the query.
   */
  public function renderStatements(array $statements) {
    // Ensure we can support the statements and normalize the statements into
    // a list of groups.
    $groups = $this->preprocessStatements($statements);

    // We now have a list of groups containing one or more fields each. If the
    // group contains several statements, they will be against the same field.
    // We can now map the array using $this->renderGroup();
    return array_map('reset', array_map([$this, 'renderGroup'], $groups));
  }

  /**
   * Render a group into a statement.
   *
   * The groups must be "Primo" compatible. See parameter documentation for
   * details.
   *
   * @param \Ting\Search\BooleanStatementGroup $group
   *   A list of BooleanStatementGroup instances containing one or more
   *   statements all against the same field if they are joined by OR.
   *
   * @return array
   *   A list of <key> => <query> arrays where key is a valid query key such as
   *   "query".
   */
  protected function renderGroup(BooleanStatementGroup $group) {
    // We're a group group containing one or more field statements (against the
    // same field) into a single query=<fieldname>,exact,<list of values>.
    // See https://developers.exlibrisgroup.com/primo/apis/webservices/xservices/search/briefsearch
    // for more details.
    $statements = $group->getStatements();

    // The group has been preprocessed so we know it to contain at least one
    // statement and all statements will be against the same field so the
    // following is safe.
    $field_name = $statements[0]->getName();
    // If this is a field we have a mapping for, map it.
    if (isset($this->mapping[$field_name])) {
      $field_name = $this->mapping[$field_name];
    }
    $values = array_map(function (TingSearchFieldFilter $statement) {
      // "Escape" the string by replacing commas with spaces.
      return str_replace(',', ' ', $this->escapeValue($statement->getValue()));
    }, $statements);

    $values_joined = implode(' ' . $group->getLogicOperator() . ' ', $values);

    // Eg. query=rtype,exact,audiobooks OR articles.
    return [['query' => $field_name . ',exact,' . $values_joined]];
  }

  /**
   * Verify we can process the statements and convert them to groups.
   *
   * @param mixed[] $statements
   *   One or more instances of BooleanStatementGroup and/or
   *   TingSearchFieldFilter.
   *
   * @return \Ting\Search\BooleanStatementGroup[]
   *   Statements processed into a list of one or more groups.
   *
   * @throws \Ting\Search\UnsupportedSearchQueryException
   *   Thrown if the statement is not supported by Primo.
   */
  public function preprocessStatements(array $statements) {
    return array_reduce($statements, function ($carry, $statement) {
      // SAL dictates that all statements added on their own will be AND'ed
      // together and this aligns with Primo where all query= statements are
      // AND'ed, so if we hit a statement we can just add it and continue.
      if ($statement instanceof TingSearchFieldFilter) {
        // Convert the statement to a group.
        $carry[] = new BooleanStatementGroup([$statement]);
        return $carry;
      }

      // We have a group, examine it to determine whether we Primo will be able
      // to execute the statements.
      /** @var \Ting\Search\BooleanStatementGroup $statement */
      $group_statements = $statement->getStatements();

      // Collect the unique field-names in the group.
      $field_names = array_unique(array_map(function ($statement) {
        /** @var \Ting\Search\TingSearchFieldFilter $statement */
        return $statement->getName();
      }, $group_statements));

      // If the group is joined by anything but AND we require the field-name
      // to be the same so that we can combine the field statements into
      // a single "query=name,exact,value OR VALUE OR VALUE".
      if (count($field_names) > 1) {
        // The group references more than one field, if it joined by AND we
        // can stil support it.
        if ($statement->getLogicOperator() === BooleanStatementGroup::OP_AND) {
          // Wrap each statement in the group in its own group and add it. This
          // will work as
          // "name=value AND (name=value AND name=value)"
          // equals
          // "name=value AND name=value AND name=value".
          $carry = array_merge($carry, array_map(function ($statement) {
            return new BooleanStatementGroup([$statement]);
          }, $group_statements));
        }
        else {
          // The group referenced more than one field and was not joined by AND.
          throw new UnsupportedSearchQueryException("Primo only supports AND between different field.");
        }
      }
      else {
        // The all statements in the group is referencing the same field, go
        // ahead and add it.
        $carry[] = $statement;
      }
      return $carry;
    }, []);
  }

  /**
   * Escapes a value to be placed into a primo query parameter.
   *
   * @param string $value
   *   The value.
   *
   * @return string
   *   The escaped string.
   */
  public function escapeValue($value) {
    $replacements = [
      // AND and OR are keywords, strip them.
      ' AND ' => ' ',
      ' OR ' => ' ',
      // Commas should be replaced with spaces.
      ',' => ' ',
    ];

    return str_replace(array_keys($replacements), array_values($replacements), $value);
  }

}
