///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/15 13:33)

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
        void DoRunUnitTest() override;

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

    private: 
        int32_t messageId;
        int increase;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ONLY_SENDING_CLIENT_TESTING_H