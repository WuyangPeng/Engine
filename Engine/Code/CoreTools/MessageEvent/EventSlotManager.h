//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/26 15:24)

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
        using SubclassSmartPointerType = typename EventSlot::SubclassSmartPointerType;
        using CallbackMemberFunction = typename EventSlot::CallbackMemberFunction;
        using EventSlotPriorityType = typename EventSlot::EventSlotPriorityType;

    public:
        EventSlotManager();

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] uint64_t Registered(const SubclassSmartPointerType& smartPointer, EventSlotPriorityType priority, CallbackMemberFunction callbackMemberFunction);
        void Unregistered(uint64_t index);
        void CallEvent(const CallbackParameters& callbackParameters);
        void DelayCallEvent(const CallbackParameters& callbackParameters, uint32_t delayTime);

        // �����Ļص�˳��ʱ������������ȼ��������ԡ�
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

    private:
        EventSlotRelationContainer m_EventSlotRelationContainer;
        EventSlotOrderContainer m_EventSlotOrderContainer;
        uint64_t m_Index;
        bool m_IsChange;
        DelayContainer m_UnorderedDelayContainer;
        DelayContainer m_RelationDelayContainer;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_H
