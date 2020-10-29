//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 9:54)

#ifndef NETWORK_NETWORK_MESSAGE_DOUBLE_MESSAGE_H
#define NETWORK_NETWORK_MESSAGE_DOUBLE_MESSAGE_H

#include "Network/NetworkDll.h"

#include "MessageInterface.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE DoubleMessage : public MessageInterface
    {
    public:
        using ClassType = DoubleMessage;
        using ParentType = MessageInterface;

    public:
        explicit DoubleMessage(int64_t messageID) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        CORE_TOOLS_RTTI_OVERRIDE_DECLARE;
        NETWORK_STREAM_DECLARE(DoubleMessage);

        [[nodiscard]] int GetMessageID() const override;
        [[nodiscard]] int GetSubMessageID() const override;

    private:
        static constexpr auto sm_MessageBytes = 32LL;
        static constexpr auto sm_MaxMessageID = (1LL << sm_MessageBytes) - 1LL;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(DoubleMessage);
}

#endif  // NETWORK_NETWORK_MESSAGE_DOUBLE_MESSAGE_H
