///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 13:45)

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

        using TestFunction = void (ClassType::*)();

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

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_BASE_MAIN_MANAGER_TESTING_H