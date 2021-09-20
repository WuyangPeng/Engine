//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 15:32)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_MESSAGE_MANAGER_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_MESSAGE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "EventEntity.h"
#include "EventSlotManager.h"
#include "MessageEventFwd.h"
#include "TelegramLess.h"

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
        virtual ~TelegramMessageManager() = default;

        TelegramMessageManager(const TelegramMessageManager& rhs) = default;
        TelegramMessageManager& operator=(const TelegramMessageManager& rhs) = default;
        TelegramMessageManager(TelegramMessageManager&& rhs) = default;
        TelegramMessageManager& operator=(TelegramMessageManager&& rhs) = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void CallEvent(const Telegram& telegram);
        void CallEventImmediately(int64_t currentTime, const Telegram& telegram);

        void DispatchDelayEvent(int64_t currentTime);

        [[nodiscard]] bool RegisterAllEvent(uint64_t entityID);
        [[nodiscard]] bool UnregisterAllEvent(uint64_t entityID);

        [[nodiscard]] bool Register(EventType eventType, uint64_t entityID);
        [[nodiscard]] bool Unregister(EventType eventType, uint64_t entityID);

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

#endif  // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_MESSAGE_MANAGER_H
