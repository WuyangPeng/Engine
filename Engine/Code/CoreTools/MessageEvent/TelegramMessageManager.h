/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:21)

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

        using TelegramType = Telegram<EventType>;
        using TelegramLessType = TelegramLess<EventType>;

    public:
        explicit TelegramMessageManager(int64_t difference);
        virtual ~TelegramMessageManager() noexcept = default;

        TelegramMessageManager(const TelegramMessageManager& rhs) = default;
        TelegramMessageManager& operator=(const TelegramMessageManager& rhs) = default;
        TelegramMessageManager(TelegramMessageManager&& rhs) noexcept = default;
        TelegramMessageManager& operator=(TelegramMessageManager&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void CallEvent(const TelegramType& telegram);
        void CallEventImmediately(int64_t currentTime, const TelegramType& telegram);

        void DispatchDelayEvent(int64_t currentTime);

        NODISCARD bool RegisterAllEvent(int64_t entityId);
        NODISCARD bool UnRegisterAllEvent(int64_t entityId) noexcept;

        NODISCARD bool Register(EventType eventType, int64_t entityId);
        NODISCARD bool UnRegister(EventType eventType, int64_t entityId);

    private:
        using EventContainer = std::set<TelegramType, TelegramLessType>;
        using RegisterContainer = std::set<int64_t>;
        using EventRegisterContainer = std::map<EventType, RegisterContainer>;
        using EventEntityType = EventEntity<EventType>;
        using EventEntityPtr = std::shared_ptr<EventEntityType>;

    private:
        void DisposeEvent(const TelegramType& telegram);
        void DisposeAllEvent(const TelegramType& telegram);
        void DisposeEvent(int64_t entityId, const TelegramType& telegram);

    private:
        TelegramLessType telegramLess;
        EventContainer eventContainer;
        RegisterContainer registerContainer;
        EventRegisterContainer eventRegisterContainer;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_MESSAGE_MANAGER_H
