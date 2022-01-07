///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/26 0:15)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_DETAIL_H

#include "CoreTools/CoreToolsExport.h"

#include "Telegram.h"
#include "TelegramLess.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename EventType>
CoreTools::TelegramLess<EventType>::TelegramLess(int64_t difference) noexcept
    : m_Difference{ difference < 0 ? -difference : difference }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename EventType>
bool CoreTools::TelegramLess<EventType>::IsValid() const noexcept
{
    if (0 <= m_Difference)
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
    const auto difference = lhsDispatchMillisecondTime - rhsDispatchMillisecondTime;

    if (-m_Difference <= difference && difference <= m_Difference)
    {
        return DonotCompareTime(lhs, rhs);
    }
    else
    {
        if (lhsDispatchMillisecondTime < rhsDispatchMillisecondTime)
            return true;
        else if (rhsDispatchMillisecondTime < lhsDispatchMillisecondTime)
            return false;
        else
            return DonotCompareTime(lhs, rhs);
    }
}

template <typename EventType>
bool CoreTools::TelegramLess<EventType>::DonotCompareTime(const Telegram& lhs, const Telegram& rhs) const
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