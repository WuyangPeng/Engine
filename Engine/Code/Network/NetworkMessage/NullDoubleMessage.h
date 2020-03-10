// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:38)

#ifndef NETWORK_NETWORK_MESSAGE_NULL_DOUBLE_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_NULL_DOUBLE_MESSAGE_H

#include "Network/NetworkDll.h"

#include "DoubleMessage.h" 

namespace Network
{
	class NETWORK_DEFAULT_DECLARE NullDoubleMessage : public DoubleMessage
	{
	public:
		using ClassType = NullDoubleMessage;
		using ParentType = DoubleMessage;

	public:
		explicit NullDoubleMessage(int64_t messageID);
		virtual ~NullDoubleMessage();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		CORE_TOOLS_RTTI_DECLARE;
		NETWORK_STREAM_DECLARE(NullDoubleMessage);
	};

	using NullDoubleMessageSharedPtr = std::shared_ptr<NullDoubleMessage>;
	using ConstNullDoubleMessageSharedPtr = std::shared_ptr<const NullDoubleMessage>;
}

#endif // NETWORK_NETWORK_MESSAGE_NULL_DOUBLE_MESSAGE_H
