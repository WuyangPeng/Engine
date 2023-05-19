///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/15 10:20)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ACCEPTOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ACCEPTOR_TESTING_H

#include "SingletonTesting.h"

namespace Network
{
    class SockAcceptorTesting final : public SingletonTesting
    {
    public:
        using ClassType = SockAcceptorTesting;
        using ParentType = SingletonTesting;

    public:
        explicit SockAcceptorTesting(const OStreamShared& stream);

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

        void ACEGetACEHandleTest();
        void ACEGetBoostHandleExceptionTest();
        void ACEGetNetworkHandleExceptionTest();

        void BoostGetACEHandleExceptionTest();
        void BoostGetBoostHandleTest();
        void BoostGetNetworkHandleExceptionTest();

        void NetworkGetACEHandleExceptionTest();
        void NetworkGetBoostHandleExceptionTest();

        void NullGetACEHandleExceptionTest();
        void NullGetBoostHandleExceptionTest();
        void NullGetNetworkHandleExceptionTest();
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ACCEPTOR_TESTING_H