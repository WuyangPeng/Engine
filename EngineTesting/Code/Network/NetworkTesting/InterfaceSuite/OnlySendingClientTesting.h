///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 13:54)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ONLY_SENDING_CLIENT_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ONLY_SENDING_CLIENT_TESTING_H

#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTesting.h"

namespace Network
{
    class OnlySendingClientTesting : public SingletonTesting
    {
    public:
        using ClassType = OnlySendingClientTesting;
        using ParentType = SingletonTesting;

    public:
        explicit OnlySendingClientTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        using TestFunction = void (ClassType::*)();

    private:
        void MainTest();

        void ACETest();
        void BoostTest();
        void AsyncBoostTest();
        void NullTest();

        void CreateMessage();
        void DestroyMessage();

        void ACEOnlySendingClientTest();
        void ACEAsyncOnlySendingClientTest();
        void ACEServerThread();
        void DoACEServerThread();

        void BoostOnlySendingClientTest();
        void BoostAsyncOnlySendingClientTest();
        void BoostServerThread();
        void BoostRunServerThread();
        void DoBoostServerThread();

        void NullOnlySendingClientTest();
        void NullAsyncOnlySendingClientTest();
        void NullServerThread();
        void DoNullServerThread() noexcept;

        void DoRunUnitTest() override;

    private:
        int mPort;
        uint32_t messageID;
        int increase;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ONLY_SENDING_CLIENT_TESTING_H