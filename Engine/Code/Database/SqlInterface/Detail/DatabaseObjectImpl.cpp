//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:37)

#include "Database/DatabaseExport.h"

#include "DatabaseObjectImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Database::DatabaseObjectImpl::DatabaseObjectImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : m_ConfigurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::DatabaseObjectImpl::~DatabaseObjectImpl() noexcept
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseObjectImpl)

Database::ConfigurationStrategy Database::DatabaseObjectImpl::GetConfigurationStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_ConfigurationStrategy;
}

Database::DatabaseObjectImpl::MysqlxSessionPtr Database::DatabaseObjectImpl::GetMysqlxSessionPtr()
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("DatabaseObjectImpl的GetMysqlxSessionPtr未实现。"s));
}
