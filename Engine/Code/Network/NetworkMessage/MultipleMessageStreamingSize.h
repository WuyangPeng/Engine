// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:37)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_H

#include "Network/NetworkDll.h"

#include "MultipleMessageSize.h"
#include "MultipleMessageCast.h"
#include "MultipleMessageElement.h"
#include "NetworkMessageInternalFwd.h" 

namespace Network
{
	template<int Index, typename MultipleType>
	class MultipleMessageStreamingSize;

	template<int Index, typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessageStreamingSize<Index, MultipleMessageContainer<E, ByteType, Types...>> :
		public MultipleMessageStreamingSize<Index - 1, MultipleMessageContainer<E, ByteType, Types...>>
	{
	public:
		using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
		using ClassType = MultipleMessageStreamingSize<Index, MultipleMessageContainer>;
		using ParentType = MultipleMessageStreamingSize<Index - 1, MultipleMessageContainer>;

		MultipleMessageStreamingSize();
		virtual ~MultipleMessageStreamingSize();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 int GetStreamingSize(const MultipleMessageContainer& container) const override;
	};

	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessageStreamingSize<1, MultipleMessageContainer<E, ByteType, Types...>>
	{
	public:
		using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
		using ClassType = MultipleMessageStreamingSize<0, MultipleMessageContainer>;

		MultipleMessageStreamingSize();
		virtual ~MultipleMessageStreamingSize();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual int GetStreamingSize(const MultipleMessageContainer& container) const;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_H
