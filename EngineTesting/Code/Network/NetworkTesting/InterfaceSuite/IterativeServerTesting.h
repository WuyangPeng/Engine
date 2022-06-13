///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/24 13:53)

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