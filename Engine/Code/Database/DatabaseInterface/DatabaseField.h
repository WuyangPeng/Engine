///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.10 (2023/05/26 09:42)

#ifndef DATABASE_DATABASE_INTERFACE_DATABASE_FIELD_H
#define DATABASE_DATABASE_INTERFACE_DATABASE_FIELD_H

#include "Database/DatabaseDll.h"

#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"
#include "Database/DatabaseInterface/Flags/DataType.h"

#include <string>

namespace Database
{
    class DatabaseField final
    {
    public:
        using ClassType = DatabaseField;

    public:
        constexpr DatabaseField(const std::string_view fieldName, const DataType dataType, const IndexType indexType = IndexType::Null)
            : fieldName{ fieldName }, dataType{ dataType }, indexType{ indexType }
        {
        }

        NODISCARD constexpr std::string_view GetFieldName() const noexcept
        {
            return fieldName;
        }

        NODISCARD constexpr DataType GetDataType() const noexcept
        {
            return dataType;
        }

        NODISCARD constexpr IndexType GetIndexType() const noexcept
        {
            return indexType;
        }

    private:
        std::string_view fieldName;
        DataType dataType;
        IndexType indexType;
    };
}

#endif  // DATABASE_DATABASE_INTERFACE_DATABASE_FIELD_H