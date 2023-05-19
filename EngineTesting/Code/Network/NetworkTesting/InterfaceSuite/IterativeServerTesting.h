///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/17 14:50)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ITERATIVE_SERVER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ITERATIVE_SERVER_TESTING_H

#include "Detail/TestSocketEvent.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/Interface/Client.h"
#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class IterativeServerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = IterativeServerTesting;
        using ParentType = UnitTest;

    public:
        explicit IterativeServerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void CreateMessage();
        void IterativeServerTest();
        void ClientThread(Client& client, const TestSocketEvent& testSocketManager);
        void DestroyMessage();

    private:
        int port;
        int32_t messageId;
        int increase;
        int bufferSize;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ITERATIVE_SERVER_TESTING_H