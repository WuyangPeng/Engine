///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 17:19)

#ifndef DATABASE_DATABASE_INTERFACE_DATA_TYPE_TRAITS_H
#define DATABASE_DATABASE_INTERFACE_DATA_TYPE_TRAITS_H

#include "Database/DatabaseDll.h"

#include "DatabaseInterfaceFwd.h"
#include "Flags/DataType.h"

#include <memory>
#include <string>
#include <vector>

namespace Database
{
    template <DataType Type>
    struct DataTypeTraits;

    template <>
    struct DataTypeTraits<DataType::Null>
    {
        using Type = decltype(nullptr);
    };

    template <>
    struct DataTypeTraits<DataType::String>
    {
        using Type = std::string;
    };

    template <>
    struct DataTypeTraits<DataType::Int32>
    {
        using Type = int32_t;
    };

    template <>
    struct DataTypeTraits<DataType::Int32Count>
    {
        using Type = int32_t;
    };

    template <>
    struct DataTypeTraits<DataType::Int64>
    {
        using Type = int64_t;
    };

    template <>
    struct DataTypeTraits<DataType::Int64Count>
    {
        using Type = int64_t;
    };

    template <>
    struct DataTypeTraits<DataType::Double>
    {
        using Type = double;
    };

    template <>
    struct DataTypeTraits<DataType::Bool>
    {
        using Type = bool;
    };

    template <>
    struct DataTypeTraits<DataType::ByteArray>
    {
        using Type = std::vector<uint8_t>;
    };

    template <>
    struct DataTypeTraits<DataType::Object>
    {
        using Type = std::shared_ptr<BasisDatabase>;
    };

    template <>
    struct DataTypeTraits<DataType::ObjectArray>
    {
        using Type = std::vector<std::shared_ptr<BasisDatabase>>;
    };

    namespace Traits
    {
        using String = Database::DataTypeTraits<DataType::String>::Type;
        using Int32 = Database::DataTypeTraits<DataType::Int32>::Type;
        using Int32Count = Database::DataTypeTraits<DataType::Int32Count>::Type;
        using Int64 = Database::DataTypeTraits<DataType::Int64>::Type;
        using Int64Count = Database::DataTypeTraits<DataType::Int64Count>::Type;
        using Double = Database::DataTypeTraits<DataType::Double>::Type;
        using Bool = Database::DataTypeTraits<DataType::Bool>::Type;
    }
}

#endif  // DATABASE_DATABASE_INTERFACE_DATA_TYPE_TRAITS_H
