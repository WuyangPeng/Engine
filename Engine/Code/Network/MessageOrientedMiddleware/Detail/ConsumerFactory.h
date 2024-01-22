/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:27)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_FACTORY_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_FACTORY_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/MessageOrientedMiddleware/MessageOrientedMiddlewareInternalFwd.h"

#include <memory>

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
