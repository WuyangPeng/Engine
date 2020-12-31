//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/27 10:14)

#ifndef NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_H
#define NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_H

#include "Network/NetworkDll.h"

#include "NetworkMessageInternalFwd.h"
#include "System/Helper/PragmaWarning.h"

template class NETWORK_DEFAULT_DECLARE std::weak_ptr<Network::NetworkMessageEvent>;
template class NETWORK_DEFAULT_DECLARE std::enable_shared_from_this<Network::NetworkMessageEvent>;

namespace Network
{
    class NETWORK_DEFAULT_DECLARE NetworkMessageEvent : public std::enable_shared_from_this<NetworkMessageEvent>
    {
    public:
        using ClassType = NetworkMessageEvent;

    public:
        NetworkMessageEvent() noexcept;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26456)

        virtual ~NetworkMessageEvent() noexcept = default;

        NetworkMessageEvent(const NetworkMessageEvent& rhs) = default;
        NetworkMessageEvent& operator=(const NetworkMessageEvent& rhs) = default;
        NetworkMessageEvent(NetworkMessageEvent&& rhs) noexcept = default;
        NetworkMessageEvent& operator=(NetworkMessageEvent&& rhs) noexcept = default;

#include STSTEM_WARNING_POP

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void CallBackEvent(uint64_t socketID, const ConstMessageInterfaceSharedPtr& message) = 0;
    };

    CORE_TOOLS_SHARED_PTR_DECLARE(NetworkMessageEvent);
    CORE_TOOLS_WEAK_PTR_DECLARE(NetworkMessageEvent);
}

#endif  // NETWORK_NETWORK_MESSAGE_NETWORK_MESSAGE_EVENT_H
