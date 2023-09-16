///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:55)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BASE_MAIN_MANAGER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BASE_MAIN_MANAGER_TESTING_H

#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class BaseMainManagerTesting final : public SingletonTesting
    {
    public:
        using ClassType = BaseMainManagerTesting;
        using ParentType = SingletonTesting;

    public:
        explicit BaseMainManagerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();
        void DoRunUnitTest() override;

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
        void NetworkGetIoContextExceptionTest();
        void NetworkStopContextExceptionTest();
        void NetworkIsContextStopExceptionTest();
        void NetworkRestartContextExceptionTest();

        void NullRunTest();
        void NullGetIoContextExceptionTest();
        void NullStopContextExceptionTest();
        void NullIsContextStopExceptionTest();
        void NullRestartContextExceptionTest();
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BASE_MAIN_MANAGER_TESTING_H