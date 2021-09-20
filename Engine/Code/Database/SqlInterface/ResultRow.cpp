//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 10:43)

#include "Database/DatabaseExport.h"

#include "ResultRow.h"
#include "Detail/ResultRowFactory.h"
#include "Detail/ResultRowImpl.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Contract/Flags/ImplFlags.h"

using std::ostream;
using std::string;
using std::wstring;

Database::ResultRow::ResultRow(const ConfigurationStrategy& configurationStrategy)
    :   impl{ CoreTools::ImplCreateUseFactory::Default, configurationStrategy  }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
Database::ResultRow::ResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocPtr& mysqlxDbDoc)
    :  impl{ CoreTools::ImplCreateUseFactory::Default,configurationStrategy, mysqlxDbDoc  }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::ResultRow::ResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow)
    : impl{ CoreTools::ImplCreateUseFactory::Default,configurationStrategy, mysqlxRow  }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

#endif  // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)

CLASS_INVARIANT_STUB_DEFINE(Database, ResultRow)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ResultRow, Print, ostream&, void)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ResultRow, GetIntValue, int, int)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ResultRow, GetUIntValue, int, uint32_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ResultRow, GetInt64Value, int, int64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ResultRow, GetUInt64Value, int, uint64_t)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ResultRow, GetFloatValue, int, float)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ResultRow, GetDoubleValue, int, double)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ResultRow, GetBoolValue, int, bool)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ResultRow, GetStringValue, int, string)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ResultRow, GetWStringValue, int, wstring)
IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, ResultRow, GetColCount, int)

ostream& Database::operator<<(ostream& out, const ResultRow& docResultRow)
{
    docResultRow.Print(out);

    return out;
}
