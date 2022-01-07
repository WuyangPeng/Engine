///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/26 0:14)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_DETAIL_H

#include "CoreTools/CoreToolsExport.h"

#include "Telegram.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename EventType>
CoreTools::Telegram<EventType>::Telegram(uint64_t sender, uint64_t receiver, EventType message, int64_t dispatchMillisecondTime)
    : sender{ sender }, m_Receiver{ receiver }, message{ message }, dispatchMillisecondTime{ dispatchMillisecondTime }, callbackParameters{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>::Telegram(uint64_t sender, uint64_t receiver, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters)
    : sender{ sender }, m_Receiver{ receiver }, message{ message }, dispatchMillisecondTime{ dispatchMillisecondTime }, callbackParameters{ callbackParameters }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>::Telegram(uint64_t sender, EventType message, int64_t dispatchMillisecondTime)
    : sender{ sender }, m_Receiver{}, message{ message }, dispatchMillisecondTime{ dispatchMillisecondTime }, callbackParameters{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>::Telegram(uint64_t sender, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters) noexcept
    : sender{ sender }, m_Receiver{}, message{ message }, dispatchMillisecondTime{ dispatchMillisecondTime }, callbackParameters{ callbackParameters }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>::Telegram(uint64_t sender, const ReceiverInfo& receiver, EventType message, int64_t dispatchMillisecondTime)
    : sender{ sender }, m_Receiver{ receiver }, message{ message }, dispatchMillisecondTime{ dispatchMillisecondTime }, callbackParameters{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>::Telegram(uint64_t sender, const ReceiverInfo& receiver, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters)
    : sender{ sender }, m_Receiver{ receiver }, message{ message }, dispatchMillisecondTime{ dispatchMillisecondTime }, callbackParameters{ callbackParameters }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT

template <typename EventType>
bool CoreTools::Telegram<EventType>::IsValid() const noexcept
{
    return true;
}

#endif  // OPEN_CLASS_INVARIANT

template <typename EventType>
uint64_t CoreTools::Telegram<EventType>::GetSender() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sender;
}

template <typename EventType>
typename CoreTools::Telegram<EventType>::ReceiverInfo CoreTools::Telegram<EventType>::GetReceiver() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return m_Receiver;
}

template <typename EventType>
EventType CoreTools::Telegram<EventType>::GetMessageType() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return message;
}

template <typename EventType>
int64_t CoreTools::Telegram<EventType>::GetDispatchMillisecondTime() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return dispatchMillisecondTime;
}

template <typename EventType>
CoreTools::CallbackParameters CoreTools::Telegram<EventType>::GetCallbackParameters() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return callbackParameters;
}

template <typename EventType>
void CoreTools::Telegram<EventType>::AddReceiver(uint64_t receiver)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_Receiver.emplace_back(receiver);
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_DETAIL_H