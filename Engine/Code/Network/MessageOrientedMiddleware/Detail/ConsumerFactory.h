///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.8 (2023/05/10 09:36)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_FACTORY_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_FACTORY_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/MessageOrientedMiddleware/MessageOrientedMiddlewareInternalFwd.h"

#include <memory>
#include <string>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE ConsumerFactory
    {
    public:
        using ClassType = ConsumerFactory;
        using ConsumerSharedPtr = std::shared_ptr<ConsumerImpl>;

    public:
        CLASS_INVARIANT_DECLARE;

        NODISCARD static ConsumerSharedPtr Create(const ConfigurationStrategy& configurationStrategy, const System::String& address);
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_FACTORY_H
