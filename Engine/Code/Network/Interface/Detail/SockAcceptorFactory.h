///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/20 16:10)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

#include <memory>
#include <string>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockAcceptorFactory final
    {
    public:
        using ClassType = SockAcceptorFactory;
        using ImplType = SockAcceptorImpl;
        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;

    public:
        SockAcceptorFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static ImplTypeSharedPtr Create(int port, const ConfigurationStrategy& configurationStrategy);
        NODISCARD static ImplTypeSharedPtr Create(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy);
        NODISCARD static ImplTypeSharedPtr Create(const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_FACTORY_H
