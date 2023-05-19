///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/15 09:13)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SINGLETON_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SINGLETON_TESTING_H

#include "System/Helper/Platform.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"
#include "Network/Configuration/ConfigurationStrategy.h"

namespace Network
{
    class SingletonTesting : public CoreTools::UnitTest
    {
    public:
        using ClassType = SingletonTesting;
        using ParentType = UnitTest;

    public:
        explicit SingletonTesting(const OStreamShared& stream);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    protected:
        template <typename Test>
        void ACESingletonTest(Test* test, typename Test::TestFunction function);

        template <typename Test>
        void BoostSingletonTest(Test* test, typename Test::TestFunction function);

        template <typename Test>
        void ThreadsBoostSingletonTest(Test* test, typename Test::TestFunction function);

        template <typename Test>
        void MultiContextBoostSingletonTest(Test* test, typename Test::TestFunction function);

        template <typename Test>
        void NetworkSingletonTest(Test* test, typename Test::TestFunction function);

        template <typename Test>
        void NullSingletonTest(Test* test, typename Test::TestFunction function);

        template <typename Test>
        void SocketSingletonTest(Test* test, typename Test::TestFunction function);

        // Server
        NODISCARD ConfigurationStrategy GetACEServerConfigurationStrategy(int increase = 0) const;
        NODISCARD ConfigurationStrategy GetBoostServerConfigurationStrategy(int increase = 0) const;
        NODISCARD ConfigurationStrategy GetBoostFixedServerConfigurationStrategy(int increase = 0) const;
        NODISCARD ConfigurationStrategy GetThreadsBoostServerConfigurationStrategy(int increase = 0) const;
        NODISCARD ConfigurationStrategy GetMultiContextBoostServerConfigurationStrategy(int increase = 0) const;
        NODISCARD ConfigurationStrategy GetNetworkServerConfigurationStrategy(int increase = 0) const;
        NODISCARD ConfigurationStrategy GetSocketServerConfigurationStrategy(int increase = 0) const;
        NODISCARD ConfigurationStrategy GetNullServerConfigurationStrategy(int increase = 0) const;

        // Client
        NODISCARD ConfigurationStrategy GetBoostClientConfigurationStrategy(int increase = 0) const;
        NODISCARD ConfigurationStrategy GetBoostFixedClientConfigurationStrategy(int increase = 0) const;

    protected:
        NODISCARD int GetPort() const noexcept;
        NODISCARD int GetShiftingPort(int shifting) const noexcept;
        NODISCARD std::string GetHostName() const;
        NODISCARD int GetBufferSize() const noexcept;

    private:
        int port;
        std::string hostName;
        int bufferSize;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SINGLETON_TESTING_H