// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 16:23)

#ifndef NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_INET_ADDRESS_TESTING_H
#define NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_INET_ADDRESS_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
	class BoostSockInetAddressTesting : public SingletonTesting
	{
	public:
            using ClassType = BoostSockInetAddressTesting;
            using ParentType = SingletonTesting;

        public:
            explicit BoostSockInetAddressTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		using TestingType = SockAddress;
		using TestingTypeSharedPtr = std::shared_ptr<SockAddress>;

	private:
		void MainTest();

		void AddressTest();

		void Address1Test();
		void Address2Test();
		void Address3Test();

		void ACEAddressExceptionTest();
		void WinSocketAddressExceptionTest();

		void CopyConstructorTest(const SockAddressSharedPtr& sockAddress);
		void CopyOperatorTest(const SockAddressSharedPtr& sockAddress);

		void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_BOOST_WRAPPERS_SUITE_BOOST_SOCK_INET_ADDRESS_TESTING_H