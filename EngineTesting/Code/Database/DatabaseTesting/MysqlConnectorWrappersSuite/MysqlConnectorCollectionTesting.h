// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/16 18:54)

#ifndef DATABASE_TESTING_SQL_INTERFACE_SUITE_MYSQL_CONNECTOR_COLLECTION_TESTING_H
#define DATABASE_TESTING_SQL_INTERFACE_SUITE_MYSQL_CONNECTOR_COLLECTION_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Database
{
	class MysqlConnectorCollectionTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MysqlConnectorCollectionTesting);

	private:
		void MainTest();

		void CollectionTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // DATABASE_TESTING_SQL_INTERFACE_SUITE_MYSQL_CONNECTOR_COLLECTION_TESTING_H