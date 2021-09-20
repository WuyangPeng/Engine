// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/16 18:57)

#include "MysqlConnectorSessionTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/SqlInterface/Session.h"
#include "Database/Configuration/ConfigurationStrategy.h"

using std::vector;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, MysqlConnectorSessionTesting)

void Database::MysqlConnectorSessionTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(SessionTest);
}

void Database::MysqlConnectorSessionTesting
	::SessionTest()
{
	ConfigurationStrategy configurationStrategy{ WrappersStrategy::MysqlConnector,"127.0.0.1",33060,"","root","TCRE" };

	Session session{ configurationStrategy };
}

