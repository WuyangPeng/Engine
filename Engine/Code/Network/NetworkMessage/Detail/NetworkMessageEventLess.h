///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/18 11:50)

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
