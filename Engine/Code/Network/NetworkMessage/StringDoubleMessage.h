///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 18:19)

#ifndef NETWORK_NETWORK_MESSAGE_STRING_DOUBLE_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_STRING_DOUBLE_MESSAGE_H

#include "Network/NetworkDll.h"

#include "DoubleMessage.h"
#include "MessageContainer.h"

#include <vector>

namespace Network
{
    template <typename E>
    class StringDoubleMessage : public DoubleMessage
    {
    public:
        static_assert(std::is_enum_v<E>, "E must be is enum.");

        using ClassType = StringDoubleMessage<E>;
        using ParentType = DoubleMessage;
        using MessageContainer = MessageContainer<E, std::string>;
        using StringType = typename MessageContainer::MessageType;

    public:
        StringDoubleMessage(int64_t messageID, const StringType& stringType);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(StringDoubleMessage);

        NODISCARD std::string GetValue(E index) const;
        NODISCARD int GetSize() const;

    private:
        MessageContainer m_String;
    };

    template <typename E>
    using StringDoubleMessageSharedPtr = std::shared_ptr<StringDoubleMessage<E>>;

    template <typename E>
    using ConstStringDoubleMessageSharedPtr = std::shared_ptr<const StringDoubleMessage<E>>;
}

#endif  // NETWORK_NETWORK_MESSAGE_STRING_DOUBLE_MESSAGE_H
