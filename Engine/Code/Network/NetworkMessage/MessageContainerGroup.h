// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:29)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_H

#include "Network/NetworkDll.h"

#include "MessageContainer.h"
#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <vector>

namespace Network
{
	template<typename E, typename T>
	class MessageContainerGroup
	{
	public:
		static_assert(std::is_enum_v<E>, "E must be is enum.");

		using ClassType = MessageContainerGroup<E, T>;
		using MessageType = std::vector<T>;
		using ContainerType = MessageContainer<E, T>;
		using StructureType = std::vector<MessageType>;
		using GroupType = std::vector<ContainerType>;
		using GroupConstIter = typename GroupType::const_iterator;

	public:
		MessageContainerGroup();
		explicit MessageContainerGroup(const StructureType& group);

		CLASS_INVARIANT_DECLARE;

		void Load(const MessageSourceSharedPtr& source);
		void Save(const MessageTargetSharedPtr& target) const;
		int GetStreamingSize() const;

		const ContainerType GetValue(int index) const;
		int GetSize() const;

		GroupConstIter begin() const;
		GroupConstIter end() const;

	private:
		GroupType m_Group;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_GROUP_H
