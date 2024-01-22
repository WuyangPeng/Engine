/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:27)

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
