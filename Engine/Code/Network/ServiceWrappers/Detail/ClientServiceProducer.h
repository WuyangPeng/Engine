/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:04)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_CLIENT_SERVICE_PRODUCER_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_CLIENT_SERVICE_PRODUCER_H

#include "Network/NetworkDll.h"

#include "ServiceProducerImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ClientServiceProducer : public ServiceProducerImpl
    {
    public:
        using ClassType = ClientServiceProducer;
        using ParentType = ServiceProducerImpl;

    public:
        explicit ClientServiceProducer(const ConfigurationStrategy& configurationStrategy) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_CLIENT_SERVICE_PRODUCER_H
