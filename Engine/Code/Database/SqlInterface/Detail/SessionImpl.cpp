//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/29 10:41)

#include "Database/DatabaseExport.h"

#include "SessionImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

Database::SessionImpl::SessionImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : m_ConfigurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::SessionImpl::~SessionImpl() noexcept
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, SessionImpl)

Database::ConfigurationStrategy Database::SessionImpl::GetConfigurationStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_ConfigurationStrategy;
}

Database::SessionImpl::MysqlxSchemaPtr Database::SessionImpl::GetMysqlxSchemaPtr()
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��GetMysqlxSchemaPtrδʵ�֡�"s));
}

Database::SessionImpl::MysqlxSchemaPtr Database::SessionImpl::GetMysqlxSchemaPtr([[maybe_unused]] int dbIndex)
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��GetMysqlxSchemaPtrδʵ�֡�"s));
}

Database::SessionImpl::SchemaContainer Database::SessionImpl::GetSchemaContainer()
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��GetSchemaContainerδʵ�֡�"s));
}

Database::SessionImpl::ResultPtr Database::SessionImpl::ExecuteResult([[maybe_unused]] const string& findStatement, [[maybe_unused]] int bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��ExecuteResultδʵ�֡�"s));
}

Database::SessionImpl::ResultPtr Database::SessionImpl::ExecuteResult([[maybe_unused]] const string& findStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��ExecuteResultδʵ�֡�"s));
}

Database::SessionImpl::ResultPtr Database::SessionImpl::ExecuteResult([[maybe_unused]] const string& findStatement, [[maybe_unused]] const string& bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��ExecuteResultδʵ�֡�"s));
}

void Database::SessionImpl::Execute([[maybe_unused]] const string& findStatement, [[maybe_unused]] const string& bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��Executeδʵ�֡�"s));
}

void Database::SessionImpl::Execute([[maybe_unused]] const string& findStatement, [[maybe_unused]] int bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��Executeδʵ�֡�"s));
}

void Database::SessionImpl::Execute([[maybe_unused]] const string& findStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��Executeδʵ�֡�"s));
}
