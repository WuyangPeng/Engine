/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:17)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_H

#include "Network/NetworkDll.h"

#include "MultipleMessageCast.h"
#include "MultipleMessageElement.h"
#include "MultipleMessageSize.h"
#include "NetworkMessageInternalFwd.h"

namespace Network
{
    template <int Index, typename MultipleType>
    class MultipleMessageStreamingSize;

    template <int Index, typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageStreamingSize<Index, MultipleMessageContainer<E, ByteType, Types...>> : public MultipleMessageStreamingSize<Index - 1, MultipleMessageContainer<E, ByteType, Types...>>
    {
    public:
        using MultipleMessageContainerType = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageStreamingSize<Index, MultipleMessageContainerType>;
        using ParentType = MultipleMessageStreamingSize<Index - 1, MultipleMessageContainerType>;

        MultipleMessageStreamingSize() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        NODISCARD int GetStreamingSize(const MultipleMessageContainerType& container) const override;
    };

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageStreamingSize<1, MultipleMessageContainer<E, ByteType, Types...>>
    {
    public:
        using MultipleMessageContainerType = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageStreamingSize<0, MultipleMessageContainerType>;

        MultipleMessageStreamingSize() noexcept;
        virtual ~MultipleMessageStreamingSize() noexcept = default;

        MultipleMessageStreamingSize(const MultipleMessageStreamingSize& rhs) noexcept = default;
        MultipleMessageStreamingSize& operator=(const MultipleMessageStreamingSize& rhs) noexcept = default;
        MultipleMessageStreamingSize(MultipleMessageStreamingSize&& rhs) noexcept = default;
        MultipleMessageStreamingSize& operator=(MultipleMessageStreamingSize&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        NODISCARD virtual int GetStreamingSize(const MultipleMessageContainerType& container) const;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_H
