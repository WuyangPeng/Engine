//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:41)

#ifndef CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_DETAIL_H

#include "MessageManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"

#include <vector>

template <typename EventSlot, typename EventType>
CoreTools::MessageManager<EventSlot, EventType>::MessageManager()
    : m_EventContainer{}
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
uint64_t CoreTools::MessageManager<EventSlot, EventType>::Registered(MessageManagerEventType eventType, const SubclassSmartPointerType& smartPointer, EventSlotPriorityType priority, CallbackMemberFunction callbackMemberFunction)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_EventContainer[eventType].Registered(smartPointer, priority, callbackMemberFunction);
}

template <typename EventSlot, typename EventType>
void CoreTools::MessageManager<EventSlot, EventType>::Unregistered(MessageManagerEventType eventType, uint64_t index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_EventContainer[eventType].Unregistered(index);
}

template <typename EventSlot, typename EventType>
void CoreTools::MessageManager<EventSlot, EventType>::CallEvent(MessageManagerEventType eventType, const CallbackParameters& callbackParameters)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_EventContainer[eventType].CallEvent(callbackParameters);
}

template <typename EventSlot, typename EventType>
void CoreTools::MessageManager<EventSlot, EventType>::CallEventUnordered(MessageManagerEventType eventType, const CallbackParameters& callbackParameters)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_EventContainer[eventType].CallEventUnordered(callbackParameters);
}

template <typename EventSlot, typename EventType>
void CoreTools::MessageManager<EventSlot, EventType>::DelayCallEvent(MessageManagerEventType eventType, const CallbackParameters& callbackParameters, uint32_t delayTime)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_EventContainer[eventType].DelayCallEvent(callbackParameters, delayTime);
}

template <typename EventSlot, typename EventType>
void CoreTools::MessageManager<EventSlot, EventType>::DelayCallEventUnordered(MessageManagerEventType eventType, const CallbackParameters& callbackParameters, uint32_t delayTime)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    return m_EventContainer[eventType].DelayCallEventUnordered(callbackParameters, delayTime);
}

template <typename EventSlot, typename EventType>
void CoreTools::MessageManager<EventSlot, EventType>::DispatchDelayEvent(uint64_t currentTime)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto& event : m_EventContainer)
    {
        event.second.DispatchDelayEvent(currentTime);
    }
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_DETAIL_H