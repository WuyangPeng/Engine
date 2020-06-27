// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 09:56)

#ifndef NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_MULTI_INDEX_CONTAINER_H
#define NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_MULTI_INDEX_CONTAINER_H

#include "Network/NetworkDll.h"

#include "BufferSendStreamContainer.h"
#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/NetworkMessage/BufferSendStream.h"

#include <map>

namespace Network
{
	struct NETWORK_HIDDEN_DECLARE BufferSendStreamMultiIndexContainer
	{
	public:
		using ClassType = BufferSendStreamMultiIndexContainer;
		using BufferSendStreamContainerSharedPtr = std::shared_ptr<BufferSendStreamContainer>;
		using BufferSendStreamContainerWeakPtr = std::weak_ptr<BufferSendStreamContainer>;
		using SocketIDContainer = std::map<uint64_t, BufferSendStreamContainerSharedPtr>;
		using SocketIDContainerConstIter = SocketIDContainer::const_iterator;

	public:
		BufferSendStreamMultiIndexContainer();

		CLASS_INVARIANT_DECLARE;

		void Insert(uint64_t socketID, ACEHandle handle, int bufferSize, ParserStrategy parserStrategy);

		BufferSendStreamContainerSharedPtr GetBufferSendStreamContainerPtrBySocketID(uint64_t socketID);
		BufferSendStreamContainerSharedPtr GetBufferSendStreamContainerPtrByHandle(ACEHandle handle);

		void Erase(uint64_t socketID);
		SocketIDContainerConstIter begin() const;
		SocketIDContainerConstIter end() const;

	private:
		using HandleIDContainer = std::map<ACEHandle, BufferSendStreamContainerWeakPtr>;

	private:
		SocketIDContainer m_SocketIDContainer;
		HandleIDContainer m_HandleIDContainer;
	};
}

#endif // NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_MULTI_INDEX_CONTAINER_H
