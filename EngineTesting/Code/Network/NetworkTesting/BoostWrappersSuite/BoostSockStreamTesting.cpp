///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/25 14:00)

#include "BoostSockStreamTesting.h"
#include "System/Time/DeltaTime.h"
#include "CoreTools/Base/Version.h"
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
#include "Network/NetworkTesting/InterfaceSuite/Detail/TestSocketManager.h"
using std::make_shared;

Network::BoostSockStreamTesting::BoostSockStreamTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    SELF_CLASS_IS_VALID_1;
}
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockStreamTesting)

void Network::BoostSockStreamTesting::ClientThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoClientThread);
}

void Network::BoostSockStreamTesting::DoClientThread()
{
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };

    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    ClientSharedPtr client{ make_shared<Client>(configurationStrategy, std::make_shared<MessageEventManager>(MessageEventManager::Create())) };

    const auto socketID = ClientConnect(client);
    ClientSend(client, socketID, testSocketManager);
    ASSERT_NOT_THROW_EXCEPTION_2(ClientReceive, client, testSocketManager);
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

uint64_t Network::BoostSockStreamTesting::ClientConnect(const ClientSharedPtr& client)
{
    uint64_t socketID{ 0 };
    for (auto i = 0; i < connectTime; ++i)
    {
        socketID = client->Connect();
        if (socketID != 0u)
        {
            break;
        }

        ASSERT_UNEQUAL_FAILURE_THROW(i + 1, connectTime, "连接服务器失败。");
    }

    return socketID;
}

void Network::BoostSockStreamTesting::ClientSend(const ClientSharedPtr& client, uint64_t socketID, const TestSocketManagerSharedPtr& testSocketManager)
{
    MessageInterfaceSharedPtr message{ make_shared<NullMessage>(MessageHeadStrategy::Default, GetMessageID()) };
    client->AsyncSend(socketID, message);
    client->ImmediatelyAsyncSend(socketID);

    for (auto i = 0; i < sendTime; ++i)
    {
        if (0 < testSocketManager->GetAsyncSendCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, sendTime);
    }
}

void Network::BoostSockStreamTesting::ClientReceive(const ClientSharedPtr& client, const TestSocketManagerSharedPtr& testSocketManager)
{
    client->AsyncReceive();

    for (auto i = 0; i < asynchronousReceiveTime; ++i)
    {
        if (0 < testSocketManager->GetAsyncReceiveCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, asynchronousReceiveTime);
    }
}

#include STSTEM_WARNING_POP

void Network::BoostSockStreamTesting::ClientNoSendThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoClientNoSendThread);
}

void Network::BoostSockStreamTesting::DoClientNoSendThread()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };
#include STSTEM_WARNING_POP
    auto configurationStrategy = GetBoostClientConfigurationStrategy(GetRealOffset());

    ClientSharedPtr client{ make_shared<Client>(configurationStrategy, std::make_shared<MessageEventManager>(MessageEventManager::Create())) };

    const auto socketID = ClientConnect(client);
    ASSERT_LESS(0, socketID);
}

void Network::BoostSockStreamTesting::ServerThread()
{
    ASSERT_NOT_THROW_EXCEPTION_0(DoServerThread);
}

void Network::BoostSockStreamTesting::DoServerThread()
{
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };
#include STSTEM_WARNING_POP
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    ServerSharedPtr server{ make_shared<Server>(std::make_shared<MessageEventManager>(MessageEventManager::Create()), configurationStrategy) };

    testSocketManager->SetServerWeakPtr(server);

    for (auto i = 0; i < receiveTime; ++i)
    {
        MAYBE_UNUSED const auto value = server->RunServer();

        if (0 < testSocketManager->GetAsyncSendCount())
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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26414)
    TestSocketManagerSharedPtr testSocketManager{ make_shared<TestSocketManager>(GetMessageID()) };
#include STSTEM_WARNING_POP
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    ServerSharedPtr server{ make_shared<Server>(std::make_shared<MessageEventManager>(MessageEventManager::Create()), configurationStrategy) };

    testSocketManager->SetServerWeakPtr(server);

    for (auto i = 0; i < acceptTime; ++i)
    {
        MAYBE_UNUSED const auto value = server->RunServer();

        if (0 < testSocketManager->GetAsyncAcceptorCount())
        {
            break;
        }

        ASSERT_UNEQUAL(i + 1, acceptTime);
    }
}

void Network::BoostSockStreamTesting::CreateMessage()
{
    MESSAGE_MANAGER_SINGLETON.Insert(GetMessageID(), MessageTypeCondition::CreateNullCondition(), NullMessage::Factory);
}

void Network::BoostSockStreamTesting::DestroyMessage()
{
    MESSAGE_MANAGER_SINGLETON.Remove(GetMessageID());
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

Network::MessageBufferSharedPtr Network::BoostSockStreamTesting::CreateMessageBuffer() const
{
    auto configurationStrategy = GetBoostServerConfigurationStrategy(GetRealOffset());

    MessageBufferSharedPtr messageBuffer{ make_shared<MessageBuffer>(BuffBlockSize::Size512, 0, configurationStrategy.GetParserStrategy()) };

    auto initialBuffered = messageBuffer->GetInitialBufferedPtr();

    auto aMessageID = GetMessageID();

    auto messageLength = reinterpret_cast<int32_t*>(initialBuffered);

    if (messageLength == nullptr)
    {
        return messageBuffer;
    }

    // 长度等于消息头长度加上消息ID和子消息ID长度。
    *messageLength = MessageInterface::GetMessageHeadSize() + CoreTools::GetStreamSize(aMessageID) * 2;

    initialBuffered += CoreTools::GetStreamSize(*messageLength);
    auto fullVersion = reinterpret_cast<int32_t*>(initialBuffered);
    if (fullVersion == nullptr)
    {
        return messageBuffer;
    }

    *fullVersion = MESSAGE_MANAGER_SINGLETON.GetFullVersion();

    initialBuffered += CoreTools::GetStreamSize(*fullVersion);
    auto timeInMicroseconds = reinterpret_cast<int64_t*>(initialBuffered);
    if (timeInMicroseconds == nullptr)
    {
        return messageBuffer;
    }
    *timeInMicroseconds = System::GetTimeInMicroseconds();

    initialBuffered += CoreTools::GetStreamSize(*timeInMicroseconds);
    auto messageNumber = reinterpret_cast<int64_t*>(initialBuffered);
    if (messageNumber == nullptr)
    {
        return messageBuffer;
    }
    *messageNumber = aMessageID;

    messageBuffer->AddCurrentWriteIndex(*messageLength);

    return messageBuffer;
}

#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
#include SYSTEM_WARNING_DISABLE(26481)
#include SYSTEM_WARNING_DISABLE(26490)

void Network::BoostSockStreamTesting::VerificationMessageBuffer(const MessageBufferSharedPtr& messageBuffer)
{
    auto initialBuffered = messageBuffer->GetInitialBufferedPtr();

    const auto aMessageID = GetMessageID();

    auto messageLength = reinterpret_cast<const int32_t*>(initialBuffered);
    if (messageLength == nullptr)
    {
        return;
    }

    // 长度等于消息头长度加上消息ID和子消息ID长度。
    const auto verificationMessageLength = MessageInterface::GetMessageHeadSize() + CoreTools::GetStreamSize(aMessageID) * 2;
    ASSERT_EQUAL(*messageLength, verificationMessageLength);

    initialBuffered += CoreTools::GetStreamSize(*messageLength);
    auto fullVersion = reinterpret_cast<const int32_t*>(initialBuffered);
    if (fullVersion == nullptr)
    {
        return;
    }

    ASSERT_EQUAL(*fullVersion, MESSAGE_MANAGER_SINGLETON.GetFullVersion());

    initialBuffered += CoreTools::GetStreamSize(*fullVersion);
    auto timeInMicroseconds = reinterpret_cast<const int64_t*>(initialBuffered);
    if (timeInMicroseconds == nullptr)
    {
        return;
    }
    ASSERT_LESS_EQUAL(*timeInMicroseconds, System::GetTimeInMicroseconds());

    initialBuffered += CoreTools::GetStreamSize(*timeInMicroseconds);
    auto messageNumber = reinterpret_cast<const int64_t*>(initialBuffered);
    if (messageNumber == nullptr)
    {
        return;
    }
    ASSERT_EQUAL(*messageNumber, aMessageID);
}

#include STSTEM_WARNING_POP
