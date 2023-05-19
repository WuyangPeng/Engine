///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 17:03)

#include "ConsumerTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/MessageOrientedMiddleware/Consumer.h"

Network::ConsumerTesting::ConsumerTesting(const OStreamShared& stream)
    : ParentType{ stream }, bufferSize{ 1048576 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ConsumerTesting)

void Network::ConsumerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ConsumerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConsumerTest);
}

void Network::ConsumerTesting::ConsumerTest()
{
    auto subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                       ConnectStrategy::Tcp,
                                                       ServerStrategy::Reactive,
                                                       MessageStrategy::Default,
                                                       ParserStrategy::LittleEndian,
                                                       OpenSSLStrategy::Default,
                                                       EncryptedCompressionStrategy::Default,
                                                       subStrategy,
                                                       ConfigurationParameter::Create(),
                                                       SocketSendMessage::Default,
                                                       "127.0.0.1",
                                                       1580 };

    Consumer consumer{ configurationStrategy, SYSTEM_TEXT("consumer") };

    MAYBE_UNUSED const auto& manager = consumer.GetMessageEventManager();
}