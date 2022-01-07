///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/26 18:17)

#ifndef CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_H
#define CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"

#include <map>
#include <vector>

namespace CoreTools
{
    template <typename EventSlot>
    class EventSlotManager final
    {
    public:
        using ClassType = EventSlotManager<EventSlot>;
        using SubclassSharedPtr = typename EventSlot::SubclassSharedPtr;
        using CallbackMemberFunction = typename EventSlot::CallbackMemberFunction;
        using EventSlotPriorityType = typename EventSlot::EventSlotPriorityType;

    public:
        EventSlotManager() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint64_t Registered(const SubclassSharedPtr& subclass, EventSlotPriorityType priority, CallbackMemberFunction callbackMemberFunction);
        void Unregistered(uint64_t index);
        void CallEvent(const CallbackParameters& callbackParameters);
        void DelayCallEvent(const CallbackParameters& callbackParameters, uint32_t delayTime);

        // 不关心回调顺序时调用这个，优先级将被忽略。
        void CallEventUnordered(const CallbackParameters& callbackParameters);
        void DelayCallEventUnordered(const CallbackParameters& callbackParameters, uint32_t delayTime);

        void DispatchDelayEvent(uint64_t currentTime);

    private:
        using EventSlotRelationContainer = std::map<uint64_t, EventSlot>;
        using EventSlotOrderContainer = std::vector<EventSlot>;
        using CallbackParametersContainer = std::vector<CallbackParameters>;
        using DelayContainer = std::map<uint32_t, CallbackParametersContainer>;

    private:
        void Reorder();
        void CallEvent(uint64_t currentTime);
        void CallEventUnordered(uint64_t currentTime);

    private:
        EventSlotRelationContainer eventSlotRelationContainer;
        EventSlotOrderContainer eventSlotOrderContainer;
        uint64_t uniqueIndex;
        bool isChange;
        DelayContainer unorderedDelayContainer;
        DelayContainer relationDelayContainer;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_H
