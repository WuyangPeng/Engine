// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.4 (2020/03/11 15:56)

#include "Network/NetworkExport.h" 

#include "BoostSockConnector.h"
#include "BoostSockConnectorHelper.h"
#include "System/Helper/PragmaWarning/AsioConnect.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h" 
#include "Network/Interface/SockStream.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/BaseMainManager.h" 
#include "Network/Interface/Data/AddressData.h"

using std::to_string;
using std::make_shared;
using namespace std::literals;
using boost::asio::connect;
using boost::asio::async_connect;
using TcpType = boost::asio::ip::tcp;

namespace
{
	const auto g_SynchronizeConnectorDescription = SYSTEM_TEXT("׼������ͬ�����ӣ���ַ��"s);
	const auto g_AsynchronousConnectorDescription = SYSTEM_TEXT("׼�������첽���ӣ���ַ��"s);
	const auto g_SynchronizeConnectorSuccessDescription = SYSTEM_TEXT("ͬ�����ӳɹ�����ַ��"s);
}

Network::BoostSockConnector
	::BoostSockConnector()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockConnector
	::~BoostSockConnector()
{
	NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostSockConnector)

bool Network::BoostSockConnector
	::Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	auto& ioService = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

	TcpType::resolver resolver{ ioService };
	ErrorCodeType errorCode;

	BoostSockConnectorHelper::PrintConnectorLog(g_SynchronizeConnectorDescription, AddressData{ sockAddress });

	connect(sockStream->GetBoostSockStream(), resolver.resolve(sockAddress->GetBoostInetAddress()), errorCode);

	if (errorCode == ErrorCodeType{})
	{
		BoostSockConnectorHelper::PrintConnectorSuccessLog(g_SynchronizeConnectorSuccessDescription, AddressData{ sockAddress });

		return true;
	}
	else
	{
		return false;
	}
}

void Network::BoostSockConnector
	::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	auto& ioService = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

	TcpType::resolver resolver{ ioService };

	BoostSockConnectorHelper::PrintConnectorLog(g_AsynchronousConnectorDescription, AddressData{ sockAddress });

	async_connect(sockStream->GetBoostSockStream(), resolver.resolve(sockAddress->GetBoostInetAddress()), [eventInterface](const ErrorCodeType& errorCode, const BoostInetAddressType& endpoint)
	{
		BoostSockConnectorHelper::EventFunction(errorCode, eventInterface, AddressData{ endpoint.address().to_string() + ":" + to_string(endpoint.port()), endpoint.port() });
	});
}

const Network::BoostSockConnector::SockConnectorPtr Network::BoostSockConnector
	::Clone() const
{
	NETWORK_CLASS_IS_VALID_CONST_9;

	return make_shared<ClassType>(*this);
}

