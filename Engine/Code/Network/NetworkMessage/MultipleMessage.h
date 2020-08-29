// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:32)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h" 
#include "NetworkMessageInternalFwd.h"
#include "MultipleMessageContainer.h" 

#include <vector> 

namespace Network
{
	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessage : public MessageInterface
	{
	public:
		static_assert(std::is_enum_v<E>, "E must be is enum.");

		using ClassType = MultipleMessage<E, ByteType, Types...>;
		using ParentType = MessageInterface;
		using MessageType = MultipleMessageContainer<E, ByteType, Types...>;

	public:
		MultipleMessage(int64_t messageID, const MessageType& messageType);

		template<typename T, typename... OtherTypes>
		MultipleMessage(int64_t messageID, T value, OtherTypes... otherValue);

		virtual ~MultipleMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		CORE_TOOLS_RTTI_DECLARE;
		NETWORK_STREAM_DECLARE(MultipleMessage);

		template<E index>
		auto GetValue() const
		{
			NETWORK_CLASS_IS_VALID_CONST_9;

			return m_Message.GetValue<index>();
		}

		int GetSize() const;

	private:
		MessageType m_Message;
	};

	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	using MultipleMessageSharedPtr = std::shared_ptr<MultipleMessage<E, ByteType, Types...>>;

	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	using ConstMultipleMessageSharedPtr = std::shared_ptr<const MultipleMessage<E, ByteType, Types...>>;
}

#endif // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_H
