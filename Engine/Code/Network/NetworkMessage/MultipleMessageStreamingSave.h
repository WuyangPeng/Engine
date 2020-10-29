//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:12)

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
        using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageStreamingSave<Index, MultipleMessageContainer>;
        using ParentType = MultipleMessageStreamingSave<Index - 1, MultipleMessageContainer>;

        MultipleMessageStreamingSave();
      

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void Save(const MultipleMessageContainer& container, const MessageTargetSharedPtr& target) const override;
    };

    template <typename E, MultipleMessageByteType ByteType, MultipleMessageByteType... Types>
    class MultipleMessageStreamingSave<1, MultipleMessageContainer<E, ByteType, Types...>>
    {
    public:
        using MultipleMessageContainer = MultipleMessageContainer<E, ByteType, Types...>;
        using ClassType = MultipleMessageStreamingSave<0, MultipleMessageContainer>;

        MultipleMessageStreamingSave();
        virtual ~MultipleMessageStreamingSave() noexcept = default;

        MultipleMessageStreamingSave(const MultipleMessageStreamingSave& rhs) = default;
        MultipleMessageStreamingSave& operator=(const MultipleMessageStreamingSave& rhs) = default;
        MultipleMessageStreamingSave(MultipleMessageStreamingSave&& rhs) noexcept = default;
        MultipleMessageStreamingSave& operator=(MultipleMessageStreamingSave&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Save(const MultipleMessageContainer& container, const MessageTargetSharedPtr& target) const;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_MULTIPLE_MESSAGE_STREAMING_SAVE_H
