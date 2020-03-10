// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒıÇæ°æ±¾£º0.0.2.2 (2020/01/22 17:04)

#ifndef CORE_TOOLS_MESSAGE_EVENT_FWD_H
#define CORE_TOOLS_MESSAGE_EVENT_FWD_H

namespace CoreTools
{
	class ParametersInterface;
	class CallbackParameters;
	class EventInterface;

	template <typename T, typename PriorityType>
	class EventSlot;

	template <typename EventSlot>
	class EventSlotManager;

	template <typename EventSlot, typename EventType>
	class MessageManager;

	template <typename EventType>
	class Telegram;

	template <typename EventType>
	class TelegramLess;

	class BaseEntity;

	class EntityManager;

	template <typename EventType>
	class EventEntity;

	template <typename EventType>
	class TelegramMessageManager;
}

#endif // CORE_TOOLS_MESSAGE_EVENT_FWD_H