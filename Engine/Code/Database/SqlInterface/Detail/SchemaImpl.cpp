///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 17:19)

#include "Database/DatabaseExport.h"

#include "SchemaImpl.h"

#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

Database::SchemaImpl::SchemaImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : configurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

Database::SchemaImpl::~SchemaImpl() noexcept = default;

CLASS_INVARIANT_STUB_DEFINE(Database, SchemaImpl)

Database::ConfigurationStrategy Database::SchemaImpl::GetConfigurationStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_9;

    return configurationStrategy;
}

Database::SchemaImpl::MysqlxCollectionUniquePtr Database::SchemaImpl::GetCollection(MAYBE_UNUSED const string& collectionName) const
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SchemaImpl的GetCollection未实现。"s));
}

Database::SchemaImpl::MysqlxTableUniquePtr Database::SchemaImpl::GetTable(MAYBE_UNUSED const string& tableonName) const
{
    DATABASE_CLASS_IS_VALID_9;

    THROW_EXCEPTION(SYSTEM_TEXT("SchemaImpl的GetTable未实现。"s));
}
