///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 17:11)

#include "ActiveMQRouteServiceTesting.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/AnalysisNetworkConfiguration.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/MessageOrientedMiddleware/RouteService.h"
#include "Network/MessageOrientedMiddleware/RouteServiceManager.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/NullMessage.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestMessageEvent.h"

Network::ActiveMQRouteServiceTesting::ActiveMQRouteServiceTesting(const OStreamShared& stream)
    : ParentType{ stream }, messageId{ 5 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ActiveMQRouteServiceTesting)

void Network::ActiveMQRouteServiceTesting::DoRunUnitTest()
{
    CreateMessage();
    RouteServiceManager::Create(true);

    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);

    RouteServiceManager::Destroy();
    DestroyMessage();
}

void Network::ActiveMQRouteServiceTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BroadcastMessageTest);
}

void Network::ActiveMQRouteServiceTesting::BroadcastMessageTest()
{
    const AnalysisNetworkConfiguration analysisNetworkConfiguration{ "Configuration/ActiveMQTest.json" };

    RouteService routeService{ analysisNetworkConfiguration.GetConfigurationStrategy(SYSTEM_TEXT("ActiveMQ")) };

    routeService.Insert(messageId, std::make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable));

    const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, messageId);
    routeService.SendServerMessage(routeService.GetAddress(), message);

    routeService.AddConsumer(SocketType::GatewayServer, 2508, routeService.GetAddress());

    routeService.BroadcastMessage(SocketType::GatewayServer, message);
    routeService.BroadcastMessage(message);
}

void Network::ActiveMQRouteServiceTesting::CreateMessage()
{
    MESSAGE_MANAGER_SINGLETON.Insert(messageId, MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::ActiveMQRouteServiceTesting::DestroyMessage()  
{
    MESSAGE_MANAGER_SINGLETON.Remove(messageId);
}
