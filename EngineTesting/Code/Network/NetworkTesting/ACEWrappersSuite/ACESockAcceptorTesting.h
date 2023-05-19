///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 09:41)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_ACCEPTOR_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_ACCEPTOR_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class ACESockAcceptorTesting : public SingletonTesting
    {
    public:
        using ClassType = ACESockAcceptorTesting;
        using ParentType = SingletonTesting;

    public:
        explicit ACESockAcceptorTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void AcceptorTest();
    };
}

#endif  // NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_ACCEPTOR_TESTING_H