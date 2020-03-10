// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:07)

#include "Database/DatabaseExport.h"

#include "ResultRow.h"
#include "Detail/ResultRowFactory.h"
#include "Detail/ResultRowImpl.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::ostream;
using std::string;
using std::wstring;

Database::ResultRow
	::ResultRow(const ConfigurationStrategy& configurationStrategy)
	: m_Impl{ ResultRowFactory::Create(configurationStrategy) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

#if defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)
Database::ResultRow
	::ResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocPtr& mysqlxDbDoc)
	: m_Impl{ ResultRowFactory::Create(configurationStrategy,mysqlxDbDoc) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::ResultRow
	::ResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow)
	: m_Impl{ ResultRowFactory::Create(configurationStrategy,mysqlxRow) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

#endif // defined(BUILDING_DATABASE_EXPORT) || defined(BUILDING_DATABASE_NO_IMPORT) || defined(BUILDING_DATABASE_STATIC)

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Database, ResultRow)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_1_V(Database, ResultRow, Print, ostream&,void) 
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

ostream& Database
	::operator<<(ostream& out, const ResultRow& docResultRow)
{
	docResultRow.Print(out);

	return out;
}
 
