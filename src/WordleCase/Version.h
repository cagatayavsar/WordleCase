#ifndef WordleCase_Version
#define WordleCase_Version

#define VER_STRING(n)				#n
#define VER_STRING2(n)				VER_STRING(n)

#define VER_MAJOR					0
#define VER_MINOR					1
#define VER_PATCH					0
#define VER_BUILD					0

#define VER_FILEVERSION             VER_MAJOR,VER_MINOR,VER_PATCH,VER_BUILD
#define VER_FILEVERSION_STR         VER_STRING2(VER_MAJOR) "." VER_STRING2(VER_MINOR) "." VER_STRING2(VER_PATCH) "." VER_STRING2(VER_BUILD)

#define VER_PRODUCTVERSION          VER_MAJOR,VER_MINOR,VER_PATCH,VER_BUILD
#define VER_PRODUCTVERSION_STR      VER_STRING2(VER_MAJOR) "." VER_STRING2(VER_MINOR) "." VER_STRING2(VER_PATCH) "." VER_STRING2(VER_BUILD)

#define VER_COMPANYNAME_STR         "Cagatay Avsar"
#define VER_FILEDESCRIPTION_STR     "Wordle Game"
#define VER_INTERNALNAME_STR        "WordleCase.exe"
#define VER_LEGALCOPYRIGHT_STR      "Copyright (C) 2022 - Cagatay Avsar"
#define VER_LEGALTRADEMARKS1_STR    "All Rights Reserved"
#define VER_LEGALTRADEMARKS2_STR    VER_LEGALTRADEMARKS1_STR
#define VER_ORIGINALFILENAME_STR    "WordleCase.exe"
#define VER_PRODUCTNAME_STR         "WordleCase"

#define VER_COMPANYDOMAIN_STR       "https://github.com/cagatayavsar"

#endif
