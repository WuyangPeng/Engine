/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:47)

#ifndef CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_DETAIL_H

#include "EventSlotManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"

#include <algorithm>

template <typename EventSlot>
CoreTools::EventSlotManager<EventSlot>::EventSlotManager() noexcept
    : eventSlotRelationContainer{}, eventSlotOrderContainer{}, uniqueIndex{ 0 }, isChange{ false }, unorderedDelayContainer{}, relationDelayContainer{}
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename EventSlot>
bool CoreTools::EventSlotManager<EventSlot>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename EventSlot>
int64_t CoreTools::EventSlotManager<EventSlot>::Registered(const SubclassSharedPtr& subclass, EventSlotPriorityType priority, CallbackMemberFunction callbackMemberFunction)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    EventSlot eventSlot{ subclass, priority, callbackMemberFunction };

    eventSlotRelationContainer.insert({ ++uniqueIndex, eventSlot });

    isChange = true;

    return uniqueIndex;
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>::Unregistered(int64_t index)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    if (eventSlotRelationContainer.erase(index) == 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("事件不存在。"s));
    }
    else
    {
        isChange = true;
    }
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>::CallEvent(const CallbackParameters& callbackParameters)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    Reorder();

    for_each(eventSlotOrderContainer.begin(), eventSlotOrderContainer.end(), [callbackParameters](auto& slot) {
        EXCEPTION_TRY
        {
            const auto result = slot(callbackParameters);
            if (!result)
            {
                LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("CallEvent 失败"));
            }
        }
        EXCEPTION_ENGINE_EXCEPTION_CATCH(CoreTools);
    });
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>::Reorder()
{
    if (isChange)
    {
        eventSlotOrderContainer.clear();

        for (const auto& value : eventSlotRelationContainer)
        {
            eventSlotOrderContainer.emplace_back(value.second);
        }

        sort(eventSlotOrderContainer.begin(), eventSlotOrderContainer.end());

        isChange = false;
    }
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>::CallEventUnordered(const CallbackParameters& callbackParameters)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    for (auto& slot : eventSlotRelationContainer)
    {
        const auto result = (slot.second)(callbackParameters);
        if (!result)
        {
            LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools, SYSTEM_TEXT("CallEvent 失败"));
        }
    }
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>::DelayCallEventUnordered(const CallbackParameters& callbackParameters, int32_t delayTime)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    unorderedDelayContainer[delayTime].emplace_back(callbackParameters);
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>::DelayCallEvent(const CallbackParameters& callbackParameters, int32_t delayTime)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    relationDelayContainer[delayTime].emplace_back(callbackParameters);
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>::DispatchDelayEvent(int64_t currentTime)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    CallEventUnordered(currentTime);
    CallEvent(currentTime);
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>::CallEvent(int64_t currentTime)
{
    for (auto iter = relationDelayContainer.begin(); iter != relationDelayContainer.end();)
    {
        if (iter->first <= currentTime)
        {
            for (const auto& callbackParameters : iter->second)
            {
                CallEvent(callbackParameters);
            }

            relationDelayContainer.erase(iter++);
        }
        else
        {
            break;
        }
    }
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>::CallEventUnordered(int64_t currentTime)
{
    for (auto iter = unorderedDelayContainer.begin(); iter != unorderedDelayContainer.end();)
    {
        if (iter->first <= currentTime)
        {
            for (const auto& callbackParameters : iter->second)
            {
                CallEventUnordered(callbackParameters);
            }

            unorderedDelayContainer.erase(iter++);
        }
        else
        {
            break;
        }
    }
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_DETAIL_H