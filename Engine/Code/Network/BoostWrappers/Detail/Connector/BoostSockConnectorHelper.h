///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/22 19:22)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_CONNECTOR_HELPER_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_CONNECTOR_HELPER_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostSockConnectorHelper final
    {
    public:
        using ClassType = BoostSockConnectorHelper;
        using String = System::String;

    public:
        static void EventFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData);
        static void PrintConnectorLog(const String& prefix, const AddressData& addressData);
        static void PrintConnectorSuccessLog(const String& prefix, const AddressData& addressData);
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_CONNECTOR_HELPER_H
