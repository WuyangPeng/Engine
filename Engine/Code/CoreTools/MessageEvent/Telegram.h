///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/26 18:20)

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
        Telegram(uint64_t sender, uint64_t receiver, EventType message, int64_t dispatchMillisecondTime);
        Telegram(uint64_t sender, uint64_t receiver, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters);
        Telegram(uint64_t sender, EventType message, int64_t dispatchMillisecondTime);
        Telegram(uint64_t sender, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters) noexcept;
        Telegram(uint64_t sender, const ReceiverInfo& receiver, EventType message, int64_t dispatchMillisecondTime);
        Telegram(uint64_t sender, const ReceiverInfo& receiver, EventType message, int64_t dispatchMillisecondTime, const CallbackParameters& callbackParameters);

        CLASS_INVARIANT_DECLARE;

        NODISCARD uint64_t GetSender() const noexcept;
        NODISCARD ReceiverInfo GetReceiver() const;
        NODISCARD EventType GetMessageType() const noexcept;
        NODISCARD int64_t GetDispatchMillisecondTime() const noexcept;
        NODISCARD CallbackParameters GetCallbackParameters() const noexcept;

        void AddReceiver(uint64_t receiver);

    private:
        uint64_t sender;
        ReceiverInfo m_Receiver;
        EventType message;
        int64_t dispatchMillisecondTime;
        CallbackParameters callbackParameters;
    };
}

#endif  // CORE_TOOLS_MESSAGE_EVENT_TELEGRAM_H
