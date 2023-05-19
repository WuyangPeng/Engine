///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 14:30)

#include "Network/NetworkExport.h"

#include "BoostFixedSockStream.h"
#include "BoostSockStreamHelper.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Network/Interface/Data/AddressData.h"
#include "Network/NetworkMessage/MessageBuffer.h"

Network::BoostFixedSockStream::BoostFixedSockStream(CoreTools::DisableNotThrow disableNotThrow)
    : ParentType{ disableNotThrow }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostFixedSockStream)

int Network::BoostFixedSockStream::Receive(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    messageBuffer->ClearCurrentIndex();

    const auto receiveSize = HandleReceive(messageBuffer);

    if (receiveSize != 0 && messageBuffer->GetMessageLength() != receiveSize)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("接收消息错误！"s));
    }

    return receiveSize;
}

void Network::BoostFixedSockStream::AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    messageBuffer->ClearCurrentIndex();

    HandleAsyncReceive(eventInterface, messageBuffer, messageBuffer->GetCurrentWriteIndex());
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::BoostFixedSockStream::SubclassAsyncReceiveEvent(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer, int originalWriteIndex)
{
    BoostSockStreamHelper::EventReceiveFunction(errorCode, eventInterface, AddressData{ *this }, messageBuffer->GetCurrentWriteIndex() - originalWriteIndex);
}

#include STSTEM_WARNING_POP