///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/29 13:38)

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

        // �����Ļص�˳��ʱ������������ȼ��������ԡ�
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
