--- src/basic_fun.cpp.orig	2014-10-10 23:18:05.000000000 +0200
+++ src/basic_fun.cpp	2014-10-10 23:21:54.000000000 +0200
@@ -6483,7 +6483,7 @@
       while (p < e) 
       {
         // scheme = 1*[ lowalpha | digit | "+" | "-" | "." ]
-        if (!(isalpha(*p)) && !(isdigit(*p)) && (*p != '+') && (*p != '.') && (*p != '-')) 
+        if (!(std::isalpha(*p)) && !(std::isdigit(*p)) && (*p != '+') && (*p != '.') && (*p != '-')) 
         {
           if (e + 1 < ue) goto parse_port;
           else goto just_path;
@@ -6501,7 +6501,7 @@
       {
         // check if the data we get is a port this allows us to correctly parse things like a.com:80
         p = e + 1;
-        while (isdigit(*p)) p++;
+        while (std::isdigit(*p)) p++;
 	if ((*p == '\0' || *p == '/') && (p - e) < 7) goto parse_port;
         urlstru->InitTag("SCHEME", DStringGDL(string(s, (e - s))));
         length -= ++e - s;
