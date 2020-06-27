// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.4 (2020/03/11 09:55)

#ifndef NETWORK_NETWORK_INTERFACE_ADDRESS_DATA_H
#define NETWORK_NETWORK_INTERFACE_ADDRESS_DATA_H

#include "Network/NetworkDll.h" 

#include "Network/Interface/NetworkInternalFwd.h"

#include <string>

namespace Network
{
	class NETWORK_HIDDEN_DECLARE AddressData
	{
	public:
		using ClassType = AddressData;

	public:
		AddressData(const std::string& address, int port);
		explicit AddressData(const SockStreamSharedPtr& sockStream);
		explicit AddressData(const BoostSockAcceptor& boostSockAcceptor);
		explicit AddressData(const BoostSockStream& boostSockStream);
		explicit AddressData(const SockAddressSharedPtr& sockAddress);

		CLASS_INVARIANT_DECLARE;

		std::string GetAddress() const;
		int GetPort() const;

	private:
		std::string m_Address;
		int m_Port;
	};
}

#endif // NETWORK_NETWORK_INTERFACE_ADDRESS_DATA_H
