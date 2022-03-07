// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 11:31)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BASE_MAIN_MANAGER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BASE_MAIN_MANAGER_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h" 

namespace Network
{
	class BaseMainManagerTesting : public SingletonTesting
	{
	public:
            using ClassType = BaseMainManagerTesting;
            using ParentType = SingletonTesting;

        public:
            explicit BaseMainManagerTesting(const OStreamShared& stream);
            CLASS_INVARIANT_OVERRIDE_DECLARE;
		using TestFunction = void(ClassType::*)();

	private:
		void MainTest();

		void ACETest();
		void BoostTest();
		void ThreadsBoostTest();
		void MultiContextBoostTest();
		void NetworkTest();
		void NullTest();

		void ACERunTest();
		void ACEGetIOContextExceptionTest();
		void ACEStopContextExceptionTest();
		void ACEIsContextStopExceptionTest();
		void ACERestartContextExceptionTest();

		void NetworkRunTest();
		void NetworkGetIOContextExceptionTest();
		void NetworkStopContextExceptionTest();
		void NetworkIsContextStopExceptionTest();
		void NetworkRestartContextExceptionTest();

		void NullRunTest();
		void NullGetIOContextExceptionTest();
		void NullStopContextExceptionTest();
		void NullIsContextStopExceptionTest();
		void NullRestartContextExceptionTest();

		void DoRunUnitTest() override;
	};
}

#endif // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BASE_MAIN_MANAGER_TESTING_H