///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 11:24)

#include "BoostSockConnectorHandleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
using std::make_shared;

Network::BoostSockConnectorHandleTesting::BoostSockConnectorHandleTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockConnectorHandleTesting)

void Network::BoostSockConnectorHandleTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::BoostSockConnectorHandleTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(BoostSingletonTest<ClassType>, this, &ClassType::ConnectorTest);
}

void Network::BoostSockConnectorHandleTesting::ConnectorTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(CopyConstructorTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CopyOperatorTest);
}

void Network::BoostSockConnectorHandleTesting::CopyConstructorTest()
{
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy) };

    TestingType sockConnector{ configurationStrategy };
    TestingType copySockConnector{ sockConnector };

    // 触发复制操作
    MAYBE_UNUSED const auto value = copySockConnector.Connect(sockStream, sockAddress);
}

void Network::BoostSockConnectorHandleTesting::CopyOperatorTest()
{
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    SockStreamSharedPtr sockStream{ make_shared<SockStream>(configurationStrategy) };
    SockAddressSharedPtr sockAddress{ make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy) };

    TestingType sockConnector{ configurationStrategy };
    TestingType copySockConnector{ GetBoostClientConfigurationStrategy() };

    copySockConnector = sockConnector;

    // 触发复制操作
    MAYBE_UNUSED const auto value = copySockConnector.Connect(sockStream, sockAddress);
}
