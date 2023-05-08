///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.7 (2023/05/06 17:48)

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
        using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageInitValue<Index, MultipleMessageContainer>;
        using ParentType = MultipleMessageInitValue<Index - 1, MultipleMessageContainer>;

        template <typename T, typename... OtherT>
        MultipleMessageInitValue(MultipleMessageContainer& container, T value, OtherT&&... otherValues);

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageInitValue<1, MultipleMessageContainer<E, ByteType, Types...>>
    {
    public:
        using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageInitValue<0, MultipleMessageContainer>;

        template <typename T>
        MultipleMessageInitValue(MultipleMessageContainer& container, T value);

        virtual ~MultipleMessageInitValue() noexcept = default;

        MultipleMessageInitValue(const MultipleMessageInitValue& rhs) noexcept = default;
        MultipleMessageInitValue& operator=(const MultipleMessageInitValue& rhs) noexcept = default;
        MultipleMessageInitValue(MultipleMessageInitValue&& rhs) noexcept = default;
        MultipleMessageInitValue& operator=(MultipleMessageInitValue&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_INIT_VALUE_H
