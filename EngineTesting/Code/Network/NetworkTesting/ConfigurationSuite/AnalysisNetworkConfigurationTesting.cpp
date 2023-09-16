///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:12)

#include "AnalysisNetworkConfigurationTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/AnalysisNetworkConfiguration.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

Network::AnalysisNetworkConfigurationTesting::AnalysisNetworkConfigurationTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, AnalysisNetworkConfigurationTesting)

void Network::AnalysisNetworkConfigurationTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::AnalysisNetworkConfigurationTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(AnalysisNetworkConfigurationTest);
}

void Network::AnalysisNetworkConfigurationTesting::AnalysisNetworkConfigurationTest()
{
    const TestingType analysisNetworkConfiguration{ "Configuration/NetworkTest.json" };

    constexpr auto configurationSize = 2;
    ASSERT_EQUAL(configurationSize, analysisNetworkConfiguration.GetSize());

    GameServerTest(analysisNetworkConfiguration);
    GameClientTest(analysisNetworkConfiguration);
}

void Network::AnalysisNetworkConfigurationTesting::GameServerTest(const TestingType& analysisNetworkConfiguration)
{
    const auto gameServer = analysisNetworkConfiguration.GetConfigurationStrategy(SYSTEM_TEXT("GameServer"));

    ASSERT_ENUM_EQUAL(gameServer.GetWrappersStrategy(), WrappersStrategy::Ace);
    ASSERT_ENUM_EQUAL(gameServer.GetServerStrategy(), ServerStrategy::Iterative);
    ASSERT_ENUM_EQUAL(gameServer.GetClientStrategy(), ClientStrategy::Disable);
    ASSERT_ENUM_EQUAL(gameServer.GetMessageStrategy(), MessageStrategy::Iovec);
    ASSERT_ENUM_EQUAL(gameServer.GetConnectStrategy(), ConnectStrategy::Udp);
    ASSERT_ENUM_EQUAL(gameServer.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_ENUM_EQUAL(gameServer.GetOpenSslStrategy(), OpenSslStrategy::OpenSsl);

    const auto configurationSubStrategy = gameServer.GetConfigurationSubStrategy();

    ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
    ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::Threads));

    ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::MultiContext), 2);
    ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::Threads), 3);

    ASSERT_EQUAL(gameServer.GetHost(), "127.0.1.1");

    ASSERT_EQUAL(gameServer.GetPort(), 8010);

    const auto configurationParameter = gameServer.GetConfigurationParameter();

    ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("ServerId"), SYSTEM_TEXT("1")));
    ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("ServerId"), SYSTEM_TEXT("2")));
    ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("PlatformId"), SYSTEM_TEXT("1")));
    ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("ServerName"), SYSTEM_TEXT("GameServer")));
    ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("BufferSize"), SYSTEM_TEXT("100000")));
}

void Network::AnalysisNetworkConfigurationTesting::GameClientTest(const TestingType& analysisNetworkConfiguration)
{
    const auto gameClient = analysisNetworkConfiguration.GetConfigurationStrategy(SYSTEM_TEXT("GameClient"));

    ASSERT_ENUM_EQUAL(gameClient.GetWrappersStrategy(), WrappersStrategy::Network);
    ASSERT_ENUM_EQUAL(gameClient.GetServerStrategy(), ServerStrategy::Disable);
    ASSERT_ENUM_EQUAL(gameClient.GetClientStrategy(), ClientStrategy::Cache);
    ASSERT_ENUM_EQUAL(gameClient.GetMessageStrategy(), MessageStrategy::Iovec);
    ASSERT_ENUM_EQUAL(gameClient.GetConnectStrategy(), ConnectStrategy::Tcp);
    ASSERT_ENUM_EQUAL(gameClient.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_ENUM_EQUAL(gameClient.GetOpenSslStrategy(), OpenSslStrategy::Default);

    const auto configurationSubStrategy = gameClient.GetConfigurationSubStrategy();

    ASSERT_EQUAL(gameClient.GetHost(), "127.0.0.1");

    ASSERT_EQUAL(gameClient.GetPort(), 8010);

    const auto configurationParameter = gameClient.GetConfigurationParameter();

    ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("PlatformId"), SYSTEM_TEXT("1")));
    ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("PlatformId"), SYSTEM_TEXT("2")));
    ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("ClientName"), SYSTEM_TEXT("GameClient")));
    ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("BufferSize"), SYSTEM_TEXT("100000")));
}
