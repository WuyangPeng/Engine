///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/10 14:49)

#include "Network/NetworkExport.h"

#include "ActiveMQService.h"
#include "ActiveMQProducerSession.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

#ifdef NETWORK_USE_ACTIVE_MQ

Network::ActiveMQProducerSession::ActiveMQProducerSession(ActiveMQService& activeMQService, const std::string& address)
    : configurationStrategy{ activeMQService.GetConfigurationStrategy() },
      address{ address },
      connection{ activeMQService.GetConnection() },
      session{},
      destination{},
      producer{}
{
    Create();

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::ActiveMQProducerSession::~ActiveMQProducerSession() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;

    EXCEPTION_TRY
    {
        session->close();
        producer->close();
    }
    EXCEPTION_ALL_CATCH(Network)
}

void Network::ActiveMQProducerSession::Create()
{
    const auto connectionSharedPtr = connection.lock();
    if (connectionSharedPtr == nullptr)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("connection 已释放。"s))
    }

    session = SessionUniquePtr{ connectionSharedPtr->createSession(cms::Session::CLIENT_ACKNOWLEDGE) };
    destination = DestinationUniquePtr{ session->createQueue(address) };
    producer = MessageProducerUniquePtr{ session->createProducer(destination.get()) };
    producer->setDeliveryMode(cms::DeliveryMode::NON_PERSISTENT);
}

CLASS_INVARIANT_STUB_DEFINE(Network, ActiveMQProducerSession)

Network::ActiveMQProducerSession::BytesMessageUniquePtr Network::ActiveMQProducerSession::CreateBytesMessage()
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    try
    {
        return BytesMessageUniquePtr{ session->createBytesMessage() };
    }
    catch (const std::exception& error)
    {
        LOG_SINGLETON_ENGINE_APPENDER(Error, Network, error, CoreTools::LogAppenderIOManageSign::TriggerAssert);

        Create();

        return BytesMessageUniquePtr{ session->createBytesMessage() };
    }
}

void Network::ActiveMQProducerSession::SendBytesMessage(BytesMessage& bytesMessage)
{
    NETWORK_CLASS_IS_VALID_9;

    producer->send(&bytesMessage);
}

#endif  // NETWORK_USE_ACTIVE_MQ
