// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/16 18:46)

#include "CollectionTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Database/SqlInterface/Session.h"
#include "Database/SqlInterface/Schema.h"
#include "Database/SqlInterface/Collection.h"
#include "Database/Configuration/ConfigurationStrategy.h"

using std::vector;
using std::string;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Database, CollectionTesting)

void Database::CollectionTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(NullCollectionTest);
}

void Database::CollectionTesting
	::NullCollectionTest()
{
	ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,"127.0.0.1",3306,"tcretest","root","123456" };

	Session session{ configurationStrategy };

	Schema  schema{ session };

	Collection collection{ schema ,"my_collection" };
}

