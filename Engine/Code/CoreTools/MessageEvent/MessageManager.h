// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.1 (2019/06/28 17:51)

#ifndef CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_H
#define CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"
#include "EventSlotManager.h"

#include <map>

namespace CoreTools
{
	class CallbackParameters;

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
		virtual ~MessageManager();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		uint64_t Registered(MessageManagerEventType eventType, const SubclassSmartPointerType& smartPointer, EventSlotPriorityType priority, CallbackMemberFunction callbackMemberFunction);
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
		EventContainer m_EventContainer;
	};
}

#endif // CORE_TOOLS_MESSAGE_EVENT_MESSAGE_MANAGER_H
