///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 11:39)

#include "Network/NetworkExport.h"

#include "BufferSendStreamContainer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::BufferSendStreamContainer::BufferSendStreamContainer(int64_t socketId, ACEHandleType handle, int bufferSize, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy)
    : socketId{ socketId }, handle{ handle }, bufferSendStream{ bufferSize, parserStrategy, encryptedCompressionStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BufferSendStreamContainer)

bool Network::BufferSendStreamContainer::Insert(const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    return bufferSendStream.Insert(message);
}

void Network::BufferSendStreamContainer::Save(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    return bufferSendStream.Save(messageBuffer);
}

void Network::BufferSendStreamContainer::Clear()
{
    NETWORK_CLASS_IS_VALID_9;

    return bufferSendStream.Clear();
}

bool Network::BufferSendStreamContainer::IsEmpty() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return bufferSendStream.IsEmpty();
}

int Network::BufferSendStreamContainer::GetCurrentSize() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return bufferSendStream.GetCurrentSize();
}

Network::ACEHandle Network::BufferSendStreamContainer::GetACEHandle() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return handle;
}

int64_t Network::BufferSendStreamContainer::GetSocketId() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return socketId;
}
