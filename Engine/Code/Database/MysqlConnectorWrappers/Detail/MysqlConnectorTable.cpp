// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:52)

#include "Database/DatabaseExport.h"

#include "MysqlConnectorTable.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "Database/SqlInterface/Schema.h"
#include "Database/SqlInterface/Detail/SchemaImpl.h"

using std::make_shared;
using std::string;
using std::initializer_list;

#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR

Database::MysqlConnectorTable
	::MysqlConnectorTable(const Schema& schema, const string& tableName)
	: ParentType{ schema.GetConfigurationStrategy() }, m_MysqlxTable{ GetMysqlxTablePtr(schema,tableName) }
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

Database::MysqlConnectorTable
	::~MysqlConnectorTable()
{
	DATABASE_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool Database::MysqlConnectorTable
	::IsValid() const noexcept
{
	if (ParentType::IsValid() && m_MysqlxTable)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

Database::MysqlConnectorTable::MysqlxTablePtr Database::MysqlConnectorTable
	::GetMysqlxTablePtr(const Schema& schema, const string& tableName)
{
	auto implPtr = schema.GetImplType().lock();

	if (implPtr)
	{
		return implPtr->GetTable(tableName);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("ªÒ»°schema ß∞‹°£"));
	}
}

Database::MysqlConnectorTable::ResultPtr Database::MysqlConnectorTable
	::Select(initializer_list<string> selectStatement, const string& whereStatement, const string& orderByStatement, const BindStatementType& bindStatement)
{
	DATABASE_CLASS_IS_VALID_1;

	using MysqlxRowResultPtr = std::shared_ptr<MysqlxRowResult>;

	auto statement = m_MysqlxTable->select(selectStatement);

	if (!whereStatement.empty())
	{
		statement = statement.where(whereStatement);
	}

	if (!orderByStatement.empty())
	{
		statement = statement.orderBy(orderByStatement);
	}

	for (const auto& value : bindStatement)
	{
		statement = statement.bind(value.first, value.second);
	}

	return make_shared<Result>(GetConfigurationStrategy(), make_shared<MysqlxRowResult>(statement.execute()));
}

#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR