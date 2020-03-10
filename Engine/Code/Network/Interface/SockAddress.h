// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.1.0 (2019/10/20 19:00)


#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string> 
 
template class NETWORK_DEFAULT_DECLARE std::weak_ptr<Network::SockAddress>;
template class NETWORK_DEFAULT_DECLARE std::enable_shared_from_this<Network::SockAddress>;

NETWORK_EXPORT_SHARED_PTR(SockAddressImpl);

namespace Network
{	
	class NETWORK_DEFAULT_DECLARE SockAddress : public std::enable_shared_from_this<SockAddress>
	{
	public:
		// ��᷵���ڲ����������ã������޷�ʹ���ӳٸ��ơ�
		COPY_UNSHARE_CLASSES_TYPE_DECLARE_USE_SWAP(SockAddress); 

	public:
		explicit SockAddress(const ConfigurationStrategy& configurationStrategy);
		SockAddress(const std::string& hostName, int port,const ConfigurationStrategy& configurationStrategy);
		SockAddress(int port, const ConfigurationStrategy& configurationStrategy);

		IMPL_MOVE_OPERATOR_COMPLETE_DECLARE(SockAddress);

		// ACE ר�ã�����������׳��쳣��
		const ACEInetAddressType& GetACEInetAddress() const;
		ACEInetAddressType& GetACEInetAddress();

		// boost ר�ã�����������׳��쳣��
		const BoostInetAddressType& GetBoostInetAddress() const;
		BoostInetAddressType& GetBoostInetAddress();

		// Network ר�ã�����������׳��쳣��
		const WinSockInetAddressType& GetWinSockInetAddress() const;
		WinSockInetAddressType& GetWinSockInetAddress();

		const std::string GetAddress() const;
		int GetPort() const;

	private:
		IMPL_TYPE_DECLARE(SockAddress); 
	};	

	using SockAddressSharedPtr = std::shared_ptr<SockAddress>;
	using ConstSockAddressSharedPtr = std::shared_ptr<const SockAddress>;
} 

#endif // NETWORK_NETWORK_INTERFACE_SOCK_ADDRESS_H
