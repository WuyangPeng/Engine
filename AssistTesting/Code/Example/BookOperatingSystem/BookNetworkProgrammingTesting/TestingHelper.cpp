// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎辅助版本：0.0.0.1 (2019/08/30 22:56)

#include "Testing.h"
#include "TestingHelper.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

BookNetworkProgramming::TestingHelper::TestingHelper(int argc, char** argv)
    : ParentType{ argc, argv, "书籍 操作系统 网络编程" }
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
    auto networkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite = GenerateSuite("网络虚拟环境图形架构设计");

    AddSuite(networkedGraphicsBuildingNetworkedGamesAndVirtualEnvironmentsSuite);
}

void BookNetworkProgramming::TestingHelper ::AddMultiplayerGameProgrammingSuite()
{
    auto multiplayerGameProgrammingSuite = GenerateSuite("网络多人游戏架构与编程");

    AddSuite(multiplayerGameProgrammingSuite);
}

void BookNetworkProgramming::TestingHelper ::AddNetworkProgrammingForMicrosoftWindowsSuite()
{
    auto networkProgrammingForMicrosoftWindowsSuite = GenerateSuite("Windows 网络编程");

    AddSuite(networkProgrammingForMicrosoftWindowsSuite);
}

void BookNetworkProgramming::TestingHelper ::AddEffectiveTCPIPProgrammingSuite()
{
    auto effectiveTCPIPProgrammingSuite = GenerateSuite("TCP IP 高效编程");

    AddSuite(effectiveTCPIPProgrammingSuite);
}

void BookNetworkProgramming::TestingHelper ::AddInternetworkingWithTCPIPSuite()
{
    auto internetworkingWithTCPIPSuite = GenerateSuite("用TCP-IP进行网际互联");

    AddInternetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite(internetworkingWithTCPIPSuite);
    AddInternetworkingWithTCPIPDesignImplementationAndInternalsSuite(internetworkingWithTCPIPSuite);
    AddInternetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite(internetworkingWithTCPIPSuite);

    AddSuite(internetworkingWithTCPIPSuite);
}

void BookNetworkProgramming::TestingHelper ::AddInternetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite(Suite& internetworkingWithTCPIPSuite)
{
    auto internetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite = GenerateSuite("用TCP-IP进行网际互联 第一卷 原理、协议与结构");

    internetworkingWithTCPIPSuite.AddSuite(internetworkingWithTCPIPPrinciplesProtocolsAndArchitecturesSuite);
}

void BookNetworkProgramming::TestingHelper ::AddInternetworkingWithTCPIPDesignImplementationAndInternalsSuite(Suite& internetworkingWithTCPIPSuite)
{
    auto internetworkingWithTCPIPDesignImplementationAndInternalsSuite = GenerateSuite("用TCP-IP进行网际互联 第二卷 设计、实现与内核");

    internetworkingWithTCPIPSuite.AddSuite(internetworkingWithTCPIPDesignImplementationAndInternalsSuite);
}

void BookNetworkProgramming::TestingHelper ::AddInternetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite(Suite& internetworkingWithTCPIPSuite)
{
    auto internetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite = GenerateSuite("用TCP-IP进行网际互联 第三卷 客户—服务器编程与应用");

    internetworkingWithTCPIPSuite.AddSuite(internetworkingWithTCPIPClientServerProgrammingAndApplicationsSuite);
}

void BookNetworkProgramming::TestingHelper ::AddUNIXNetworkProgrammingSuite()
{
    auto unixNetworkProgrammingSuite = GenerateSuite("UNIX 网络编程");

    AddUNIXNetworkProgrammingTheSocketsNetworkingAPISuite(unixNetworkProgrammingSuite);
    AddUNIXNetworkProgrammingInterprocessCommunicationSuite(unixNetworkProgrammingSuite);

    AddSuite(unixNetworkProgrammingSuite);
}

void BookNetworkProgramming::TestingHelper ::AddUNIXNetworkProgrammingTheSocketsNetworkingAPISuite(Suite& unixNetworkProgrammingSuite)
{
    auto unixNetworkProgrammingTheSocketsNetworkingAPISuite = GenerateSuite("UNIX 网络编程 第一卷 套接字联网API");

    unixNetworkProgrammingSuite.AddSuite(unixNetworkProgrammingTheSocketsNetworkingAPISuite);
}

void BookNetworkProgramming::TestingHelper ::AddUNIXNetworkProgrammingInterprocessCommunicationSuite(Suite& unixNetworkProgrammingSuite)
{
    auto unixNetworkProgrammingInterprocessCommunicationSuite = GenerateSuite("UNIX 网络编程 第二卷 进程间通信");

    unixNetworkProgrammingSuite.AddSuite(unixNetworkProgrammingInterprocessCommunicationSuite);
}

void BookNetworkProgramming::TestingHelper ::AddConfiguringWindowsServer2008NetworkInfrastructureSuite()
{
    auto configuringWindowsServer2008NetworkInfrastructureSuite = GenerateSuite("Windows Server 2008 网络基础架构");

    AddSuite(configuringWindowsServer2008NetworkInfrastructureSuite);
}

void BookNetworkProgramming::TestingHelper ::AddAdvancedCORBAProgrammingWithCppSuite()
{
    auto advancedCORBAProgrammingWithCppSuite = GenerateSuite("基于C++ CORBA高级编程");

    AddSuite(advancedCORBAProgrammingWithCppSuite);
}

