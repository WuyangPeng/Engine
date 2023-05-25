///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/24 11:46)

#ifndef DATABASE_DATABASE_INTERFACE_FIELD_NAME_H
#define DATABASE_DATABASE_INTERFACE_FIELD_NAME_H

#include "Database/DatabaseDll.h"

#include "Database/DatabaseInterface/DatabaseInterfaceFwd.h"

#include <string>

namespace Database
{
    class FieldName
    {
    public:
        using ClassType = FieldName;

    public:
        constexpr FieldName(std::string_view fieldName, DataType dataType)
            : fieldName{ fieldName }, dataType{ dataType }
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

    private:
        std::string_view fieldName;
        DataType dataType;
    };
}

#endif  // DATABASE_DATABASE_INTERFACE_FIELD_NAME_H