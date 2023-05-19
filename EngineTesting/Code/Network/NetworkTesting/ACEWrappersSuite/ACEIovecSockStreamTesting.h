///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 10:10)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_IOVEC_SOCK_STREAM_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_IOVEC_SOCK_STREAM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class ACEIovecSockStreamTesting : public SingletonTesting
    {
    public:
        using ClassType = ACEIovecSockStreamTesting;
        using ParentType = SingletonTesting;

    public:
        explicit ACEIovecSockStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void StreamTest();

        void ACEServerThread();
        void DoACEServerThread();

        void DoRunUnitTest() override;

    private:
        int port;
    };
}

#endif  // NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_IOVEC_SOCK_STREAM_TESTING_H