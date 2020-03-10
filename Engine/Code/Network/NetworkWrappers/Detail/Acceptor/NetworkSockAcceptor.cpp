// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/02 10:16)

#include "Network/NetworkExport.h" 

#include "NetworkSockAcceptor.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkWrappers/Detail/Address/NetworkSockInetAddress.h"
#include "System/Helper/UnusedMacro.h"
#include "System/Network/SocketPrototypes.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"

#include <boost/numeric/conversion/cast.hpp>

using std::string;

 Network::NetworkSockAcceptor
	::NetworkSockAcceptor(int port)
	 :ParentType{}, m_SocketHandle{ System::GetSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
	if (!System::IsSocketValid(m_SocketHandle))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("创建本地端口失败！"));
	}	

	NetworkSockInetAddress sockAddress{ port };

	System::Bind(m_SocketHandle, &sockAddress.GetWinSockInetAddress());
	System::Listen(m_SocketHandle, 5);

	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockAcceptor
	::NetworkSockAcceptor(const string& hostName, int port)
	:ParentType{}, m_SocketHandle{ System::GetSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
	if (!System::IsSocketValid(m_SocketHandle))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("创建本地端口失败！"));
	}

	NetworkSockInetAddress sockAddress{ hostName,port };

	System::Bind(m_SocketHandle, &sockAddress.GetWinSockInetAddress());
	System::Listen(m_SocketHandle, 5);

	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockAcceptor
	::~NetworkSockAcceptor()
{
	NETWORK_SELF_CLASS_IS_VALID_9;	
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NetworkSockAcceptor)

bool Network::NetworkSockAcceptor
	::Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

	auto addrLen = boost::numeric_cast<int>(sizeof(sockAddress->GetWinSockInetAddress()));

	auto acceptHandle = System::Accept(m_SocketHandle, &sockAddress->GetWinSockInetAddress(), &addrLen);

	if (System::IsSocketValid(acceptHandle))
	{
		sockStream->SetNetworkHandle(acceptHandle);

		return true;
	}
	else
	{
		return false;
	}	 
}

bool Network::NetworkSockAcceptor
	::Accept(const SockStreamSharedPtr& sockStream)
{
	NETWORK_CLASS_IS_VALID_9;	

	NetworkSockInetAddress sockAddress;

	auto addrLen = boost::numeric_cast<int>(sizeof(sockAddress.GetWinSockInetAddress()));

	auto acceptHandle = System::Accept(m_SocketHandle, &sockAddress.GetWinSockInetAddress(), &addrLen);
	 
	if (System::IsSocketValid(acceptHandle))
	{
		sockStream->SetNetworkHandle(acceptHandle);

		return true;
	}
	else
	{
		return false;
	}
}

bool Network::NetworkSockAcceptor
	::EnableNonBlock()
{
	NETWORK_CLASS_IS_VALID_9;

	unsigned long nonblock{ 1 };
	return System::IoctlSocket(m_SocketHandle, System::IoctlSocketCmd::FionBio, &nonblock);
}

System::WinSocket Network::NetworkSockAcceptor
	::GetWinSocket()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_SocketHandle;
}

void Network::NetworkSockAcceptor
	::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
	NETWORK_CLASS_IS_VALID_9;

	Accept(sockStream);

	SYSTEM_UNUSED_ARG(eventInterface);
}

void Network::NetworkSockAcceptor
	::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream,  const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

	Accept(sockStream, sockAddress);

	SYSTEM_UNUSED_ARG(eventInterface);
}

const std::string Network::NetworkSockAcceptor
	::GetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return "";
}

int Network::NetworkSockAcceptor
	::GetPort() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return 0;
}

