///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:54)

#include "RouteServiceTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/MessageOrientedMiddleware/RouteService.h"
#include "Network/NetworkMessage/NullMessage.h"

Network::RouteServiceTesting::RouteServiceTesting(const OStreamShared& stream)
    : ParentType{ stream }, bufferSize{ 1048576 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, RouteServiceTesting)

void Network::RouteServiceTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::RouteServiceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConsumerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BroadcastMessageTest);
}

void Network::RouteServiceTesting::ConsumerTest()
{
    auto subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    auto configurationParameter = ConfigurationParameter::Create();
    configurationParameter.AddParameter(SYSTEM_TEXT("SocketType"), SYSTEM_TEXT("Gateway"));
    configurationParameter.AddParameter(SYSTEM_TEXT("ServerId"), SYSTEM_TEXT("1000"));
    configurationParameter.AddParameter(SYSTEM_TEXT("IntranetIp"), SYSTEM_TEXT("127.0.0.1"));
    configurationParameter.AddParameter(SYSTEM_TEXT("IntranetPort"), SYSTEM_TEXT("2580"));

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                       ConnectStrategy::Tcp,
                                                       ServerStrategy::Reactive,
                                                       MessageStrategy::Default,
                                                       ParserStrategy::LittleEndian,
                                                       OpenSslStrategy::Default,
                                                       EncryptedCompressionStrategy::Default,
                                                       subStrategy,
                                                       configurationParameter,
                                                       SocketSendMessage::Default,
                                                       "127.0.0.1",
                                                       1580 };

    RouteService routeService{ configurationStrategy };

    ASSERT_EQUAL(routeService.GetAddress(), SYSTEM_TEXT("Gateway_1000_127.0.0.1_2580"));

    ASSERT_THROW_EXCEPTION_1(ConsumerExceptionTest, routeService);

    routeService.AddConsumer(SocketType::GatewayServer, 2508, SYSTEM_TEXT("Gate"));

    ASSERT_EQUAL(routeService.GetFirstConsumer(SocketType::GatewayServer), SYSTEM_TEXT("Gate"));

    routeService.RemoveConsumer(SocketType::GatewayServer, 2508);

    ASSERT_THROW_EXCEPTION_1(ConsumerExceptionTest, routeService);
}

void Network::RouteServiceTesting::ConsumerExceptionTest(const RouteService& routeService)
{
    MAYBE_UNUSED const auto result = routeService.GetFirstConsumer(SocketType::GatewayServer);
}

void Network::RouteServiceTesting::BroadcastMessageTest()
{
    auto subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    auto configurationParameter = ConfigurationParameter::Create();
    configurationParameter.AddParameter(SYSTEM_TEXT("SocketType"), SYSTEM_TEXT("Gateway"));
    configurationParameter.AddParameter(SYSTEM_TEXT("ServerId"), SYSTEM_TEXT("1000"));
    configurationParameter.AddParameter(SYSTEM_TEXT("IntranetIp"), SYSTEM_TEXT("127.0.0.1"));
    configurationParameter.AddParameter(SYSTEM_TEXT("IntranetPort"), SYSTEM_TEXT("2580"));

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                       ConnectStrategy::Tcp,
                                                       ServerStrategy::Reactive,
                                                       MessageStrategy::Default,
                                                       ParserStrategy::LittleEndian,
                                                       OpenSslStrategy::Default,
                                                       EncryptedCompressionStrategy::Default,
                                                       subStrategy,
                                                       configurationParameter,
                                                       SocketSendMessage::Default,
                                                       "127.0.0.1",
                                                       1580 };

    RouteService routeService{ configurationStrategy };

    const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, 5);
    routeService.SendServerMessage(SYSTEM_TEXT("Gateway"), message);

    routeService.BroadcastMessage(SocketType::GatewayServer, message);
    routeService.BroadcastMessage(message);
}
