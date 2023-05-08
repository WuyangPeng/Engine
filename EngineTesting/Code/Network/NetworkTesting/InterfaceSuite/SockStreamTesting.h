///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 14:00)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_STREAM_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_STREAM_TESTING_H

#include "SingletonTesting.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class SockStreamTesting : public SingletonTesting
    {
    public:
        using ClassType = SockStreamTesting;
        using ParentType = SingletonTesting;

    public:
        explicit SockStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

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

        void ACEGetACESockStreamTest();
        void ACEGetBoostSockStreamExceptionTest();
        void ACEGetNetworkSockStreamExceptionTest();

        void BoostGetACESockStreamExceptionTest();
        void BoostGetBoostSockStreamTest();
        void BoostGetNetworkSockStreamExceptionTest();

        void NetworkGetACESockStreamExceptionTest();
        void NetworkGetBoostSockStreamExceptionTest();
        void NetworkGetNetworkSockStreamTest();

        void NullGetACESockStreamExceptionTest();
        void NullGetBoostSockStreamExceptionTest();
        void NullGetNetworkSockStreamExceptionTest();

        void ACEGetACEHandleTest();
        void ACESetACEHandleTest();
        void ACESetNetworkHandleExceptionTest();

        void BoostGetACEHandleExceptionTest();
        void BoostSetACEHandleExceptionTest();
        void BoostSetNetworkHandleExceptionTest();

        void NetworkGetACEHandleExceptionTest();
        void NetworkSetACEHandleExceptionTest();
        void NetworkSetNetworkHandleTest();

        void NullGetACEHandleExceptionTest();
        void NullSetACEHandleExceptionTest();
        void NullSetNetworkHandleExceptionTest();

        void DoRunUnitTest() override;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_STREAM_TESTING_H