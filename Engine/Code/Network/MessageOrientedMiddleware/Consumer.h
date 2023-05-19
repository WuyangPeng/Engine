///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 17:01)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"

NETWORK_NON_COPY_EXPORT_IMPL(ConsumerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE Consumer
    {
    public:
        NON_COPY_TYPE_DECLARE(Consumer);
        using String = System::String;

    public:
        Consumer(const ConfigurationStrategy& configurationStrategy, const String& address);

        CLASS_INVARIANT_DECLARE;

        NODISCARD MessageEventManager& GetMessageEventManager() noexcept;

        void Insert(int64_t messageId, const NetworkMessageEventSharedPtr& messageEvent);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_CONSUMER_H
