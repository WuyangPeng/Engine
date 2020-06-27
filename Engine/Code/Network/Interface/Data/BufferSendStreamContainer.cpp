// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:52)

#include "Network/NetworkExport.h" 

#include "BufferSendStreamContainer.h"
#include "CoreTools/Helper/ExceptionMacro.h" 
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 

Network::BufferSendStreamContainer
	::BufferSendStreamContainer(uint64_t socketID, ACEHandle handle, int bufferSize, ParserStrategy parserStrategy)
	:m_SocketID{ socketID }, m_Handle{ handle }, m_BufferSendStream{ bufferSize, parserStrategy }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BufferSendStreamContainer)

bool Network::BufferSendStreamContainer
	::Insert(const MessageInterfaceSharedPtr& message)
{
	NETWORK_CLASS_IS_VALID_9;

	return m_BufferSendStream.Insert(message);
}

void Network::BufferSendStreamContainer
	::Save(const MessageBufferSharedPtr& messageBuffer)
{
	NETWORK_CLASS_IS_VALID_9;

	return m_BufferSendStream.Save(messageBuffer);
}

void Network::BufferSendStreamContainer
	::Clear()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_BufferSendStream.Clear();
}

bool Network::BufferSendStreamContainer
	::IsEmpty() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_BufferSendStream.IsEmpty();
}

uint32_t Network::BufferSendStreamContainer
	::GetCurrentSize() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_BufferSendStream.GetCurrentSize();
}

Network::ACEHandle Network::BufferSendStreamContainer
	::GetACEHandle() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Handle;
}

uint64_t Network::BufferSendStreamContainer
	::GetSocketID() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_SocketID;
}

