///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:19)

#include "NetworkSockStreamTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/ConfigurationParameter.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/NullMessage.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"
#include "Network/NetworkTesting/InterfaceSuite/SingletonTestingDetail.h"

#include <array>

Network::NetworkSockStreamTesting::NetworkSockStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }, bufferSize{ 1048576 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NetworkSockStreamTesting)

void Network::NetworkSockStreamTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Network::NetworkSockStreamTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_2(NetworkSingletonTest<ClassType>, this, &ClassType::StreamTest);
}

void Network::NetworkSockStreamTesting::StreamTest()
{
    auto configurationSubStrategy = ConfigurationSubStrategy::Create();
    configurationSubStrategy.Insert(WrappersSubStrategy::ReceiveBufferSize, bufferSize);
    configurationSubStrategy.Insert(WrappersSubStrategy::SendBufferSize, bufferSize);

    const ConfigurationStrategy clientConfigurationStrategy{ WrappersStrategy::Network,
                                                             ConnectStrategy::Tcp,
                                                             ClientStrategy::OnlySending,
                                                             MessageStrategy::Default,
                                                             ParserStrategy::LittleEndian,
                                                             OpenSslStrategy::Default,
                                                             EncryptedCompressionStrategy::Default,
                                                             configurationSubStrategy,
                                                             ConfigurationParameter::Create(),
                                                             SocketSendMessage::Default,
                                                             "127.0.0.1",
                                                             7543 };

    SockStream sockStream{ clientConfigurationStrategy };
}
