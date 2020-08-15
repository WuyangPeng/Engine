// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 13:42)

#ifndef NETWORK_ACE_WRAPPERS_ACE_SOCK_INET_ADDRESS_H
#define NETWORK_ACE_WRAPPERS_ACE_SOCK_INET_ADDRESS_H

#include "Network/NetworkDll.h"

#ifdef NETWORK_USE_ACE

#include "Network/Interface/Detail/SockAddressImpl.h" 

namespace Network
{
	class NETWORK_HIDDEN_DECLARE ACESockInetAddress : public SockAddressImpl
	{
	public:
		using ClassType = ACESockInetAddress;
		using ParentType = SockAddressImpl;

	public:
		ACESockInetAddress();
		explicit ACESockInetAddress(int port);
		ACESockInetAddress(const std::string& hostName, int port);
 

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		const ACEInetAddressType& GetACEInetAddress() const noexcept override;
		ACEInetAddressType& GetACEInetAddress() override;

		const SockAddressPtr Clone() const override;

		const std::string GetAddress() const override;
		int GetPort() const override;

	private:
		ACEInetAddress m_ACEInetAddress;
	};
}

#endif // NETWORK_USE_ACE

#endif // NETWORK_ACE_WRAPPERS_ACE_SOCK_INET_ADDRESS_H
