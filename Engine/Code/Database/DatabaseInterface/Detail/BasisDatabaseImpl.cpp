﻿/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:48)

#include "Database/DatabaseExport.h"

#include "BasisDatabaseImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Database::BasisDatabaseImpl::BasisDatabaseImpl(std::string_view fieldName, DataType dataType, std::any value)
    : fieldName{ fieldName }, dataType{ dataType }, value{ std::move(value) }
{
    if (this->fieldName.empty())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("字段名为空。"))
    }

    DATABASE_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool Database::BasisDatabaseImpl::IsValid() const noexcept
{
    return !fieldName.empty();
}

#endif  // OPEN_CLASS_INVARIANT

std::string_view Database::BasisDatabaseImpl::GetFieldName() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return fieldName;
}

Database::DataType Database::BasisDatabaseImpl::GetDataType() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return dataType;
}

std::any Database::BasisDatabaseImpl::GetValue() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return value;
}

std::string Database::BasisDatabaseImpl::GetSqlFieldString() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    if (dataType == DataType::String)
    {
        return "`" + std::any_cast<DataTypeTraits<DataType::String>::Type>(value) + "`";
    }
    else
    {
        return GetString();
    }
}

std::string Database::BasisDatabaseImpl::GetString() const
{
    if (value.has_value())
    {
        switch (dataType)
        {
            case DataType::String:
                return std::any_cast<DataTypeTraits<DataType::String>::Type>(value);
            case DataType::Int32:
                return std::to_string(std::any_cast<DataTypeTraits<DataType::Int32>::Type>(value));
            case DataType::Int32Count:
                return std::to_string(std::any_cast<DataTypeTraits<DataType::Int32Count>::Type>(value));
            case DataType::Int64:
                return std::to_string(std::any_cast<DataTypeTraits<DataType::Int64>::Type>(value));
            case DataType::Int64Count:
                return std::to_string(std::any_cast<DataTypeTraits<DataType::Int64Count>::Type>(value));
            case DataType::Double:
                return std::to_string(std::any_cast<DataTypeTraits<DataType::Double>::Type>(value));
            case DataType::Bool:
            {
                if (const auto result = std::any_cast<DataTypeTraits<DataType::Bool>::Type>(value);
                    result)
                {
                    return "true";
                }
                else
                {
                    return "false";
                }
            }

            case DataType::StringArray:
            {
                const auto anyValue = std::any_cast<DataTypeTraits<DataType::StringArray>::Type>(value);

                std::string result{};

                auto index = 0u;
                for (const auto& element : anyValue)
                {
                    result += element;

                    ++index;

                    if (index != anyValue.size())
                    {
                        result += "|";
                    }
                }

                return result;
            }

            case DataType::Int32Array:
            {
                const auto anyValue = std::any_cast<DataTypeTraits<DataType::Int32Array>::Type>(value);

                std::string result{};

                auto index = 0u;
                for (const auto& element : anyValue)
                {
                    result += std::to_string(element);

                    ++index;

                    if (index != anyValue.size())
                    {
                        result += "|";
                    }
                }

                return result;
            }

            case DataType::Int64Array:
            {
                const auto anyValue = std::any_cast<DataTypeTraits<DataType::Int64Array>::Type>(value);

                std::string result{};

                auto index = 0u;
                for (const auto& element : anyValue)
                {
                    result += std::to_string(element);

                    ++index;

                    if (index != anyValue.size())
                    {
                        result += "|";
                    }
                }

                return result;
            }

            case DataType::DoubleArray:
            {
                const auto anyValue = std::any_cast<DataTypeTraits<DataType::DoubleArray>::Type>(value);

                std::string result{};

                auto index = 0u;
                for (const auto& element : anyValue)
                {
                    result += std::to_string(element);

                    ++index;

                    if (index != anyValue.size())
                    {
                        result += "|";
                    }
                }

                return result;
            }

            default:
                return "";
        }
    }
    else
    {
        return "";
    }
}

std::string Database::BasisDatabaseImpl::GetQuotationMarkString() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    if (dataType == DataType::String)
    {
        return "\"" + std::any_cast<DataTypeTraits<DataType::String>::Type>(value) + "\"";
    }
    else
    {
        return GetString();
    }
}
