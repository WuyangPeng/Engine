// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 17:04)

#ifndef CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_H
#define CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"

#include <map>
#include <vector>

namespace CoreTools
{
	template <typename EventSlot>
	class EventSlotManager
	{
	public:
		using ClassType = EventSlotManager<EventSlot>;
		using SubclassSmartPointerType = typename EventSlot::SubclassSmartPointerType;
		using CallbackMemberFunction = typename EventSlot::CallbackMemberFunction;
		using EventSlotPriorityType = typename EventSlot::EventSlotPriorityType;

	public:
		EventSlotManager();

		CLASS_INVARIANT_DECLARE;

		uint64_t Registered(const SubclassSmartPointerType& smartPointer, EventSlotPriorityType priority, CallbackMemberFunction callbackMemberFunction);
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

	private:
		EventSlotRelationContainer m_EventSlotRelationContainer;
		EventSlotOrderContainer m_EventSlotOrderContainer;
		uint64_t m_Index;
		bool m_IsChange;
		DelayContainer m_UnorderedDelayContainer;
		DelayContainer m_RelationDelayContainer;
	};
}

#endif // CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_H
