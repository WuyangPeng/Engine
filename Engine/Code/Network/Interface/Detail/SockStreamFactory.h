///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 16:23)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_STREAM_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_SOCK_STREAM_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

#include <memory>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockStreamFactory final
    {
    public:
        using ClassType = SockStreamFactory;
        using ImplType = SockStreamImpl;
        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;

    public:
        SockStreamFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static ImplTypeSharedPtr Create(const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_STREAM_FACTORY_H
