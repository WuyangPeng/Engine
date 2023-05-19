///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.8 (2023/05/15 09:05)

#include "TestMessageEvent.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Threading/Flags/MutexFlags.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/Interface/SendSocket.h"
#include "Network/NetworkMessage/NullMessage.h"

Network::TestMessageEvent::TestMessageEvent(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}, callBackTime{ 0 }, testMessageEventCriticalSection{ CoreTools::MutexCreate::UseCriticalSection }, server{}
{
    System::UnusedFunction(disableNotThrow);

    testMessageEventCriticalSection.Initialize();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::TestMessageEvent::~TestMessageEvent() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    testMessageEventCriticalSection.Delete();
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestMessageEvent);

int64_t Network::TestMessageEvent::GetCallBackTime() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return callBackTime;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::TestMessageEvent::CallBackEvent(int64_t socketId, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::ScopedMutex scopedMutex{ testMessageEventCriticalSection };

    callBackTime += message->GetMessageId();

    if (const auto serverSharedPtr = server.lock();
        serverSharedPtr)
    {
        const MessageInterfaceSharedPtr sendMessage{ std::make_shared<NullMessage>(MessageHeadStrategy::Default, message->GetMessageId()) };
        serverSharedPtr->Send(socketId, sendMessage);
    }
}

#include STSTEM_WARNING_POP

void Network::TestMessageEvent::SetServerWeakPtr(const ServerSharedPtr& aServer) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    server = aServer;
}
