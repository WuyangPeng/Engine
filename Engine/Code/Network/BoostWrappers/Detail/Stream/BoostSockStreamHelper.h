///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/22 19:23)

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
