// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 10:06)

#ifndef NETWORK_NETWORK_INTERFACE_NULL_SOCK_ADDRESS_H
#define NETWORK_NETWORK_INTERFACE_NULL_SOCK_ADDRESS_H

#include "Network/NetworkDll.h"

#include "SockAddressImpl.h"

namespace Network
{
	class NETWORK_HIDDEN_DECLARE NullSockAddress :public SockAddressImpl
	{
	public:
		using ClassType = NullSockAddress;
		using ParentType = SockAddressImpl;

	public:
		NullSockAddress(const std::string& address, int ip);
		virtual ~NullSockAddress();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual const SockAddressPtr Clone() const override;

		virtual const std::string GetAddress() const override;
		virtual int GetPort() const override;

	private:
		std::string m_Address;
		int m_IP;
	};
}

#endif // NETWORK_NETWORK_INTERFACE_NULL_SOCK_ADDRESS_H
