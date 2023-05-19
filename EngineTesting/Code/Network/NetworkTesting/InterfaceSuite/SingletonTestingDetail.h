///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/15 09:30)

#ifndef NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SINGLETON_TESTING_DETAIL_H
#define NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SINGLETON_TESTING_DETAIL_H

#include "SingletonTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/BaseMainManager.h"

template <typename Test>
void Network::SingletonTesting::ACESingletonTest(Test* test, typename Test::TestFunction function)
{
#ifdef NETWORK_USE_ACE

    BaseMainManager::Create(GetACEServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();

#else  // !NETWORK_USE_ACE

    System::UnusedFunction(test, function);

#endif  // NETWORK_USE_ACE
}

template <typename Test>
void Network::SingletonTesting::BoostSingletonTest(Test* test, typename Test::TestFunction function)
{
    BaseMainManager::Create(GetBoostServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();
}

template <typename Test>
void Network::SingletonTesting::ThreadsBoostSingletonTest(Test* test, typename Test::TestFunction function)
{
    BaseMainManager::Create(GetThreadsBoostServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();
}

template <typename Test>
void Network::SingletonTesting::MultiContextBoostSingletonTest(Test* test, typename Test::TestFunction function)
{
    BaseMainManager::Create(GetMultiContextBoostServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();
}

template <typename Test>
void Network::SingletonTesting::NetworkSingletonTest(Test* test, typename Test::TestFunction function)
{
    BaseMainManager::Create(GetNetworkServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();
}

template <typename Test>
void Network::SingletonTesting::SocketSingletonTest(Test* test, typename Test::TestFunction function)
{
    BaseMainManager::Create(GetSocketServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();
}

template <typename Test>
void Network::SingletonTesting::NullSingletonTest(Test* test, typename Test::TestFunction function)
{
    BaseMainManager::Create(GetNullServerConfigurationStrategy());
    AssertNotThrowException(test, function, (CORE_TOOLS_FUNCTION_DESCRIBED), "");
    BaseMainManager::Destroy();
}

#endif  // NETWORK_TESTING_NETWORK_INTERFACE_SUITE_SINGLETON_TESTING_DETAIL_H