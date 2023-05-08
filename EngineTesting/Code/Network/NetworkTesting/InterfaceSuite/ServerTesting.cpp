///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 14:56)

#include "ServerTesting.h"
#include "SingletonTestingDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/Server.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::make_shared;

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

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)

void Network::ServerTesting::ACEConstructionTest()
{
    ServerSharedPtr server{ make_shared<Server>(nullptr, GetACEServerConfigurationStrategy()) };
}

void Network::ServerTesting::BoostConstructionTest()
{
    ServerSharedPtr server{ make_shared<Server>(nullptr, GetBoostServerConfigurationStrategy()) };
}

void Network::ServerTesting::NetworkConstructionTest()
{
    ServerSharedPtr server{ make_shared<Server>(nullptr, GetNetworkServerConfigurationStrategy()) };
}

#include STSTEM_WARNING_POP
