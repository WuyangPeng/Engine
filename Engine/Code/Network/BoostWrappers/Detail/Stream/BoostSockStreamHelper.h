//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 16:29)

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

#endif // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_HELPER_H
