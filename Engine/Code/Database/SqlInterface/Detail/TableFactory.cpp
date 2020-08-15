// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/16 12:31)

#include "Database/DatabaseExport.h"

#include "TableFactory.h"
#include "TableImpl.h"
#include "NullTable.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/DatabaseClassInvariantMacro.h" 
#include "Database/SqlInterface/Schema.h"
#include "Database/MysqlConnectorWrappers/Detail/MysqlConnectorTable.h"

using std::make_shared;
using std::string;

Database::TableFactory
	::TableFactory() noexcept
{
	DATABASE_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Database, TableFactory)

Database::TableFactory::ImplTypePtr Database::TableFactory
	::Create(const Schema& schema, const string& tableName)
{
    const auto configurationStrategy = schema.GetConfigurationStrategy();
	const auto wrappersStrategy = configurationStrategy.GetWrappersStrategy();
	switch (wrappersStrategy)
	{
	#ifdef DATABASE_USE_MYSQL_CPP_CONNECTOR 

	case Database::WrappersStrategy::MysqlConnector:
		return make_shared<MysqlConnectorTable>(schema, tableName);

	#endif // DATABASE_USE_MYSQL_CPP_CONNECTOR

	case Database::WrappersStrategy::Null:
	case Database::WrappersStrategy::Mysql:
	case Database::WrappersStrategy::SQLite:
	case Database::WrappersStrategy::SqlServer:
	case Database::WrappersStrategy::FlatFile:
	default:
		return make_shared<NullTable>(configurationStrategy);
	}
}


