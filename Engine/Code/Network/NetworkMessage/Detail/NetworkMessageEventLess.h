//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/26 20:43)

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

        [[nodiscard]] bool operator()(const NetworkMessageEventWeakPtr& lhs, const NetworkMessageEventWeakPtr& rhs) const noexcept;
    };
}

#endif  // NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_LESS_H
