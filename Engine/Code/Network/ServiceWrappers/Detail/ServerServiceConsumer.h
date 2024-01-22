/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:03)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_SERVER_SERVICE_CONSUMER_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_SERVER_SERVICE_CONSUMER_H

#include "Network/NetworkDll.h"

#include "ServiceConsumerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ServerServiceConsumer : public ServiceConsumerImpl
    {
    public:
        using ClassType = ServerServiceConsumer;
        using ParentType = ServiceConsumerImpl;

    public:
        explicit ServerServiceConsumer(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_SERVER_SERVICE_CONSUMER_H