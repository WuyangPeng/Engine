// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/03 10:04)

#include "Database/DatabaseExport.h"

#include "ResultImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

Database::ResultImpl
	::ResultImpl(const ConfigurationStrategy& configurationStrategy)
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

	THROW_EXCEPTION(SYSTEM_TEXT("DocResultImpl的FetchOne未实现。"));
}

Database::ResultImpl::ResultRowContainer Database::ResultImpl
	::FetchAll()
{
	DATABASE_CLASS_IS_VALID_9;

	THROW_EXCEPTION(SYSTEM_TEXT("DocResultImpl的FetchAll未实现。"));
}

Database::ConfigurationStrategy Database::ResultImpl
	::GetConfigurationStrategy() const
{
	DATABASE_CLASS_IS_VALID_CONST_9;

	return m_ConfigurationStrategy;
}

