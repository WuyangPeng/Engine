///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.8 (2022/05/25 11:24)

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

    // �������Ʋ���
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

    // �������Ʋ���
    MAYBE_UNUSED const auto value = copySockConnector.Connect(sockStream, sockAddress);
}
