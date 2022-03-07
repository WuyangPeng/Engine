///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/20 14:27)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_SOCK_ADDRESS_H
#define NETWORK_NETWORK_INTERFACE_NULL_SOCK_ADDRESS_H

#include "Network/NetworkDll.h"

#include "SockAddressImpl.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE NullSockAddress final : public SockAddressImpl
    {
    public:
        using ClassType = NullSockAddress;
        using ParentType = SockAddressImpl;

    public:
        NullSockAddress(const std::string& address, int ip);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD SockAddressSharedPtr Clone() const final;

        NODISCARD std::string GetAddress() const final;
        NODISCARD int GetPort() const noexcept final;

    private:
        std::string address;
        int ip;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_ADDRESS_H
