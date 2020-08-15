// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/16 12:31)

#include "Database/DatabaseExport.h"

#include "SessionImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::string;

Database::SessionImpl
	::SessionImpl(const ConfigurationStrategy& configurationStrategy) noexcept
	: m_ConfigurationStrategy{ configurationStrategy }
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::SessionImpl
	::~SessionImpl()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, SessionImpl)

Database::ConfigurationStrategy Database::SessionImpl
	::GetConfigurationStrategy() const noexcept
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_ConfigurationStrategy;
}

Database::SessionImpl::MysqlxSchemaPtr Database::SessionImpl
	::GetMysqlxSchemaPtr()
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��GetMysqlxSchemaPtrδʵ�֡�"s));
}

Database::SessionImpl::MysqlxSchemaPtr Database::SessionImpl
	::GetMysqlxSchemaPtr(int dbIndex)
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	SYSTEM_UNUSED_ARG(dbIndex);

	THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��GetMysqlxSchemaPtrδʵ�֡�"s));
}

Database::SessionImpl::SchemaContainer Database::SessionImpl
	::GetSchemaContainer()
{
	DATABASE_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��GetSchemaContainerδʵ�֡�"s));
}

Database::SessionImpl::ResultPtr Database::SessionImpl
	::ExecuteResult(const string& findStatement, int bindStatement)
{
	DATABASE_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(findStatement);
	SYSTEM_UNUSED_ARG(bindStatement);

	THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��ExecuteResultδʵ�֡�"s));
}

Database::SessionImpl::ResultPtr Database::SessionImpl
	::ExecuteResult(const string& findStatement)
{
	DATABASE_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(findStatement);

	THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��ExecuteResultδʵ�֡�"s));
}

Database::SessionImpl::ResultPtr Database::SessionImpl
	::ExecuteResult(const string& findStatement, const string& bindStatement)
{
	DATABASE_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(findStatement);
	SYSTEM_UNUSED_ARG(bindStatement);

	THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��ExecuteResultδʵ�֡�"s));
}

void Database::SessionImpl
	::Execute(const string& findStatement, const string& bindStatement)
{
	DATABASE_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(findStatement);
	SYSTEM_UNUSED_ARG(bindStatement);

	THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��Executeδʵ�֡�"s));
}

void Database::SessionImpl
	::Execute(const string& findStatement, int bindStatement)
{
	DATABASE_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(findStatement);
	SYSTEM_UNUSED_ARG(bindStatement);

	THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��Executeδʵ�֡�"s));
}

void Database::SessionImpl
	::Execute(const string& findStatement)
{
	DATABASE_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(findStatement);

	THROW_EXCEPTION(SYSTEM_TEXT("SessionImpl��Executeδʵ�֡�"s));
}
