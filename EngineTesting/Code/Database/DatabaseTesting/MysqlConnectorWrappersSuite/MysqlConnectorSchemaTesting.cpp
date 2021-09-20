// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/16 18:57)

#include "MysqlConnectorSchemaTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/SqlInterface/Session.h"
#include "Database/SqlInterface/Schema.h"
#include "Database/Configuration/ConfigurationStrategy.h"

using std::vector;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, MysqlConnectorSchemaTesting)

void Database::MysqlConnectorSchemaTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SchemaTest);
	ASSERT_NOT_THROW_EXCEPTION_0(SchemaContainerTest);
}

void Database::MysqlConnectorSchemaTesting
	::SchemaTest()
{
	ConfigurationStrategy::FlagsOption flagsOption;
	ConfigurationStrategy::StringOption stringOption;
	ConfigurationStrategy::BooleanOption booleanOption;
	ConfigurationStrategy::IntOption intOption;
	ConfigurationStrategy::SSLOption sslOption;
	ConfigurationStrategy::DBMapping dbMapping;

	dbMapping.insert({ 1,"dbtest" });

	ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector,"127.0.0.1",33060,"tcretest","root","TCRE",false,10,100,1000,
												 flagsOption ,stringOption,booleanOption,intOption,sslOption,dbMapping };

	Session session{ configurationStrategy };

	Schema firstSchema{ session };
	Schema secondSchema{ session,1 };
}

void Database::MysqlConnectorSchemaTesting
	::SchemaContainerTest()
{
	ConfigurationStrategy::FlagsOption flagsOption;
	ConfigurationStrategy::StringOption stringOption;
	ConfigurationStrategy::BooleanOption booleanOption;
	ConfigurationStrategy::IntOption intOption;
	ConfigurationStrategy::SSLOption sslOption;
	ConfigurationStrategy::DBMapping dbMapping;

	dbMapping.insert({ 1,"dbtest" });

	ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector,"127.0.0.1",33060,"tcretest","root","TCRE",false,10,100,1000,
												 flagsOption ,stringOption,booleanOption,intOption,sslOption,dbMapping };

	Session session{ configurationStrategy };

	auto schemaContainer = session.GetSchemaContainer();

	ASSERT_LESS(0u, schemaContainer.size());
}

