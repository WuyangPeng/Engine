///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/11 09:26)

#include "Testing.h"
#include "TestingHelper.h"
#include "ThreadingCoreRenderEngineTesting/Version.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkMessage/MessageManager.h"

Network::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "网络" }
{
    CreateSingleton();

    InitSuite();

    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::TestingHelper::~TestingHelper() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    NoexceptNoReturn(*this, &ClassType::ReleaseSingleton);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestingHelper)

void Network::TestingHelper::CreateSingleton()
{
    MessageManager::Create();
    MESSAGE_MANAGER_SINGLETON.SetFullVersion(gTCRETestingVersion);

    CoreTools::InitTerm::ExecuteInitializer();
}

void Network::TestingHelper::ReleaseSingleton()
{
    CoreTools::InitTerm::ExecuteTerminator();
    MessageManager::Destroy();
}

void Network::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddConfigurationSuite();
    AddNetworkMessageSuite();
    AddInterfaceSuite();
    AddACEWrappersSuite();
    AddBoostWrappersSuite();
    AddNetworkWrappersSuite();
    AddOpensslSuite();
    AddMessageOrientedMiddlewareSuite();
    AddActiveMQSuite();
    AddNatsSuite();
    AddKafkaSuite();
}

void Network::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("宏");

    ADD_TEST(helperSuite, StreamMacroTesting);
    ADD_TEST(helperSuite, UserMacroTesting);

    AddSuite(helperSuite);
}

void Network::TestingHelper::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("网络库配置");

    ADD_TEST(configurationSuite, ConfigurationStrategyTesting);
    ADD_TEST(configurationSuite, ConfigurationSubStrategyTesting);
    ADD_TEST(configurationSuite, ConfigurationParameterTesting);
    ADD_TEST(configurationSuite, AnalysisNetworkConfigurationTesting);

    AddSuite(configurationSuite);
}

void Network::TestingHelper::AddNetworkMessageSuite()
{
    auto networkMessageSuite = GenerateSuite("网络消息");

    ADD_TEST(networkMessageSuite, MessageInterfaceTesting);
    ADD_TEST(networkMessageSuite, NullMessageTesting);
    ADD_TEST(networkMessageSuite, NullDoubleMessageTesting);
    ADD_TEST(networkMessageSuite, ProtoBufMessageTesting);
    ADD_TEST(networkMessageSuite, JsonMessageTesting);
    ADD_TEST(networkMessageSuite, MessageContainerTesting);
    ADD_TEST(networkMessageSuite, IntegerMessageTesting);
    ADD_TEST(networkMessageSuite, StringMessageTesting);
    ADD_TEST(networkMessageSuite, MultipleMessageCastTesting);
    ADD_TEST(networkMessageSuite, MultipleMessageElementTesting);
    ADD_TEST(networkMessageSuite, MultipleMessageSizeTesting);
    ADD_TEST(networkMessageSuite, MultipleMessageInitValueTesting);
    ADD_TEST(networkMessageSuite, MultipleMessageStreamingSizeTesting);
    ADD_TEST(networkMessageSuite, MultipleMessageStreamingSaveTesting);
    ADD_TEST(networkMessageSuite, MultipleMessageStreamingLoadTesting);
    ADD_TEST(networkMessageSuite, MultipleMessageContainerTesting);
    ADD_TEST(networkMessageSuite, MultipleMessageTesting);
    ADD_TEST(networkMessageSuite, MessageContainerGroupTesting);
    ADD_TEST(networkMessageSuite, MultipleMessageContainerGroupTesting);
    ADD_TEST(networkMessageSuite, MessageInterfaceSharedPtrLessTesting);
    ADD_TEST(networkMessageSuite, NetworkMessageEventTesting);
    ADD_TEST(networkMessageSuite, MessageTypeConditionTesting);
    ADD_TEST(networkMessageSuite, MessageTypeConditionOperatingTesting);
    ADD_TEST(networkMessageSuite, MessageManagerTesting);
    ADD_TEST(networkMessageSuite, MessageEventContainerTesting);
    ADD_TEST(networkMessageSuite, MessageEventManagerTesting);
    ADD_TEST(networkMessageSuite, SendMessageLevelTesting);
    ADD_TEST(networkMessageSuite, ReceiveMessageLevelTesting);
    ADD_TEST(networkMessageSuite, MessageBufferTesting);
    ADD_TEST(networkMessageSuite, MessageSourceTesting);
    ADD_TEST(networkMessageSuite, MessageTargetTesting);
    ADD_TEST(networkMessageSuite, BufferReceiveStreamTesting);
    ADD_TEST(networkMessageSuite, BufferSendStreamTesting);

    AddSuite(networkMessageSuite);
}

void Network::TestingHelper::AddInterfaceSuite()
{
    auto interfaceSuite = GenerateSuite("网络接口");

    ADD_TEST(interfaceSuite, BaseMainManagerTesting);
    ADD_TEST(interfaceSuite, SockAddressTesting);
    ADD_TEST(interfaceSuite, SockAcceptorTesting);
    ADD_TEST(interfaceSuite, SockConnectorTesting);
    ADD_TEST(interfaceSuite, SockStreamTesting);
    ADD_TEST(interfaceSuite, HandleSetTesting);
    ADD_TEST(interfaceSuite, HandleSetIteratorTesting);
    ADD_TEST(interfaceSuite, ClientTesting);
    ADD_TEST(interfaceSuite, CacheClientTesting);
    ADD_TEST(interfaceSuite, OnlySendingClientTesting);
    ADD_TEST(interfaceSuite, ServerTesting);
    ADD_TEST(interfaceSuite, IterativeServerTesting);
    ADD_TEST(interfaceSuite, ReactiveServerTesting);

    AddSuite(interfaceSuite);
}

void Network::TestingHelper::AddACEWrappersSuite()
{
    auto aCEWrappersSuite = GenerateSuite("ACE包装器");

    ADD_TEST(aCEWrappersSuite, ACEMainManagerTesting);
    ADD_TEST(aCEWrappersSuite, ACESockInternetAddressTesting);
    ADD_TEST(aCEWrappersSuite, ACESockAcceptorTesting);
    ADD_TEST(aCEWrappersSuite, ACESockConnectorTesting);
    ADD_TEST(aCEWrappersSuite, ACESockStreamTesting);
    ADD_TEST(aCEWrappersSuite, ACEIovecSockStreamTesting);
    ADD_TEST(aCEWrappersSuite, SockACEHandleSetTesting);
    ADD_TEST(aCEWrappersSuite, SockACEHandleSetIteratorTesting);

    AddSuite(aCEWrappersSuite);
}

void Network::TestingHelper::AddBoostWrappersSuite()
{
    auto boostWrappersSuite = GenerateSuite("boost包装器");

    ADD_TEST(boostWrappersSuite, BoostMainManagerTesting);
    ADD_TEST(boostWrappersSuite, BoostMainManagerUseThreadsTesting);
    ADD_TEST(boostWrappersSuite, BoostMainManagerUseMultiContextTesting);
    ADD_TEST(boostWrappersSuite, BoostSockInternetAddressTesting);
    boostWrappersSuite.AddSuite(GetBoostSockAcceptorSuite());
    boostWrappersSuite.AddSuite(GetBoostSockConnectorSuite());
    boostWrappersSuite.AddSuite(GetBoostSockStreamSuite());

    AddSuite(boostWrappersSuite);
}

CoreTools::Suite Network::TestingHelper::GetBoostSockAcceptorSuite()
{
    auto boostSockAcceptorSuite = GenerateSuite("boost套接字接受器");

    ADD_TEST(boostSockAcceptorSuite, BoostSockAcceptorSynchronizeTesting);
    ADD_TEST(boostSockAcceptorSuite, BoostSockAcceptorNonBlockingTesting);
    ADD_TEST(boostSockAcceptorSuite, BoostSockAcceptorAsynchronousTesting);
    ADD_TEST(boostSockAcceptorSuite, BoostSockAcceptorHandleTesting);

    return boostSockAcceptorSuite;
}

CoreTools::Suite Network::TestingHelper::GetBoostSockConnectorSuite()
{
    auto boostSockConnectorSuite = GenerateSuite("boost套接字连接器");

    ADD_TEST(boostSockConnectorSuite, BoostSockConnectorSynchronizeTesting);
    ADD_TEST(boostSockConnectorSuite, BoostSockConnectorAsynchronousTesting);
    ADD_TEST(boostSockConnectorSuite, BoostSockConnectorHandleTesting);

    return boostSockConnectorSuite;
}

CoreTools::Suite Network::TestingHelper::GetBoostSockStreamSuite()
{
    auto boostSockStreamSuite = GenerateSuite("boost套接字流");

    ADD_TEST(boostSockStreamSuite, BoostFixedSockStreamSynchronizeTesting);
    ADD_TEST(boostSockStreamSuite, BoostFixedSockStreamNonBlockingTesting);
    ADD_TEST(boostSockStreamSuite, BoostFixedSockStreamAsynchronousTesting);
    ADD_TEST(boostSockStreamSuite, BoostSegmentationSockStreamSynchronizeTesting);
    ADD_TEST(boostSockStreamSuite, BoostSegmentationSockStreamNonBlockingTesting);
    ADD_TEST(boostSockStreamSuite, BoostSegmentationSockStreamAsynchronousTesting);
    ADD_TEST(boostSockStreamSuite, BoostSockStreamHandleTesting);

    return boostSockStreamSuite;
}

void Network::TestingHelper::AddNetworkWrappersSuite()
{
    auto networkWrappersSuite = GenerateSuite("Network包装器");

    ADD_TEST(networkWrappersSuite, NetworkMainManagerTesting);
    ADD_TEST(networkWrappersSuite, NetworkSockInternetAddressTesting);
    ADD_TEST(networkWrappersSuite, NetworkSockAcceptorTesting);
    ADD_TEST(networkWrappersSuite, NetworkSockConnectorTesting);
    ADD_TEST(networkWrappersSuite, NetworkSockStreamTesting);

    AddSuite(networkWrappersSuite);
}

void Network::TestingHelper::AddOpensslSuite()
{
    auto opensslSuite = GenerateSuite("Openssl包装器");

    AddSuite(opensslSuite);
}

void Network::TestingHelper::AddMessageOrientedMiddlewareSuite()
{
    auto messageOrientedMiddlewareSuite = GenerateSuite("消息中间件");

    ADD_TEST(messageOrientedMiddlewareSuite, ConsumerTesting);
    ADD_TEST(messageOrientedMiddlewareSuite, ProducerTesting);
    ADD_TEST(messageOrientedMiddlewareSuite, RouteServiceManagerTesting);
    ADD_TEST(messageOrientedMiddlewareSuite, RouteServiceTesting);

    AddSuite(messageOrientedMiddlewareSuite);
}

void Network::TestingHelper::AddActiveMQSuite()
{
    auto activeMQSuite = GenerateSuite("Active MQ");

    ADD_TEST(activeMQSuite, ActiveMQConsumerTesting);
    ADD_TEST(activeMQSuite, ActiveMQProducerTesting);
    ADD_TEST(activeMQSuite, ActiveMQRouteServiceManagerTesting);
    ADD_TEST(activeMQSuite, ActiveMQRouteServiceTesting);

    AddSuite(activeMQSuite);
}

void Network::TestingHelper::AddNatsSuite()
{
    auto natsSuite = GenerateSuite("Nats");

    AddSuite(natsSuite);
}

void Network::TestingHelper::AddKafkaSuite()
{
    auto kafkaSuite = GenerateSuite("Kafka");

    AddSuite(kafkaSuite);
}
