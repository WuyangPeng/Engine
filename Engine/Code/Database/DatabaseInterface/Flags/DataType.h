///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/14 15:20)

#ifndef DATABASE_DATABASE_INTERFACE_DATA_TYPE_H
#define DATABASE_DATABASE_INTERFACE_DATA_TYPE_H

#include "System/Helper/EnumOperator.h"

namespace Database
{
    enum class DataType
    {
        Null = 0,
        String = 1,
        StringArray = 2,
        Int32 = 3,
        Int32Count = 4,
        Int32Array = 5,
        Int64 = 6,
        Int64Count = 7,
        Int64Array = 8,
        Double = 9,
        DoubleArray = 10,
        Bool = 11,
        ByteArray = 12,
        Object = 13,
        ObjectArray = 14,
    };

    enum class IndexType
    {
        Null = 0,
        Key = 1,
        UniqueIndex = 2,
        Index = 3,
        CompositeUniqueIndex = 4,
        CompositeIndex = 5,
    };

    enum class ChangeType
    {
        Select = 0,
        Update = 1,
        Insert = 2,
        Delete = 3
    };
}

#endif  // DATABASE_DATABASE_INTERFACE_DATA_TYPE_H
