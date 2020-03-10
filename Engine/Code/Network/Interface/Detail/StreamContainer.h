// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/01 16:56)

#ifndef NETWORK_NETWORK_STREAM_CONTAINER_H
#define NETWORK_NETWORK_STREAM_CONTAINER_H

#include "Network/NetworkDll.h"

#include "Network/Interface/SockStream.h"
#include "Network/NetworkMessage/BufferSendStream.h" 

namespace Network
{ 
	class NETWORK_HIDDEN_DECLARE StreamContainer 
	{
	public:
		using ClassType = StreamContainer; 

	public:
		explicit StreamContainer(const ConfigurationStrategy& configurationStrategy, const SockStreamSharedPtr& sockStream);

		CLASS_INVARIANT_DECLARE;	

		void SetSockStream(const SockStreamSharedPtr& sockStream);

		SockStreamSharedPtr GetSockStreamSharedPtr();
		BufferSendStream& GetBufferSendStream(); 

	private:			
		BufferSendStream m_BufferSendStream;
		SockStreamSharedPtr m_SockStream;
	};
} 

#endif // NETWORK_NETWORK_STREAM_CONTAINER_H
