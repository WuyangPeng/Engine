// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.0.0.1 (2019/08/30 22:56)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

BookNetworkProgramming::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "�鼮 ����ϵͳ ������" }
{
    InitSuite();
}

void BookNetworkProgramming::TestingHelper ::InitSuite()
{
    AddNetworkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite();
    AddMultiplayerGameProgrammingSuite();
    AddNetworkProgrammingForMicrosoftWindowsSuite();
    AddEffectiveTCPIPProgrammingSuite();

    AddInternetworkingWithTCPIPSuite();
    AddUNIXNetworkProgrammingSuite();
    AddConfiguringWindowsServer2008NetworkInfrastructureSuite();
    AddAdvancedCORBAProgrammingWithCppSuite();
}

void BookNetworkProgramming::TestingHelper ::AddNetworkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite()
{
    auto networkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite = GenerateSuite("�������⻷��ͼ�μܹ����");

    AddSuite(networkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite);
}

void BookNetworkProgramming::TestingHelper ::AddMultiplayerGameProgrammingSuite()
{
    auto multiplayerGameProgrammingSuite = GenerateSuite("���������Ϸ�ܹ�����");

    AddSuite(multiplayerGameProgrammingSuite);
}

void BookNetworkProgramming::TestingHelper ::AddNetworkProgrammingForMicrosoftWindowsSuite()
{
    auto networkProgrammingForMicrosoftWindowsSuite = GenerateSuite("Windows ������");

    AddSuite(networkProgrammingForMicrosoftWindowsSuite);
}

void BookNetworkProgramming::TestingHelper ::AddEffectiveTCPIPProgrammingSuite()
{
    auto effectiveTCPIPProgrammingSuite = GenerateSuite("TCP IP ��Ч���");

    AddSuite(effectiveTCPIPProgrammingSuite);
}

void BookNetworkProgramming::TestingHelper ::AddInternetworkingWithTCPIPSuite()
{
    auto internetworkingWithTCPIPSuite = GenerateSuite("��TCP-IP�������ʻ���");

    AddInternetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite(internetworkingWithTCPIPSuite);
    AddInternetworkingWithTCPIPDesignImplementationAndInternalsSuite(internetworkingWithTCPIPSuite);
    AddInternetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite(internetworkingWithTCPIPSuite);

    AddSuite(internetworkingWithTCPIPSuite);
}

void BookNetworkProgramming::TestingHelper ::AddInternetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite(Suite& internetworkingWithTCPIPSuite)
{
    auto internetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite = GenerateSuite("��TCP-IP�������ʻ��� ��һ�� ԭ��Э����ṹ");

    internetworkingWithTCPIPSuite.AddSuite(internetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite);
}

void BookNetworkProgramming::TestingHelper ::AddInternetworkingWithTCPIPDesignImplementationAndInternalsSuite(Suite& internetworkingWithTCPIPSuite)
{
    auto internetworkingWithTCPIPDesignImplementationAndInternalsSuite = GenerateSuite("��TCP-IP�������ʻ��� �ڶ��� ��ơ�ʵ�����ں�");

    internetworkingWithTCPIPSuite.AddSuite(internetworkingWithTCPIPDesignImplementationAndInternalsSuite);
}

void BookNetworkProgramming::TestingHelper ::AddInternetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite(Suite& internetworkingWithTCPIPSuite)
{
    auto internetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite = GenerateSuite("��TCP-IP�������ʻ��� ������ �ͻ��������������Ӧ��");

    internetworkingWithTCPIPSuite.AddSuite(internetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite);
}

void BookNetworkProgramming::TestingHelper ::AddUNIXNetworkProgrammingSuite()
{
    auto unixNetworkProgrammingSuite = GenerateSuite("UNIX ������");

    AddUNIXNetworkProgrammingTheSocketsNetworkingAPISuite(unixNetworkProgrammingSuite);
    AddUNIXNetworkProgrammingInterprocessCommunicationSuite(unixNetworkProgrammingSuite);

    AddSuite(unixNetworkProgrammingSuite);
}

void BookNetworkProgramming::TestingHelper ::AddUNIXNetworkProgrammingTheSocketsNetworkingAPISuite(Suite& unixNetworkProgrammingSuite)
{
    auto unixNetworkProgrammingTheSocketsNetworkingAPISuite = GenerateSuite("UNIX ������ ��һ�� �׽�������API");

    unixNetworkProgrammingSuite.AddSuite(unixNetworkProgrammingTheSocketsNetworkingAPISuite);
}

void BookNetworkProgramming::TestingHelper ::AddUNIXNetworkProgrammingInterprocessCommunicationSuite(Suite& unixNetworkProgrammingSuite)
{
    auto unixNetworkProgrammingInterprocessCommunicationSuite = GenerateSuite("UNIX ������ �ڶ��� ���̼�ͨ��");

    unixNetworkProgrammingSuite.AddSuite(unixNetworkProgrammingInterprocessCommunicationSuite);
}

void BookNetworkProgramming::TestingHelper ::AddConfiguringWindowsServer2008NetworkInfrastructureSuite()
{
    auto configuringWindowsServer2008NetworkInfrastructureSuite = GenerateSuite("Windows Server 2008 ��������ܹ�");

    AddSuite(configuringWindowsServer2008NetworkInfrastructureSuite);
}

void BookNetworkProgramming::TestingHelper ::AddAdvancedCORBAProgrammingWithCppSuite()
{
    auto advancedCORBAProgrammingWithCppSuite = GenerateSuite("����C++ CORBA�߼����");

    AddSuite(advancedCORBAProgrammingWithCppSuite);
}

