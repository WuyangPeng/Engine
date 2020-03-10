// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:05)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_H

#include "CoreTools/CoreToolsDll.h"  

namespace CoreTools
{
	template <typename EventType>
	class Telegram;

	template <typename EventType>
	class TelegramLess
	{
	public:
		using ClassType = TelegramLess<EventType>;
		using Telegram = Telegram<EventType>;

	public:
		explicit TelegramLess(int64_t difference);

		CLASS_INVARIANT_DECLARE;

		bool operator()(const Telegram& lhs, const Telegram& rhs) const;

	private:
		bool DonotCompareTime(const Telegram& lhs, const Telegram& rhs) const;

	private:
		int64_t m_Difference;
	};
}

#endif // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_LESS_H
