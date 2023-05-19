///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 09:50)

#ifndef NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_STREAM_TESTING_H
#define NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_STREAM_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class ACESockStreamTesting final : public SingletonTesting
    {
    public:
        using ClassType = ACESockStreamTesting;
        using ParentType = SingletonTesting;

    public:
        explicit ACESockStreamTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void StreamTest();

        void ACEServerThread();
        void DoACEServerThread();

    private:
        int port;
        int bufferSize;
    };
}

#endif  // NETWORK_TESTING_ACE_WRAPPERS_SUITE_ACE_SOCK_STREAM_TESTING_H