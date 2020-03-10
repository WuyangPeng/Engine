// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.1.0 (2019/11/29 10:19)


#ifndef NETWORK_NETWORK_INTERFACE_ADDRESS_DATA_H
#define NETWORK_NETWORK_INTERFACE_ADDRESS_DATA_H

#include "Network/NetworkDll.h" 

#include "Network/Interface/NetworkInternalFwd.h"

#include <string>

namespace Network
{
	class BoostSockStream;
	class BoostSockAcceptor;

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
