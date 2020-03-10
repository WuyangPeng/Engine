// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:34)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_ELEMENT_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_ELEMENT_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"

namespace Network
{ 
	template<int Index, typename MultipleType>
	struct MultipleMessageElement;

	template<int Index, typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	struct MultipleMessageElement<Index, MultipleMessageContainer<E, ByteType, Types...>> : public MultipleMessageElement<Index - 1, MultipleMessageContainer<E, Types...>>
	{
		using ClassType = MultipleMessageElement<Index, MultipleMessageContainer<E, ByteType, Types...>>;
		using ParentType = MultipleMessageElement<Index - 1, MultipleMessageContainer<E, Types...>>;
	};

	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	struct MultipleMessageElement<0, MultipleMessageContainer<E, ByteType, Types...>>
	{
		using ClassType = MultipleMessageElement<0, MultipleMessageContainer<E, ByteType, Types...>>;

		static constexpr MultipleMessageByteType sm_ByteType = ByteType;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_ELEMENT_H
