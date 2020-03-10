// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.1.0 (2019/10/20 18:54)


#ifndef NETWORK_BOOST_WRAPPERS_BOOST_SOCK_INET_ADDRESS_H
#define NETWORK_BOOST_WRAPPERS_BOOST_SOCK_INET_ADDRESS_H

#include "Network/NetworkDll.h"

#include "Network/Interface/Detail/SockAddressImpl.h" 

namespace Network
{
	class NETWORK_HIDDEN_DECLARE BoostSockInetAddress : public SockAddressImpl
	{
	public:
		using ClassType = BoostSockInetAddress;
		using ParentType = SockAddressImpl;

	public:
		BoostSockInetAddress();
		explicit BoostSockInetAddress(int port);
		BoostSockInetAddress(const std::string& hostName, int port);
		virtual ~BoostSockInetAddress();

		BoostSockInetAddress(const BoostSockInetAddress& rhs);
		BoostSockInetAddress& operator=(const BoostSockInetAddress& rhs);
		BoostSockInetAddress(BoostSockInetAddress&& rhs) noexcept;
		BoostSockInetAddress& operator=(BoostSockInetAddress&& rhs) noexcept;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		virtual const BoostInetAddressType& GetBoostInetAddress() const override;
		virtual BoostInetAddressType& GetBoostInetAddress() override;

		virtual const SockAddressPtr Clone() const override;

		virtual const std::string GetAddress() const override;
		virtual int GetPort() const override;

	private:
		BoostInetAddressType m_Endpoint;
	};
}

#endif // NETWORK_BOOST_WRAPPERS_BOOST_SOCK_INET_ADDRESS_H
