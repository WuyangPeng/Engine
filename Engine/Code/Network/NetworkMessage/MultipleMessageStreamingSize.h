//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:13)

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
        using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageStreamingSize<Index, MultipleMessageContainer>;
        using ParentType = MultipleMessageStreamingSize<Index - 1, MultipleMessageContainer>;

        MultipleMessageStreamingSize();

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        [[nodiscard]] int GetStreamingSize(const MultipleMessageContainer& container) const override;
    };

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageStreamingSize<1, MultipleMessageContainer<E, ByteType, Types...>>
    {
    public:
        using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageStreamingSize<0, MultipleMessageContainer>;

        MultipleMessageStreamingSize();
        virtual ~MultipleMessageStreamingSize() noexcept = default;

        MultipleMessageStreamingSize(const MultipleMessageStreamingSize& rhs) = default;
        MultipleMessageStreamingSize& operator=(const MultipleMessageStreamingSize& rhs) = default;
        MultipleMessageStreamingSize(MultipleMessageStreamingSize&& rhs) noexcept = default;
        MultipleMessageStreamingSize& operator=(MultipleMessageStreamingSize&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

         [[nodiscard]] virtual int GetStreamingSize(const MultipleMessageContainer& container) const;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SIZE_H
