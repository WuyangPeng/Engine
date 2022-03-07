///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 16:56)

#include "Database/DatabaseExport.h"

#include "DatabaseObjectImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Database::DatabaseObjectImpl::DatabaseObjectImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : configurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::DatabaseObjectImpl::~DatabaseObjectImpl() noexcept = default;

CLASS_INVARIANT_STUB_DEFINE(Database, DatabaseObjectImpl)

Database::ConfigurationStrategy Database::DatabaseObjectImpl::GetConfigurationStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return configurationStrategy;
}

Database::DatabaseObjectImpl::MysqlxSessionUniquePtr Database::DatabaseObjectImpl::GetMysqlxSession() const
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("DatabaseObjectImpl的GetMysqlxSessionPtr未实现。"s));
}
