// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:35)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_H

#include "Network/NetworkDll.h"

#include "MultipleMessageSize.h"
#include "MultipleMessageCast.h"
#include "MultipleMessageElement.h"
#include "NetworkMessageInternalFwd.h" 

namespace Network
{ 
	template<int Index, typename MultipleType>
	class MultipleMessageStreamingSave;

	template<int Index, typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessageStreamingSave<Index, MultipleMessageContainer<E, ByteType, Types...>> :
		public MultipleMessageStreamingSave<Index - 1, MultipleMessageContainer<E, ByteType, Types...>>
	{
	public:
		using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
		using ClassType = MultipleMessageStreamingSave<Index, MultipleMessageContainer>;
		using ParentType = MultipleMessageStreamingSave<Index - 1, MultipleMessageContainer>;

		MultipleMessageStreamingSave();
		virtual ~MultipleMessageStreamingSave();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		 void Save(const MultipleMessageContainer& container, const MessageTargetSharedPtr& target) const override;
	};

	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessageStreamingSave<1, MultipleMessageContainer<E, ByteType, Types...>>
	{
	public:
		using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
		using ClassType = MultipleMessageStreamingSave<0, MultipleMessageContainer>;

		MultipleMessageStreamingSave();
		virtual ~MultipleMessageStreamingSave();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual void Save(const MultipleMessageContainer& container, const MessageTargetSharedPtr& target) const;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_H
