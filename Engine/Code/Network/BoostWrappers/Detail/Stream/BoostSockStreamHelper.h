// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 15:48)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_HELPER_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_STREAM_HELPER_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BoostSockStreamHelper
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
