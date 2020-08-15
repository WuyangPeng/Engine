// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/16 12:29)

#include "Database/DatabaseExport.h"

#include "ResultImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

Database::ResultImpl ::ResultImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : m_ConfigurationStrategy{ configurationStrategy }
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::ResultImpl
	::~ResultImpl()
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ResultImpl)

Database::ResultImpl::ResultRowPtr Database::ResultImpl
	::FetchOne()
{
	DATABASE_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("DocResultImpl��FetchOneδʵ�֡�"s));
}

Database::ResultImpl::ResultRowContainer Database::ResultImpl
	::FetchAll()
{
	DATABASE_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("DocResultImpl��FetchAllδʵ�֡�"s));
}

Database::ConfigurationStrategy Database::ResultImpl
	::GetConfigurationStrategy() const noexcept
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_ConfigurationStrategy;
}

