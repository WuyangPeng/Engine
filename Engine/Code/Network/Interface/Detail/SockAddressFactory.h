///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 16:15)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

#include <memory>
#include <string>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockAddressFactory final
    {
    public:
        using ClassType = SockAddressFactory;
        using ImplType = SockAddressImpl;
        using ImplTypeSharedPtr = std::shared_ptr<ImplType>;

    public:
        SockAddressFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD static ImplTypeSharedPtr Create(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy);
        NODISCARD static ImplTypeSharedPtr Create(const ConfigurationStrategy& configurationStrategy);
        NODISCARD static ImplTypeSharedPtr Create(int port, const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_FACTORY_H
