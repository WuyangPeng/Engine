// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 17:08)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_DETAIL_H

#include "CoreTools/CoreToolsExport.h"

#include "Telegram.h" 
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h" 

template <typename EventType>
CoreTools::Telegram<EventType>
	::Telegram()
	:m_Sender{ 0 }, m_Receiver{}, m_Message{ 0 }, m_DispatchMillisecondTime{ 0 }, m_CallbackParameters{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>
	::Telegram(uint64_t sender, uint64_t receiver, EventType message, int64_t dispatchMillisecondTime)
	:m_Sender{ sender }, m_Receiver{ receiver }, m_Message{ message }, m_DispatchMillisecondTime{ dispatchMillisecondTime }, m_CallbackParameters{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>
	::Telegram(uint64_t sender, uint64_t receiver, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters)
	:m_Sender{ sender }, m_Receiver{ receiver }, m_Message{ message }, m_DispatchMillisecondTime{ dispatchMillisecondTime }, m_CallbackParameters{ callbackParameters }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>
	::Telegram(uint64_t sender, EventType message, int64_t dispatchMillisecondTime)
	:m_Sender{ sender }, m_Receiver{  }, m_Message{ message }, m_DispatchMillisecondTime{ dispatchMillisecondTime }, m_CallbackParameters{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>
	::Telegram(uint64_t sender, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters)
	:m_Sender{ sender }, m_Receiver{}, m_Message{ message }, m_DispatchMillisecondTime{ dispatchMillisecondTime }, m_CallbackParameters{ callbackParameters }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>
	::Telegram(uint64_t sender, const ReceiverInfo& receiver, EventType message, int64_t dispatchMillisecondTime)
	:m_Sender{ sender }, m_Receiver{ receiver }, m_Message{ message }, m_DispatchMillisecondTime{ dispatchMillisecondTime }, m_CallbackParameters{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>
	::Telegram(uint64_t sender, const ReceiverInfo& receiver, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters)
	:m_Sender{ sender }, m_Receiver{ receiver }, m_Message{ message }, m_DispatchMillisecondTime{ dispatchMillisecondTime }, m_CallbackParameters{ callbackParameters }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename EventType>
bool CoreTools::Telegram<EventType>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename EventType>
uint64_t CoreTools::Telegram<EventType>
	::GetSender() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Sender;
}

template <typename EventType>
typename CoreTools::Telegram<EventType>::ReceiverInfo CoreTools::Telegram<EventType>
	::GetReceiver() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Receiver;
}

template <typename EventType>
EventType CoreTools::Telegram<EventType>
	::GetMessageType() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_Message;
}

template <typename EventType>
int64_t CoreTools::Telegram<EventType>
	::GetDispatchMillisecondTime() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_DispatchMillisecondTime;
}

template <typename EventType>
const CoreTools::CallbackParameters CoreTools::Telegram<EventType>
	::GetCallbackParameters() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_9;

	return m_CallbackParameters;
}

template <typename EventType>
void CoreTools::Telegram<EventType>
	::AddReceiver(uint64_t receiver)
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_Receiver.push_back(receiver);
}

#endif // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_DETAIL_H