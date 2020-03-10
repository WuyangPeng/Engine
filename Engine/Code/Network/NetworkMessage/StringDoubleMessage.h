// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:39)

#ifndef NETWORK_NETWORK_MESSAGE_STRING_DOUBLE_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_STRING_DOUBLE_MESSAGE_H

#include "Network/NetworkDll.h"

#include "DoubleMessage.h" 
#include "MessageContainer.h"

#include <vector>

namespace Network
{
	template<typename E>
	class StringDoubleMessage : public DoubleMessage
	{
	public:
		static_assert(std::is_enum_v<E>, "E must be is enum.");

		using ClassType = StringDoubleMessage<E>;
		using ParentType = DoubleMessage;
		using MessageContainer = MessageContainer<E, std::string>;
		using StringType = typename MessageContainer::MessageType;

	public:
		StringDoubleMessage(int64_t messageID, const StringType& stringType);
		virtual ~StringDoubleMessage();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		CORE_TOOLS_RTTI_DECLARE;
		NETWORK_STREAM_DECLARE(StringDoubleMessage);

		std::string GetValue(E index) const;
		int GetSize() const;

	private:
		MessageContainer m_String;
	};

	template<typename E>
	using StringDoubleMessageSharedPtr = std::shared_ptr<StringDoubleMessage<E>>;

	template<typename E>
	using ConstStringDoubleMessageSharedPtr = std::shared_ptr<const StringDoubleMessage<E>>;
}

#endif // NETWORK_NETWORK_MESSAGE_STRING_DOUBLE_MESSAGE_H
