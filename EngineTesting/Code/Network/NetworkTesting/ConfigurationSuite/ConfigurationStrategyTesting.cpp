// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.2.4 (2020/03/12 10:39)

#include "ConfigurationStrategyTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE_USE_TESTING_TYPE(Network, ConfigurationStrategy)

void Network::ConfigurationStrategyTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ServerTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ClientTest);
}

void Network::ConfigurationStrategyTesting
	::DefaultTest()
{
	ConfigurationStrategy configurationStrategy{};

	ASSERT_ENUM_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::Boost);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetPatternStrategy(), ServerStrategy::Disable);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetClientStrategy(), ClientStrategy::Disable);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetMessageStrategy(), MessageStrategy::Default);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetConnectStrategy(), ConnectStrategy::TCP);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetParserStrategy(), ParserStrategy::LittleEndian);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetOpenSSLStrategy(), OpenSSLStrategy::Default);

	auto configurationSubStrategy = configurationStrategy.GetConfigurationSubStrategy();

	ASSERT_FALSE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
	ASSERT_FALSE(configurationSubStrategy.IsExist(WrappersSubStrategy::Threads));

	ASSERT_TRUE(configurationStrategy.GetIP().empty());

	ASSERT_EQUAL(configurationStrategy.GetPort(), 0);

	auto configurationParameter = configurationStrategy.GetConfigurationParameter();

	ASSERT_FALSE(configurationParameter.IsParameterExist(SYSTEM_TEXT("ServerID"), SYSTEM_TEXT("1")));
}

void Network::ConfigurationStrategyTesting
	::ServerTest()
{
	ConfigurationSubStrategy subStrategy;
	subStrategy.Insert(WrappersSubStrategy::MultiContext, 2);
	subStrategy.Insert(WrappersSubStrategy::Threads, 3);

	ConfigurationParameter configurationParameter;
	configurationParameter.AddParameter(SYSTEM_TEXT("ServerID"), SYSTEM_TEXT("1"));
	configurationParameter.AddParameter(SYSTEM_TEXT("BufferSize"), SYSTEM_TEXT("1000"));

	ConfigurationStrategy configurationStrategy{ WrappersStrategy::ACE,ConnectStrategy::UDP,ServerStrategy::Iterative,
												 MessageStrategy::Iovec,ParserStrategy::BigEndian,OpenSSLStrategy::OpenSSL,
												 subStrategy ,configurationParameter ,SocketSendMessage::Immediately, "172.0.1.1",8010 };

	ASSERT_ENUM_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::ACE);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetPatternStrategy(), ServerStrategy::Iterative);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetClientStrategy(), ClientStrategy::Disable);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetMessageStrategy(), MessageStrategy::Iovec);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetConnectStrategy(), ConnectStrategy::UDP);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetParserStrategy(), ParserStrategy::BigEndian);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetOpenSSLStrategy(), OpenSSLStrategy::OpenSSL);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetSocketSendMessage(), SocketSendMessage::Immediately);

	auto configurationSubStrategy = configurationStrategy.GetConfigurationSubStrategy();

	ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
	ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::Threads));

	ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::MultiContext), 2);
	ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::Threads), 3);

	ASSERT_EQUAL(configurationStrategy.GetIP(), "172.0.1.1");

	ASSERT_EQUAL(configurationStrategy.GetPort(), 8010);

	auto secondConfigurationParameter = configurationStrategy.GetConfigurationParameter();

	ASSERT_TRUE(secondConfigurationParameter.IsParameterExist(SYSTEM_TEXT("ServerID"), SYSTEM_TEXT("1")));

	ASSERT_EQUAL(configurationStrategy.GetBufferSize(), 1000);
}

void Network::ConfigurationStrategyTesting
	::ClientTest()
{
	ConfigurationSubStrategy subStrategy;
	subStrategy.Insert(WrappersSubStrategy::MultiContext, 2);
	subStrategy.Insert(WrappersSubStrategy::Threads, 3);

	ConfigurationParameter configurationParameter;
	configurationParameter.AddParameter(SYSTEM_TEXT("ServerID"), SYSTEM_TEXT("1"));

	ConfigurationStrategy configurationStrategy{ WrappersStrategy::ACE,ConnectStrategy::UDP,ClientStrategy::Cache,
												 MessageStrategy::Iovec,ParserStrategy::BigEndian,OpenSSLStrategy::OpenSSL,
												 subStrategy ,configurationParameter ,SocketSendMessage::Cache,"172.0.1.1",8010 };

	ASSERT_ENUM_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::ACE);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetPatternStrategy(), ServerStrategy::Disable);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetClientStrategy(), ClientStrategy::Cache);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetMessageStrategy(), MessageStrategy::Iovec);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetConnectStrategy(), ConnectStrategy::UDP);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetParserStrategy(), ParserStrategy::BigEndian);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetOpenSSLStrategy(), OpenSSLStrategy::OpenSSL);
	ASSERT_ENUM_EQUAL(configurationStrategy.GetSocketSendMessage(), SocketSendMessage::Cache);

	auto configurationSubStrategy = configurationStrategy.GetConfigurationSubStrategy();

	ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
	ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::Threads));

	ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::MultiContext), 2);
	ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::Threads), 3);

	ASSERT_EQUAL(configurationStrategy.GetIP(), "172.0.1.1");

	ASSERT_EQUAL(configurationStrategy.GetPort(), 8010);

	auto secondConfigurationParameter = configurationStrategy.GetConfigurationParameter();

	ASSERT_TRUE(secondConfigurationParameter.IsParameterExist(SYSTEM_TEXT("ServerID"), SYSTEM_TEXT("1")));

	ASSERT_EQUAL(configurationStrategy.GetBufferSize(), 1024);
}


