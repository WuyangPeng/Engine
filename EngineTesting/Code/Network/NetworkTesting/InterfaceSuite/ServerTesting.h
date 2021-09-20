// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:11)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SERVER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SERVER_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h" 

namespace Network
{
	class ServerTesting : public SingletonTesting
	{
	public:
            using ClassType = ServerTesting;
            using ParentType = SingletonTesting;

        public:
            explicit ServerTesting(const OStreamShared& stream);
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

		virtual void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SERVER_TESTING_H