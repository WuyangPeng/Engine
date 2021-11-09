///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨�����԰汾��0.7.2.3 (2021/09/23 21:47)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookNetworkProgramming/Helper/BookNetworkProgrammingClassInvariantMacro.h"

BookNetworkProgramming::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "���鼮������ϵͳ�������̡���Ԫ�����׼��鼮" }
{
    InitSuite();

    BOOK_NETWORK_PROGRAMMING_SELF_CLASS_IS_VALID_1;
}

void BookNetworkProgramming::TestingHelper::InitSuite()
{
    AddNetworkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite();
    AddMultiplayerGameProgrammingSuite();
    AddNetworkProgrammingForMicrosoftWindowsSuite();
    AddEffectiveTCPIPProgrammingSuite();
    AddComputerNetworksSuite();

    AddInternetworkingWithTCPIPSuite();
    AddUNIXNetworkProgrammingSuite();
    AddConfiguringWindowsServer2008NetworkInfrastructureSuite();
    AddAdvancedCORBAProgrammingWithCppSuite();

    AddComputerNetworksASystemApproachSuite();
    AddComputerNetworksATopDownApproachSuite();
    AddTCPIPProtocolSuite();
    AddCryptographyAndNetworkSecuritySuite();
}

void BookNetworkProgramming::TestingHelper::AddNetworkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite()
{
    auto networkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite = GenerateSuite("�������⻷��ͼ�μܹ����");

    ADD_TEST(networkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite, NetworkedGraphicsBuildingNetworkedGamesAndVirtualEnvironments::NetworkedGraphicsBuildingPlaceholderTesting);

    AddSuite(networkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite);
}

void BookNetworkProgramming::TestingHelper::AddMultiplayerGameProgrammingSuite()
{
    auto multiplayerGameProgrammingSuite = GenerateSuite("���������Ϸ�ܹ�����");

    ADD_TEST(multiplayerGameProgrammingSuite, MultiplayerGameProgramming::MultiplayerGameProgrammingPlaceholderTesting);

    AddSuite(multiplayerGameProgrammingSuite);
}

void BookNetworkProgramming::TestingHelper::AddNetworkProgrammingForMicrosoftWindowsSuite()
{
    auto networkProgrammingForMicrosoftWindowsSuite = GenerateSuite("Windows ������");

    ADD_TEST(networkProgrammingForMicrosoftWindowsSuite, NetworkProgrammingForMicrosoftWindows::MicrosoftWindowsPlaceholderTesting);

    AddSuite(networkProgrammingForMicrosoftWindowsSuite);
}

void BookNetworkProgramming::TestingHelper::AddEffectiveTCPIPProgrammingSuite()
{
    auto effectiveTCPIPProgrammingSuite = GenerateSuite("TCP IP ��Ч���");

    ADD_TEST(effectiveTCPIPProgrammingSuite, EffectiveTCPIPProgramming::EffectiveTCPIPProgrammingPlaceholderTesting);

    AddSuite(effectiveTCPIPProgrammingSuite);
}

void BookNetworkProgramming::TestingHelper::AddComputerNetworksSuite()
{
    auto computerNetworksSuite = GenerateSuite("���������");

    ADD_TEST(computerNetworksSuite, ComputerNetworks::ComputerNetworksPlaceholderTesting);

    AddSuite(computerNetworksSuite);
}

void BookNetworkProgramming::TestingHelper::AddInternetworkingWithTCPIPSuite()
{
    auto internetworkingWithTCPIPSuite = GenerateSuite("��TCP-IP�������ʻ���");

    internetworkingWithTCPIPSuite.AddSuite(GetPrinciplesProtocolsAndArchitecturesSuite());
    internetworkingWithTCPIPSuite.AddSuite(GetDesignImplementationAndInternalsSuite());
    internetworkingWithTCPIPSuite.AddSuite(GetClientServerProgrammingAndApplicationsSuite());

    AddSuite(internetworkingWithTCPIPSuite);
}

CoreTools::Suite BookNetworkProgramming::TestingHelper::GetPrinciplesProtocolsAndArchitecturesSuite()
{
    auto internetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite = GenerateSuite("��TCP-IP�������ʻ��� ��һ�� ԭ��Э����ṹ");

    ADD_TEST(internetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite, PrinciplesProtocolsAndArchitectures::PrinciplesProtocolsPlaceholderTesting);

    return internetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite;
}

CoreTools::Suite BookNetworkProgramming::TestingHelper::GetDesignImplementationAndInternalsSuite()
{
    auto internetworkingWithTCPIPDesignImplementationAndInternalsSuite = GenerateSuite("��TCP-IP�������ʻ��� �ڶ��� ��ơ�ʵ�����ں�");

    ADD_TEST(internetworkingWithTCPIPDesignImplementationAndInternalsSuite, DesignImplementationAndInternals::DesignImplementationPlaceholderTesting);

    return internetworkingWithTCPIPDesignImplementationAndInternalsSuite;
}

CoreTools::Suite BookNetworkProgramming::TestingHelper::GetClientServerProgrammingAndApplicationsSuite()
{
    auto internetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite = GenerateSuite("��TCP-IP�������ʻ��� ������ �ͻ��������������Ӧ��");

    ADD_TEST(internetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite, ClientServerProgrammingAndApplications::ClientServerProgrammingPlaceholderTesting);

    return internetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite;
}

void BookNetworkProgramming::TestingHelper::AddUNIXNetworkProgrammingSuite()
{
    auto unixNetworkProgrammingSuite = GenerateSuite("UNIX ������");

    unixNetworkProgrammingSuite.AddSuite(GetUNIXNetworkProgrammingTheSocketsNetworkingAPISuite());
    unixNetworkProgrammingSuite.AddSuite(GetUNIXNetworkProgrammingInterprocessCommunicationSuite());

    AddSuite(unixNetworkProgrammingSuite);
}

CoreTools::Suite BookNetworkProgramming::TestingHelper::GetUNIXNetworkProgrammingTheSocketsNetworkingAPISuite()
{
    auto unixNetworkProgrammingTheSocketsNetworkingAPISuite = GenerateSuite("UNIX ������ ��һ�� �׽�������API");

    ADD_TEST(unixNetworkProgrammingTheSocketsNetworkingAPISuite, UnixNetworkProgramming::TheSocketsNetworkingAPIPlaceholderTesting);

    return unixNetworkProgrammingTheSocketsNetworkingAPISuite;
}

CoreTools::Suite BookNetworkProgramming::TestingHelper::GetUNIXNetworkProgrammingInterprocessCommunicationSuite()
{
    auto unixNetworkProgrammingInterprocessCommunicationSuite = GenerateSuite("UNIX ������ �ڶ��� ���̼�ͨ��");

    ADD_TEST(unixNetworkProgrammingInterprocessCommunicationSuite, UnixNetworkProgramming::InterprocessCommunicationsPlaceholderTesting);

    return unixNetworkProgrammingInterprocessCommunicationSuite;
}

void BookNetworkProgramming::TestingHelper::AddConfiguringWindowsServer2008NetworkInfrastructureSuite()
{
    auto configuringWindowsServer2008NetworkInfrastructureSuite = GenerateSuite("Windows Server 2008 ��������ܹ�");

    ADD_TEST(configuringWindowsServer2008NetworkInfrastructureSuite, ConfiguringWindowsServer2008NetworkInfrastructure::ConfiguringWindowsServerPlaceholderTesting);

    AddSuite(configuringWindowsServer2008NetworkInfrastructureSuite);
}

void BookNetworkProgramming::TestingHelper::AddAdvancedCORBAProgrammingWithCppSuite()
{
    auto advancedCORBAProgrammingWithCppSuite = GenerateSuite("����C++ CORBA�߼����");

    ADD_TEST(advancedCORBAProgrammingWithCppSuite, AdvancedCORBAProgrammingWithCpp::AdvancedCORBAProgrammingWithCppPlaceholderTesting);

    AddSuite(advancedCORBAProgrammingWithCppSuite);
}

void BookNetworkProgramming::TestingHelper::AddComputerNetworksASystemApproachSuite()
{
    auto computerNetworksASystemApproachSuite = GenerateSuite("��������磺ϵͳ����");

    ADD_TEST(computerNetworksASystemApproachSuite, ComputerNetworksASystemApproach::ComputerNetworksASystemApproachPlaceholderTesting);

    AddSuite(computerNetworksASystemApproachSuite);
}

void BookNetworkProgramming::TestingHelper::AddComputerNetworksATopDownApproachSuite()
{
    auto computerNetworksATopDownApproachSuite = GenerateSuite("��������磺�Զ����·���");

    ADD_TEST(computerNetworksATopDownApproachSuite, ComputerNetworksATopDownApproach::ComputerNetworksATopDownApproachPlaceholderTesting);

    AddSuite(computerNetworksATopDownApproachSuite);
}

void BookNetworkProgramming::TestingHelper::AddTCPIPProtocolSuite()
{
    auto tcpIPProtocolSuite = GenerateSuite("TCP/IPЭ����");

    ADD_TEST(tcpIPProtocolSuite, TCPIPProtocol::TCPIPProtocolPlaceholderTesting);

    AddSuite(tcpIPProtocolSuite);
}

void BookNetworkProgramming::TestingHelper::AddCryptographyAndNetworkSecuritySuite()
{
    auto cryptographyAndNetworkSecuritySuite = GenerateSuite("�������ѧ�����簲ȫ����ԭ����ʵ��");

    ADD_TEST(cryptographyAndNetworkSecuritySuite, CryptographyAndNetworkSecurity::CryptographyAndNetworkSecurityPlaceholderTesting);

    AddSuite(cryptographyAndNetworkSecuritySuite);
}
