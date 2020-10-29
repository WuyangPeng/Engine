//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 9:55)

#ifndef NETWORK_NETWORK_MESSAGE_INTEGER_DOUBLE_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_INTEGER_DOUBLE_MESSAGE_H

#include "Network/NetworkDll.h"

#include "DoubleMessage.h"
#include "MessageContainer.h"

#include <vector>

namespace Network
{
    template <typename E>
    class IntegerDoubleMessage : public DoubleMessage
    {
    public:
        static_assert(std::is_enum_v<E>, "E must be is enum.");

        using ClassType = IntegerDoubleMessage<E>;
        using ParentType = DoubleMessage;
        using MessageContainer = MessageContainer<E, int32_t>;
        using IntegerType = typename MessageContainer::MessageType;

    public:
        IntegerDoubleMessage(int64_t messageID, const IntegerType& integerType);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_DECLARE;
        NETWORK_STREAM_DECLARE(IntegerDoubleMessage);

        [[nodiscard]] int32_t GetValue(E index) const;
        [[nodiscard]] int GetSize() const;

    private:
        MessageContainer m_Integer;
    };

    template <typename E>
    using IntegerDoubleMessageSharedPtr = std::shared_ptr<IntegerDoubleMessage<E>>;

    template <typename E>
    using ConstIntegerDoubleMessageSharedPtr = std::shared_ptr<const IntegerDoubleMessage<E>>;
}

#endif  // NETWORK_NETWORK_MESSAGE_INTEGER_DOUBLE_MESSAGE_H
