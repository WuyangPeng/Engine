///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.8 (2023/05/09 14:49)

#include "Network/NetworkExport.h"

#include "NetworkSockAcceptor.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkWrappers/Detail/Address/NetworkSockInternetAddress.h"

Network::NetworkSockAcceptor::NetworkSockAcceptor(int port)
    : ParentType{}, socketHandle{ System::CreateSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
    if (!System::IsSocketValid(socketHandle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("创建本地端口失败！"s))
    }

    if (NetworkSockInternetAddress sockAddress{ port };
        !System::Bind(socketHandle, &sockAddress.GetWinSockInternetAddress()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("绑定失败！"s))
    }

    if (!System::Listen(socketHandle, System::soMaxConn))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("监听失败！"s))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockAcceptor::NetworkSockAcceptor(const std::string& hostName, int port)
    : ParentType{}, socketHandle{ System::CreateSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
    if (!System::IsSocketValid(socketHandle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("创建本地端口失败！"s))
    }

    if (NetworkSockInternetAddress sockAddress{ hostName, port };
        !System::Bind(socketHandle, &sockAddress.GetWinSockInternetAddress()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("绑定失败！"s))
    }

    if (!System::Listen(socketHandle, System::soMaxConn))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("监听失败！"s))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NetworkSockAcceptor)

bool Network::NetworkSockAcceptor::Accept(SockStream& sockStream, SockAddress& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    auto addressLength = boost::numeric_cast<int>(sizeof(sockAddress.GetWinSockInternetAddress()));

    if (const auto acceptHandle = System::Accept(socketHandle, &sockAddress.GetWinSockInternetAddress(), &addressLength);
        System::IsSocketValid(acceptHandle))
    {
        sockStream.SetNetworkHandle(acceptHandle);

        return true;
    }
    else
    {
        return false;
    }
}

bool Network::NetworkSockAcceptor::Accept(SockStream& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    NetworkSockInternetAddress sockAddress{ CoreTools::DisableNotThrow::Disable };

    auto addressLength = boost::numeric_cast<int>(sizeof(sockAddress.GetWinSockInternetAddress()));

    if (const auto acceptHandle = System::Accept(socketHandle, &sockAddress.GetWinSockInternetAddress(), &addressLength);
        System::IsSocketValid(acceptHandle))
    {
        sockStream.SetNetworkHandle(acceptHandle);

        return true;
    }
    else
    {
        return false;
    }
}

bool Network::NetworkSockAcceptor::EnableNonBlock() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    unsigned long nonBlock{ 1 };
    return IoctlSocket(socketHandle, System::IoctlSocketCmd::FionBio, &nonBlock);
}

System::WinSocket Network::NetworkSockAcceptor::GetWinSocket() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return socketHandle;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)

void Network::NetworkSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface);

    MAYBE_UNUSED const auto result = Accept(*sockStream);
}

void Network::NetworkSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface);

    MAYBE_UNUSED const auto result = Accept(*sockStream, *sockAddress);
}

#include STSTEM_WARNING_POP

std::string Network::NetworkSockAcceptor::GetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return std::string{};
}

int Network::NetworkSockAcceptor::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}
