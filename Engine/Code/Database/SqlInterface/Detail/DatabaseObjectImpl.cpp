// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/16 12:26)

#include "Database/DatabaseExport.h"

#include "DatabaseObjectImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

Database::DatabaseObjectImpl
	::DatabaseObjectImpl(const ConfigurationStrategy& configurationStrategy)
	: m_ConfigurationStrategy{ configurationStrategy }
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::DatabaseObjectImpl
	::~DatabaseObjectImpl()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseObjectImpl)

Database::ConfigurationStrategy Database::DatabaseObjectImpl
	::GetConfigurationStrategy() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_ConfigurationStrategy;
}

Database::DatabaseObjectImpl::MysqlxSessionPtr Database::DatabaseObjectImpl
	::GetMysqlxSessionPtr()
{
	DATABASE_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("DatabaseObjectImpl��GetMysqlxSessionPtrδʵ�֡�"));
}

