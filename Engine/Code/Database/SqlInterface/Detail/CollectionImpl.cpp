///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 16:52)

#include "Database/DatabaseExport.h"

#include "CollectionImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

Database::CollectionImpl::CollectionImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : configurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::CollectionImpl::~CollectionImpl() noexcept = default;

CLASS_INVARIANT_STUB_DEFINE(Database, CollectionImpl)

Database::CollectionImpl::ResultSharedPtr Database::CollectionImpl::ExecuteDoc(MAYBE_UNUSED const string& findStatement, MAYBE_UNUSED const BindStatementType& bindStatement, MAYBE_UNUSED int limitStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("CollectionImpl未实现Execute"s));
}

Database::ConfigurationStrategy Database::CollectionImpl::GetConfigurationStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return configurationStrategy;
}
