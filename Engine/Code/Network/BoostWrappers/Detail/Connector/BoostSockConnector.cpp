//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.1 (2020/10/28 17:54)

#include "Network/NetworkExport.h"

#include "BoostSockConnector.h"
#include "BoostSockConnectorHelper.h"
#include "System/Helper/PragmaWarning/AsioConnect.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/Data/AddressData.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"

using std::make_shared;
using std::to_string;
using namespace std::literals;
using boost::asio::async_connect;
using boost::asio::connect;
using TcpType = boost::asio::ip::tcp;

namespace
{
    const auto GetSynchronizeConnectorDescription()
    {
        static const auto synchronizeConnector = SYSTEM_TEXT("׼������ͬ�����ӣ���ַ��"s);

        return synchronizeConnector;
    }

    const auto GetAsynchronousConnectorDescription()
    {
        static const auto asynchronousConnector = SYSTEM_TEXT("׼�������첽���ӣ���ַ��"s);

        return asynchronousConnector;
    }

    const auto GetSynchronizeConnectorSuccessDescription()
    {
        static const auto synchronizeConnectorSuccess = SYSTEM_TEXT("ͬ�����ӳɹ�����ַ��"s);

        return synchronizeConnectorSuccess;
    }
}

Network::BoostSockConnector::BoostSockConnector() noexcept
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(Network, BoostSockConnector)

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
bool Network::BoostSockConnector::Connect(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto& ioService = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    TcpType::resolver resolver{ ioService };
    ErrorCodeType errorCode;

    BoostSockConnectorHelper::PrintConnectorLog(GetSynchronizeConnectorDescription(), AddressData{ *sockAddress });

    connect(sockStream->GetBoostSockStream(), resolver.resolve(sockAddress->GetBoostInetAddress()), errorCode);

    if (errorCode == ErrorCodeType{})
    {
        BoostSockConnectorHelper::PrintConnectorSuccessLog(GetSynchronizeConnectorSuccessDescription(), AddressData{ *sockAddress });

        return true;
    }
    else
    {
        return false;
    }
}

void Network::BoostSockConnector::AsyncConnect(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    auto& ioService = BASE_MAIN_MANAGER_SINGLETON.GetIOContext();

    TcpType::resolver resolver{ ioService };

    BoostSockConnectorHelper::PrintConnectorLog(GetAsynchronousConnectorDescription(), AddressData{ *sockAddress });

    async_connect(sockStream->GetBoostSockStream(), resolver.resolve(sockAddress->GetBoostInetAddress()), [eventInterface](const ErrorCodeType& errorCode, const BoostInetAddressType& endpoint) {
        BoostSockConnectorHelper::EventFunction(errorCode, eventInterface, AddressData{ endpoint.address().to_string() + ":" + to_string(endpoint.port()), endpoint.port() });
    });
}
#include STSTEM_WARNING_POP

const Network::BoostSockConnector::SockConnectorPtr Network::BoostSockConnector::Clone() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return make_shared<ClassType>(*this);
}
