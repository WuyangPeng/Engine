///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 16:56)

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

    THROW_EXCEPTION(SYSTEM_TEXT("DatabaseObjectImpl��GetMysqlxSessionPtrδʵ�֡�"s));
}
