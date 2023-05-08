///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 13:58)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ACCEPTOR_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ACCEPTOR_TESTING_H

#include "SingletonTesting.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Network
{
    class SockAcceptorTesting : public SingletonTesting
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

        void DoRunUnitTest() override;

    private:
        int mPort;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SOCK_ACCEPTOR_TESTING_H