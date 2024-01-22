/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:27)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_PRODUCER_FACTORY_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_PRODUCER_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Configuration/ConfigurationFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ProducerFactory
    {
    public:
        using ClassType = ProducerFactory;

        using ProducerSharedPtr = std::shared_ptr<ProducerImpl>;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static ProducerSharedPtr Create(const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_PRODUCER_FACTORY_H
