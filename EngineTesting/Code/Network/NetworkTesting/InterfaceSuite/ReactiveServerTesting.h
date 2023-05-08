///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 13:56)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_REACTIVE_SERVER_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_REACTIVE_SERVER_TESTING_H

#include "Network/Interface/Client.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class ReactiveServerTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = ReactiveServerTesting;
        using ParentType = UnitTest;

    public:
        explicit ReactiveServerTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void MainTest();
        void CreateMessage();
        void ReactiveServerTest();
        void ClientThread(Client& client);
        void DestroyMessage();

        void DoRunUnitTest() override;

    private:
        int mPort;
        uint32_t serverSendMessageID;
        uint32_t clientSendMessageID;
        int increase;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_REACTIVE_SERVER_TESTING_H