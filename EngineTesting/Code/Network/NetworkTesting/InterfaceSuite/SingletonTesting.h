// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 13:11)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SINGLETON_TESTING_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SINGLETON_TESTING_H

#include "System/Helper/Platform.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"

namespace Network
{
    class SingletonTesting : public CoreTools::UnitTest
    {
    public:
        UNIT_TEST_SUBCLASS_COMPLETE_DECLARE(SingletonTesting);

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
        const ConfigurationStrategy GetACEServerConfigurationStrategy(int increase = 0) const;
        const ConfigurationStrategy GetBoostServerConfigurationStrategy(int increase = 0) const;
        const ConfigurationStrategy GetBoostFixedServerConfigurationStrategy(int increase = 0) const;
        const ConfigurationStrategy GetThreadsBoostServerConfigurationStrategy(int increase = 0) const;
        const ConfigurationStrategy GetMultiContextBoostServerConfigurationStrategy(int increase = 0) const;
        const ConfigurationStrategy GetNetworkServerConfigurationStrategy(int increase = 0) const;
        const ConfigurationStrategy GetSocketServerConfigurationStrategy(int increase = 0) const;
        const ConfigurationStrategy GetNullServerConfigurationStrategy(int increase = 0) const;

        // Client
        const ConfigurationStrategy GetBoostClientConfigurationStrategy(int increase = 0) const;
        const ConfigurationStrategy GetBoostFixedClientConfigurationStrategy(int increase = 0) const;

    protected:
        int GetPort() const noexcept;
        const std::string GetHostName() const;

    private:
        int m_Port;
        std::string m_HostName;
    };
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SINGLETON_TESTING_H