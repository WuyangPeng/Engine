///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/15 17:16)

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

using namespace std::literals;

namespace
{
    constexpr auto synchronizeAccept = SYSTEM_TEXT("准备进行同步接受，地址："sv);
    constexpr auto asynchronousAccept = SYSTEM_TEXT("准备进行异步接受，地址："sv);
    constexpr auto synchronizeAcceptSuccess = SYSTEM_TEXT("同步接受成功，地址："sv);
}

Network::BoostSockAcceptor::BoostSockAcceptor(int port)
    : ParentType{}, acceptor{ BASE_MAIN_MANAGER_SINGLETON.GetContext(), BoostInternetAddressType{ boost::asio::ip::tcp::v4(), boost::numeric_cast<uint16_t>(port) } }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockAcceptor::BoostSockAcceptor(const std::string& hostName, int port)
    : ParentType{}, acceptor{ BASE_MAIN_MANAGER_SINGLETON.GetContext(), BoostInternetAddressType{ boost::asio::ip::make_address(hostName), boost::numeric_cast<uint16_t>(port) } }
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
        acceptor = std::move(rhs.acceptor);
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

    acceptor.accept(sockStream.GetBoostSockStream(), sockAddress.GetBoostInternetAddress(), errorCode);

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

void Network::BoostSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, sockStream, sockAddress);

    BoostSockAcceptorHelper::PrintAcceptLog(asynchronousAccept.data(), AddressData{ *this });

    acceptor.async_accept(sockStream->GetBoostSockStream(), sockAddress->GetBoostInternetAddress(), [eventInterface, sockAddress](const ErrorCodeType& errorCode) {
        BoostSockAcceptorHelper::EventFunction(errorCode, eventInterface, AddressData{ *sockAddress });
    });
}

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

std::string Network::BoostSockAcceptor::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return acceptor.local_endpoint().address().to_string() + ":"s + std::to_string(GetPort());
}

int Network::BoostSockAcceptor::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return acceptor.local_endpoint().port();
}
