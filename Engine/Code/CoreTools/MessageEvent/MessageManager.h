//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/26 15:25)

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
        using SubclassSmartPointerType = typename EventSlot::SubclassSmartPointerType;
        using CallbackMemberFunction = typename EventSlot::CallbackMemberFunction;
        using EventSlotPriorityType = typename EventSlot::EventSlotPriorityType;
        using MessageManagerEventType = EventType;
        using EventSlotManagerType = EventSlotManager<EventSlot>;

    public:
        MessageManager();
        virtual ~MessageManager() = default;

        MessageManager(const MessageManager& rhs) = default;
        MessageManager& operator=(const MessageManager& rhs) = default;
        MessageManager(MessageManager&& rhs) = default;
        MessageManager& operator=(MessageManager&& rhs) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        [[nodiscard]] uint64_t Registered(MessageManagerEventType eventType, const SubclassSmartPointerType& smartPointer, EventSlotPriorityType priority, CallbackMemberFunction callbackMemberFunction);
        void Unregistered(MessageManagerEventType eventType, uint64_t index);
        void CallEvent(MessageManagerEventType eventType, const CallbackParameters& callbackParameters);
        void DelayCallEvent(MessageManagerEventType eventType, const CallbackParameters& callbackParameters, uint32_t delayTime);

        // �����Ļص�˳��ʱ������������ȼ��������ԡ�
        void CallEventUnordered(MessageManagerEventType eventType, const CallbackParameters& callbackParameters);
        void DelayCallEventUnordered(MessageManagerEventType eventType, const CallbackParameters& callbackParameters, uint32_t delayTime);

        void DispatchDelayEvent(uint64_t currentTime);

    private:
        using EventContainer = std::map<MessageManagerEventType, EventSlotManagerType>;

    private:
        EventContainer m_EventContainer;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_H
