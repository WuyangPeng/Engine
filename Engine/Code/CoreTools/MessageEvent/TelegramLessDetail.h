///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.4 (2023/03/29 13:47)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_DETAIL_H

#include "CoreTools/CoreToolsExport.h"

#include "Telegram.h"
#include "TelegramLess.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename EventType>
CoreTools::TelegramLess<EventType>::TelegramLess(int64_t difference) noexcept
    : difference{ difference < 0 ? -difference : difference }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename EventType>
bool CoreTools::TelegramLess<EventType>::IsValid() const noexcept
{
    if (0 <= difference)
        return true;
    else
        return false;
}

#endif  // #ifdef OPEN_CLASS_INVARIANT

template <typename EventType>
bool CoreTools::TelegramLess<EventType>::operator()(const Telegram& lhs, const Telegram& rhs) const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

    const auto lhsDispatchMillisecondTime = lhs.GetDispatchMillisecondTime();
    const auto rhsDispatchMillisecondTime = rhs.GetDispatchMillisecondTime();
    const auto differenceTime = lhsDispatchMillisecondTime - rhsDispatchMillisecondTime;

    if (-difference <= differenceTime && differenceTime <= difference)
    {
        return DoNotCompareTime(lhs, rhs);
    }
    else
    {
        if (lhsDispatchMillisecondTime < rhsDispatchMillisecondTime)
            return true;
        else if (rhsDispatchMillisecondTime < lhsDispatchMillisecondTime)
            return false;
        else
            return DoNotCompareTime(lhs, rhs);
    }
}

template <typename EventType>
bool CoreTools::TelegramLess<EventType>::DoNotCompareTime(const Telegram& lhs, const Telegram& rhs) const
{
    if (lhs.GetMessageType() < rhs.GetMessageType())
        return true;
    else if (rhs.GetMessageType() < lhs.GetMessageType())
        return false;
    else if (lhs.GetSender() < rhs.GetSender())
        return true;
    else if (rhs.GetSender() < lhs.GetSender())
        return false;
    else
        return lhs.GetReceiver() < rhs.GetReceiver();
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_DETAIL_H