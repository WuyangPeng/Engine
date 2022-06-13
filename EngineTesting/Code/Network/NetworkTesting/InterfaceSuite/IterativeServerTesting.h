///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 13:53)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ITERATIVE_SERVER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ITERATIVE_SERVER_TESTING_H

#include "Detail/TestSocketManager.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/Interface/Client.h"
#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class IterativeServerTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(IterativeServerTesting);

    private:
        void MainTest();
        void CreateMessage();
        void IterativeServerTest();
        void ClientThread(ClientSharedPtr client, TestSocketManagerSharedPtr testSocketManagerSharedPtr);
        void DestroyMessage();

        void DoRunUnitTest() override;

    private:
        int mPort;
        uint32_t messageID;
        int increase;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ITERATIVE_SERVER_TESTING_H