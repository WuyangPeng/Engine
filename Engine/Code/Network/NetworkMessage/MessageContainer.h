// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:29)

#ifndef NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/NetworkMessageInternalFwd.h"

#include <vector>

namespace Network
{
	template<typename E, typename T>
	class MessageContainer
	{
	public:
		static_assert(std::is_enum_v<E>, "E must be is enum.");

		using ClassType = MessageContainer<E, T>;
		using MessageType = std::vector<T>;

	public:
		MessageContainer();
		explicit MessageContainer(const MessageType& messageType);

		CLASS_INVARIANT_DECLARE;

		void Load(const MessageSourceSharedPtr& source);
		void Save(const MessageTargetSharedPtr& target) const;
		int GetStreamingSize() const;

		T GetValue(E index) const;
		int GetSize() const;

	private:
		MessageType m_Message;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MESSAGE_CONTAINER_H
