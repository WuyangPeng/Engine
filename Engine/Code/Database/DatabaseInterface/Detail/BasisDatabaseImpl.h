/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 13:45)

#ifndef DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_IMPL_H
#define DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_IMPL_H

#include "Database/DatabaseDll.h"

#include "Database/DatabaseInterface/DataTypeTraits.h"

#include <any>
#include <string>

namespace Database
{
    class DATABASE_HIDDEN_DECLARE BasisDatabaseImpl
    {
    public:
        using ClassType = BasisDatabaseImpl;

    public:
        BasisDatabaseImpl(std::string_view fieldName, DataType dataType, std::any value);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string_view GetFieldName() const noexcept;
        NODISCARD DataType GetDataType() const noexcept;
        NODISCARD std::any GetValue() const;
        NODISCARD std::string GetSqlFieldString() const;
        NODISCARD std::string GetString() const;
        NODISCARD std::string GetQuotationMarkString() const;

    private:
        std::string_view fieldName;
        DataType dataType;
        std::any value;
    };
}
#endif  // DATABASE_DATABASE_INTERFACE_BASIS_DATABASE_IMPL_H