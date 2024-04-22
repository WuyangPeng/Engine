///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 10:12)

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
    const auto configurationStrategy = ConfigurationStrategy::Create();

    ASSERT_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::Boost);
    ASSERT_EQUAL(configurationStrategy.GetServerStrategy(), ServerStrategy::Disable);
    ASSERT_EQUAL(configurationStrategy.GetClientStrategy(), ClientStrategy::Disable);
    ASSERT_EQUAL(configurationStrategy.GetMessageStrategy(), MessageStrategy::Default);
    ASSERT_EQUAL(configurationStrategy.GetConnectStrategy(), ConnectStrategy::Tcp);
    ASSERT_EQUAL(configurationStrategy.GetParserStrategy(), ParserStrategy::LittleEndian);
    ASSERT_EQUAL(configurationStrategy.GetOpenSslStrategy(), OpenSslStrategy::Default);

    const auto configurationSubStrategy = configurationStrategy.GetConfigurationSubStrategy();

    ASSERT_FALSE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
    ASSERT_FALSE(configurationSubStrategy.IsExist(WrappersSubStrategy::Threads));

    ASSERT_TRUE(configurationStrategy.GetHost().empty());
    ASSERT_EQUAL(configurationStrategy.GetPort(), 0);

    const auto configurationParameter = configurationStrategy.GetConfigurationParameter();

    ASSERT_FALSE(configurationParameter.IsParameterExist(SYSTEM_TEXT("ServerId"), SYSTEM_TEXT("1")));
}

void Network::ConfigurationStrategyTesting::ServerTest()
{
    auto subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::MultiContext, 2);
    subStrategy.Insert(WrappersSubStrategy::Threads, 3);

    auto configurationParameter = ConfigurationParameter::Create();
    configurationParameter.AddParameter(SYSTEM_TEXT("ServerId"), SYSTEM_TEXT("1"));
    configurationParameter.AddParameter(SYSTEM_TEXT("BufferSize"), SYSTEM_TEXT("1000"));

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::Ace,
                                                       ConnectStrategy::Udp,
                                                       ServerStrategy::Iterative,
                                                       MessageStrategy::Iovec,
                                                       ParserStrategy::BigEndian,
                                                       OpenSslStrategy::OpenSsl,
                                                       EncryptedCompressionStrategy::Default,
                                                       subStrategy,
                                                       configurationParameter,
                                                       SocketSendMessage::Immediately,
                                                       "172.0.1.1",
                                                       8010 };

    ASSERT_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::Ace);
    ASSERT_EQUAL(configurationStrategy.GetServerStrategy(), ServerStrategy::Iterative);
    ASSERT_EQUAL(configurationStrategy.GetClientStrategy(), ClientStrategy::Disable);
    ASSERT_EQUAL(configurationStrategy.GetMessageStrategy(), MessageStrategy::Iovec);
    ASSERT_EQUAL(configurationStrategy.GetConnectStrategy(), ConnectStrategy::Udp);
    ASSERT_EQUAL(configurationStrategy.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(configurationStrategy.GetOpenSslStrategy(), OpenSslStrategy::OpenSsl);
    ASSERT_EQUAL(configurationStrategy.GetSocketSendMessage(), SocketSendMessage::Immediately);

    const auto configurationSubStrategy = configurationStrategy.GetConfigurationSubStrategy();

    ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
    ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::Threads));

    ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::MultiContext), 2);
    ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::Threads), 3);

    ASSERT_EQUAL(configurationStrategy.GetHost(), "172.0.1.1");

    ASSERT_EQUAL(configurationStrategy.GetPort(), 8010);

    const auto parameter = configurationStrategy.GetConfigurationParameter();

    ASSERT_TRUE(parameter.IsParameterExist(SYSTEM_TEXT("ServerId"), SYSTEM_TEXT("1")));
}

void Network::ConfigurationStrategyTesting::ClientTest()
{
    auto subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::MultiContext, 0);
    subStrategy.Insert(WrappersSubStrategy::Threads, 3);

    ConfigurationParameter configurationParameter = ConfigurationParameter::Create();
    configurationParameter.AddParameter(SYSTEM_TEXT("ServerId"), SYSTEM_TEXT("1"));

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::Ace,
                                                       ConnectStrategy::Udp,
                                                       ClientStrategy::Cache,
                                                       MessageStrategy::Iovec,
                                                       ParserStrategy::BigEndian,
                                                       OpenSslStrategy::OpenSsl,
                                                       EncryptedCompressionStrategy::Default,
                                                       subStrategy,
                                                       configurationParameter,
                                                       SocketSendMessage::Cache,
                                                       "172.0.1.1",
                                                       8010 };

    ASSERT_EQUAL(configurationStrategy.GetWrappersStrategy(), WrappersStrategy::Ace);
    ASSERT_EQUAL(configurationStrategy.GetServerStrategy(), ServerStrategy::Disable);
    ASSERT_EQUAL(configurationStrategy.GetClientStrategy(), ClientStrategy::Cache);
    ASSERT_EQUAL(configurationStrategy.GetMessageStrategy(), MessageStrategy::Iovec);
    ASSERT_EQUAL(configurationStrategy.GetConnectStrategy(), ConnectStrategy::Udp);
    ASSERT_EQUAL(configurationStrategy.GetParserStrategy(), ParserStrategy::BigEndian);
    ASSERT_EQUAL(configurationStrategy.GetOpenSslStrategy(), OpenSslStrategy::OpenSsl);
    ASSERT_EQUAL(configurationStrategy.GetSocketSendMessage(), SocketSendMessage::Cache);

    const auto configurationSubStrategy = configurationStrategy.GetConfigurationSubStrategy();

    ASSERT_FALSE(configurationSubStrategy.IsExist(WrappersSubStrategy::MultiContext));
    ASSERT_TRUE(configurationSubStrategy.IsExist(WrappersSubStrategy::Threads));

    ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::MultiContext), 0);
    ASSERT_EQUAL(configurationSubStrategy.GetValue(WrappersSubStrategy::Threads), 3);

    ASSERT_EQUAL(configurationStrategy.GetHost(), "172.0.1.1");

    ASSERT_EQUAL(configurationStrategy.GetPort(), 8010);

    const auto parameter = configurationStrategy.GetConfigurationParameter();

    ASSERT_TRUE(parameter.IsParameterExist(SYSTEM_TEXT("ServerId"), SYSTEM_TEXT("1")));
}
