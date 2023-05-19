///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/18 10:46)

#include "BoostSockStreamTesting.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/Client.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/NullMessage.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketEvent.h"

Network::BoostSockStreamTesting::BoostSockStreamTesting(const OStreamShared& stream, int increase)
    : ParentType{ stream, increase }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockStreamTesting)

void Network::BoostSockStreamTesting::ClientThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoClientThread);
}

void Network::BoostSockStreamTesting::DoClientThread()
{
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();

    messageEventManager->SetCallbackEvent(testSocketEvent);

    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    Client client{ configurationStrategy, messageEventManager };

    const auto socketId = ClientConnect(client);
    ClientSend(client, socketId, *testSocketEvent);
    ASSERT_NOT_THROW_EXCEPTION_2(ClientReceive, client, *testSocketEvent);
}

int64_t Network::BoostSockStreamTesting::ClientConnect(Client& client)
{
    auto socketId = 0LL;
    for (auto i = 0; i < connectTime; ++i)
    {
        socketId = client.Connect();
        if (socketId != 0u)
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, connectTime, "连接服务器失败。");
    }

    return socketId;
}

void Network::BoostSockStreamTesting::ClientSend(Client& client, int64_t socketId, const TestSocketEvent& testSocketEvent)
{
    const auto message = std::make_shared<NullMessage>(MessageHeadStrategy::Default, GetMessageId());
    client.AsyncSend(socketId, message);
    client.ImmediatelyAsyncSend(socketId);

    for (auto i = 0; i < sendTime; ++i)
    {
        if (0 < testSocketEvent.GetAsyncSendCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, sendTime);
    }
}

void Network::BoostSockStreamTesting::ClientReceive(Client& client, const TestSocketEvent& testSocketEvent)
{
    client.AsyncReceive();

    for (auto i = 0; i < asynchronousReceiveTime; ++i)
    {
        if (0 < testSocketEvent.GetAsyncReceiveCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, asynchronousReceiveTime);
    }
}

void Network::BoostSockStreamTesting::ClientNoSendThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoClientNoSendThread);
}

void Network::BoostSockStreamTesting::DoClientNoSendThread()
{
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();

    messageEventManager->SetCallbackEvent(testSocketEvent);

    const auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    Client client{ configurationStrategy, messageEventManager };

    const auto socketId = ClientConnect(client);
    ASSERT_LESS(0, socketId);
}

void Network::BoostSockStreamTesting::ServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoServerThread);
}

void Network::BoostSockStreamTesting::DoServerThread()
{
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    const auto testMessageEvent = std::make_shared<Network::TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    messageEventManager->SetCallbackEvent(testSocketEvent);
    messageEventManager->Insert(GetMessageId(), testMessageEvent);
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    const auto server = make_shared<Server>(configurationStrategy, messageEventManager);

    testMessageEvent->SetServerWeakPtr(server);

    for (auto i = 0; i < receiveTime; ++i)
    {
        ASSERT_TRUE(server->RunServer());

        if (0 < testMessageEvent->GetCallBackTime())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, receiveTime);
    }
}

void Network::BoostSockStreamTesting::ServerNoReceiveThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoServerNoReceiveThread);
}

void Network::BoostSockStreamTesting::DoServerNoReceiveThread()
{
    const auto testSocketEvent = std::make_shared<TestSocketEvent>();
    const auto messageEventManager = MessageEventManager::CreateSharedPtr();
    const auto testMessageEvent = std::make_shared<Network::TestMessageEvent>(CoreTools::DisableNotThrow::Disable);
    messageEventManager->SetCallbackEvent(testSocketEvent);
    messageEventManager->Insert(GetMessageId(), testMessageEvent);

    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    const auto server = make_shared<Server>(configurationStrategy, messageEventManager);

    testMessageEvent->SetServerWeakPtr(server);

    for (auto i = 0; i < acceptTime; ++i)
    {
        MAYBE_UNUSED const auto result = server->RunServer();

        if (0 < testSocketEvent->GetAsyncAcceptorCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, acceptTime);
    }
}

void Network::BoostSockStreamTesting::CreateMessage()
{
    MESSAGE_MANAGER_SINGLETON.Insert(GetMessageId(), MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::BoostSockStreamTesting::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(GetMessageId());
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

Network::MessageBufferSharedPtr Network::BoostSockStreamTesting::CreateMessageBuffer() const
{
    const auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    auto messageBuffer = std::make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy());

    auto initialBuffered = messageBuffer->GetInitialBufferedPtr();

    const auto messageLength = reinterpret_cast<int32_t*>(initialBuffered);

    if (messageLength == nullptr)
    {
        return messageBuffer;
    }

    // 长度等于消息头长度加上消息ID和子消息ID长度。
    *messageLength = MessageInterface::GetMessageHeadSize() + CoreTools::GetStreamSize(GetMessageId()) * 2;

    initialBuffered += CoreTools::GetStreamSize(*messageLength);
    const auto fullVersion = reinterpret_cast<int32_t*>(initialBuffered);
    if (fullVersion == nullptr)
    {
        return messageBuffer;
    }

    *fullVersion = MESSAGE_MANAGER_SINGLETON.GetFullVersion();

    initialBuffered += CoreTools::GetStreamSize(*fullVersion);
    const auto timeInMicroseconds = reinterpret_cast<int64_t*>(initialBuffered);
    if (timeInMicroseconds == nullptr)
    {
        return messageBuffer;
    }
    *timeInMicroseconds = System::GetTimeInMicroseconds();

    initialBuffered += CoreTools::GetStreamSize(*timeInMicroseconds);
    const auto messageHeadStrategy = reinterpret_cast<int32_t*>(initialBuffered);
    if (messageHeadStrategy == nullptr)
    {
        return messageBuffer;
    }
    *messageHeadStrategy = System::EnumCastUnderlying(MessageHeadStrategy::Default);

    initialBuffered += CoreTools::GetStreamSize(*messageHeadStrategy);
    const auto messageNumber = reinterpret_cast<int32_t*>(initialBuffered);
    if (messageNumber == nullptr)
    {
        return messageBuffer;
    }
    *messageNumber = GetMessageId();

    messageBuffer->AddCurrentWriteIndex(*messageLength);

    return messageBuffer;
}

void Network::BoostSockStreamTesting::VerificationMessageBuffer(const MessageBuffer& messageBuffer)
{
    auto initialBuffered = messageBuffer.GetInitialBufferedPtr();

    const auto messageLength = reinterpret_cast<const int32_t*>(initialBuffered);
    if (messageLength == nullptr)
    {
        return;
    }

    // 长度等于消息头长度加上消息ID和子消息ID长度。
    const auto verificationMessageLength = MessageInterface::GetMessageHeadSize() + CoreTools::GetStreamSize(GetMessageId()) * 2;
    ASSERT_EQUAL(*messageLength, verificationMessageLength);

    initialBuffered += CoreTools::GetStreamSize(*messageLength);
    const auto fullVersion = reinterpret_cast<const int32_t*>(initialBuffered);
    if (fullVersion == nullptr)
    {
        return;
    }

    ASSERT_EQUAL(*fullVersion, MESSAGE_MANAGER_SINGLETON.GetFullVersion());

    initialBuffered += CoreTools::GetStreamSize(*fullVersion);
    const auto timeInMicroseconds = reinterpret_cast<const int64_t*>(initialBuffered);
    if (timeInMicroseconds == nullptr)
    {
        return;
    }
    ASSERT_LESS_EQUAL(*timeInMicroseconds, System::GetTimeInMicroseconds());

    initialBuffered += CoreTools::GetStreamSize(*timeInMicroseconds);
    const auto messageHeadStrategy = reinterpret_cast<const int32_t*>(initialBuffered);
    if (messageHeadStrategy == nullptr)
    {
        return;
    }
    ASSERT_EQUAL(*messageHeadStrategy, System::EnumCastUnderlying(MessageHeadStrategy::Default));

    initialBuffered += CoreTools::GetStreamSize(*messageHeadStrategy);
    const auto messageNumber = reinterpret_cast<const int32_t*>(initialBuffered);
    if (messageNumber == nullptr)
    {
        return;
    }
    ASSERT_EQUAL(*messageNumber, GetMessageId());
}

#include STSTEM_WARNING_POP
