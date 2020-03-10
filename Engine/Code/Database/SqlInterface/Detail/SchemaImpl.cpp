// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/03 10:05)

#include "Database/DatabaseExport.h"

#include "SchemaImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "System/Helper/UnusedMacro.h"

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

	THROW_EXCEPTION(SYSTEM_TEXT("SchemaImpl的GetCollection未实现。"));
}

Database::SchemaImpl::MysqlxTablePtr Database::SchemaImpl
	::GetTable(const string& tableonName)
{
	DATABASE_CLASS_IS_VALID_9;

	SYSTEM_UNUSED_ARG(tableonName);

	THROW_EXCEPTION(SYSTEM_TEXT("SchemaImpl的GetTable未实现。"));
}

