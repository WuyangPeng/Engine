// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:38)

#ifndef NETWORK_NETWORK_MESSAGE_NULL_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_NULL_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h" 

namespace Network
{
	class NETWORK_DEFAULT_DECLARE NullMessage : public MessageInterface
	{
	public:
		using ClassType = NullMessage;
		using ParentType = MessageInterface;

	public:
		explicit NullMessage(int64_t messageID);
		virtual ~NullMessage();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		CORE_TOOLS_RTTI_DECLARE;
		NETWORK_STREAM_DECLARE(NullMessage);
	};

	using NullMessageSharedPtr = std::shared_ptr<NullMessage>;
	using ConstNullMessageSharedPtr = std::shared_ptr<const NullMessage>;
}

#endif // NETWORK_NETWORK_MESSAGE_NULL_MESSAGE_H
