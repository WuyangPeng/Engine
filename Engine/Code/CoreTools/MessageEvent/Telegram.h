//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/26 15:31)

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

        [[nodiscard]] uint64_t GetSender() const;
        [[nodiscard]] ReceiverInfo GetReceiver() const;
        [[nodiscard]] EventType GetMessageType() const;
        [[nodiscard]] int64_t GetDispatchMillisecondTime() const;
        [[nodiscard]] const CallbackParameters GetCallbackParameters() const;

        void AddReceiver(uint64_t receiver);

    private:
        uint64_t m_Sender;
        ReceiverInfo m_Receiver;
        EventType m_Message;
        int64_t m_DispatchMillisecondTime;
        CallbackParameters m_CallbackParameters;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_H
