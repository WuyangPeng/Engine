///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 17:14)

#include "Network/NetworkExport.h"

#include "BufferSendStreamContainer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::BufferSendStreamContainer::BufferSendStreamContainer(uint64_t socketID, ACEHandle handle, int bufferSize, ParserStrategy parserStrategy, EncryptedCompressionStrategy encryptedCompressionStrategy)
    : socketID{ socketID }, handle{ handle }, bufferSendStream{ bufferSize, parserStrategy, encryptedCompressionStrategy }
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

int Network::BufferSendStreamContainer::GetCurrentSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return bufferSendStream.GetCurrentSize();
}

Network::ACEHandle Network::BufferSendStreamContainer::GetACEHandle() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return handle;
}

uint64_t Network::BufferSendStreamContainer::GetSocketID() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return socketID;
}
