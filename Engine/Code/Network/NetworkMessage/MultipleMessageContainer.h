// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/10 14:33)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_H

#include "Network/NetworkDll.h"

#include "MultipleMessageSize.h"
#include "MultipleMessageCast.h"
#include "MultipleMessageElement.h" 
#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#include <any>
#include <array>
#include <vector>

namespace Network
{
	template<typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
	class MultipleMessageContainer
	{
	public:
		static_assert(std::is_enum_v<E>, "E must be is enum.");

		using ClassType = MultipleMessageContainer<E, ByteType, Types...>;
		static constexpr size_t sm_Size = MultipleMessageSize<ClassType>::value;
		using MessageType = std::array<std::any, sm_Size>;

	public:
		MultipleMessageContainer();

		template<typename T, typename... OtherTypes>
		MultipleMessageContainer(T value, OtherTypes... otherValue);

		CLASS_INVARIANT_DECLARE;

		void Load(const MessageSourceSharedPtr& source);
		void Save(const MessageTargetSharedPtr& target) const;
		int GetStreamingSize() const;

		int GetSize() const;

		template<E index>
		auto GetValue() const
		{
			NETWORK_CLASS_IS_VALID_CONST_9;

			static_assert(0 <= System::EnumCastUnderlying(index) && System::EnumCastUnderlying(index) < sm_Size, "The index is out of bounds.");

			using ValueType = typename MultipleMessageCast<MultipleMessageElement<System::EnumCastUnderlying(index), ClassType>::sm_ByteType>::ValueType;

			return std::any_cast<ValueType>(m_Message[System::EnumCastUnderlying(index)]);
		}

		template<int index>
		void SetValue(typename MultipleMessageParameterCast<MultipleMessageElement<index, ClassType>::sm_ByteType>::ValueType value);

	private:
		MessageType m_Message;
	};
}

#endif // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_H
