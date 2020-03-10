// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:05)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_H

#include "CoreTools/CoreToolsDll.h"  

#include "CallbackParameters.h"

#include <vector>

namespace CoreTools
{
	template <typename EventType = int>
	class Telegram
	{
	public:
		using ClassType = Telegram<EventType>;
		using ReceiverInfo = std::vector<uint64_t>;

	public:
		Telegram();
		Telegram(uint64_t sender, uint64_t receiver, EventType message, int64_t dispatchMillisecondTime);
		Telegram(uint64_t sender, uint64_t receiver, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters);
		Telegram(uint64_t sender, EventType message, int64_t dispatchMillisecondTime);
		Telegram(uint64_t sender, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters);
		Telegram(uint64_t sender, const ReceiverInfo& receiver, EventType message, int64_t dispatchMillisecondTime);
		Telegram(uint64_t sender, const ReceiverInfo& receiver, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters);

		CLASS_INVARIANT_DECLARE;

		uint64_t GetSender() const;
		ReceiverInfo GetReceiver() const;
		EventType GetMessageType() const;
		int64_t GetDispatchMillisecondTime() const;
		const CallbackParameters GetCallbackParameters() const;

		void AddReceiver(uint64_t receiver);

	private:
		uint64_t m_Sender;
		ReceiverInfo m_Receiver;
		EventType m_Message;
		int64_t m_DispatchMillisecondTime;
		CallbackParameters m_CallbackParameters;
	};
}

#endif // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_H
