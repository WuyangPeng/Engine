// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:08)

#include "Database/DatabaseExport.h"

#include "Table.h"
#include "Detail/TableImpl.h"
#include "Detail/TableFactory.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::string;
using std::initializer_list;

Database::Table
	::Table(const Schema& schema, const string& tableName)
	: m_Impl{ TableFactory::Create(schema,tableName) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_IMPL_IS_VALID_DEFINE(Database, Table)

IMPL_CONST_MEMBER_FUNCTION_DEFINE_0(Database, Table, GetConfigurationStrategy, Database::ConfigurationStrategy)

Database::Table::ResultPtr Database::Table
	::Select(initializer_list<string> selectStatement, const string& whereStatement, const string& orderByStatement, const BindStatementType& bindStatement)
{
	IMPL_NON_CONST_MEMBER_FUNCTION_STATIC_ASSERT;

	return m_Impl->Select(selectStatement, whereStatement, orderByStatement, bindStatement);
}
 
