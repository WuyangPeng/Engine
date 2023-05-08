///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 15:36)

#include "ConfigurationStrategyTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
Network::ConfigurationStrategyTesting::ConfigurationStrategyTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ConfigurationStrategyTesting)

void Network::ConfigurationStrategyTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ConfigurationStrategyTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DefaultTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ServerTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ClientTest);
}

void Network::ConfigurationStrategyTesting::DefaultTest()
{
    ConfigurationStrategy configurationStrategy = ConfigurationStrategy::Create();

    ASSERT_ENUM_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::Boost);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetServerStrategy(), ServerStrategy::Disable);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetClientStrategy(), ClientStrategy::Disable);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetMessageStrategy(), MessageStrategy::Default);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetConnectStrategy(), ConnectStrategy::Tcp);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetOpenSSLStrategy(), OpenSSLStrategy::Default);

    auto configurationSubStrategy = configurationStrategy.GetConfigurationSubStrategy();

    ASSERT_FALSE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
    ASSERT_FALSE(configurationSubStrategy.IsExist(WrappersSubStrategy::Threads));

    ASSERT_TRUE(configurationStrategy.GetHost().empty());

    ASSERT_EQUAL(configurationStrategy.GetPort(), 0);

    auto configurationParameter = configurationStrategy.GetConfigurationParameter();

    ASSERT_FALSE(configurationParameter.IsParameterExist(SYSTEM_TEXT("ServerID"), SYSTEM_TEXT("1")));
}

void Network::ConfigurationStrategyTesting::ServerTest()
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::MultiContext, 2);
    subStrategy.Insert(WrappersSubStrategy::Threads, 3);

    ConfigurationParameter configurationParameter = ConfigurationParameter::Create();
    configurationParameter.AddParameter(SYSTEM_TEXT("ServerID"), SYSTEM_TEXT("1"));
    configurationParameter.AddParameter(SYSTEM_TEXT("BufferSize"), SYSTEM_TEXT("1000"));

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Ace,
                                                 ConnectStrategy::Udp,
                                                 ServerStrategy::Iterative,
                                                 MessageStrategy::Iovec,
                                                 ParserStrategy::BigEndian,
                                                 OpenSSLStrategy::OpenSSL,
                                                 EncryptedCompressionStrategy::Default,
                                                 subStrategy,
                                                 configurationParameter,
                                                 SocketSendMessage::Immediately,
                                                 "172.0.1.1",
                                                 8010 };

    ASSERT_ENUM_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::Ace);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetServerStrategy(), ServerStrategy::Iterative);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetClientStrategy(), ClientStrategy::Disable);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetMessageStrategy(), MessageStrategy::Iovec);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetConnectStrategy(), ConnectStrategy::Udp);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetOpenSSLStrategy(), OpenSSLStrategy::OpenSSL);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetSocketSendMessage(), SocketSendMessage::Immediately);

    auto configurationSubStrategy = configurationStrategy.GetConfigurationSubStrategy();

    ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
    ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::Threads));

    ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::MultiContext), 2);
    ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::Threads), 3);

    ASSERT_EQUAL(configurationStrategy.GetHost(), "172.0.1.1");

    ASSERT_EQUAL(configurationStrategy.GetPort(), 8010);

    auto secondConfigurationParameter = configurationStrategy.GetConfigurationParameter();

    ASSERT_TRUE(secondConfigurationParameter.IsParameterExist(SYSTEM_TEXT("ServerID"), SYSTEM_TEXT("1")));
}

void Network::ConfigurationStrategyTesting::ClientTest()
{
    ConfigurationSubStrategy subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::MultiContext, 2);
    subStrategy.Insert(WrappersSubStrategy::Threads, 3);

    ConfigurationParameter configurationParameter = ConfigurationParameter::Create();
    configurationParameter.AddParameter(SYSTEM_TEXT("ServerID"), SYSTEM_TEXT("1"));

    ConfigurationStrategy configurationStrategy{ WrappersStrategy::Ace,
                                                 ConnectStrategy::Udp,
                                                 ClientStrategy::Cache,
                                                 MessageStrategy::Iovec,
                                                 ParserStrategy::BigEndian,
                                                 OpenSSLStrategy::OpenSSL,
                                                 EncryptedCompressionStrategy::Default,
                                                 subStrategy,
                                                 configurationParameter,
                                                 SocketSendMessage::Cache,
                                                 "172.0.1.1",
                                                 8010 };

    ASSERT_ENUM_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::Ace);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetServerStrategy(), ServerStrategy::Disable);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetClientStrategy(), ClientStrategy::Cache);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetMessageStrategy(), MessageStrategy::Iovec);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetConnectStrategy(), ConnectStrategy::Udp);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetOpenSSLStrategy(), OpenSSLStrategy::OpenSSL);
    ASSERT_ENUM_EQUAL(configurationStrategy.GetSocketSendMessage(), SocketSendMessage::Cache);

    auto configurationSubStrategy = configurationStrategy.GetConfigurationSubStrategy();

    ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
    ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::Threads));

    ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::MultiContext), 2);
    ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::Threads), 3);

    ASSERT_EQUAL(configurationStrategy.GetHost(), "172.0.1.1");

    ASSERT_EQUAL(configurationStrategy.GetPort(), 8010);

    auto secondConfigurationParameter = configurationStrategy.GetConfigurationParameter();

    ASSERT_TRUE(secondConfigurationParameter.IsParameterExist(SYSTEM_TEXT("ServerID"), SYSTEM_TEXT("1")));
}
