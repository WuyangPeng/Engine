// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 16:29)

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
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		 const WinSockInetAddressType& GetWinSockInetAddress() const noexcept override;
		 WinSockInetAddressType& GetWinSockInetAddress() override;

		 const SockAddressPtr Clone() const override;

		 const std::string GetAddress() const override;
		 int GetPort() const override;

	private:
		WinSockInetAddressType m_InetAddress;
		std::string m_AddressName;
	};
}

#endif // NETWORK_NETWORK_WRAPPERS_NETWORK_SOCK_INET_ADDRESS_H
