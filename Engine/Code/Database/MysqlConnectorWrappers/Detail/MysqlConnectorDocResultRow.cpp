///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/25 18:51)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorDocResultRow.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::ostream;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorDocResultRow::MysqlConnectorDocResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxDbDocSharedPtr& mysqlxDbDoc) noexcept
    : ParentType{ configurationStrategy }, mysqlxDbDoc{ mysqlxDbDoc }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT

bool Database::MysqlConnectorDocResultRow::IsValid() const noexcept
{
    if (ParentType::IsValid() && mysqlxDbDoc)
        return true;
    else
        return false;
}

    #endif  // OPEN_CLASS_INVARIANT

void Database::MysqlConnectorDocResultRow::Print(ostream& os) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    os << *mysqlxDbDoc;
}

int Database::MysqlConnectorDocResultRow::GetColCount() const noexcept
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return 0;
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR