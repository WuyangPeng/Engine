///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/04 16:23)

#ifndef NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageContainer.h"
#include "MessageInterface.h"

namespace Network
{
    template <typename E>
    requires(std::is_enum_v<E>)
    class IntegerMessage : public MessageInterface
    {
    public:
        using ClassType = IntegerMessage<E>;
        using ParentType = MessageInterface;

        using MessageContainer = MessageContainer<E, int32_t>;
        using IntegerType = typename MessageContainer::MessageType;

    public:
        IntegerMessage(MessageHeadStrategy messageHeadStrategy, int64_t messageId, const IntegerType& message);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(IntegerMessage);

        NODISCARD int32_t GetValue(E index) const;
        NODISCARD int GetSize() const noexcept;

    private:
        MessageContainer message;
    };

    template <typename E>
    using IntegerMessageSharedPtr = std::shared_ptr<IntegerMessage<E>>;

    template <typename E>
    using ConstIntegerMessageSharedPtr = std::shared_ptr<const IntegerMessage<E>>;
}

#endif  // NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_H
