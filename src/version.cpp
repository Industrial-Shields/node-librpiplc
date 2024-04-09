#include "version.h"

#define xstr(a) str(a)
#define str(a) #a



const int cVersionMajor = __LIB_RPIPLC_VERSION_MAJOR_NUM;
const int cVersionMinor = __LIB_RPIPLC_VERSION_MINOR_NUM;
const int cVersionPatch = __LIB_RPIPLC_VERSION_PATCH_NUM;
const char* cVersion = LIB_RPIPLC_VERSION;
