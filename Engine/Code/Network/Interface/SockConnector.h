// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 09:58)

#ifndef NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_H
#define NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_H

#include "Network/NetworkDll.h"

#include "NetworkInternalFwd.h"
#include "CoreTools/Helper/ExportMacro.h" 

#include <boost/noncopyable.hpp>

NETWORK_EXPORT_SHARED_PTR(SockConnectorImpl);
EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
	class NETWORK_DEFAULT_DECLARE SockConnector : private boost::noncopyable
	{
	public:
		DELAY_COPY_UNSHARE_CLASSES_TYPE_DECLARE(SockConnector);

	public:
		explicit SockConnector(const ConfigurationStrategy& configurationStrategy);

		CLASS_INVARIANT_DECLARE;

		bool Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress);

		// 异步回调，必须保证this、EventInterface、SockStream和SockAddress的生命周期和线程安全。
		void AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress);

	private:
		IMPL_TYPE_DECLARE(SockConnector);
	};
}

#endif // NETWORK_NETWORK_INTERFACE_SOCK_CONNECTOR_H
