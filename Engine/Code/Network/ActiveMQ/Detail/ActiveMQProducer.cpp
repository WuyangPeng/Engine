/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:26)

#include "Network/NetworkExport.h"

#include "ActiveMQProducer.h"
#include "ActiveMQProducerSession.h"
#include "System/Helper/Tools.h"
#include "CoreTools/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "Network/Configuration/Flags/ConfigurationStrategyFlags.h"
#include "Network/NetworkMessage/Flags/MessageLengthFlags.h"
#include "Network/NetworkMessage/MessageBuffer.h"

#ifdef NETWORK_USE_ACTIVE_MQ

Network::ActiveMQProducer::ActiveMQProducer(const ConfigurationStrategy& configurationStrategy)
    : ParentType{ configurationStrategy },
      activeMQService{ configurationStrategy },
      sessionContainer{},
      bufferSendStream{ configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize),
                        configurationStrategy.GetParserStrategy(),
                        configurationStrategy.GetEncryptedCompressionStrategy() },
      sendBuffer(std::make_shared<MessageBuffer>(BuffBlockSize::Automatic,
                                                 configurationStrategy.GetConfigurationSubStrategy().GetValue(WrappersSubStrategy::SendBufferSize),
                                                 configurationStrategy.GetParserStrategy()))

{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, ActiveMQProducer)

void Network::ActiveMQProducer::SendServerMessage(const String& address, const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto iter = sessionContainer.find(address);

    if (iter == sessionContainer.cend())
    {
        const auto activeMQSession = std::make_shared<ActiveMQProducerSession>(activeMQService, CoreTools::StringConversion::StandardConversionMultiByte(address));
        iter = sessionContainer.emplace(address, activeMQSession).first;
    }

    if (iter == sessionContainer.cend())
    {
        THROW_EXCEPTION(SYSTEM_TEXT("创建session失败。"s))
    }

    bufferSendStream.Clear();
    if (!bufferSendStream.Insert(message))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("消息插入失败。"s))
    }

    sendBuffer->ClearCurrentIndex();
    bufferSendStream.Save(sendBuffer);

    const auto bytesMessage = iter->second->CreateBytesMessage();

    #include SYSTEM_WARNING_PUSH
    #include SYSTEM_WARNING_DISABLE(26490)

    bytesMessage->writeBytes(reinterpret_cast<unsigned char*>(sendBuffer->GetInitialBufferedPtr()), 0, sendBuffer->GetCurrentWriteIndex());

    #include SYSTEM_WARNING_POP

    iter->second->SendBytesMessage(*bytesMessage);
}

#endif  // NETWORK_USE_ACTIVE_MQ