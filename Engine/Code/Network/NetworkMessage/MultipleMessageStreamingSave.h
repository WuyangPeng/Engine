/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:17)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_H

#include "Network/NetworkDll.h"

#include "MultipleMessageCast.h"
#include "MultipleMessageElement.h"
#include "MultipleMessageSize.h"
#include "NetworkMessageInternalFwd.h"

namespace Network
{
    template <int Index, typename MultipleType>
    class MultipleMessageStreamingSave;

    template <int Index, typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageStreamingSave<Index, MultipleMessageContainer<E, ByteType, Types...>> : public MultipleMessageStreamingSave<Index - 1, MultipleMessageContainer<E, ByteType, Types...>>
    {
    public:
        using MultipleMessageContainerType = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageStreamingSave<Index, MultipleMessageContainerType>;
        using ParentType = MultipleMessageStreamingSave<Index - 1, MultipleMessageContainerType>;

        MultipleMessageStreamingSave() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Save(const MultipleMessageContainerType& container, MessageTarget& target) const override;
    };

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageStreamingSave<1, MultipleMessageContainer<E, ByteType, Types...>>
    {
    public:
        using MultipleMessageContainerType = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageStreamingSave<0, MultipleMessageContainerType>;

        MultipleMessageStreamingSave() noexcept;
        virtual ~MultipleMessageStreamingSave() noexcept = default;

        MultipleMessageStreamingSave(const MultipleMessageStreamingSave& rhs) noexcept = default;
        MultipleMessageStreamingSave& operator=(const MultipleMessageStreamingSave& rhs) noexcept = default;
        MultipleMessageStreamingSave(MultipleMessageStreamingSave&& rhs) noexcept = default;
        MultipleMessageStreamingSave& operator=(MultipleMessageStreamingSave&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Save(const MultipleMessageContainerType& container, MessageTarget& target) const;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_H
