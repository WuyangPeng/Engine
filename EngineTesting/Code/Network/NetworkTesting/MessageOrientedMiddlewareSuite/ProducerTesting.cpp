///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:54)

#include "ProducerTesting.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/MessageOrientedMiddleware/Consumer.h"
#include "Network/MessageOrientedMiddleware/Producer.h"
#include "Network/NetworkMessage/NullMessage.h"

Network::ProducerTesting::ProducerTesting(const OStreamShared& stream)
    : ParentType{ stream }, bufferSize{ 1048576 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ProducerTesting)

void Network::ProducerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::ProducerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ProducerTest);
}

void Network::ProducerTesting::ProducerTest()
{
    auto subStrategy = ConfigurationSubStrategy::Create();
    subStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    subStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    const ConfigurationStrategy configurationStrategy{ WrappersStrategy::Null,
                                                       ConnectStrategy::Tcp,
                                                       ServerStrategy::Reactive,
                                                       MessageStrategy::Default,
                                                       ParserStrategy::LittleEndian,
                                                       OpenSslStrategy::Default,
                                                       EncryptedCompressionStrategy::Default,
                                                       subStrategy,
                                                       ConfigurationParameter::Create(),
                                                       SocketSendMessage::Default,
                                                       "127.0.0.1",
                                                       1580 };

    Producer producer{ configurationStrategy };

    producer.SendServerMessage(SYSTEM_TEXT("address"), std::make_shared<NullMessage>(MessageHeadStrategy::Default, 5));
}
