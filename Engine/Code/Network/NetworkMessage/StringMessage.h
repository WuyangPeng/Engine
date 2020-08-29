// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:39)

#ifndef NETWORK_NETWORK_MESSAGE_STRING_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_STRING_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h" 
#include "MessageContainer.h"

#include <vector>

namespace Network
{
	template<typename E>
	class StringMessage : public MessageInterface
	{
	public:
		static_assert(std::is_enum_v<E>, "E must be is enum.");

		using ClassType = StringMessage<E>;
		using ParentType = MessageInterface;
		using MessageContainer = MessageContainer<E, std::string>;
		using StringType = typename MessageContainer::MessageType;

	public:
		StringMessage(int64_t messageID, const StringType& stringType);
		virtual ~StringMessage();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		CORE_TOOLS_RTTI_DECLARE;
		NETWORK_STREAM_DECLARE(StringMessage);

		std::string GetValue(E index) const;
		int GetSize() const;

	private:
		MessageContainer m_String;
	};

	template<typename E>
	using StringMessageSharedPtr = std::shared_ptr<StringMessage<E>>;

	template<typename E>
	using ConstStringMessageSharedPtr = std::shared_ptr<const StringMessage<E>>;
}

#endif // NETWORK_NETWORK_MESSAGE_STRING_MESSAGE_H
