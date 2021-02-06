
#pragma once

#include <string>


#ifdef  _WIN32

#define OTL_ODBC

#define OTL_BIGINT int64_t

#define OTL_STR_TO_BIGINT(str, n)\
{\
    n = strtoll(str, NULL, 10);\
}

#define OTL_BIGINT_TO_STR(n, str)\
{\
    std::string strx = std::to_string(n);\
    memcpy(str, strx.c_str(), strx.length());\
}

#else
//#define OTL_BIGINT int64_t

#endif  //_WIN32

#include "otl/otlv4.h"


