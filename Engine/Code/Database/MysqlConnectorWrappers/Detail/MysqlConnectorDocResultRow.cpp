// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/03 10:25)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorDocResultRow.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 

using std::make_shared;
using std::ostream;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR
 
Database::MysqlConnectorDocResultRow
	::MysqlConnectorDocResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocPtr& mysqlxDbDoc)
	: ParentType{ configurationStrategy }, m_MysqlxDbDoc{ mysqlxDbDoc }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorDocResultRow
	::~MysqlConnectorDocResultRow()
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorDocResultRow
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_MysqlxDbDoc)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

void Database::MysqlConnectorDocResultRow
	::Print(ostream& os) const
{
	DATABASE_CLASS_IS_VALID_CONST_1;

	os << *m_MysqlxDbDoc;
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR