///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 16:26)

#include "Network/NetworkExport.h"

#include "ActiveMQConsumer.h"
#include "ActiveMQConsumerSession.h"
#include "System/Helper/PragmaWarning/PolymorphicCast.h"
#include "System/Threading/SyncTools.h"
#include "System/Time/Using/DeltaTimeUsing.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/BufferReceiveStream.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"

#ifdef NETWORK_USE_ACTIVE_MQ

Network::ActiveMQConsumer::ActiveMQConsumer(const ConfigurationStrategy& configurationStrategy, const System::String& address)
    : ParentType{ configurationStrategy },
      activeMQService{ configurationStrategy },
      activeMQConsumerSession{ activeMQService, CoreTools::StringConversion::StandardConversionMultiByte(address) },
      thread{ &ClassType::Run, this },
      mutex{},
      conditionVariable{},
      isStop{ false },
      receiveBuffer(std::make_shared<MessageBuffer>(BuffBlockSize::Automatic,
                                                    configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::ReceiveBufferSize),
                                                    configurationStrategy.GetParserStrategy()))
{
    activeMQConsumerSession.Create();
    activeMQConsumerSession.SetMessageListener(this);

    NETWORK_SELF_CLASS_IS_VALID_9;
}

void Network::ActiveMQConsumer::StopThread()
{
    std::unique_lock uniqueLock{ mutex };

    isStop = true;
    conditionVariable.notify_one();

    activeMQConsumerSession.SetMessageListener(nullptr);
}

void Network::ActiveMQConsumer::Release()
{
    StopThread();

    thread.join();
}

Network::ActiveMQConsumer::~ActiveMQConsumer() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        Release();
    }
    EXCEPTION_ALL_CATCH(Network)
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ActiveMQConsumer)

void Network::ActiveMQConsumer::onMessage(const cms::Message* message)
{
    std::lock_guard lockGuard{ mutex };

    CORE_TOOLS_CLASS_IS_VALID_9;

    if (message != nullptr)
    {
        message->acknowledge();

        if (const auto bytesMessage = boost::polymorphic_cast<const cms::BytesMessage*>(message);
            bytesMessage != nullptr && 0 < bytesMessage->getBodyLength())
        {
            Message result(bytesMessage->getBodyLength());

            bytesMessage->readBytes(result);

            messageContainer.emplace_back(result);

            conditionVariable.notify_one();
        }
    }
}

void Network::ActiveMQConsumer::Run()
{
    NETWORK_CLASS_IS_VALID_9;

    do
    {
        std::unique_lock uniqueLock{ mutex };
        conditionVariable.wait(uniqueLock, [this] {
            return isStop || !messageContainer.empty();
        });

        Execution();

    } while (!isStop || !messageContainer.empty());
}

void Network::ActiveMQConsumer::Execution()
{
    NETWORK_CLASS_IS_VALID_9;

    if (!messageContainer.empty())
    {
        try
        {
            const auto message = ExtractNextMessage();

            if (!message.empty())
            {
                receiveBuffer->Write(1, boost::numeric_cast<int>(message.size()), message.data());

                BufferReceiveStream bufferReceiveStream{ receiveBuffer, GetConfigurationStrategy().GetParserStrategy(), GetConfigurationStrategy().GetEncryptedCompressionStrategy() };
                bufferReceiveStream.OnEvent(0, GetMessageEventManager());
            }

            return;
        }
        EXCEPTION_ALL_CATCH(Network)

        activeMQConsumerSession.Create();
        activeMQConsumerSession.SetMessageListener(this);
    }
}

Network::ActiveMQConsumer::Message Network::ActiveMQConsumer::ExtractNextMessage() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    auto message = messageContainer.front();

    messageContainer.pop_front();

    return message;
}

#endif  // NETWORK_USE_ACTIVE_MQ
