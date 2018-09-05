core = 7.x
api = 2

; For ding_innskraning.

libraries[php-saml][download][type] = "git"
libraries[php-saml][download][url] = "http://github.com/onelogin/php-saml.git"
libraries[php-saml][download][tag] = "v2.7.0"
libraries[php-saml][destination] = "libraries"

libraries[xmlseclibs][download][type] = "git"
libraries[xmlseclibs][download][url] = "http://github.com/robrichards/xmlseclibs.git"
libraries[xmlseclibs][download][tag] = "2.0.0"
libraries[xmlseclibs][destination] = "libraries"

; For BBS theme.

projects[quicktabs][subdir] = "contrib"
projects[quicktabs][version] = "3.8"
