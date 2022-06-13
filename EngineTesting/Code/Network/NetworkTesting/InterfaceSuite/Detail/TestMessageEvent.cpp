///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/24 14:04)

#include "TestMessageEvent.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Threading/Flags/MutexFlags.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "Network/Interface/SendSocket.h"
#include "Network/NetworkMessage/NullMessage.h"

using std::make_shared;

Network::TestMessageEvent::TestMessageEvent(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}, callBackTime{ 0 }, testMessageEventCriticalSection{ CoreTools::MutexCreate::UseCriticalSection }, serverWeakPtr{}
{
    testMessageEventCriticalSection.Initialize();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::TestMessageEvent::~TestMessageEvent() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    testMessageEventCriticalSection.Delete();
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, TestMessageEvent);

uint64_t Network::TestMessageEvent::GetCallBackTime() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return callBackTime;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::TestMessageEvent::CallBackEvent(MAYBE_UNUSED uint64_t socketID, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    CoreTools::ScopedMutex scopedMutex{ testMessageEventCriticalSection };

    callBackTime += message->GetMessageID();

    auto serverSharedPtr = serverWeakPtr.lock();

    if (serverSharedPtr)
    {
        MessageInterfaceSharedPtr sendMessage{ make_shared<NullMessage>(message->GetMessageID()) };
        serverSharedPtr->AsyncSend(socketID, sendMessage);
    }
}

#include STSTEM_WARNING_POP

void Network::TestMessageEvent::SetServerWeakPtr(const ServerSharedPtr& ptr) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    serverWeakPtr = ptr;
}
