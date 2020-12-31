//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/27 10:11)

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

        MultipleMessageStreamingLoad();

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Load(MultipleMessageContainer& container, const MessageSourceSharedPtr& source) const override;
    };

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageStreamingLoad<1, MultipleMessageContainer<E, ByteType, Types...>>
    {
    public:
        using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageStreamingLoad<0, MultipleMessageContainer>;

        MultipleMessageStreamingLoad();
        virtual ~MultipleMessageStreamingLoad() noexcept = default;

        MultipleMessageStreamingLoad(const MultipleMessageStreamingLoad& rhs) = default;
        MultipleMessageStreamingLoad& operator=(const MultipleMessageStreamingLoad& rhs) = default;
        MultipleMessageStreamingLoad(MultipleMessageStreamingLoad&& rhs) noexcept = default;
        MultipleMessageStreamingLoad& operator=(MultipleMessageStreamingLoad&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Load(MultipleMessageContainer& container, const MessageSourceSharedPtr& source) const;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_LOAD_H
