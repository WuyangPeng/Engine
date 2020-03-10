// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/02 10:16)

#ifndef NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INET_ADDRESS_H
#define NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INET_ADDRESS_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockAddressImpl.h" 

namespace Network
{	
	class NETWORK_HIDDEN_DECLARE NetworkSockInetAddress : public SockAddressImpl
	{
	public:
		using ClassType = NetworkSockInetAddress;
		using ParentType = SockAddressImpl;

	public:
		NetworkSockInetAddress();
		explicit NetworkSockInetAddress(int port);
		NetworkSockInetAddress(const std::string& hostName, int port);
		virtual ~NetworkSockInetAddress();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual const WinSockInetAddressType& GetWinSockInetAddress() const override;
		virtual WinSockInetAddressType& GetWinSockInetAddress() override;

		virtual const SockAddressPtr Clone() const override;

		virtual const std::string GetAddress() const override;
		virtual int GetPort() const override;
		 
	private:
		WinSockInetAddressType m_InetAddress;
		std::string m_AddressName;
	};	
} 

#endif // NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INET_ADDRESS_H
