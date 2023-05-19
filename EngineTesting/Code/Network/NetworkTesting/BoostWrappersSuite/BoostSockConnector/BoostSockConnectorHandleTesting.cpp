///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.8 (2023/05/18 14:16)

#include "BoostSockConnectorHandleTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockConnector.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

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
    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    const auto sockStream = std::make_shared<SockStream>(configurationStrategy);
    const auto sockAddress = make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy);

    const TestingType sockConnector{ configurationStrategy };
    TestingType copySockConnector{ sockConnector };

    // �������Ʋ���
    MAYBE_UNUSED const auto result = copySockConnector.Connect(sockStream, sockAddress);
}

void Network::BoostSockConnectorHandleTesting::CopyOperatorTest()
{
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    const auto sockStream = std::make_shared<SockStream>(configurationStrategy);
    const auto sockAddress = make_shared<SockAddress>(configurationStrategy.GetHost(), configurationStrategy.GetPort(), configurationStrategy);

    const TestingType sockConnector{ configurationStrategy };
    TestingType copySockConnector{ GetBoostClientConfigurationStrategy() };

    copySockConnector = sockConnector;

    // �������Ʋ���
    MAYBE_UNUSED const auto result = copySockConnector.Connect(sockStream, sockAddress);
}
