///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:12)

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
        using EventInterface = CoreTools::EventInterface;

    public:
        static void EventFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData);
        static void PrintAcceptLog(const String& prefix, const AddressData& addressData);
        static void PrintAcceptSuccessLog(const String& prefix, const AddressData& addressData);
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_HELPER_H
