///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/17 15:37)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_REACTIVE_SERVER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_REACTIVE_SERVER_TESTING_H

#include "Network/Interface/Client.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class ReactiveServerTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ReactiveServerTesting;
        using ParentType = UnitTest;

    public:
        explicit ReactiveServerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void DoRunUnitTest() override;

        void CreateMessage();
        void ReactiveServerTest();
        void ClientThread(Client& client);
        void DestroyMessage();

    private:
        int port;
        int32_t serverSendMessageId;
        int32_t clientSendMessageId;
        int increase;
        int bufferSize;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_REACTIVE_SERVER_TESTING_H