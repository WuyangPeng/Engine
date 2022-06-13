///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 14:11)

#include "TestSocketManager.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"

using std::make_shared;

Network::TestSocketManagerSharedPtr Network::TestSocketManager::Create(uint32_t messageID)
{
    return make_shared<ClassType>(messageID);
}

Network::TestSocketManager::TestSocketManager(uint32_t messageID)
    : ParentType{ CoreTools::DisableNotThrow::Disable },
      messageID{ messageID },
      testMessageEvent(make_shared<TestMessageEvent>(CoreTools::DisableNotThrow::Disable)),
      asyncConnectCount{ 0 },
      asyncAcceptorCount{ 0 },
      asyncReceiveCount{ 0 },
      asyncSendCount{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestSocketManager);

void Network::TestSocketManager::InitEvent(uint64_t socketID)
{
    InsertEvent(socketID, messageID, testMessageEvent);
}

uint64_t Network::TestSocketManager::GetCallBackTime() const noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return testMessageEvent->GetCallBackTime();
}

bool Network::TestSocketManager::EventFunction(const CoreTools::CallbackParameters& callbackParameters)
{
    NETWORK_CLASS_IS_VALID_9;

    auto eventType = System::UnderlyingCastEnum<SocketManagerEvent>(callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPoisition::Event)));

    switch (eventType)
    {
        case Network::SocketManagerEvent::AsyncConnect:
        {
            ++asyncConnectCount;
            return true;
        }
        case Network::SocketManagerEvent::AsyncAcceptor:
        {
            ++asyncAcceptorCount;
            return true;
        }
        break;
        case Network::SocketManagerEvent::AsyncReceive:
        {
            ++asyncReceiveCount;
            return true;
        }
        break;
        case Network::SocketManagerEvent::AsyncSend:
        {
            ++asyncSendCount;
            return true;
        }
        default:
            break;
    }

    return false;
}

int Network::TestSocketManager::GetAsyncConnectCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return asyncConnectCount;
}

void Network::TestSocketManager::SetServerWeakPtr(const ServerSharedPtr& ptr) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    testMessageEvent->SetServerWeakPtr(ptr);
}

int Network::TestSocketManager::GetAsyncReceiveCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return asyncReceiveCount;
}

int Network::TestSocketManager::GetAsyncAcceptorCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return asyncAcceptorCount;
}

int Network::TestSocketManager::GetAsyncSendCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return asyncSendCount;
}
