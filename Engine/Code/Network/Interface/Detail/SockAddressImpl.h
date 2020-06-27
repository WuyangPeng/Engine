// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:14)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE SockAddressImpl
	{
	public:
		using ClassType = SockAddressImpl;
		using SockAddressPtr = std::shared_ptr<ClassType>;

	public:
		SockAddressImpl();
		virtual ~SockAddressImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual const ACEInetAddressType& GetACEInetAddress() const;
		virtual const BoostInetAddressType& GetBoostInetAddress() const;
		virtual const WinSockInetAddressType& GetWinSockInetAddress() const;

		virtual ACEInetAddressType& GetACEInetAddress();
		virtual BoostInetAddressType& GetBoostInetAddress();
		virtual WinSockInetAddressType& GetWinSockInetAddress();

		virtual const SockAddressPtr Clone() const = 0;

		virtual const std::string GetAddress() const = 0;
		virtual int GetPort() const = 0;
	};
}

#endif // NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_IMPL_H
