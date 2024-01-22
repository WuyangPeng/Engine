/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:27)

#include "Network/NetworkExport.h"

#include "ActiveMQConsumerSession.h"
#include "ActiveMQService.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#ifdef NETWORK_USE_ACTIVE_MQ

Network::ActiveMQConsumerSession::ActiveMQConsumerSession(ActiveMQService& activeMQService, std::string address)
    : configurationStrategy{ activeMQService.GetConfigurationStrategy() },
      address{ std::move(address) },
      connection{ activeMQService.GetConnection() },
      session{},
      destination{},
      consumer{}
{
    Create();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ActiveMQConsumerSession::~ActiveMQConsumerSession() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        Close();
    }
    EXCEPTION_ALL_CATCH(Network)
}

void Network::ActiveMQConsumerSession::Create()
{
    const auto connectionSharedPtr = connection.lock();
    if (connectionSharedPtr == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("connection 已释放。"s))
    }

    session = SessionUniquePtr{ connectionSharedPtr->createSession(cms::Session::AUTO_ACKNOWLEDGE) };
    destination = DestinationUniquePtr{ session->createQueue(address) };
    consumer = MessageConsumerUniquePtr{ session->createConsumer(destination.get()) };
}

void Network::ActiveMQConsumerSession::Close()
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    session->close();
    consumer->close();
}

void Network::ActiveMQConsumerSession::SetMessageListener(cms::MessageListener* messageListener)
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    consumer->setMessageListener(messageListener);
}

CLASS_INVARIANT_STUB_DEFINE(Network, ActiveMQConsumerSession)

#endif  // NETWORK_USE_ACTIVE_MQ
