// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:11)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_CONNECTOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_CONNECTOR_TESTING_H

#include "SingletonTesting.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace Network
{
	class SockConnectorTesting : public SingletonTesting
	{
	public:
            using ClassType = SockConnectorTesting;
            using ParentType = SingletonTesting;

        public:
            explicit SockConnectorTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void MainTest();

		void ACETest();
		void BoostTest();
		void NetworkTest();
		void NullTest();

		void ACEConstructionTest();
		void BoostConstructionTest();
		void NetworkConstructionTest();
		void NullConstructionTest();

		void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_CONNECTOR_TESTING_H