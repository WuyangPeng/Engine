// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:34)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_H

#include "Network/NetworkDll.h"

#include "MultipleMessageContainer.h" 

namespace Network
{
	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessageContainerGroup
	{
	public:
		static_assert(std::is_enum_v<E>, "E must be is enum.");

		using ClassType = MultipleMessageContainerGroup<E, ByteType, Types...>;
		using MessageType = MultipleMessageContainer<E, ByteType, Types...>;
		using GroupType = std::vector<MessageType>;
		using GroupConstIter = typename GroupType::const_iterator;

	public:
		MultipleMessageContainerGroup();

		explicit MultipleMessageContainerGroup(const GroupType& group);

		CLASS_INVARIANT_DECLARE;

		void Load(const MessageSourceSharedPtr& source);
		void Save(const MessageTargetSharedPtr& target) const;
		int GetStreamingSize() const;

		int GetSize() const;

		const MessageType GetValue(int index) const;

		GroupConstIter begin() const;
		GroupConstIter end() const;

	private:
		GroupType m_Group;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_GROUP_H
