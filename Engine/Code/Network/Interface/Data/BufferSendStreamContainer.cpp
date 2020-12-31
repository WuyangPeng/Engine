//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 11:04)

#include "Network/NetworkExport.h"

#include "BufferSendStreamContainer.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"

Network::BufferSendStreamContainer::BufferSendStreamContainer(uint64_t socketID, ACEHandle handle, int bufferSize, ParserStrategy parserStrategy)
    : m_SocketID{ socketID }, m_Handle{ handle }, m_BufferSendStream{ bufferSize, parserStrategy }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BufferSendStreamContainer)

bool Network::BufferSendStreamContainer::Insert(const MessageInterfaceSharedPtr& message)
{
    NETWORK_CLASS_IS_VALID_9;

    return m_BufferSendStream.Insert(message);
}

void Network::BufferSendStreamContainer::Save(const MessageBufferSharedPtr& messageBuffer)
{
    NETWORK_CLASS_IS_VALID_9;

    return m_BufferSendStream.Save(messageBuffer);
}

void Network::BufferSendStreamContainer::Clear()
{
    NETWORK_CLASS_IS_VALID_9;

    return m_BufferSendStream.Clear();
}

bool Network::BufferSendStreamContainer::IsEmpty() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_BufferSendStream.IsEmpty();
}

uint32_t Network::BufferSendStreamContainer::GetCurrentSize() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_BufferSendStream.GetCurrentSize();
}

Network::ACEHandle Network::BufferSendStreamContainer::GetACEHandle() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Handle;
}

uint64_t Network::BufferSendStreamContainer::GetSocketID() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_SocketID;
}
