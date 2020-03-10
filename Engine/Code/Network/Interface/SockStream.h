// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.1.0 (2019/10/23 10:02)


#ifndef NETWORK_NETWORK_INTERFACE_SOCK_STREAM_H
#define NETWORK_NETWORK_INTERFACE_SOCK_STREAM_H

#include "Network/NetworkDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "NetworkInternalFwd.h"

#include <boost/noncopyable.hpp> 

template class NETWORK_DEFAULT_DECLARE std::weak_ptr<Network::SockStream>;
template class NETWORK_DEFAULT_DECLARE std::enable_shared_from_this<Network::SockStream>;

NETWORK_EXPORT_SHARED_PTR(SockStreamImpl);
EXPORT_NONCOPYABLE_CLASS(NETWORK);

namespace Network
{
	class ConfigurationStrategy;

	class NETWORK_DEFAULT_DECLARE SockStream : private boost::noncopyable, public std::enable_shared_from_this<SockStream>
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(SockStream);

	public:
		explicit SockStream(const ConfigurationStrategy& configurationStrategy);

		CLASS_INVARIANT_DECLARE;

		virtual int Send(const MessageBufferSharedPtr& messageBuffer);
		virtual int Receive(const MessageBufferSharedPtr& messageBuffer);

		// 异步回调，必须保证this、EventInterface和MessageBuffer的生命周期和线程安全。
		virtual void AsyncSend(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer);
		virtual void AsyncReceive(const EventInterfaceSharedPtr& eventInterface, const MessageBufferSharedPtr& messageBuffer);

		ACESockStreamType& GetACESockStream();
		BoostSockStreamType& GetBoostSockStream();
		WinSocketStreamType& GetNetworkSockStream();

		ACEHandleType GetACEHandle() const;

		void SetACEHandle(ACEHandleType handle);
		void SetNetworkHandle(WinSocketStreamType winSocket);

		bool CloseHandle();

		bool EnableNonBlock();

		const std::string GetRemoteAddress() const;
		int GetRemotePort() const;

	private:
		IMPL_TYPE_DECLARE(SockStream);
	};

	using SockStreamSharedPtr = std::shared_ptr<SockStream>;
	using ConstSockStreamSharedPtr = std::shared_ptr<const SockStream>;
}

#endif // NETWORK_NETWORK_INTERFACE_SOCK_STREAM_H
