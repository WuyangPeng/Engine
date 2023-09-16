///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 11:29)

#ifndef NETWORK_NETWORK_INTERFACE_HANDLE_SET_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_HANDLE_SET_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE HandleSetFactory final
    {
    public:
        using ClassType = HandleSetFactory;

        using ImplType = HandleSetImpl;
        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;

    public:
        HandleSetFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static ImplTypeSharedPtr Create(const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_HANDLE_SET_FACTORY_H
