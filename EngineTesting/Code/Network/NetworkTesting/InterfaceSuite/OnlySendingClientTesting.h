// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 11:38)

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
        int m_Port;
        uint32_t m_MessageID;
        int m_Increase;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_ONLY_SENDING_CLIENT_TESTING_H