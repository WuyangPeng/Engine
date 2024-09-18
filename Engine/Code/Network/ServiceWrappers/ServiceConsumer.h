/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:02)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_CONSUMER_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_CONSUMER_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/Interface/NetworkInternalFwd.h"
#include "Network/NetworkMessage/NetworkMessageFwd.h"
#include "Network/ServiceWrappers/ServiceWrappersFwd.h"

NETWORK_NON_COPY_EXPORT_IMPL(ServiceConsumerImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE ServiceConsumer
    {
    public:
        NON_COPY_TYPE_DECLARE(ServiceConsumer);

        using String = System::String;

    public:
        ServiceConsumer(ServiceSession& serviceSession, const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string Response();

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_CONSUMER_H
