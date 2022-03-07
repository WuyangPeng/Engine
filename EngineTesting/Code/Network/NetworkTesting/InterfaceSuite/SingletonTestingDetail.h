// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/13 10:53)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SINGLETON_TESTING_DETAIL_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SINGLETON_TESTING_DETAIL_H

#include "SingletonTesting.h"

#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"

template <typename Test>
void Network::SingletonTesting ::ACESingletonTest(Test* test, typename Test::TestFunction function)
{
#ifdef NETWORK_USE_ACE

    BaseMainManager::Create(GetACEServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();

#else  // !NETWORK_USE_ACE
    SYSTEM_UNUSED_ARG(test);
    SYSTEM_UNUSED_ARG(function);
#endif  // NETWORK_USE_ACE
}

template <typename Test>
void Network::SingletonTesting ::BoostSingletonTest(Test* test, typename Test::TestFunction function)
{
    BaseMainManager::Create(GetBoostServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();
}

template <typename Test>
void Network::SingletonTesting ::ThreadsBoostSingletonTest(Test* test, typename Test::TestFunction function)
{
    BaseMainManager::Create(GetThreadsBoostServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();
}

template <typename Test>
void Network::SingletonTesting ::MultiContextBoostSingletonTest(Test* test, typename Test::TestFunction function)
{
    BaseMainManager::Create(GetMultiContextBoostServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();
}

template <typename Test>
void Network::SingletonTesting ::NetworkSingletonTest(Test* test, typename Test::TestFunction function)
{
    BaseMainManager::Create(GetNetworkServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();
}

template <typename Test>
void Network::SingletonTesting ::SocketSingletonTest(Test* test, typename Test::TestFunction function)
{
    BaseMainManager::Create(GetSocketServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();
}

template <typename Test>
void Network::SingletonTesting ::NullSingletonTest(Test* test, typename Test::TestFunction function)
{
    BaseMainManager::Create(GetNullServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SINGLETON_TESTING_DETAIL_H