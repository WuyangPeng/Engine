// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:06)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_MESSAGE_MANAGER_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_MESSAGE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "EventEntity.h"
#include "TelegramLess.h"
#include "EventSlotManager.h"
#include "MessageEventFwd.h"

#include <map>
#include <set>

namespace CoreTools
{
	template <typename EventType = int>
	class TelegramMessageManager
	{
	public:
		using ClassType = TelegramMessageManager<EventType>;
		using Telegram = Telegram<EventType>;
		using TelegramLess = TelegramLess<EventType>;

	public:
		explicit TelegramMessageManager(int64_t difference);
		virtual ~TelegramMessageManager();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void CallEvent(const Telegram& telegram);
		void CallEventImmediately(int64_t currentTime, const Telegram& telegram);

		void DispatchDelayEvent(int64_t currentTime);

		bool RegisterAllEvent(uint64_t entityID);
		bool UnregisterAllEvent(uint64_t entityID);

		bool Register(EventType eventType, uint64_t entityID);
		bool Unregister(EventType eventType, uint64_t entityID);

	private:
		using EventContainer = std::set<Telegram, TelegramLess>;
		using RegisterContainer = std::set<uint64_t>;
		using EventRegisterContainer = std::map<EventType, RegisterContainer>;
		using EventEntity = EventEntity<EventType>;
		using EventEntityPtr = std::shared_ptr<EventEntity>;

	private:
		void DisposeEvent(const Telegram& telegram);
		void DisposeAllEvent(const Telegram& telegram);
		void DisposeEvent(uint64_t entityID, const Telegram& telegram);

	private:
		TelegramLess m_TelegramLess;
		EventContainer m_EventContainer;
		RegisterContainer m_RegisterContainer;
		EventRegisterContainer m_EventRegisterContainer;
	};
}

#endif // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_MESSAGE_MANAGER_H
