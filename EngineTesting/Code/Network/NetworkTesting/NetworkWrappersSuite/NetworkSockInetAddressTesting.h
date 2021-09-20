// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:44)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_NETWORK_INET_ADDRESS_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_NETWORK_INET_ADDRESS_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
	class NetworkSockInetAddressTesting : public SingletonTesting
	{
	public:
            using ClassType = NetworkSockInetAddressTesting;
            using ParentType = SingletonTesting;

        public:
            explicit NetworkSockInetAddressTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void MainTest();

		void AddressTest();

		virtual void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_NETWORK_INET_ADDRESS_TESTING_H