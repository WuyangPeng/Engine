///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/15 10:32)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_HANDLE_SET_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_HANDLE_SET_TESTING_H

#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class HandleSetTesting final : public SingletonTesting
    {
    public:
        using ClassType = HandleSetTesting;
        using ParentType = SingletonTesting;

    public:
        explicit HandleSetTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void ACETest();
        void BoostTest();
        void NetworkTest();
        void NullTest();

        void ACEConstructionTest();
        void BoostConstructionTest();
        void NetworkConstructionTest();
        void NullConstructionTest();

        void ACEHandleTest();
        void BoostHandleTest();
        void NetworkHandleTest();
        void NullHandleTest();

        void BoostGetFdSetExceptionTest();
        void NetworkGetFdSetExceptionTest();
        void NullGetFdSetExceptionTest();

        void BoostGetACEHandleSetExceptionTest();
        void NetworkGetACEHandleSetExceptionTest();
        void NullGetACEHandleSetExceptionTest();
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_HANDLE_SET_TESTING_H