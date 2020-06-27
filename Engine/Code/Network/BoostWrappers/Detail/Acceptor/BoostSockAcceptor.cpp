// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.4 (2020/03/11 15:51)

#include "Network/NetworkExport.h" 

#include "BoostSockAcceptor.h"
#include "BoostSockAcceptorHelper.h" 
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/Data/AddressData.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::move;
using std::string;
using std::to_string;
using namespace std::literals;
using boost::numeric_cast;
using boost::asio::ip::make_address;
using TcpType = boost::asio::ip::tcp;

namespace
{
	const auto g_SynchronizeAcceptDescription = SYSTEM_TEXT("准备进行同步接受，地址："s);
	const auto g_AsynchronousAcceptDescription = SYSTEM_TEXT("准备进行异步接受，地址："s);
	const auto g_SynchronizeAcceptSuccessDescription = SYSTEM_TEXT("同步接受成功，地址："s);
}

Network::BoostSockAcceptor
	::BoostSockAcceptor(int port)
	:ParentType{}, m_Acceptor{ BASE_MAIN_MANAGER_SINGLETON.GetIOContext(), BoostInetAddressType{ TcpType::v4(), numeric_cast<uint16_t>(port) } }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockAcceptor
	::BoostSockAcceptor(const string& hostName, int port)
	:ParentType{}, m_Acceptor{ BASE_MAIN_MANAGER_SINGLETON.GetIOContext(), BoostInetAddressType{ make_address(hostName), numeric_cast<uint16_t>(port) } }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockAcceptor
	::BoostSockAcceptor(BoostSockAcceptor&& rhs) noexcept
	:ParentType{}, m_Acceptor{ move(rhs.m_Acceptor) }
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockAcceptor& Network::BoostSockAcceptor
	::operator=(BoostSockAcceptor&& rhs) noexcept
{
	NETWORK_CLASS_IS_VALID_9;

	rhs.m_Acceptor = move(rhs.m_Acceptor);

	return *this;
}

Network::BoostSockAcceptor
	::~BoostSockAcceptor()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockAcceptor)

bool Network::BoostSockAcceptor
	::Accept(const SockStreamSharedPtr& sockStream)
{
	NETWORK_CLASS_IS_VALID_9;

	BoostSockAcceptorHelper::PrintAcceptLog(g_SynchronizeAcceptDescription, AddressData{ *this });

	ErrorCodeType errorCode{};

	m_Acceptor.accept(sockStream->GetBoostSockStream(), errorCode);

	if (errorCode == ErrorCodeType{})
	{
		BoostSockAcceptorHelper::PrintAcceptSuccessLog(g_SynchronizeAcceptSuccessDescription, AddressData{ sockStream });

		return true;
	}
	else
	{
		return false;
	}
}

bool Network::BoostSockAcceptor
	::Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

	BoostSockAcceptorHelper::PrintAcceptLog(g_SynchronizeAcceptDescription, AddressData{ *this });

	ErrorCodeType errorCode{};

	m_Acceptor.accept(sockStream->GetBoostSockStream(), sockAddress->GetBoostInetAddress(), errorCode);

	if (errorCode == ErrorCodeType{})
	{
		BoostSockAcceptorHelper::PrintAcceptSuccessLog(g_SynchronizeAcceptSuccessDescription, AddressData{ sockAddress });

		return true;
	}
	else
	{
		return false;
	}
}

void Network::BoostSockAcceptor
	::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
	NETWORK_CLASS_IS_VALID_9;

	BoostSockAcceptorHelper::PrintAcceptLog(g_AsynchronousAcceptDescription, AddressData{ *this });

	m_Acceptor.async_accept(sockStream->GetBoostSockStream(), [eventInterface, sockStream](const ErrorCodeType& errorCode)
	{
		BoostSockAcceptorHelper::EventFunction(errorCode, eventInterface, AddressData{ sockStream });
	});
}

void Network::BoostSockAcceptor
	::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_9;

	BoostSockAcceptorHelper::PrintAcceptLog(g_AsynchronousAcceptDescription, AddressData{ *this });

	m_Acceptor.async_accept(sockStream->GetBoostSockStream(), sockAddress->GetBoostInetAddress(), [eventInterface, sockAddress](const ErrorCodeType& errorCode)
	{
		BoostSockAcceptorHelper::EventFunction(errorCode, eventInterface, AddressData{ sockAddress });
	});
}

bool Network::BoostSockAcceptor
	::EnableNonBlock()
{
	NETWORK_CLASS_IS_VALID_9;

	ErrorCodeType errorCode{};

	m_Acceptor.non_blocking(true, errorCode);

	if (errorCode == ErrorCodeType{})
		return true;
	else
		return false;
}

Network::BoostHandleType Network::BoostSockAcceptor
	::GetBoostHandle()
{
	NETWORK_CLASS_IS_VALID_9;

	return m_Acceptor.native_handle();
}

const string Network::BoostSockAcceptor
	::GetAddress() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Acceptor.local_endpoint().address().to_string() + ":" + to_string(GetPort());
}

int Network::BoostSockAcceptor
	::GetPort() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return m_Acceptor.local_endpoint().port();
}


