#ifndef COMMON_DATATYPE_H
#define COMMON_DATATYPE_H

enum DataType {
    TYPE_INVALID    = -1,
    TYPE_INT        = 0,
    TYPE_FLOAT      = 1,
    TYPE_STRING     = 2,
    TYPE_INTARRAY   = 3,
    TYPE_FLOATARRAY = 4,
    TYPE_CUSTOME    = 5,
    TYPE_NUM,           //所有新增类型定义在上面
};

#endif // COMMON_DATATYPE_H