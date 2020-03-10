// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/21 17:25)


#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_CONNECTOR_HELPER_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_CONNECTOR_HELPER_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BoostSockConnectorHelper
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

#endif // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_CONNECTOR_HELPER_H
