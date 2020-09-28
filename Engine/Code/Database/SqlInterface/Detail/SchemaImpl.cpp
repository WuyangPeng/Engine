// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/16 12:30)

#include "Database/DatabaseExport.h"

#include "SchemaImpl.h"

#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::string;

Database::SchemaImpl ::SchemaImpl(const ConfigurationStrategy& configurationStrategy) noexcept
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

Database::ConfigurationStrategy Database::SchemaImpl ::GetConfigurationStrategy() const noexcept
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_ConfigurationStrategy;
}

Database::SchemaImpl::MysqlxCollectionPtr Database::SchemaImpl ::GetCollection([[maybe_unused]] const string& collectionName)
{
	DATABASE_CLASS_IS_VALID_9;

 

	THROW_EXCEPTION(SYSTEM_TEXT("SchemaImpl的GetCollection未实现。"s));
}

Database::SchemaImpl::MysqlxTablePtr Database::SchemaImpl ::GetTable([[maybe_unused]] const string& tableonName)
{
	DATABASE_CLASS_IS_VALID_9;

 

	THROW_EXCEPTION(SYSTEM_TEXT("SchemaImpl的GetTable未实现。"s));
}

