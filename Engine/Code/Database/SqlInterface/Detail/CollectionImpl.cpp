//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:04)

#include "Database/DatabaseExport.h"

#include "CollectionImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

Database::CollectionImpl::CollectionImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : m_ConfigurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::CollectionImpl::~CollectionImpl() noexcept
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, CollectionImpl)

Database::CollectionImpl::ResultPtr Database::CollectionImpl::ExecuteDoc([[maybe_unused]] const string& findStatement, [[maybe_unused]] const BindStatementType& bindStatement, [[maybe_unused]] int limitStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("CollectionImpl未实现Execute"s));
}

Database::ConfigurationStrategy Database::CollectionImpl::GetConfigurationStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return m_ConfigurationStrategy;
}
