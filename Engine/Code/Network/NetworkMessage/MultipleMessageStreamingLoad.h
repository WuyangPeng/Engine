/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:17)

#ifndef NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_H
#define NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_H

#include "Network/NetworkDll.h"

#include "MultipleMessageCast.h"
#include "MultipleMessageElement.h"
#include "MultipleMessageSize.h"
#include "NetworkMessageInternalFwd.h"

namespace Network
{
    template <int Index, typename MultipleType>
    class MultipleMessageStreamingLoad;

    template <int Index, typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageStreamingLoad<Index, MultipleMessageContainer<E, ByteType, Types...>> : public MultipleMessageStreamingLoad<Index - 1, MultipleMessageContainer<E, ByteType, Types...>>
    {
    public:
        using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageStreamingLoad<Index, MultipleMessageContainer>;
        using ParentType = MultipleMessageStreamingLoad<Index - 1, MultipleMessageContainer>;

        MultipleMessageStreamingLoad() noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Load(MultipleMessageContainer& container, MessageSource& source) const override;
    };

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageStreamingLoad<1, MultipleMessageContainer<E, ByteType, Types...>>
    {
    public:
        using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageStreamingLoad<0, MultipleMessageContainer>;

        MultipleMessageStreamingLoad() noexcept;
        virtual ~MultipleMessageStreamingLoad() noexcept = default;

        MultipleMessageStreamingLoad(const MultipleMessageStreamingLoad& rhs) noexcept = default;
        MultipleMessageStreamingLoad& operator=(const MultipleMessageStreamingLoad& rhs) noexcept = default;
        MultipleMessageStreamingLoad(MultipleMessageStreamingLoad&& rhs) noexcept = default;
        MultipleMessageStreamingLoad& operator=(MultipleMessageStreamingLoad&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Load(MultipleMessageContainer& container, MessageSource& source) const;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_H
