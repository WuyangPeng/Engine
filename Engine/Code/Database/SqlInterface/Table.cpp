///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 17:23)

#include "Database/DatabaseExport.h"

#include "Table.h"
#include "Detail/TableFactory.h"
#include "Detail/TableImpl.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

using std::string;

Database::Table::Table(const Schema& schema, const string& tableName)
    : impl{ CoreTools::ImplCreateUseFactory::Default, schema, tableName }
{
    DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, Table)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, Table, GetConfigurationStrategy, Database::ConfigurationStrategy)

Database::Table::ResultSharedPtr Database::Table::Select(StatementType selectStatement, const string& whereStatement, const string& orderByStatement, const BindStatementType& bindStatement)
{
    DATABASE_CLASS_IS_VALID_9;

    return impl->Select(selectStatement, whereStatement, orderByStatement, bindStatement);
}
