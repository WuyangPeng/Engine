///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:34)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_ROUTE_SERVICE_MANAGER_IMPL_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_ROUTE_SERVICE_MANAGER_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/ActiveMQ/Detail/ActiveMQInit.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE RouteServiceManagerImpl
    {
    public:
        using ClassType = RouteServiceManagerImpl;

    public:
        explicit RouteServiceManagerImpl(bool useActiveMQ);
        ~RouteServiceManagerImpl() noexcept;
        RouteServiceManagerImpl(const RouteServiceManagerImpl& rhs) = delete;
        RouteServiceManagerImpl& operator=(const RouteServiceManagerImpl& rhs) = delete;
        RouteServiceManagerImpl(RouteServiceManagerImpl&& rhs) noexcept = delete;
        RouteServiceManagerImpl& operator=(RouteServiceManagerImpl&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        using ActiveMQInitSharedPtr = std::shared_ptr<ActiveMQInit>;

    private:
        ActiveMQInitSharedPtr activeMQInit;
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_ROUTE_SERVICE_MANAGER_IMPL_H
