/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:26)

#ifndef NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_PRODUCER_H
#define NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_PRODUCER_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/NetworkMessage/MessageInterface.h"

NETWORK_NON_COPY_EXPORT_IMPL(ProducerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE Producer
    {
    public:
        NON_COPY_TYPE_DECLARE(Producer);
        using String = System::String;

    public:
        explicit Producer(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        void SendServerMessage(const String& address, const MessageInterfaceSharedPtr& message);

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_MESSAGE_ORIENTED_MIDDLEWARE_PRODUCER_H
