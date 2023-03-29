///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.4 (2023/03/29 13:39)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_H

#include "CoreTools/CoreToolsDll.h"

#include "MessageEventFwd.h"

namespace CoreTools
{
    template <typename EventType>
    class TelegramLess final
    {
    public:
        using ClassType = TelegramLess<EventType>;
        using Telegram = Telegram<EventType>;

    public:
        explicit TelegramLess(int64_t difference) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool operator()(const Telegram& lhs, const Telegram& rhs) const;

    private:
        NODISCARD bool DoNotCompareTime(const Telegram& lhs, const Telegram& rhs) const;

    private:
        int64_t difference;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_H
