///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/15 10:54)

#include "ServerTesting.h"
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/Server.h"

Network::ServerTesting::ServerTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ServerTesting)

void Network::ServerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ServerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(ACESingletonTest<ClassType>, this, &ClassType::ACETest);
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::BoostTest);
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::NetworkTest);
}

void Network::ServerTesting::ACETest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ACEConstructionTest);
}

void Network::ServerTesting::BoostTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BoostConstructionTest);
}

void Network::ServerTesting::NetworkTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(NetworkConstructionTest);
}

void Network::ServerTesting::ACEConstructionTest()
{
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    Server server{ GetACEServerConfigurationStrategy(), messageEventManager };
}

void Network::ServerTesting::BoostConstructionTest()
{
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    Server server{ GetBoostServerConfigurationStrategy(), messageEventManager };
}

void Network::ServerTesting::NetworkConstructionTest()
{
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    Server server{ GetNetworkServerConfigurationStrategy(), messageEventManager };
}
