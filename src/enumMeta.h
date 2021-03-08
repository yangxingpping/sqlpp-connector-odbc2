
#pragma once

#define SQL_AGGREGATION_ITEM(MY_ENUM) \
    MY_ENUM(COUNT)\
    MY_ENUM(AVG)\
    MY_ENUM(MAX)\
    MY_ENUM(MIN)

#define DO_DESCRIPTION(e)  #e,
#define DO_ENUM(e)  e,

static char SQLAggreationDescription[][128] = {
    SQL_AGGREGATION_ITEM(DO_DESCRIPTION)
};

typedef enum {
    SQL_AGGREGATION_ITEM(DO_ENUM)
}SQLNeeConvert;
