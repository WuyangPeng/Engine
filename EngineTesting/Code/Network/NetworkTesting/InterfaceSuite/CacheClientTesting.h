///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/16 08:55)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_CACHE_CLIENT_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_CACHE_CLIENT_TESTING_H

#include "SingletonTesting.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/Interface/Server.h"

namespace Network
{
    class CacheClientTesting : public SingletonTesting
    {
    public:
        using ClassType = CacheClientTesting;
        using ParentType = SingletonTesting;

    public:
        explicit CacheClientTesting(const OStreamShared& stream);

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

        void ACESendingClientTest();
        void ACEAsyncSendingClientTest();
        void ACEServerThread();
        void DoACEServerThread();

        void BoostSendingClientTest();
        void BoostAsyncSendingClientTest();
        void BoostServerThread();
        void BoostRunServerThread();
        void DoBoostServerThread();

        void NullSendingClientTest();
        void NullAsyncSendingClientTest();
        void NullServerThread();
        void DoNullServerThread() noexcept;

    private:
        uint32_t messageId;
        int increase;
        std::atomic_int boostStop;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_CACHE_CLIENT_TESTING_H