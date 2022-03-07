///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 17:20)

#include "Database/DatabaseExport.h"

#include "SessionImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

Database::SessionImpl::SessionImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : configurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::SessionImpl::~SessionImpl() noexcept = default;

CLASS_INVARIANT_STUB_DEFINE(Database, SessionImpl)

Database::ConfigurationStrategy Database::SessionImpl::GetConfigurationStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return configurationStrategy;
}

Database::SessionImpl::MysqlxSchemaUniquePtr Database::SessionImpl::GetMysqlxSchema() const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl的GetMysqlxSchemaPtr未实现。"s));
}

Database::SessionImpl::MysqlxSchemaUniquePtr Database::SessionImpl::GetMysqlxSchema(MAYBE_UNUSED int dbIndex) const
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl的GetMysqlxSchemaPtr未实现。"s));
}

Database::SessionImpl::SchemaContainer Database::SessionImpl::GetSchemaContainer()
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl的GetSchemaContainer未实现。"s));
}

Database::SessionImpl::ResultUniquePtr Database::SessionImpl::ExecuteResult(MAYBE_UNUSED const string& findStatement, MAYBE_UNUSED int bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl的ExecuteResult未实现。"s));
}

Database::SessionImpl::ResultUniquePtr Database::SessionImpl::ExecuteResult(MAYBE_UNUSED const string& findStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl的ExecuteResult未实现。"s));
}

Database::SessionImpl::ResultUniquePtr Database::SessionImpl::ExecuteResult(MAYBE_UNUSED const string& findStatement, MAYBE_UNUSED const string& bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl的ExecuteResult未实现。"s));
}

void Database::SessionImpl::Execute(MAYBE_UNUSED const string& findStatement, MAYBE_UNUSED const string& bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl的Execute未实现。"s));
}

void Database::SessionImpl::Execute(MAYBE_UNUSED const string& findStatement, MAYBE_UNUSED int bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl的Execute未实现。"s));
}

void Database::SessionImpl::Execute(MAYBE_UNUSED const string& findStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl的Execute未实现。"s));
}
