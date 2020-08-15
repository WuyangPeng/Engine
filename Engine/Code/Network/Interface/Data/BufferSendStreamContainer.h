// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 09:55)

#ifndef NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_CONTAINER_H
#define NETWORK_NETWORK_INTERFACE_BUFFER_SEND_STREAM_CONTAINER_H

#include "Network/NetworkDll.h"

#include "Network/ACEWrappers/Using/ACEUsing.h"
#include "Network/NetworkMessage/BufferSendStream.h"

namespace Network
{
	struct NETWORK_HIDDEN_DECLARE BufferSendStreamContainer
	{
	public:
		using ClassType = BufferSendStreamContainer;

	public:
		BufferSendStreamContainer(uint64_t socketID, ACEHandle handle, int bufferSize, ParserStrategy parserStrategy);

		CLASS_INVARIANT_DECLARE;

		bool Insert(const MessageInterfaceSharedPtr& message);

		void Save(const MessageBufferSharedPtr& messageBuffer);

		void Clear();

		bool IsEmpty() const noexcept;

		uint32_t GetCurrentSize() const;

		ACEHandle GetACEHandle() const noexcept;
		uint64_t GetSocketID() const noexcept;

	private:
		uint64_t m_SocketID;
		ACEHandle m_Handle;
		BufferSendStream m_BufferSendStream;
	};
}

#endif // NETWORK_NETWORK_INTERFACE_REACTIVE_SERVER_H
