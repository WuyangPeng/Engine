// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:21)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_FACTORY_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_FACTORY_H

#include "Network/NetworkDll.h" 

#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <memory>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE MessageBufferFactory
	{
	public:
		using ClassType = MessageBufferFactory;
		using ImplType = MessageBufferImpl;
		using ImplTypePtr = std::shared_ptr<ImplType>;

	public:
		MessageBufferFactory() noexcept;

		CLASS_INVARIANT_DECLARE;

		static const ImplTypePtr Create(BuffBlockSize buffBlockSize, int count, ParserStrategy parserStrategy);
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_BUFFER_FACTORY_H
