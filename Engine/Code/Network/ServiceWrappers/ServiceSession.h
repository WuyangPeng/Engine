/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 16:02)

#ifndef NETWORK_SERVICE_WRAPPERS_SERVICE_SESSION_H
#define NETWORK_SERVICE_WRAPPERS_SERVICE_SESSION_H

#include "Network/NetworkDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "Network/Configuration/ConfigurationFwd.h"
#include "Network/Configuration/ConfigurationStrategy.h"
#include "Network/NetworkMessage/MessageInterface.h"

NETWORK_NON_COPY_EXPORT_IMPL(ServiceSessionImpl);

namespace Network
{
    class NETWORK_DEFAULT_DECLARE ServiceSession
    {
    public:
        NON_COPY_TYPE_DECLARE(ServiceSession);

        using String = System::String;

    public:
        explicit ServiceSession(const ConfigurationStrategy& configurationStrategy);

        CLASS_INVARIANT_DECLARE;

        void SendTextMessage(const std::string& message);
        NODISCARD std::string Response();

    private:
        PackageType impl;
    };
}

#endif  // NETWORK_SERVICE_WRAPPERS_SERVICE_SESSION_H
