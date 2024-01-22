/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:13)

#ifndef NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_LESS_H
#define NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_LESS_H

#include "Network/NetworkDll.h"

#include "Network/NetworkMessage/NetworkMessageEvent.h"

namespace Network
{
    class NETWORK_DEFAULT_DECLARE NetworkMessageEventLess final
    {
    public:
        using ClassType = NetworkMessageEventLess;

    public:
        NetworkMessageEventLess() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD bool operator()(const NetworkMessageEventWeakPtr& lhs, const NetworkMessageEventWeakPtr& rhs) const noexcept;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_LESS_H
