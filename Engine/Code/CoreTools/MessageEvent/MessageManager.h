/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:22)

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

        NODISCARD int64_t Registered(MessageManagerEventType eventType, const SubclassSharedPtr& subclass, EventSlotPriorityType priority, CallbackMemberFunction callbackMemberFunction);
        void Unregistered(MessageManagerEventType eventType, int64_t index);
        void CallEvent(MessageManagerEventType eventType, const CallbackParameters& callbackParameters);
        void DelayCallEvent(MessageManagerEventType eventType, const CallbackParameters& callbackParameters, int32_t delayTime);

        /// 不关心回调顺序时调用这个，优先级将被忽略。
        void CallEventUnordered(MessageManagerEventType eventType, const CallbackParameters& callbackParameters);
        void DelayCallEventUnordered(MessageManagerEventType eventType, const CallbackParameters& callbackParameters, int32_t delayTime);

        void DispatchDelayEvent(int64_t currentTime);

    private:
        using EventContainer = std::map<MessageManagerEventType, EventSlotManagerType>;

    private:
        EventContainer eventContainer;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_H
