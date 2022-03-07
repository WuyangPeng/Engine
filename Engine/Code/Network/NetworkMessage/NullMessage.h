///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/18 18:17)

#ifndef NETWORK_NETWORK_MESSAGE_NULL_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_NULL_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE NullMessage final : public MessageInterface
    {
    public:
        using ClassType = NullMessage;
        using ParentType = MessageInterface;

    public:
        explicit NullMessage(int64_t messageID) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(NullMessage);
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(NullMessage);
}

#endif  // NETWORK_NETWORK_MESSAGE_NULL_MESSAGE_H
