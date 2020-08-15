// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.4 (2020/03/11 10:14)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_FACTORY_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_FACTORY_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

#include <memory>
#include <string>

namespace Network
{
    class NETWORK_HIDDEN_DECLARE SockAddressFactory
    {
    public:
        using ClassType = SockAddressFactory;
        using ImplType = SockAddressImpl;
        using ImplTypePtr = std::shared_ptr<ImplType>;

    public:
        SockAddressFactory() noexcept;

        CLASS_INVARIANT_DECLARE;

        static const ImplTypePtr Create(const std::string& hostName, int port, const ConfigurationStrategy& configurationStrategy);
        static const ImplTypePtr Create(const ConfigurationStrategy& configurationStrategy);
        static const ImplTypePtr Create(int port, const ConfigurationStrategy& configurationStrategy);
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_FACTORY_H
