/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:17)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_H

#include "Network/NetworkDll.h"

#include "MultipleMessageCast.h"
#include "MultipleMessageElement.h"
#include "MultipleMessageSize.h"
#include "NetworkMessageInternalFwd.h"

namespace Network
{
    template <int Index, typename MultipleType>
    class MultipleMessageInitValue;

    template <int Index, typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageInitValue<Index, MultipleMessageContainer<E, ByteType, Types...>> : public MultipleMessageInitValue<Index - 1, MultipleMessageContainer<E, ByteType, Types...>>
    {
    public:
        using MultipleMessageContainerType = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageInitValue<Index, MultipleMessageContainerType>;
        using ParentType = MultipleMessageInitValue<Index - 1, MultipleMessageContainerType>;

        template <typename T, typename... OtherT>
        MultipleMessageInitValue(MultipleMessageContainerType& container, T value, OtherT&&... otherValues);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageInitValue<1, MultipleMessageContainer<E, ByteType, Types...>>
    {
    public:
        using MultipleMessageContainerType = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageInitValue<0, MultipleMessageContainerType>;

        template <typename T>
        MultipleMessageInitValue(MultipleMessageContainerType& container, T value);

        virtual ~MultipleMessageInitValue() noexcept = default;

        MultipleMessageInitValue(const MultipleMessageInitValue& rhs) noexcept = default;
        MultipleMessageInitValue& operator=(const MultipleMessageInitValue& rhs) noexcept = default;
        MultipleMessageInitValue(MultipleMessageInitValue&& rhs) noexcept = default;
        MultipleMessageInitValue& operator=(MultipleMessageInitValue&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_H
