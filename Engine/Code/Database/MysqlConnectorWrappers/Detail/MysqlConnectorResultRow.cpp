//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/29 13:45)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorResultRow.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::string;
using std::wstring;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorResultRow::MysqlConnectorResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow) noexcept
    : ParentType{ configurationStrategy }, m_MysqlxRow{ mysqlxRow }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorResultRow::IsValid() const noexcept
{
    if (ParentType::IsValid() && m_MysqlxRow)
        return true;
    else
        return false;
}
    #endif  // OPEN_CLASS_INVARIANT

void Database::MysqlConnectorResultRow::Print(std::ostream& os) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    os << *m_MysqlxRow;
}

int Database::MysqlConnectorResultRow::GetIntValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*m_MysqlxRow)[pos];
}

uint32_t Database::MysqlConnectorResultRow::GetUIntValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*m_MysqlxRow)[pos];
}

int64_t Database::MysqlConnectorResultRow::GetInt64Value(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*m_MysqlxRow)[pos];
}

uint64_t Database::MysqlConnectorResultRow::GetUInt64Value(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*m_MysqlxRow)[pos];
}

float Database::MysqlConnectorResultRow::GetFloatValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*m_MysqlxRow)[pos];
}

double Database::MysqlConnectorResultRow::GetDoubleValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*m_MysqlxRow)[pos];
}

bool Database::MysqlConnectorResultRow::GetBoolValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*m_MysqlxRow)[pos].get<bool>();
}

string Database::MysqlConnectorResultRow::GetStringValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*m_MysqlxRow)[pos].get<string>();
}

wstring Database::MysqlConnectorResultRow::GetWStringValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*m_MysqlxRow)[pos].get<wstring>();
}

int Database::MysqlConnectorResultRow::GetColCount() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return m_MysqlxRow->colCount();
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR