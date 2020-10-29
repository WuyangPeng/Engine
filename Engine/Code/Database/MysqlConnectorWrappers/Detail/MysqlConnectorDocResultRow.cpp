//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:44)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorDocResultRow.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::ostream;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorDocResultRow::MysqlConnectorDocResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocPtr& mysqlxDbDoc) noexcept
    : ParentType{ configurationStrategy }, m_MysqlxDbDoc{ mysqlxDbDoc }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorDocResultRow::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_MysqlxDbDoc)
        return true;
    else
        return false;
}
    #endif  // OPEN_CLASS_INVARIANT

void Database::MysqlConnectorDocResultRow::Print(ostream& os) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    os << *m_MysqlxDbDoc;
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR