///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/15 11:37)

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
        explicit NullSockAddress(int ip);
        NullSockAddress(const std::string& address, int ip);

        CLASS_INVARIANT_FINAL_DECLARE;

        NODISCARD SockAddressSharedPtr Clone() const override;

        NODISCARD std::string GetAddress() const override;
        NODISCARD int GetPort() const noexcept override;

    private:
        std::string address;
        int ip;
    };
}

#endif  // NETWORK_NETWORK_INTERFACE_NULL_SOCK_ADDRESS_H
