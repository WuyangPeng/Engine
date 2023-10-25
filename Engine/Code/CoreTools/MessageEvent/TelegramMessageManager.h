///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:19)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_MESSAGE_MANAGER_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_MESSAGE_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "EventEntity.h"
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
        virtual ~TelegramMessageManager() noexcept = default;

        TelegramMessageManager(const TelegramMessageManager& rhs) = default;
        TelegramMessageManager& operator=(const TelegramMessageManager& rhs) = default;
        TelegramMessageManager(TelegramMessageManager&& rhs) noexcept = default;
        TelegramMessageManager& operator=(TelegramMessageManager&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void CallEvent(const Telegram& telegram);
        void CallEventImmediately(int64_t currentTime, const Telegram& telegram);

        void DispatchDelayEvent(int64_t currentTime);

        NODISCARD bool RegisterAllEvent(int64_t entityId);
        NODISCARD bool UnRegisterAllEvent(int64_t entityId);

        NODISCARD bool Register(EventType eventType, int64_t entityId);
        NODISCARD bool UnRegister(EventType eventType, int64_t entityId);

    private:
        using EventContainer = std::set<Telegram, TelegramLess>;
        using RegisterContainer = std::set<int64_t>;
        using EventRegisterContainer = std::map<EventType, RegisterContainer>;
        using EventEntity = EventEntity<EventType>;
        using EventEntityPtr = std::shared_ptr<EventEntity>;

    private:
        void DisposeEvent(const Telegram& telegram);
        void DisposeAllEvent(const Telegram& telegram);
        void DisposeEvent(int64_t entityId, const Telegram& telegram);

    private:
        TelegramLess telegramLess;
        EventContainer eventContainer;
        RegisterContainer registerContainer;
        EventRegisterContainer eventRegisterContainer;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_MESSAGE_MANAGER_H
