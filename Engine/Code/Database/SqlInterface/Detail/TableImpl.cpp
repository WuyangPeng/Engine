//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:42)

#include "Database/DatabaseExport.h"

#include "TableImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::initializer_list;
using std::string;
using namespace std::literals;

Database::TableImpl::TableImpl(const ConfigurationStrategy& configurationStrategy) noexcept
    : m_ConfigurationStrategy{ configurationStrategy }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, TableImpl)

Database::ConfigurationStrategy Database::TableImpl::GetConfigurationStrategy() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return m_ConfigurationStrategy;
}

Database::TableImpl::ResultPtr Database::TableImpl::Select([[maybe_unused]] std::initializer_list<string> selectStatement, [[maybe_unused]] const string& whereStatement,
                                                           [[maybe_unused]] const string& orderByStatement, [[maybe_unused]] const BindStatementType& bindStatement)
{
    DATABASE_CLASS_IS_VALID_1;

    THROW_EXCEPTION(SYSTEM_TEXT("TableImpl未实现Select"s));
}
