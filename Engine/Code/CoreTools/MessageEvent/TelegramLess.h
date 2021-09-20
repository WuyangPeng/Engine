//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/26 15:32)

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

        [[nodiscard]] bool operator()(const Telegram& lhs, const Telegram& rhs) const;

    private:
        [[nodiscard]] bool DonotCompareTime(const Telegram& lhs, const Telegram& rhs) const;

    private:
        int64_t m_Difference;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_H
