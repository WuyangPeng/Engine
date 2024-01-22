/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:47)

#ifndef CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_DETAIL_H

#include "MessageManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename EventSlot, typename EventType>
CoreTools::MessageManager<EventSlot, EventType>::MessageManager() noexcept
    : eventContainer{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename EventSlot, typename EventType>
bool CoreTools::MessageManager<EventSlot, EventType>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename EventSlot, typename EventType>
int64_t CoreTools::MessageManager<EventSlot, EventType>::Registered(MessageManagerEventType eventType, const SubclassSharedPtr& subclass, EventSlotPriorityType priority, CallbackMemberFunction callbackMemberFunction)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return eventContainer[eventType].Registered(subclass, priority, callbackMemberFunction);
}

template <typename EventSlot, typename EventType>
void CoreTools::MessageManager<EventSlot, EventType>::Unregistered(MessageManagerEventType eventType, int64_t index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return eventContainer[eventType].Unregistered(index);
}

template <typename EventSlot, typename EventType>
void CoreTools::MessageManager<EventSlot, EventType>::CallEvent(MessageManagerEventType eventType, const CallbackParameters& callbackParameters)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return eventContainer[eventType].CallEvent(callbackParameters);
}

template <typename EventSlot, typename EventType>
void CoreTools::MessageManager<EventSlot, EventType>::CallEventUnordered(MessageManagerEventType eventType, const CallbackParameters& callbackParameters)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return eventContainer[eventType].CallEventUnordered(callbackParameters);
}

template <typename EventSlot, typename EventType>
void CoreTools::MessageManager<EventSlot, EventType>::DelayCallEvent(MessageManagerEventType eventType, const CallbackParameters& callbackParameters, int32_t delayTime)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return eventContainer[eventType].DelayCallEvent(callbackParameters, delayTime);
}

template <typename EventSlot, typename EventType>
void CoreTools::MessageManager<EventSlot, EventType>::DelayCallEventUnordered(MessageManagerEventType eventType, const CallbackParameters& callbackParameters, int32_t delayTime)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return eventContainer[eventType].DelayCallEventUnordered(callbackParameters, delayTime);
}

template <typename EventSlot, typename EventType>
void CoreTools::MessageManager<EventSlot, EventType>::DispatchDelayEvent(int64_t currentTime)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto& event : eventContainer)
    {
        event.second.DispatchDelayEvent(currentTime);
    }
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_DETAIL_H