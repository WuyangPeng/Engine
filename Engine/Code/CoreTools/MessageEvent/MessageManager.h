///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/26 18:18)

#ifndef CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_H
#define CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "EventSlotManager.h"
#include "MessageEventFwd.h"

#include <map>

namespace CoreTools
{
    template <typename EventSlot, typename EventType = int>
    class MessageManager
    {
    public:
        using ClassType = MessageManager<EventSlot, EventType>;
        using SubclassSharedPtr = typename EventSlot::SubclassSharedPtr;
        using CallbackMemberFunction = typename EventSlot::CallbackMemberFunction;
        using EventSlotPriorityType = typename EventSlot::EventSlotPriorityType;
        using MessageManagerEventType = EventType;
        using EventSlotManagerType = EventSlotManager<EventSlot>;

    public:
        MessageManager() noexcept;
        virtual ~MessageManager() noexcept = default;

        MessageManager(const MessageManager& rhs) = default;
        MessageManager& operator=(const MessageManager& rhs) = default;
        MessageManager(MessageManager&& rhs) noexcept = default;
        MessageManager& operator=(MessageManager&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD uint64_t Registered(MessageManagerEventType eventType, const SubclassSharedPtr& subclass, EventSlotPriorityType priority, CallbackMemberFunction callbackMemberFunction);
        void Unregistered(MessageManagerEventType eventType, uint64_t index);
        void CallEvent(MessageManagerEventType eventType, const CallbackParameters& callbackParameters);
        void DelayCallEvent(MessageManagerEventType eventType, const CallbackParameters& callbackParameters, uint32_t delayTime);

        // 不关心回调顺序时调用这个，优先级将被忽略。
        void CallEventUnordered(MessageManagerEventType eventType, const CallbackParameters& callbackParameters);
        void DelayCallEventUnordered(MessageManagerEventType eventType, const CallbackParameters& callbackParameters, uint32_t delayTime);

        void DispatchDelayEvent(uint64_t currentTime);

    private:
        using EventContainer = std::map<MessageManagerEventType, EventSlotManagerType>;

    private:
        EventContainer eventContainer;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_H
