// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:35)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_H

#include "Network/NetworkDll.h"

#include "MultipleMessageSize.h"
#include "MultipleMessageCast.h"
#include "MultipleMessageElement.h"
#include "NetworkMessageInternalFwd.h" 

namespace Network
{
	template<int Index, typename MultipleType>
	class MultipleMessageStreamingLoad;

	template<int Index, typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessageStreamingLoad<Index, MultipleMessageContainer<E, ByteType, Types...>> :
		public MultipleMessageStreamingLoad<Index - 1, MultipleMessageContainer<E, ByteType, Types...>>
	{
	public:
		using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
		using ClassType = MultipleMessageStreamingLoad<Index, MultipleMessageContainer>;
		using ParentType = MultipleMessageStreamingLoad<Index - 1, MultipleMessageContainer>;

		MultipleMessageStreamingLoad();
		virtual ~MultipleMessageStreamingLoad();

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 void Load(MultipleMessageContainer& container, const MessageSourceSharedPtr& source) const override;
	};

	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessageStreamingLoad<1, MultipleMessageContainer<E, ByteType, Types...>>
	{
	public:
		using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
		using ClassType = MultipleMessageStreamingLoad<0, MultipleMessageContainer>;

		MultipleMessageStreamingLoad();
		virtual ~MultipleMessageStreamingLoad();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual void Load(MultipleMessageContainer& container, const MessageSourceSharedPtr& source) const;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_H
