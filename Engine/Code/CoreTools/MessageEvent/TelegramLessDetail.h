// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:08)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_DETAIL_H

#include "CoreTools/CoreToolsExport.h"

#include "TelegramLess.h" 
#include "Telegram.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

template <typename EventType>
CoreTools::TelegramLess<EventType>
	::TelegramLess(int64_t difference)
	:m_Difference{ difference < 0 ? -difference : difference }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename EventType>
bool CoreTools::TelegramLess<EventType>
	::IsValid() const noexcept
{
	if (0 <= m_Difference)
		return true;
	else
		return false;
}
#endif // #ifdef OPEN_CLASS_INVARIANT

template <typename EventType>
bool CoreTools::TelegramLess<EventType>
	::operator()(const Telegram& lhs, const Telegram& rhs) const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	auto lhsDispatchMillisecondTime = lhs.GetDispatchMillisecondTime();
	auto rhsDispatchMillisecondTime = rhs.GetDispatchMillisecondTime();
	auto difference = lhsDispatchMillisecondTime - rhsDispatchMillisecondTime;

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
bool CoreTools::TelegramLess<EventType>
	::DonotCompareTime(const Telegram& lhs, const Telegram& rhs) const
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

#endif // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_DETAIL_H