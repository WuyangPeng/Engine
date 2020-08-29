// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:28)

#ifndef NETWORK_NETWORK_MESSAGE_INTEGER_DOUBLE_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_INTEGER_DOUBLE_MESSAGE_H

#include "Network/NetworkDll.h"

#include "DoubleMessage.h" 
#include "MessageContainer.h"

#include <vector>

namespace Network
{
	template<typename E>
	class IntegerDoubleMessage : public DoubleMessage
	{
	public:
		static_assert(std::is_enum_v<E>, "E must be is enum.");

		using ClassType = IntegerDoubleMessage<E>;
		using ParentType = DoubleMessage;
		using MessageContainer = MessageContainer<E, int32_t>;
		using IntegerType = typename MessageContainer::MessageType;

	public:
		IntegerDoubleMessage(int64_t messageID, const IntegerType& integerType);
		virtual ~IntegerDoubleMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		CORE_TOOLS_RTTI_DECLARE;
		NETWORK_STREAM_DECLARE(IntegerDoubleMessage);

		int32_t GetValue(E index) const;
		int GetSize() const;   

	private:
		MessageContainer m_Integer;
	};

	template<typename E>
	using IntegerDoubleMessageSharedPtr = std::shared_ptr<IntegerDoubleMessage<E>>;

	template<typename E>
	using ConstIntegerDoubleMessageSharedPtr = std::shared_ptr<const IntegerDoubleMessage<E>>;
}

#endif // NETWORK_NETWORK_MESSAGE_INTEGER_DOUBLE_MESSAGE_H
