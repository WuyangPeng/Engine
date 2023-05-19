///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/15 10:28)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_STREAM_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_STREAM_TESTING_H

#include "SingletonTesting.h"

namespace Network
{
    class SockStreamTesting final : public SingletonTesting
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
        void DoRunUnitTest() override;

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
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_STREAM_TESTING_H