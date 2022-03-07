// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ������԰汾��0.0.2.4 (2020/03/11 18:54)

#include "Testing.h"
#include "TestingHelper.h"
#include "ThreadingCoreRenderEngineTesting/Version.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "CoreTools/ObjectSystems/InitTerm.h"
#include "CoreTools/UnitTestSuite/UnitTestSuite.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkMessage/MessageManager.h"
Network::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "����" }
{
    CreateSingleton();

    InitSuite();

    NETWORK_SELF_CLASS_IS_VALID_1;
}

Network::TestingHelper::~TestingHelper() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_1;

    NoexceptNoReturn(*this, &ClassType::DestroySingleton);
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestingHelper)

// private
void Network::TestingHelper::CreateSingleton()
{
    MessageManager::Create();
    MESSAGE_MANAGER_SINGLETON.SetFullVersion(g_TCRETestingVersion);

    CoreTools::InitTerm::ExecuteInitializers();
}

// private
void Network::TestingHelper::DestroySingleton()
{
    CoreTools::InitTerm::ExecuteTerminators();
    MessageManager::Destroy();
}

// private
void Network::TestingHelper::InitSuite()
{
    AddHelperSuite();
    AddConfigurationSuite();
    AddNetworkMessageSuite();
    AddInterfaceSuite();
    AddACEWrappersSuite();
    AddBoostWrappersSuite();
    AddNetworkWrappersSuite();
    AddSocketWrappersSuite();
    AddOpensslSuite();
}

void Network::TestingHelper::AddHelperSuite()
{
    auto helperSuite = GenerateSuite("��");

    ADD_TEST(helperSuite, StreamMacroTesting);
    ADD_TEST(helperSuite, UserMacroTesting);

    AddSuite(helperSuite);
}

void Network::TestingHelper::AddConfigurationSuite()
{
    auto configurationSuite = GenerateSuite("���������");

    ADD_TEST(configurationSuite, ConfigurationStrategyTesting);
    ADD_TEST(configurationSuite, ConfigurationSubStrategyTesting);
    ADD_TEST(configurationSuite, ConfigurationParameterTesting);
    ADD_TEST(configurationSuite, AnalysisNetworkConfigurationTesting);

    AddSuite(configurationSuite);
}

void Network::TestingHelper::AddNetworkMessageSuite()
{
    auto networkMessageSuite = GenerateSuite("������Ϣ");

    ADD_TEST(networkMessageSuite, MessageInterfaceTesting);
    ADD_TEST(networkMessageSuite, DoubleMessageTesting);
    ADD_TEST(networkMessageSuite, NullMessageTesting);
    ADD_TEST(networkMessageSuite, NullDoubleMessageTesting);
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
    ADD_TEST(networkMessageSuite, IntegerDoubleMessageTesting);
    ADD_TEST(networkMessageSuite, StringDoubleMessageTesting);
    ADD_TEST(networkMessageSuite, MultipleDoubleMessageTesting);
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
    ADD_TEST(networkMessageSuite, SocketManagerTesting);

    AddSuite(networkMessageSuite);
}

// private
void Network::TestingHelper::AddInterfaceSuite()
{
    auto interfaceSuite = GenerateSuite("����ӿ�");

    ADD_TEST(interfaceSuite, BaseMainManagerTesting);
    ADD_TEST(interfaceSuite, SockAddressTesting);
    ADD_TEST(interfaceSuite, NetworkUniqueIDManagerTesting);
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
    auto aCEWrappersSuite = GenerateSuite("ACE��װ��");

    ADD_TEST(aCEWrappersSuite, ACEMainManagerTesting);
    ADD_TEST(aCEWrappersSuite, ACESockInetAddressTesting);
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
    auto boostWrappersSuite = GenerateSuite("boost��װ��");

    ADD_TEST(boostWrappersSuite, BoostMainManagerTesting);
    ADD_TEST(boostWrappersSuite, BoostMainManagerUseThreadsTesting);
    ADD_TEST(boostWrappersSuite, BoostMainManagerUseMultiContextTesting);
    ADD_TEST(boostWrappersSuite, BoostSockInetAddressTesting);
    boostWrappersSuite.AddSuite(GetBoostSockAcceptorSuite());
    boostWrappersSuite.AddSuite(GetBoostSockConnectorSuite());
    boostWrappersSuite.AddSuite(GetBoostSockStreamSuite());

    AddSuite(boostWrappersSuite);
}

CoreTools::Suite Network::TestingHelper::GetBoostSockAcceptorSuite()
{
    auto boostSockAcceptorSuite = GenerateSuite("boost�׽��ֽ�����");

    ADD_TEST(boostSockAcceptorSuite, BoostSockAcceptorSynchronizeTesting);
    ADD_TEST(boostSockAcceptorSuite, BoostSockAcceptorNonBlockingTesting);
    ADD_TEST(boostSockAcceptorSuite, BoostSockAcceptorAsynchronousTesting);
    ADD_TEST(boostSockAcceptorSuite, BoostSockAcceptorHandleTesting);

    return boostSockAcceptorSuite;
}

CoreTools::Suite Network::TestingHelper::GetBoostSockConnectorSuite()
{
    auto boostSockConnectorSuite = GenerateSuite("boost�׽���������");

    ADD_TEST(boostSockConnectorSuite, BoostSockConnectorSynchronizeTesting);
    ADD_TEST(boostSockConnectorSuite, BoostSockConnectorAsynchronousTesting);
    ADD_TEST(boostSockConnectorSuite, BoostSockConnectorHandleTesting);

    return boostSockConnectorSuite;
}

CoreTools::Suite Network::TestingHelper::GetBoostSockStreamSuite()
{
    auto boostSockStreamSuite = GenerateSuite("boost�׽�����");

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
    auto networkWrappersSuite = GenerateSuite("Network��װ��");

    ADD_TEST(networkWrappersSuite, NetworkMainManagerTesting);
    ADD_TEST(networkWrappersSuite, NetworkSockInetAddressTesting);
    ADD_TEST(networkWrappersSuite, NetworkSockAcceptorTesting);
    ADD_TEST(networkWrappersSuite, NetworkSockConnectorTesting);
    ADD_TEST(networkWrappersSuite, NetworkSockStreamTesting);

    AddSuite(networkWrappersSuite);
}

void Network::TestingHelper::AddSocketWrappersSuite()
{
    auto socketWrappersSuite = GenerateSuite("socket��װ��");

    AddSuite(socketWrappersSuite);
}

void Network::TestingHelper::AddOpensslSuite()
{
    auto opensslSuite = GenerateSuite("Openssl��װ��");

    AddSuite(opensslSuite);
}
