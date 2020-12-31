//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 16:24)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_HELPER_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_HELPER_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostSockAcceptorHelper final
    {
    public:
        using ClassType = BoostSockAcceptorHelper;
        using String = System::String;

    public:
        static void EventFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData);
        static void PrintAcceptLog(const String& prefix, const AddressData& addressData);
        static void PrintAcceptSuccessLog(const String& prefix, const AddressData& addressData);
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_HELPER_H
