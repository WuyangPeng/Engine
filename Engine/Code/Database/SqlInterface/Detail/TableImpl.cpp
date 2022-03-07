///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 17:20)

#include "Database/DatabaseExport.h"

#include "TableImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::string;

Database::TableImpl::TableImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : configurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, TableImpl)

Database::ConfigurationStrategy Database::TableImpl::GetConfigurationStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return configurationStrategy;
}

Database::TableImpl::ResultSharedPtr Database::TableImpl::Select(MAYBE_UNUSED StatementType selectStatement,
                                                                 MAYBE_UNUSED const string& whereStatement,
                                                                 MAYBE_UNUSED const string& orderByStatement,
                                                                 MAYBE_UNUSED const BindStatementType& bindStatement)
{
    DATABASE_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("TableImpl未实现Select"s));
}
