/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 17:21)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_HELPER_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_HELPER_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
    class NETWORK_HIDDEN_DECLARE BoostSockStreamHelper final
    {
    public:
        using ClassType = BoostSockStreamHelper;

        using String = System::String;

    public:
        static void EventSendFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData, int bytesTransferred);
        static void EventReceiveFunction(const ErrorCodeType& errorCode, const EventInterfaceSharedPtr& eventInterface, const AddressData& addressData, int bytesTransferred);
        static void PrintSuccessLog(const String& prefix, const AddressData& addressData, int bytesTransferred);
    };
}

#endif  // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_HELPER_H
