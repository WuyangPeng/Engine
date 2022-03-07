// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.5 (2020/03/16 18:55)

#ifndef DATABASE_TESTING_SQL_INTERFACE_SUITE_MYSQL_CONNECTOR_RESULT_TESTING_H
#define DATABASE_TESTING_SQL_INTERFACE_SUITE_MYSQL_CONNECTOR_RESULT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Database
{
	class MysqlConnectorResultTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(MysqlConnectorResultTesting);

	private:
		void MainTest();

		void ResultTest();

		void DoRunUnitTest() override;
	};
}

#endif // DATABASE_TESTING_SQL_INTERFACE_SUITE_MYSQL_CONNECTOR_RESULT_TESTING_H