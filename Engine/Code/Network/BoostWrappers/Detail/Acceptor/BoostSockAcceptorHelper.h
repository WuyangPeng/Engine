// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 15:44)

#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_HELPER_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_HELPER_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
	class AddressData;

	class NETWORK_HIDDEN_DECLARE BoostSockAcceptorHelper
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

#endif // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_ACCEPTOR_HELPER_H
