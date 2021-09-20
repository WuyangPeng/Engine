// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.2.4 (2020/03/12 10:38)

#ifndef NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_SUB_STRATEGY_TESTING_H
#define NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_SUB_STRATEGY_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class ConfigurationSubStrategyTesting : public CoreTools::UnitTest
	{
	public:
		UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(ConfigurationSubStrategyTesting);

	private:
		void MainTest();

		void SubStrategyTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_CONFIGURATION_SUITE_CONFIGURATION_SUB_STRATEGY_TESTING_H