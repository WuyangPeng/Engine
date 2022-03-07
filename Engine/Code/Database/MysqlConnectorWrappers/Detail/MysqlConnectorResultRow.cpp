///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/25 18:51)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorResultRow.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

using std::make_shared;
using std::string;
using std::wstring;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorResultRow::MysqlConnectorResultRow(const ConfigurationStrategy& configurationStrategy, const MysqlxRowPtr& mysqlxRow) noexcept
    : ParentType{ configurationStrategy }, mysqlxRow{ mysqlxRow }
{
    DATABASE_SELF_CLASS_IS_VALID_1;
}

    #ifdef OPEN_CLASS_INVARIANT

bool Database::MysqlConnectorResultRow::IsValid() const noexcept
{
    if (ParentType::IsValid() && mysqlxRow)
        return true;
    else
        return false;
}

    #endif  // OPEN_CLASS_INVARIANT

void Database::MysqlConnectorResultRow::Print(std::ostream& os) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    os << *mysqlxRow;
}

int Database::MysqlConnectorResultRow::GetIntValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*mysqlxRow)[pos];
}

uint32_t Database::MysqlConnectorResultRow::GetUIntValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*mysqlxRow)[pos];
}

int64_t Database::MysqlConnectorResultRow::GetInt64Value(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*mysqlxRow)[pos];
}

uint64_t Database::MysqlConnectorResultRow::GetUInt64Value(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*mysqlxRow)[pos];
}

float Database::MysqlConnectorResultRow::GetFloatValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*mysqlxRow)[pos];
}

double Database::MysqlConnectorResultRow::GetDoubleValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*mysqlxRow)[pos];
}

bool Database::MysqlConnectorResultRow::GetBoolValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*mysqlxRow)[pos].get<bool>();
}

string Database::MysqlConnectorResultRow::GetStringValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*mysqlxRow)[pos].get<string>();
}

wstring Database::MysqlConnectorResultRow::GetWStringValue(int pos) const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return (*mysqlxRow)[pos].get<wstring>();
}

int Database::MysqlConnectorResultRow::GetColCount() const
{
    DATABASE_CLASS_IS_VALID_CONST_1;

    return mysqlxRow->colCount();
}

#endif  // DATABASE_USE_MYSQL_CPP_CONNECTOR