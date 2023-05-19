///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/15 09:16)

#include "TestSocketEvent.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/CallbackParameters.h"
#include "Network/NetworkMessage/Flags/MessageEventFlags.h"

Network::TestSocketEventSharedPtr Network::TestSocketEvent::Create()
{
    return std::make_shared<ClassType>();
}

Network::TestSocketEvent::TestSocketEvent() noexcept
    : ParentType{},
      asyncConnectCount{ 0 },
      asyncAcceptorCount{ 0 },
      asyncReceiveCount{ 0 },
      asyncSendCount{ 0 }
{
    NETWORK_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestSocketEvent);

bool Network::TestSocketEvent::EventFunction(const CoreTools::CallbackParameters& callbackParameters)
{
    NETWORK_CLASS_IS_VALID_9;

    switch (const auto eventType = System::UnderlyingCastEnum<SocketManagerEvent>(callbackParameters.GetInt32Value(System::EnumCastUnderlying(SocketManagerPosition::Event)));
            eventType)
    {
        case SocketManagerEvent::AsyncConnect:
        {
            ++asyncConnectCount;
            return true;
        }
        case SocketManagerEvent::AsyncAcceptor:
        {
            ++asyncAcceptorCount;
            return true;
        }
        case SocketManagerEvent::AsyncReceive:
        {
            ++asyncReceiveCount;
            return true;
        }
        case SocketManagerEvent::AsyncSend:
        {
            ++asyncSendCount;
            return true;
        }
        default:
            break;
    }

    return false;
}

int Network::TestSocketEvent::GetAsyncConnectCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return asyncConnectCount;
}

int Network::TestSocketEvent::GetAsyncReceiveCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return asyncReceiveCount;
}

int Network::TestSocketEvent::GetAsyncAcceptorCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return asyncAcceptorCount;
}

int Network::TestSocketEvent::GetAsyncSendCount() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return asyncSendCount;
}
