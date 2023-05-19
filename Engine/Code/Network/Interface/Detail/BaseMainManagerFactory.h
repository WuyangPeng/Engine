///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/08 17:25)

#ifndef NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BaseMainManagerFactory final
    {
    public:
        using ClassType = BaseMainManagerFactory;
        using ImplType = BaseMainManagerImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        BaseMainManagerFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_BASE_MAIN_MANAGER_FACTORY_H
