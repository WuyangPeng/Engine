//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 9:56)

#ifndef NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageContainer.h"
#include "MessageInterface.h"

#include <vector>

namespace Network
{
    template <typename E>
    class IntegerMessage : public MessageInterface
    {
    public:
        static_assert(std::is_enum_v<E>, "E must be is enum.");

        using ClassType = IntegerMessage<E>;
        using ParentType = MessageInterface;
        using MessageContainer = MessageContainer<E, int32_t>;
        using IntegerType = typename MessageContainer::MessageType;

    public:
        IntegerMessage(int64_t messageID, const IntegerType& integerType);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_DECLARE;
        NETWORK_STREAM_DECLARE(IntegerMessage);

        [[nodiscard]] int32_t GetValue(E index) const;
        [[nodiscard]] int GetSize() const;

    private:
        MessageContainer m_Integer;
    };

    template <typename E>
    using IntegerMessageSharedPtr = std::shared_ptr<IntegerMessage<E>>;

    template <typename E>
    using ConstIntegerMessageSharedPtr = std::shared_ptr<const IntegerMessage<E>>;
}

#endif  // NETWORK_NETWORK_MESSAGE_INTEGER_MESSAGE_H
