// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:29)

#ifndef NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h" 
#include "MessageContainer.h"

#include <vector>

namespace Network
{
	template<typename E>
	class IntegerMessage : public MessageInterface
	{
	public:
		static_assert(std::is_enum_v<E>, "E must be is enum.");

		using ClassType = IntegerMessage<E>;
		using ParentType = MessageInterface;
		using MessageContainer = MessageContainer<E, int32_t>;
		using IntegerType = typename MessageContainer::MessageType;

	public:
		IntegerMessage(int64_t messageID, const IntegerType& integerType);
		virtual ~IntegerMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		CORE_TOOLS_RTTI_DECLARE;
		NETWORK_STREAM_DECLARE(IntegerMessage);

		int32_t GetValue(E index) const;
		int GetSize() const;

	private:
		MessageContainer m_Integer;
	};

	template<typename E>
	using IntegerMessageSharedPtr = std::shared_ptr<IntegerMessage<E>>;

	template<typename E>
	using ConstIntegerMessageSharedPtr = std::shared_ptr<const IntegerMessage<E>>;
}

#endif // NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_H
