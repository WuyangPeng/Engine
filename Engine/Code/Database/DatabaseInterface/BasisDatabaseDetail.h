///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 17:43)

#ifndef DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_DETAIL_H
#define DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_DETAIL_H

#include "BasisDatabase.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "Database/DatabaseInterface/Flags/DataType.h"

template <typename T>
requires(std::is_integral_v<T>)
Database::BasisDatabase::BasisDatabase(const std::string_view& fieldName, T value)
    : ClassType{ fieldName, DataType::Int32, value }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

template <typename T>
requires(std::is_floating_point_v<T>)
Database::BasisDatabase::BasisDatabase(const std::string_view& fieldName, T value)
    : ClassType{ fieldName, DataType::Double, value }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

template <Database::DataType Type>
typename Database::DataTypeTraits<Type>::Type Database::BasisDatabase::GetValue() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    if (const auto value = GetAnyValue();
        value.has_value())
    {
        return std::any_cast<typename DataTypeTraits<Type>::Type>(value);
    }
    else
    {
        return typename Database::DataTypeTraits<Type>::Type{};
    }
}

template <Database::DataType Type>
std::string Database::BasisDatabase::GetArrayStringValue() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    const auto value = GetValue<Type>();

    std::string result{};

    auto index = 0;
    for (const auto& element : value)
    {
        if constexpr (std::is_same_v<Database::DataTypeTraits<Type>::Type, BasisDatabase::StringArray>)
        {
            result += element;
        }
        else
        {
            result += std::to_string(element);
        }

        ++index;

        if (index != value.size())
        {
            result += "|";
        }
    }

    return result;
}

#endif  // DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_DETAIL_H
