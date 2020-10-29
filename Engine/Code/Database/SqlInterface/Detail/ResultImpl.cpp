//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:40)

#include "Database/DatabaseExport.h"

#include "ResultImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Database::ResultImpl::ResultImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : m_ConfigurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, ResultImpl)

Database::ResultImpl::ResultRowPtr Database::ResultImpl::FetchOne()
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("DocResultImpl的FetchOne未实现。"s));
}

Database::ResultImpl::ResultRowContainer Database::ResultImpl::FetchAll()
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("DocResultImpl的FetchAll未实现。"s));
}

Database::ConfigurationStrategy Database::ResultImpl::GetConfigurationStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_ConfigurationStrategy;
}
