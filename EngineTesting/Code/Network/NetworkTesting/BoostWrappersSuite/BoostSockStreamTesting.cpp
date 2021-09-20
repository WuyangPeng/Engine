// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
//
// 引擎测试版本：0.0.2.4 (2020/03/13 16:39)

#include "BoostSockStreamTesting.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Base/Version.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "Network/Interface/Client.h"
#include "Network/NetworkMessage/BufferSendStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"
#include "Network/NetworkMessage/MessageManager.h"
#include "Network/NetworkMessage/MessageTypeCondition.h"
#include "Network/NetworkMessage/NullMessage.h"
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"

using std::make_shared;

Network::BoostSockStreamTesting::BoostSockStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SELF_CLASS_IS_VALID_1;
}
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockStreamTesting)

void Network::BoostSockStreamTesting ::ClientThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoClientThread);
}

void Network::BoostSockStreamTesting ::DoClientThread()
{
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    ClientSharedPtr client{ make_shared<Client>(configurationStrategy, testSocketManager) };

    auto socketID = ClientConnect(client);
    ClientSend(client, socketID, testSocketManager);
    ASSERT_NOT_THROW_EXCEPTION_2(ClientReceive, client, testSocketManager);
}

uint64_t Network::BoostSockStreamTesting ::ClientConnect(const ClientSharedPtr& client)
{
    uint64_t socketID{ 0 };
    for (auto i = 0; i < sm_ConnectTime; ++i)
    {
        socketID = client->Connect();
        if (socketID != 0u)
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, sm_ConnectTime, "连接服务器失败。");
    }

    return socketID;
}

void Network::BoostSockStreamTesting ::ClientSend(const ClientSharedPtr& client, uint64_t socketID, const TestSocketManagerSharedPtr& testSocketManager)
{
    MessageInterfaceSharedPtr message{ make_shared<NullMessage>(GetMessageID()) };
    client->AsyncSend(socketID, message);
    client->ImmediatelyAsyncSend(socketID);

    for (auto i = 0; i < sm_SendTime; ++i)
    {
        if (0 < testSocketManager->GetAsyncSendCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, sm_SendTime);
    }
}

void Network::BoostSockStreamTesting ::ClientReceive(const ClientSharedPtr& client, const TestSocketManagerSharedPtr& testSocketManager)
{
    client->AsyncReceive();

    for (auto i = 0; i < sm_AsynchronousReceiveTime; ++i)
    {
        if (0 < testSocketManager->GetAsyncReceiveCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, sm_AsynchronousReceiveTime);
    }
}

void Network::BoostSockStreamTesting ::ClientNoSendThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoClientNoSendThread);
}

void Network::BoostSockStreamTesting ::DoClientNoSendThread()
{
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    ClientSharedPtr client{ make_shared<Client>(configurationStrategy, testSocketManager) };

    auto socketID = ClientConnect(client);
    ASSERT_LESS(0, socketID);
}

void Network::BoostSockStreamTesting ::ServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoServerThread);
}

void Network::BoostSockStreamTesting ::DoServerThread()
{
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    ServerSharedPtr server{ make_shared<Server>(testSocketManager, configurationStrategy) };

    testSocketManager->SetServerWeakPtr(server);

    for (auto i = 0; i < sm_ReceiveTime; ++i)
    {
        [[maybe_unused]] auto value = server->RunServer();

        if (0 < testSocketManager->GetAsyncSendCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, sm_ReceiveTime);
    }
}

void Network::BoostSockStreamTesting ::ServerNoReceiveThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoServerNoReceiveThread);
}

void Network::BoostSockStreamTesting ::DoServerNoReceiveThread()
{
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    ServerSharedPtr server{ make_shared<Server>(testSocketManager, configurationStrategy) };

    testSocketManager->SetServerWeakPtr(server);

    for (auto i = 0; i < sm_AcceptTime; ++i)
    {
        [[maybe_unused]] auto value = server->RunServer();

        if (0 < testSocketManager->GetAsyncAcceptorCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, sm_AcceptTime);
    }
}

void Network::BoostSockStreamTesting ::CreateMessage()
{
    MESSAGE_MANAGER_SINGLETON.Insert(GetMessageID(), MessageTypeCondition{}, NullMessage::Factory);
}

void Network::BoostSockStreamTesting ::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(GetMessageID());
}

Network::MessageBufferSharedPtr Network::BoostSockStreamTesting ::CreateMessageBuffer() const
{
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy()) };

    auto initialBuffered = messageBuffer->GetInitialBufferedPtr();

    auto messageID = GetMessageID();

    auto messageLength = reinterpret_cast<int32_t*>(initialBuffered);
    // 长度等于消息头长度加上消息ID和子消息ID长度。
    *messageLength = MessageInterface::GetMessageHeadSize() + CORE_TOOLS_STREAM_SIZE(messageID) * 2;

    initialBuffered += CORE_TOOLS_STREAM_SIZE(*messageLength);
    auto fullVersion = reinterpret_cast<int32_t*>(initialBuffered);
    *fullVersion = MESSAGE_MANAGER_SINGLETON.GetFullVersion();

    initialBuffered += CORE_TOOLS_STREAM_SIZE(*fullVersion);
    auto timeInMicroseconds = reinterpret_cast<int64_t*>(initialBuffered);
    *timeInMicroseconds = System::GetTimeInMicroseconds();

    initialBuffered += CORE_TOOLS_STREAM_SIZE(*timeInMicroseconds);
    auto messageNumber = reinterpret_cast<int64_t*>(initialBuffered);
    *messageNumber = messageID;

    messageBuffer->AddCurrentWriteIndex(*messageLength);

    return messageBuffer;
}

void Network::BoostSockStreamTesting ::VerificationMessageBuffer(const MessageBufferSharedPtr& messageBuffer)
{
    auto initialBuffered = messageBuffer->GetInitialBufferedPtr();

    auto messageID = GetMessageID();

    auto messageLength = reinterpret_cast<int32_t*>(initialBuffered);
    // 长度等于消息头长度加上消息ID和子消息ID长度。
    auto verificationMessageLength = MessageInterface::GetMessageHeadSize() + CORE_TOOLS_STREAM_SIZE(messageID) * 2;
    ASSERT_EQUAL(*messageLength, verificationMessageLength);

    initialBuffered += CORE_TOOLS_STREAM_SIZE(*messageLength);
    auto fullVersion = reinterpret_cast<int32_t*>(initialBuffered);
    ASSERT_EQUAL(*fullVersion, MESSAGE_MANAGER_SINGLETON.GetFullVersion());

    initialBuffered += CORE_TOOLS_STREAM_SIZE(*fullVersion);
    auto timeInMicroseconds = reinterpret_cast<int64_t*>(initialBuffered);
    ASSERT_LESS_EQUAL(*timeInMicroseconds, System::GetTimeInMicroseconds());

    initialBuffered += CORE_TOOLS_STREAM_SIZE(*timeInMicroseconds);
    auto messageNumber = reinterpret_cast<int64_t*>(initialBuffered);
    ASSERT_EQUAL(*messageNumber, messageID);
}
