///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.2.3 (2021/09/23 21:47)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelperDetail.h"
#include "Example/BookOperatingSystem/BookNetworkProgramming/Helper/BookNetworkProgrammingClassInvariantMacro.h"

BookNetworkProgramming::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "【书籍·操作系统·网络编程】单元测试套件书籍" }
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
    auto networkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite = GenerateSuite("网络虚拟环境图形架构设计");

    ADD_TEST(networkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite, NetworkedGraphicsBuildingNetworkedGamesAndVirtualEnvironments::NetworkedGraphicsBuildingPlaceholderTesting);

    AddSuite(networkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite);
}

void BookNetworkProgramming::TestingHelper::AddMultiplayerGameProgrammingSuite()
{
    auto multiplayerGameProgrammingSuite = GenerateSuite("网络多人游戏架构与编程");

    ADD_TEST(multiplayerGameProgrammingSuite, MultiplayerGameProgramming::MultiplayerGameProgrammingPlaceholderTesting);

    AddSuite(multiplayerGameProgrammingSuite);
}

void BookNetworkProgramming::TestingHelper::AddNetworkProgrammingForMicrosoftWindowsSuite()
{
    auto networkProgrammingForMicrosoftWindowsSuite = GenerateSuite("Windows 网络编程");

    ADD_TEST(networkProgrammingForMicrosoftWindowsSuite, NetworkProgrammingForMicrosoftWindows::MicrosoftWindowsPlaceholderTesting);

    AddSuite(networkProgrammingForMicrosoftWindowsSuite);
}

void BookNetworkProgramming::TestingHelper::AddEffectiveTCPIPProgrammingSuite()
{
    auto effectiveTCPIPProgrammingSuite = GenerateSuite("TCP IP 高效编程");

    ADD_TEST(effectiveTCPIPProgrammingSuite, EffectiveTCPIPProgramming::EffectiveTCPIPProgrammingPlaceholderTesting);

    AddSuite(effectiveTCPIPProgrammingSuite);
}

void BookNetworkProgramming::TestingHelper::AddComputerNetworksSuite()
{
    auto computerNetworksSuite = GenerateSuite("计算机网络");

    ADD_TEST(computerNetworksSuite, ComputerNetworks::ComputerNetworksPlaceholderTesting);

    AddSuite(computerNetworksSuite);
}

void BookNetworkProgramming::TestingHelper::AddInternetworkingWithTCPIPSuite()
{
    auto internetworkingWithTCPIPSuite = GenerateSuite("用TCP-IP进行网际互联");

    internetworkingWithTCPIPSuite.AddSuite(GetPrinciplesProtocolsAndArchitecturesSuite());
    internetworkingWithTCPIPSuite.AddSuite(GetDesignImplementationAndInternalsSuite());
    internetworkingWithTCPIPSuite.AddSuite(GetClientServerProgrammingAndApplicationsSuite());

    AddSuite(internetworkingWithTCPIPSuite);
}

CoreTools::Suite BookNetworkProgramming::TestingHelper::GetPrinciplesProtocolsAndArchitecturesSuite()
{
    auto internetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite = GenerateSuite("用TCP-IP进行网际互联 第一卷 原理、协议与结构");

    ADD_TEST(internetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite, PrinciplesProtocolsAndArchitectures::PrinciplesProtocolsPlaceholderTesting);

    return internetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite;
}

CoreTools::Suite BookNetworkProgramming::TestingHelper::GetDesignImplementationAndInternalsSuite()
{
    auto internetworkingWithTCPIPDesignImplementationAndInternalsSuite = GenerateSuite("用TCP-IP进行网际互联 第二卷 设计、实现与内核");

    ADD_TEST(internetworkingWithTCPIPDesignImplementationAndInternalsSuite, DesignImplementationAndInternals::DesignImplementationPlaceholderTesting);

    return internetworkingWithTCPIPDesignImplementationAndInternalsSuite;
}

CoreTools::Suite BookNetworkProgramming::TestingHelper::GetClientServerProgrammingAndApplicationsSuite()
{
    auto internetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite = GenerateSuite("用TCP-IP进行网际互联 第三卷 客户—服务器编程与应用");

    ADD_TEST(internetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite, ClientServerProgrammingAndApplications::ClientServerProgrammingPlaceholderTesting);

    return internetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite;
}

void BookNetworkProgramming::TestingHelper::AddUNIXNetworkProgrammingSuite()
{
    auto unixNetworkProgrammingSuite = GenerateSuite("UNIX 网络编程");

    unixNetworkProgrammingSuite.AddSuite(GetUNIXNetworkProgrammingTheSocketsNetworkingAPISuite());
    unixNetworkProgrammingSuite.AddSuite(GetUNIXNetworkProgrammingInterprocessCommunicationSuite());

    AddSuite(unixNetworkProgrammingSuite);
}

CoreTools::Suite BookNetworkProgramming::TestingHelper::GetUNIXNetworkProgrammingTheSocketsNetworkingAPISuite()
{
    auto unixNetworkProgrammingTheSocketsNetworkingAPISuite = GenerateSuite("UNIX 网络编程 第一卷 套接字联网API");

    ADD_TEST(unixNetworkProgrammingTheSocketsNetworkingAPISuite, UnixNetworkProgramming::TheSocketsNetworkingAPIPlaceholderTesting);

    return unixNetworkProgrammingTheSocketsNetworkingAPISuite;
}

CoreTools::Suite BookNetworkProgramming::TestingHelper::GetUNIXNetworkProgrammingInterprocessCommunicationSuite()
{
    auto unixNetworkProgrammingInterprocessCommunicationSuite = GenerateSuite("UNIX 网络编程 第二卷 进程间通信");

    ADD_TEST(unixNetworkProgrammingInterprocessCommunicationSuite, UnixNetworkProgramming::InterprocessCommunicationsPlaceholderTesting);

    return unixNetworkProgrammingInterprocessCommunicationSuite;
}

void BookNetworkProgramming::TestingHelper::AddConfiguringWindowsServer2008NetworkInfrastructureSuite()
{
    auto configuringWindowsServer2008NetworkInfrastructureSuite = GenerateSuite("Windows Server 2008 网络基础架构");

    ADD_TEST(configuringWindowsServer2008NetworkInfrastructureSuite, ConfiguringWindowsServer2008NetworkInfrastructure::ConfiguringWindowsServerPlaceholderTesting);

    AddSuite(configuringWindowsServer2008NetworkInfrastructureSuite);
}

void BookNetworkProgramming::TestingHelper::AddAdvancedCORBAProgrammingWithCppSuite()
{
    auto advancedCORBAProgrammingWithCppSuite = GenerateSuite("基于C++ CORBA高级编程");

    ADD_TEST(advancedCORBAProgrammingWithCppSuite, AdvancedCORBAProgrammingWithCpp::AdvancedCORBAProgrammingWithCppPlaceholderTesting);

    AddSuite(advancedCORBAProgrammingWithCppSuite);
}

void BookNetworkProgramming::TestingHelper::AddComputerNetworksASystemApproachSuite()
{
    auto computerNetworksASystemApproachSuite = GenerateSuite("计算机网络：系统方法");

    ADD_TEST(computerNetworksASystemApproachSuite, ComputerNetworksASystemApproach::ComputerNetworksASystemApproachPlaceholderTesting);

    AddSuite(computerNetworksASystemApproachSuite);
}

void BookNetworkProgramming::TestingHelper::AddComputerNetworksATopDownApproachSuite()
{
    auto computerNetworksATopDownApproachSuite = GenerateSuite("计算机网络：自顶向下方法");

    ADD_TEST(computerNetworksATopDownApproachSuite, ComputerNetworksATopDownApproach::ComputerNetworksATopDownApproachPlaceholderTesting);

    AddSuite(computerNetworksATopDownApproachSuite);
}

void BookNetworkProgramming::TestingHelper::AddTCPIPProtocolSuite()
{
    auto tcpIPProtocolSuite = GenerateSuite("TCP/IP协议族");

    ADD_TEST(tcpIPProtocolSuite, TCPIPProtocol::TCPIPProtocolPlaceholderTesting);

    AddSuite(tcpIPProtocolSuite);
}

void BookNetworkProgramming::TestingHelper::AddCryptographyAndNetworkSecuritySuite()
{
    auto cryptographyAndNetworkSecuritySuite = GenerateSuite("密码编码学与网络安全——原理与实践");

    ADD_TEST(cryptographyAndNetworkSecuritySuite, CryptographyAndNetworkSecurity::CryptographyAndNetworkSecurityPlaceholderTesting);

    AddSuite(cryptographyAndNetworkSecuritySuite);
}
