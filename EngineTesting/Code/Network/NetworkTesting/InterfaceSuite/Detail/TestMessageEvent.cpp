///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/16 09:56)

#include "TestMessageEvent.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Threading/Flags/MutexFlags.h"
#include "CoreTools/Threading/ScopedMutex.h"
#include "Network/NetworkMessage/NullMessage.h"

Network::TestMessageEvent::TestMessageEvent(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{}, callBackTime{ 0 }, testMessageEventCriticalSection{ CoreTools::MutexCreate::UseCriticalSection }
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

void Network::TestMessageEvent::CallBackEvent(int64_t socketId, const ConstMessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(message);

    CoreTools::ScopedMutex scopedMutex{ testMessageEventCriticalSection };

    callBackTime += message->GetMessageId();

    System::UnusedFunction(socketId);
}
