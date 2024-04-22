/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 15:21)

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
        NODISCARD static bool DoNotCompareTime(const Telegram& lhs, const Telegram& rhs);

    private:
        int64_t difference;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_H
