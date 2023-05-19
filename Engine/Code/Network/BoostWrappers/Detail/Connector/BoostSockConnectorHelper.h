///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 14:28)

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
