/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:27)

#ifndef NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_CONSUMER_H
#define NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_CONSUMER_H

#include "Network/NetworkDll.h"

#include "ActiveMQConsumerSession.h"
#include "ActiveMQService.h"
#include "Network/MessageOrientedMiddleware/Detail/ConsumerImpl.h"

#include <deque>

#ifdef NETWORK_USE_ACTIVE_MQ

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ActiveMQConsumer final : public ConsumerImpl, public cms::MessageListener
    {
    public:
        using ClassType = ActiveMQConsumer;
        using ParentType = ConsumerImpl;

    public:
        ActiveMQConsumer(const ConfigurationStrategy& configurationStrategy, const System::String& address);

        ~ActiveMQConsumer() noexcept;
        ActiveMQConsumer(const ActiveMQConsumer& rhs) = delete;
        ActiveMQConsumer& operator=(const ActiveMQConsumer& rhs) = delete;
        ActiveMQConsumer(ActiveMQConsumer&& rhs) noexcept = delete;
        ActiveMQConsumer& operator=(ActiveMQConsumer&& rhs) noexcept = delete;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void onMessage(const cms::Message* message) override;

    private:
        using SessionUniquePtr = std::unique_ptr<cms::Session>;
        using DestinationUniquePtr = std::unique_ptr<cms::Destination>;
        using MessageConsumerUniquePtr = std::unique_ptr<cms::MessageConsumer>;
        using MessageUniquePtr = std::unique_ptr<cms::Message>;
        using MessageSharedPtr = std::shared_ptr<cms::Message>;
        using Message = std::vector<uint8_t>;
        using MessageContainer = std::deque<Message>;

    private:
        NODISCARD Message ExtractNextMessage() noexcept;

        void Run();
        void Execution();
        void Release();
        void StopThread();

    private:
        ActiveMQService activeMQService;
        ActiveMQConsumerSession activeMQConsumerSession;
        MessageContainer messageContainer;
        std::thread thread;
        std::mutex mutex;
        std::condition_variable conditionVariable;
        volatile bool isStop;
        MessageBufferSharedPtr receiveBuffer;
    };
}

#endif  // NETWORK_USE_ACTIVE_MQ

#endif  // NETWORK_MESSAGE_ACTIVE_MQ_ACTIVE_MQ_CONSUMER_H
