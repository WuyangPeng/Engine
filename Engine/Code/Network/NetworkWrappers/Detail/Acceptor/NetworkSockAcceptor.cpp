///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/23 17:31)

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
#include "Network/NetworkWrappers/Detail/Address/NetworkSockInetAddress.h"

using std::string;

Network::NetworkSockAcceptor::NetworkSockAcceptor(int port)
    : ParentType{}, socketHandle{ System::CreateSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
    if (!System::IsSocketValid(socketHandle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("创建本地端口失败！"s));
    }

    NetworkSockInetAddress sockAddress{ port };

    if (!System::Bind(socketHandle, &sockAddress.GetWinSockInetAddress()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("绑定失败！"s));
    }

    if (!System::Listen(socketHandle, System::soMaxConn))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("监听失败！"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockAcceptor::NetworkSockAcceptor(const string& hostName, int port)
    : ParentType{}, socketHandle{ System::CreateSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
    if (!System::IsSocketValid(socketHandle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("创建本地端口失败！"s));
    }

    NetworkSockInetAddress sockAddress{ hostName, port };

    if (!System::Bind(socketHandle, &sockAddress.GetWinSockInetAddress()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("绑定失败！"s));
    }

    if (!System::Listen(socketHandle, System::soMaxConn))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("监听失败！"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NetworkSockAcceptor)

bool Network::NetworkSockAcceptor::Accept(SockStream& sockStream, SockAddress& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    auto addrLen = boost::numeric_cast<int>(sizeof(sockAddress.GetWinSockInetAddress()));

    const auto acceptHandle = System::Accept(socketHandle, &sockAddress.GetWinSockInetAddress(), &addrLen);

    if (System::IsSocketValid(acceptHandle))
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

    NetworkSockInetAddress sockAddress{ CoreTools::DisableNotThrow::Disable };

    auto addrLen = boost::numeric_cast<int>(sizeof(sockAddress.GetWinSockInetAddress()));

    const auto acceptHandle = System::Accept(socketHandle, &sockAddress.GetWinSockInetAddress(), &addrLen);

    if (System::IsSocketValid(acceptHandle))
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

    unsigned long nonblock{ 1 };
    return System::IoctlSocket(socketHandle, System::IoctlSocketCmd::FionBio, &nonblock);
}

System::WinSocket Network::NetworkSockAcceptor::GetWinSocket() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return socketHandle;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
void Network::NetworkSockAcceptor::AsyncAccept(MAYBE_UNUSED const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    MAYBE_UNUSED const auto result = Accept(*sockStream);
}

void Network::NetworkSockAcceptor::AsyncAccept(MAYBE_UNUSED const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    MAYBE_UNUSED const auto result = Accept(*sockStream, *sockAddress);
}
#include STSTEM_WARNING_POP

string Network::NetworkSockAcceptor::GetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return string{};
}

int Network::NetworkSockAcceptor::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}
