///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/21 09:22)

#ifndef CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_H
#define CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_H

#include "CoreTools/CoreToolsDll.h"

#include "CallbackParameters.h"

#include <vector>

namespace CoreTools
{
    template <typename EventType = int>
    class Telegram final
    {
    public:
        using ClassType = Telegram<EventType>;

        using ReceiverInfo = std::vector<int64_t>;

    public:
        Telegram(int64_t sender, int64_t receiver, EventType message, int64_t dispatchMillisecondTime);
        Telegram(int64_t sender, int64_t receiver, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters);
        Telegram(int64_t sender, EventType message, int64_t dispatchMillisecondTime);
        Telegram(int64_t sender, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters) noexcept;
        Telegram(int64_t sender, const ReceiverInfo& receiver, EventType message, int64_t dispatchMillisecondTime);
        Telegram(int64_t sender, const ReceiverInfo& receiver, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int64_t GetSender() const noexcept;
        NODISCARD ReceiverInfo GetReceiver() const;
        NODISCARD EventType GetMessageType() const noexcept;
        NODISCARD int64_t GetDispatchMillisecondTime() const noexcept;
        NODISCARD CallbackParameters GetCallbackParameters() const noexcept;

        void AddReceiver(int64_t aReceiver);

    private:
        int64_t sender;
        ReceiverInfo receiver;
        EventType message;
        int64_t dispatchMillisecondTime;
        CallbackParameters callbackParameters;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_H
