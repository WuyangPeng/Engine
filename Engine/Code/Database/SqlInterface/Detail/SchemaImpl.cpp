// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/16 12:30)

#include "Database/DatabaseExport.h"

#include "SchemaImpl.h"
#include "System/Helper/UnusedMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::string;

Database::SchemaImpl
	::SchemaImpl(const ConfigurationStrategy& configurationStrategy)
	: m_ConfigurationStrategy{ configurationStrategy }
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::SchemaImpl
	::~SchemaImpl()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, SchemaImpl)

Database::ConfigurationStrategy Database::SchemaImpl
	::GetConfigurationStrategy() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_ConfigurationStrategy;
}

Database::SchemaImpl::MysqlxCollectionPtr Database::SchemaImpl
	::GetCollection(const string& collectionName)
{
	DATABASE_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(collectionName);

	THROW_EXCEPTION(SYSTEM_TEXT("SchemaImpl��GetCollectionδʵ�֡�"));
}

Database::SchemaImpl::MysqlxTablePtr Database::SchemaImpl
	::GetTable(const string& tableonName)
{
	DATABASE_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(tableonName);

	THROW_EXCEPTION(SYSTEM_TEXT("SchemaImpl��GetTableδʵ�֡�"));
}

