///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/11 17:16)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_CONSUMER_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_CONSUMER_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"

NETWORK_NON_COPY_EXPORT_IMPL(ServiceConsumerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE ServiceConsumer
    {
    public:
        NON_COPY_TYPE_DECLARE(ServiceConsumer);

        using String = System::String;

    public:
        explicit ServiceConsumer(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_CONSUMER_H
