/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 09:48)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_DETAIL_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_DETAIL_H

#include "CoreTools/CoreToolsExport.h"

#include "Telegram.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

template <typename EventType>
CoreTools::Telegram<EventType>::Telegram(int64_t sender, int64_t receiver, EventType message, int64_t dispatchMillisecondTime)
    : sender{ sender }, receiver{ receiver }, message{ message }, dispatchMillisecondTime{ dispatchMillisecondTime }, callbackParameters{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>::Telegram(int64_t sender, int64_t receiver, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters)
    : sender{ sender }, receiver{ receiver }, message{ message }, dispatchMillisecondTime{ dispatchMillisecondTime }, callbackParameters{ callbackParameters }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>::Telegram(int64_t sender, EventType message, int64_t dispatchMillisecondTime)
    : sender{ sender }, receiver{}, message{ message }, dispatchMillisecondTime{ dispatchMillisecondTime }, callbackParameters{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>::Telegram(int64_t sender, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters) noexcept
    : sender{ sender }, receiver{}, message{ message }, dispatchMillisecondTime{ dispatchMillisecondTime }, callbackParameters{ callbackParameters }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>::Telegram(int64_t sender, const ReceiverInfo& receiver, EventType message, int64_t dispatchMillisecondTime)
    : sender{ sender }, receiver{ receiver }, message{ message }, dispatchMillisecondTime{ dispatchMillisecondTime }, callbackParameters{ 0 }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

template <typename EventType>
CoreTools::Telegram<EventType>::Telegram(int64_t sender, const ReceiverInfo& receiver, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters)
    : sender{ sender }, receiver{ receiver }, message{ message }, dispatchMillisecondTime{ dispatchMillisecondTime }, callbackParameters{ callbackParameters }
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
int64_t CoreTools::Telegram<EventType>::GetSender() const noexcept
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return sender;
}

template <typename EventType>
typename CoreTools::Telegram<EventType>::ReceiverInfo CoreTools::Telegram<EventType>::GetReceiver() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_9;

    return receiver;
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
void CoreTools::Telegram<EventType>::AddReceiver(int64_t aReceiver)
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    receiver.emplace_back(aReceiver);
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_DETAIL_H