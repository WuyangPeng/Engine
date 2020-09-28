// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 16:30)

#include "Network/NetworkExport.h" 

#include "NetworkSockAcceptor.h"

#include "System/Network/SocketPrototypes.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/NetworkWrappers/Detail/Address/NetworkSockInetAddress.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;
#include "System/Helper/PragmaWarning/NumericCast.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
Network::NetworkSockAcceptor
	::NetworkSockAcceptor(int port)
	:ParentType{}, m_SocketHandle{ System::GetSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
	if (!System::IsSocketValid(m_SocketHandle))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("创建本地端口失败！"s));
	}

	NetworkSockInetAddress sockAddress{ port };

[[maybe_unused]]   auto result = System::Bind(m_SocketHandle, &sockAddress.GetWinSockInetAddress());
     result = System::Listen(m_SocketHandle, 5);

	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockAcceptor
	::NetworkSockAcceptor(const string& hostName, int port)
	:ParentType{}, m_SocketHandle{ System::GetSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
	if (!System::IsSocketValid(m_SocketHandle))
	{
		THROW_EXCEPTION(SYSTEM_TEXT("创建本地端口失败！"s));
	}

	NetworkSockInetAddress sockAddress{ hostName,port };

[[maybe_unused]] auto   result = System::Bind(m_SocketHandle, &sockAddress.GetWinSockInetAddress());
      result = System::Listen(m_SocketHandle, 5);

	NETWORK_SELF_CLASS_IS_VALID_9;
}

 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NetworkSockAcceptor)

bool Network::NetworkSockAcceptor
	::Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

	auto addrLen = boost::numeric_cast<int>(sizeof(sockAddress->GetWinSockInetAddress()));

	const auto acceptHandle = System::Accept(m_SocketHandle, &sockAddress->GetWinSockInetAddress(), &addrLen);

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

	const auto acceptHandle = System::Accept(m_SocketHandle, &sockAddress.GetWinSockInetAddress(), &addrLen);

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
	::EnableNonBlock() noexcept
{
	NETWORK_CLASS_IS_VALID_9;

	unsigned long nonblock{ 1 };
	return System::IoctlSocket(m_SocketHandle, System::IoctlSocketCmd::FionBio, &nonblock);
}

System::WinSocket Network::NetworkSockAcceptor
	::GetWinSocket() noexcept
{
	NETWORK_CLASS_IS_VALID_9;

	return m_SocketHandle;
}

void Network::NetworkSockAcceptor ::AsyncAccept([[maybe_unused]] const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
	NETWORK_CLASS_IS_VALID_9;

	Accept(sockStream);

 
}

void Network::NetworkSockAcceptor ::AsyncAccept([[maybe_unused]] const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

	Accept(sockStream, sockAddress);

 
}

const std::string Network::NetworkSockAcceptor
	::GetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return "";
}

int Network::NetworkSockAcceptor
	::GetPort() const noexcept
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return 0;
}
#include STSTEM_WARNING_POP
