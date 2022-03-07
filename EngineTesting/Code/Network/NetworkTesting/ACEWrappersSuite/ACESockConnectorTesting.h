// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 15:55)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_CONNECTOR_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_CONNECTOR_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
	class ACESockConnectorTesting : public SingletonTesting
	{
	public:
            using ClassType = ACESockConnectorTesting;
            using ParentType = SingletonTesting;

        public:
            explicit ACESockConnectorTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void MainTest();

		void ConnectorTest();

		void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_CONNECTOR_TESTING_H