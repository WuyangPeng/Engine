// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.1.0 (2019/10/18 13:40)


#ifndef NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_IMPL_H
#define NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_IMPL_H

#include "Network/NetworkDll.h"

#include "Network/Interface/NetworkInternalFwd.h"

#include <boost/noncopyable.hpp>

namespace Network
{	
	class NETWORK_HIDDEN_DECLARE SockAcceptorImpl : private boost::noncopyable
	{
	public:
		using ClassType = SockAcceptorImpl;		

	public:
		SockAcceptorImpl ();
		virtual ~SockAcceptorImpl();

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		virtual bool Accept(const SockStreamSharedPtr& sockStream) = 0;
		virtual bool Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress) = 0;		

		virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream) = 0;
		virtual void AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream,const SockAddressSharedPtr& sockAddress) = 0;
		
		virtual bool EnableNonBlock() = 0;		

		virtual const std::string GetAddress() const = 0;
		virtual int GetPort() const = 0;

		virtual ACEHandleType GetACEHandle();
		virtual BoostHandleType GetBoostHandle();
		virtual WinSocketType GetWinSocket();
	};	
} 

#endif // NETWORK_NETWORK_INTERFACE_SOCK_ACCEPTOR_IMPL_H
