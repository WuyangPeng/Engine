// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/16 18:46)

#include "DatabaseObjectTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/SqlInterface/Session.h"
#include "Database/SqlInterface/DatabaseObject.h"
#include "Database/Configuration/ConfigurationStrategy.h"

using std::vector;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, DatabaseObjectTesting)

void Database::DatabaseObjectTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(NullDatabaseObjectTest);
}

void Database::DatabaseObjectTesting
	::NullDatabaseObjectTest()
{
	ConfigurationStrategy::FlagsOption flagsOption;
	ConfigurationStrategy::StringOption stringOption;
	ConfigurationStrategy::BooleanOption booleanOption;
	ConfigurationStrategy::IntOption intOption;
	ConfigurationStrategy::SSLOption sslOption;
	ConfigurationStrategy::DBMapping dbMapping;

	ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,"127.0.0.1",3306,"tcretest","root","123456",true,10,100,1000,
												 flagsOption ,stringOption,booleanOption,intOption,sslOption,dbMapping };

	DatabaseObject databaseObject{ configurationStrategy };

	Session session{ databaseObject };
}

