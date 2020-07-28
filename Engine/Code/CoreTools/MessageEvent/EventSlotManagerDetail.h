// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 17:07)

#ifndef CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_DETAIL_H

#include "EventSlotManager.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

#include <algorithm>

template <typename EventSlot>
CoreTools::EventSlotManager<EventSlot>
	::EventSlotManager()
	:m_EventSlotRelationContainer{}, m_EventSlotOrderContainer{}, m_Index{ 0 }, m_IsChange{ false },
	 m_UnorderedDelayContainer{}, m_RelationDelayContainer{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename EventSlot>
bool CoreTools::EventSlotManager<EventSlot>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT  

template <typename EventSlot>
uint64_t CoreTools::EventSlotManager<EventSlot>
	::Registered(const SubclassSmartPointerType& smartPointer, EventSlotPriorityType priority, CallbackMemberFunction callbackMemberFunction)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	EventSlot eventSlot{ smartPointer, priority, callbackMemberFunction };

	m_EventSlotRelationContainer.insert({ ++m_Index, eventSlot });

	m_IsChange = true;

	return m_Index;
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>
	::Unregistered(uint64_t index)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	if (m_EventSlotRelationContainer.erase(index) == 0)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("事件不存在。"s));
	}
	else
	{
		m_IsChange = true;
	}
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>
	::CallEvent(const CallbackParameters& callbackParameters)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	Reorder();

	for_each(m_EventSlotOrderContainer.begin(), m_EventSlotOrderContainer.end(), [callbackParameters](auto& slot)
	{
		try
		{
			slot(callbackParameters);
		}
		catch (Error& error)
		{
			LOG_SINGLETON_ENGINE_APPENDER(Error, CoreTools)
				<< error
				<< LOG_SINGLETON_TRIGGER_ASSERT;
		}
	});
}

// private
template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>
::Reorder()
{
	if (m_IsChange)
	{
		m_EventSlotOrderContainer.clear();

		for (const auto& value : m_EventSlotRelationContainer)
		{
			m_EventSlotOrderContainer.push_back(value.second);
		}

		sort(m_EventSlotOrderContainer.begin(), m_EventSlotOrderContainer.end());

		m_IsChange = false;
	}
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>
::CallEventUnordered(const CallbackParameters& callbackParameters)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	for (auto& slot : m_EventSlotRelationContainer)
	{
		(slot.second)(callbackParameters);
	}
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>
::DelayCallEventUnordered(const CallbackParameters& callbackParameters, uint32_t delayTime)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_UnorderedDelayContainer[delayTime].push_back(callbackParameters);
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>
::DelayCallEvent(const CallbackParameters& callbackParameters, uint32_t delayTime)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_RelationDelayContainer[delayTime].push_back(callbackParameters);
}

template <typename EventSlot>
void CoreTools::EventSlotManager<EventSlot>
::DispatchDelayEvent(uint64_t currentTime)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	for (auto iter = m_UnorderedDelayContainer.begin(); iter != m_UnorderedDelayContainer.end();)
	{
		if (iter->first <= currentTime)
		{
			for (const auto& callbackParameters : iter->second)
			{
				CallEventUnordered(callbackParameters);
			}

			m_UnorderedDelayContainer.erase(iter++);
		}
		else
		{
			break;
		}
	}

	for (auto iter = m_RelationDelayContainer.begin(); iter != m_RelationDelayContainer.end();)
	{
		if (iter->first <= currentTime)
		{
			for (const auto& callbackParameters : iter->second)
			{
				CallEvent(callbackParameters);
			}

			m_RelationDelayContainer.erase(iter++);
		}
		else
		{
			break;
		}
	}
}

#endif // CORE_TOOLS_MESSAGE_EVENT_EVENT_SLOT_MANAGER_DETAIL_H