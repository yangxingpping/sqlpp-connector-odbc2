
#pragma once

#include <string>

#define OTL_STR_TO_BIGINT(str, n)\
{\
    n = strtoll(str, NULL, 10);\
}

#define OTL_BIGINT_TO_STR(n, str)\
{\
    std::string strx = std::to_string(n);\
    memcpy(str, strx.c_str(), strx.length());\
}

#include "otl/otlv4.h"


