///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/22 22:24)

#include "Network/NetworkExport.h"

#include "BoostSockAcceptor.h"
#include "BoostSockAcceptorHelper.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/Data/AddressData.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"

using std::string;
using std::to_string;
using namespace std::literals;
using boost::numeric_cast;
using boost::asio::ip::make_address;
using TcpType = boost::asio::ip::tcp;

namespace
{
    constexpr auto synchronizeAccept = SYSTEM_TEXT("׼������ͬ�����ܣ���ַ��"sv);
    constexpr auto asynchronousAccept = SYSTEM_TEXT("׼�������첽���ܣ���ַ��"sv);
    constexpr auto synchronizeAcceptSuccess = SYSTEM_TEXT("ͬ�����ܳɹ�����ַ��"sv);
}

Network::BoostSockAcceptor::BoostSockAcceptor(int port)
    : ParentType{}, acceptor{ BASE_MAIN_MANAGER_SINGLETON.GetIOContext(), BoostInetAddressType{ TcpType::v4(), numeric_cast<uint16_t>(port) } }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockAcceptor::BoostSockAcceptor(const string& hostName, int port)
    : ParentType{}, acceptor{ BASE_MAIN_MANAGER_SINGLETON.GetIOContext(), BoostInetAddressType{ make_address(hostName), numeric_cast<uint16_t>(port) } }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockAcceptor::BoostSockAcceptor(BoostSockAcceptor&& rhs) noexcept
    : ParentType{}, acceptor{ std::move(rhs.acceptor) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockAcceptor& Network::BoostSockAcceptor::operator=(BoostSockAcceptor&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    if (this != &rhs)
    {
        rhs.acceptor = std::move(rhs.acceptor);
    }

    return *this;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockAcceptor)

bool Network::BoostSockAcceptor::Accept(SockStream& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    BoostSockAcceptorHelper::PrintAcceptLog(synchronizeAccept.data(), AddressData{ *this });

    ErrorCodeType errorCode{};

    acceptor.accept(sockStream.GetBoostSockStream(), errorCode);

    if (errorCode == ErrorCodeType{})
    {
        BoostSockAcceptorHelper::PrintAcceptSuccessLog(synchronizeAcceptSuccess.data(), AddressData{ sockStream });

        return true;
    }
    else
    {
        return false;
    }
}

bool Network::BoostSockAcceptor::Accept(SockStream& sockStream, SockAddress& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    BoostSockAcceptorHelper::PrintAcceptLog(synchronizeAccept.data(), AddressData{ *this });

    ErrorCodeType errorCode{};

    acceptor.accept(sockStream.GetBoostSockStream(), sockAddress.GetBoostInetAddress(), errorCode);

    if (errorCode == ErrorCodeType{})
    {
        BoostSockAcceptorHelper::PrintAcceptSuccessLog(synchronizeAcceptSuccess.data(), AddressData{ sockAddress });

        return true;
    }
    else
    {
        return false;
    }
}

void Network::BoostSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    BoostSockAcceptorHelper::PrintAcceptLog(asynchronousAccept.data(), AddressData{ *this });

    acceptor.async_accept(sockStream->GetBoostSockStream(), [eventInterface, sockStream](const ErrorCodeType& errorCode) {
        BoostSockAcceptorHelper::EventFunction(errorCode, eventInterface, AddressData{ *sockStream });
    });
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
void Network::BoostSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    BoostSockAcceptorHelper::PrintAcceptLog(asynchronousAccept.data(), AddressData{ *this });

    acceptor.async_accept(sockStream->GetBoostSockStream(), sockAddress->GetBoostInetAddress(), [eventInterface, sockAddress](const ErrorCodeType& errorCode) {
        BoostSockAcceptorHelper::EventFunction(errorCode, eventInterface, AddressData{ *sockAddress });
    });
}
#include STSTEM_WARNING_POP

bool Network::BoostSockAcceptor::EnableNonBlock()
{
    NETWORK_CLASS_IS_VALID_9;

    ErrorCodeType errorCode{};

    acceptor.non_blocking(true, errorCode);

    if (errorCode == ErrorCodeType{})
        return true;
    else
        return false;
}

Network::BoostHandleType Network::BoostSockAcceptor::GetBoostHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    return acceptor.native_handle();
}

string Network::BoostSockAcceptor::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return acceptor.local_endpoint().address().to_string() + ":"s + to_string(GetPort());
}

int Network::BoostSockAcceptor::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return acceptor.local_endpoint().port();
}
