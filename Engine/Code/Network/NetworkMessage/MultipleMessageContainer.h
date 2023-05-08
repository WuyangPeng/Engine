///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.7 (2023/05/08 09:07)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_H

#include "Network/NetworkDll.h"

#include "MultipleMessageCast.h"
#include "MultipleMessageElement.h"
#include "MultipleMessageSize.h"
#include "NetworkMessageInternalFwd.h"
#include "System/Helper/EnumCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"

#include <any>
#include <array>
#include <vector>

namespace Network
{
    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    requires(std::is_enum_v<E>)
    class MultipleMessageContainer final
    {
    public:
        using ClassType = MultipleMessageContainer<E, ByteType, Types...>;
        static constexpr auto size = MultipleMessageSize<ClassType>::value;
        using MessageType = std::array<std::any, size>;

    public:
        MultipleMessageContainer() noexcept;

        template <typename T, typename... OtherTypes>
        explicit MultipleMessageContainer(T value, OtherTypes&&... otherValue);

        CLASS_INVARIANT_DECLARE;

        void Load(MessageSource& source);
        void Save(MessageTarget& target) const;
        NODISCARD int GetStreamingSize() const;

        NODISCARD int GetSize() const;

        template <E Index>
        requires(0 <= System::EnumCastUnderlying(Index) && System::EnumCastUnderlying(Index) < size)
        NODISCARD auto GetValue() const
        {
            NETWORK_CLASS_IS_VALID_CONST_9;

            using ValueType = typename MultipleMessageCast<MultipleMessageElement<System::EnumCastUnderlying(Index), ClassType>::byteType>::ValueType;

            return std::any_cast<ValueType>(message.at(System::EnumCastUnderlying(Index)));
        }

        template <int Index> 
        void SetValue(typename MultipleMessageParameterCast<MultipleMessageElement<Index, ClassType>::byteType>::ValueType value);

    private:
        MessageType message;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_CONTAINER_H
