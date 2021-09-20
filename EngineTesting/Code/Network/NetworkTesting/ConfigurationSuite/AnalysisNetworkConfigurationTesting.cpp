// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 10:38)

#include "AnalysisNetworkConfigurationTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/AnalysisNetworkConfiguration.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, AnalysisNetworkConfiguration)

void Network::AnalysisNetworkConfigurationTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(AnalysisNetworkConfigurationTest);
}

void Network::AnalysisNetworkConfigurationTesting
	::AnalysisNetworkConfigurationTest()
{
	TestingType analysisNetworkConfiguration{ "Configuration/NetworkTest.json" };

	constexpr auto configurationSize = 2;
	ASSERT_EQUAL(configurationSize, analysisNetworkConfiguration.GetSize());

	GameServerTest(analysisNetworkConfiguration);
	GameClientTest(analysisNetworkConfiguration);
}

void Network::AnalysisNetworkConfigurationTesting
	::GameServerTest(TestingType& analysisNetworkConfiguration)
{
	auto gameServer = analysisNetworkConfiguration.GetConfigurationStrategy(SYSTEM_TEXT("GameServer"));

	ASSERT_ENUM_EQUAL(gameServer.GetWrappersStrategy(), WrappersStrategy::ACE);
	ASSERT_ENUM_EQUAL(gameServer.GetPatternStrategy(), ServerStrategy::Iterative);
	ASSERT_ENUM_EQUAL(gameServer.GetClientStrategy(), ClientStrategy::Disable);
	ASSERT_ENUM_EQUAL(gameServer.GetMessageStrategy(), MessageStrategy::Iovec);
	ASSERT_ENUM_EQUAL(gameServer.GetConnectStrategy(), ConnectStrategy::UDP);
	ASSERT_ENUM_EQUAL(gameServer.GetParserStrategy(), ParserStrategy::BigEndian);
	ASSERT_ENUM_EQUAL(gameServer.GetOpenSSLStrategy(), OpenSSLStrategy::OpenSSL);

	auto configurationSubStrategy = gameServer.GetConfigurationSubStrategy();

	ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
	ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::Threads));

	ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::MultiContext), 2);
	ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::Threads), 3);

	ASSERT_EQUAL(gameServer.GetIP(), "127.0.1.1");

	ASSERT_EQUAL(gameServer.GetPort(), 8010);

	auto configurationParameter = gameServer.GetConfigurationParameter();

	ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("ServerID"), SYSTEM_TEXT("1")));
	ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("ServerID"), SYSTEM_TEXT("2")));
	ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("PlatformID"), SYSTEM_TEXT("1")));
	ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("ServerName"), SYSTEM_TEXT("GameServer")));
	ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("BufferSize"), SYSTEM_TEXT("100000")));
}

void Network::AnalysisNetworkConfigurationTesting
	::GameClientTest(TestingType& analysisNetworkConfiguration)
{
	auto gameClient = analysisNetworkConfiguration.GetConfigurationStrategy(SYSTEM_TEXT("GameClient"));

	ASSERT_ENUM_EQUAL(gameClient.GetWrappersStrategy(), WrappersStrategy::Network);
	ASSERT_ENUM_EQUAL(gameClient.GetPatternStrategy(), ServerStrategy::Disable);
	ASSERT_ENUM_EQUAL(gameClient.GetClientStrategy(), ClientStrategy::Cache);
	ASSERT_ENUM_EQUAL(gameClient.GetMessageStrategy(), MessageStrategy::Iovec);
	ASSERT_ENUM_EQUAL(gameClient.GetConnectStrategy(), ConnectStrategy::TCP);
	ASSERT_ENUM_EQUAL(gameClient.GetParserStrategy(), ParserStrategy::LittleEndian);
	ASSERT_ENUM_EQUAL(gameClient.GetOpenSSLStrategy(), OpenSSLStrategy::Default);

	auto configurationSubStrategy = gameClient.GetConfigurationSubStrategy();

	ASSERT_FALSE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
	ASSERT_FALSE(configurationSubStrategy.IsExist(WrappersSubStrategy::Threads));

	ASSERT_EQUAL(gameClient.GetIP(), "127.0.0.1");

	ASSERT_EQUAL(gameClient.GetPort(), 8010);

	auto configurationParameter = gameClient.GetConfigurationParameter();

	ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("PlatformID"), SYSTEM_TEXT("1")));
	ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("PlatformID"), SYSTEM_TEXT("2")));
	ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("ClientName"), SYSTEM_TEXT("GameClient")));
	ASSERT_TRUE(configurationParameter.IsParameterExist(SYSTEM_TEXT("BufferSize"), SYSTEM_TEXT("100000")));
}

