//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:43)

#include "Database/DatabaseExport.h"

#include "Table.h"
#include "Detail/TableFactory.h"
#include "Detail/TableImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"

using std::initializer_list;
using std::string;

Database::Table::Table(const Schema& schema, const string& tableName)
    : impl{ CoreTools::ImplCreateUseFactory::Default,schema, tableName  }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(Database, Table)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0_NOEXCEPT(Database, Table, GetConfigurationStrategy, Database::ConfigurationStrategy)

Database::Table::ResultPtr Database::Table::Select(initializer_list<string> selectStatement, const string& whereStatement, const string& orderByStatement, const BindStatementType& bindStatement)
{
    

    return impl->Select(selectStatement, whereStatement, orderByStatement, bindStatement);
}
