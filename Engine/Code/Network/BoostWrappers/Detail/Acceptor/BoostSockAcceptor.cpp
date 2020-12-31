//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.1 (2020/10/28 17:03)

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

using std::move;
using std::string;
using std::to_string;
using namespace std::literals;
using boost::numeric_cast;
using boost::asio::ip::make_address;
using TcpType = boost::asio::ip::tcp;

namespace
{
    const auto GetSynchronizeAcceptDescription()
    {
        static const auto synchronizeAccept = SYSTEM_TEXT("准备进行同步接受，地址："s);

        return synchronizeAccept;
    }

    const auto GetAsynchronousAcceptDescription()
    {
        static const auto asynchronousAccept = SYSTEM_TEXT("准备进行异步接受，地址："s);

        return asynchronousAccept;
    }

    const auto GetSynchronizeAcceptSuccessDescription()
    {
        static const auto synchronizeAcceptSuccess = SYSTEM_TEXT("同步接受成功，地址："s);

        return synchronizeAcceptSuccess;
    }
}

Network::BoostSockAcceptor::BoostSockAcceptor(int port)
    : ParentType{}, m_Acceptor{ BASE_MAIN_MANAGER_SINGLETON.GetIOContext(), BoostInetAddressType{ TcpType::v4(), numeric_cast<uint16_t>(port) } }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockAcceptor::BoostSockAcceptor(const string& hostName, int port)
    : ParentType{}, m_Acceptor{ BASE_MAIN_MANAGER_SINGLETON.GetIOContext(), BoostInetAddressType{ make_address(hostName), numeric_cast<uint16_t>(port) } }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockAcceptor::BoostSockAcceptor(BoostSockAcceptor&& rhs) noexcept
    : ParentType{}, m_Acceptor{ std::move(rhs.m_Acceptor) }
{
    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::BoostSockAcceptor& Network::BoostSockAcceptor::operator=(BoostSockAcceptor&& rhs) noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    rhs.m_Acceptor = std::move(rhs.m_Acceptor);

    return *this;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, BoostSockAcceptor)

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
bool Network::BoostSockAcceptor::Accept(const SockStreamSharedPtr& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    BoostSockAcceptorHelper::PrintAcceptLog(GetSynchronizeAcceptDescription(), AddressData{ *this });

    ErrorCodeType errorCode{};

    m_Acceptor.accept(sockStream->GetBoostSockStream(), errorCode);

    if (errorCode == ErrorCodeType{})
    {
        BoostSockAcceptorHelper::PrintAcceptSuccessLog(GetSynchronizeAcceptSuccessDescription(), AddressData{ *sockStream });

        return true;
    }
    else
    {
        return false;
    }
}
#include STSTEM_WARNING_POP

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
bool Network::BoostSockAcceptor::Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    BoostSockAcceptorHelper::PrintAcceptLog(GetSynchronizeAcceptDescription(), AddressData{ *this });

    ErrorCodeType errorCode{};

    m_Acceptor.accept(sockStream->GetBoostSockStream(), sockAddress->GetBoostInetAddress(), errorCode);

    if (errorCode == ErrorCodeType{})
    {
        BoostSockAcceptorHelper::PrintAcceptSuccessLog(GetSynchronizeAcceptSuccessDescription(), AddressData{ *sockAddress });

        return true;
    }
    else
    {
        return false;
    }
}
#include STSTEM_WARNING_POP

void Network::BoostSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    BoostSockAcceptorHelper::PrintAcceptLog(GetAsynchronousAcceptDescription(), AddressData{ *this });

    m_Acceptor.async_accept(sockStream->GetBoostSockStream(), [eventInterface, sockStream](const ErrorCodeType& errorCode) {
        BoostSockAcceptorHelper::EventFunction(errorCode, eventInterface, AddressData{ *sockStream });
    });
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
void Network::BoostSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    BoostSockAcceptorHelper::PrintAcceptLog(GetAsynchronousAcceptDescription(), AddressData{ *this });

    m_Acceptor.async_accept(sockStream->GetBoostSockStream(), sockAddress->GetBoostInetAddress(), [eventInterface, sockAddress](const ErrorCodeType& errorCode) {
        BoostSockAcceptorHelper::EventFunction(errorCode, eventInterface, AddressData{ *sockAddress });
    });
}
#include STSTEM_WARNING_POP

bool Network::BoostSockAcceptor::EnableNonBlock()
{
    NETWORK_CLASS_IS_VALID_9;

    ErrorCodeType errorCode{};

    m_Acceptor.non_blocking(true, errorCode);

    if (errorCode == ErrorCodeType{})
        return true;
    else
        return false;
}

Network::BoostHandleType Network::BoostSockAcceptor::GetBoostHandle()
{
    NETWORK_CLASS_IS_VALID_9;

    return m_Acceptor.native_handle();
}

const string Network::BoostSockAcceptor::GetAddress() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Acceptor.local_endpoint().address().to_string() + ":"s + to_string(GetPort());
}

int Network::BoostSockAcceptor::GetPort() const
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return m_Acceptor.local_endpoint().port();
}
