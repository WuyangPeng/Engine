///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 16:44)

#ifndef DATABASE_DATABASE_INTERFACE_DATA_TYPE_H
#define DATABASE_DATABASE_INTERFACE_DATA_TYPE_H

#include "System/Helper/EnumOperator.h"

namespace Database
{
    enum class DataType
    {
        Null = 0,
        String = 1,
        Int32 = 2,
        Int32Count = 3,
        Int64 = 4,
        Int64Count = 5,
        Double = 6,
        Bool = 7,
        ByteArray = 8,
        Object = 9,
        ObjectArray = 10,
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
