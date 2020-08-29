// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:34)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_H

#include "Network/NetworkDll.h"

#include "MultipleMessageSize.h"
#include "MultipleMessageCast.h"
#include "MultipleMessageElement.h"
#include "NetworkMessageInternalFwd.h" 

namespace Network
{
	template<int Index, typename MultipleType>
	class MultipleMessageInitValue;

	template<int Index, typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessageInitValue<Index, MultipleMessageContainer<E, ByteType, Types...>> :
		public MultipleMessageInitValue<Index - 1, MultipleMessageContainer<E, ByteType, Types...>>
	{
	public:
		using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
		using ClassType = MultipleMessageInitValue<Index, MultipleMessageContainer>;
		using ParentType = MultipleMessageInitValue<Index - 1, MultipleMessageContainer>;

		template<typename T, typename... OtherT>
		MultipleMessageInitValue(MultipleMessageContainer& container, T value, OtherT... otherValues);

		virtual ~MultipleMessageInitValue();

		CLASS_INVARIANT_OVERRIDE_DECLARE;
	};

	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessageInitValue<1, MultipleMessageContainer<E, ByteType, Types...>>
	{
	public:
		using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
		using ClassType = MultipleMessageInitValue<0, MultipleMessageContainer>;

		template<typename T>
		MultipleMessageInitValue(MultipleMessageContainer& container, T value);

		virtual ~MultipleMessageInitValue();

		CLASS_INVARIANT_VIRTUAL_DECLARE;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_H
