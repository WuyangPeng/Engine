///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.9 (2023/05/22 17:41)

#include "Database/DatabaseExport.h"

#include "BasisDatabaseDetail.h"
#include "Detail/BasisDatabaseImpl.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Database::BasisDatabase::BasisDatabase(const std::string_view& fieldName)
    : ClassType{ fieldName, DataType::Null, nullptr }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabase::BasisDatabase(const std::string_view& fieldName, const std::string& value)
    : ClassType{ fieldName, DataType::String, value }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabase::BasisDatabase(const std::string_view& fieldName, int32_t value)
    : ClassType{ fieldName, DataType::Int32, value }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabase::BasisDatabase(const std::string_view& fieldName, int64_t value)
    : ClassType{ fieldName, DataType::Int64, value }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabase::BasisDatabase(const std::string_view& fieldName, uint64_t value)
    : ClassType{ fieldName, DataType::Int64, boost::numeric_cast<int64_t>(value) }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabase::BasisDatabase(const std::string_view& fieldName, const ByteArray& value)
    : ClassType{ fieldName, DataType::ByteArray, value }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabase::BasisDatabase(const std::string_view& fieldName, bool value)
    : ClassType{ fieldName, DataType::Bool, value }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabase::BasisDatabase(const std::string_view& fieldName, const ObjectSharedPtr& value)
    : ClassType{ fieldName, DataType::Object, value }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabase::BasisDatabase(const std::string_view& fieldName, const ObjectArray& value)
    : ClassType{ fieldName, DataType::ObjectArray, value }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::BasisDatabase::BasisDatabase(const std::string_view& fieldName, DataType dataType, const std::any& value)
    : impl{ fieldName, dataType, value }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, BasisDatabase)

std::string_view Database::BasisDatabase::GetFieldName() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetFieldName();
}

Database::DataType Database::BasisDatabase::GetDataType() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetDataType();
}

std::any Database::BasisDatabase::GetAnyValue() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetValue();
}

std::string Database::BasisDatabase::GetSqlFieldString() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetSqlFieldString();
}

std::string Database::BasisDatabase::GetString() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetString();
}

std::string Database::BasisDatabase::GetQuotationMarkString() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return impl->GetQuotationMarkString();
}
