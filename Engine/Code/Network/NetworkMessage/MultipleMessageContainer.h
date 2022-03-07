///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 18:04)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_H

#include "Network/NetworkDll.h"

#include "MultipleMessageCast.h"
#include "MultipleMessageElement.h"
#include "MultipleMessageSize.h"
#include "NetworkMessageInternalFwd.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#include <any>
#include <array>
#include <vector>

namespace Network
{
    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageContainer final
    {
    public:
        static_assert(std::is_enum_v<E>, "E must be is enum.");

        using ClassType = MultipleMessageContainer<E, ByteType, Types...>;
        static constexpr auto sm_Size = MultipleMessageSize<ClassType>::value;
        using MessageType = std::array<std::any, sm_Size>;

    public:
        MultipleMessageContainer() noexcept;

        template <typename T, typename... OtherTypes>
        MultipleMessageContainer(T value, OtherTypes&&... otherValue);

        CLASS_INVARIANT_DECLARE;

        void Load(MessageSource& source);
        void Save(MessageTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        NODISCARD int GetSize() const;

        template <E index>
        NODISCARD auto GetValue() const
        {
            NETWORK_CLASS_IS_VALID_CONST_9;

            static_assert(0 <= System::EnumCastUnderlying(index) && System::EnumCastUnderlying(index) < sm_Size, "The index is out of bounds.");

            using ValueType = typename MultipleMessageCast<MultipleMessageElement<System::EnumCastUnderlying(index), ClassType>::sm_ByteType>::ValueType;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26482)
            return std::any_cast<ValueType>(message[System::EnumCastUnderlying(index)]);
#include STSTEM_WARNING_POP
        }

        template <int index>
        void SetValue(typename MultipleMessageParameterCast<MultipleMessageElement<index, ClassType>::sm_ByteType>::ValueType value);

    private:
        MessageType message;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_H
