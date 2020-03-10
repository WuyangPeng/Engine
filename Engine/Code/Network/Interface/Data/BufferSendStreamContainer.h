// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/11/29 10:21)


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

		bool IsEmpty() const;

		uint32_t GetCurrentSize() const;

		ACEHandle GetACEHandle() const;
		uint64_t GetSocketID() const;

	private:
		uint64_t m_SocketID;		 
		ACEHandle m_Handle;	
		BufferSendStream m_BufferSendStream;
	};	 
} 

#endif // NETWORK_NETWORK_INTERFACE_REACTIVE_SERVER_H
