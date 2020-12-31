// Copyright (c) 2010-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒýÇæ°æ±¾£º0.0.2.4 (2020/03/11 16:30)

#include "Network/NetworkExport.h"

#include "NetworkSockAcceptor.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Network/Flags/SocketPrototypesFlags.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Helper/ClassInvariant/NetworkClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MessageEvent/EventInterface.h"
#include "Network/Interface/BaseMainManager.h"
#include "Network/Interface/SockAddress.h"
#include "Network/Interface/SockStream.h"
#include "Network/NetworkWrappers/Detail/Address/NetworkSockInetAddress.h"

using std::string;

Network::NetworkSockAcceptor::NetworkSockAcceptor(int port)
    : ParentType{}, m_SocketHandle{ System::GetSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
    if (!System::IsSocketValid(m_SocketHandle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("´´½¨±¾µØ¶Ë¿ÚÊ§°Ü£¡"s));
    }

    NetworkSockInetAddress sockAddress{ port };

    if (!System::Bind(m_SocketHandle, &sockAddress.GetWinSockInetAddress()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("°ó¶¨Ê§°Ü£¡"s));
    }

    if (!System::Listen(m_SocketHandle, System::g_SoMaxConn))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("¼àÌýÊ§°Ü£¡"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockAcceptor::NetworkSockAcceptor(const string& hostName, int port)
    : ParentType{}, m_SocketHandle{ System::GetSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
    if (!System::IsSocketValid(m_SocketHandle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("´´½¨±¾µØ¶Ë¿ÚÊ§°Ü£¡"s));
    }

    NetworkSockInetAddress sockAddress{ hostName, port };

    if (!System::Bind(m_SocketHandle, &sockAddress.GetWinSockInetAddress()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("°ó¶¨Ê§°Ü£¡"s));
    }

    if (!System::Listen(m_SocketHandle, System::g_SoMaxConn))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("¼àÌýÊ§°Ü£¡"s));
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Network, NetworkSockAcceptor)

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26415)
#include SYSTEM_WARNING_DISABLE(26418)
bool Network::NetworkSockAcceptor::Accept(const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
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

bool Network::NetworkSockAcceptor::Accept(const SockStreamSharedPtr& sockStream)
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
#include STSTEM_WARNING_POP

bool Network::NetworkSockAcceptor::EnableNonBlock() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    unsigned long nonblock{ 1 };
    return System::IoctlSocket(m_SocketHandle, System::IoctlSocketCmd::FionBio, &nonblock);
}

System::WinSocket Network::NetworkSockAcceptor::GetWinSocket() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return m_SocketHandle;
}

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26418)
void Network::NetworkSockAcceptor::AsyncAccept([[maybe_unused]] const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    [[maybe_unused]] const auto result = Accept(sockStream);
}

void Network::NetworkSockAcceptor::AsyncAccept([[maybe_unused]] const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    [[maybe_unused]] const auto result = Accept(sockStream, sockAddress);
}
#include STSTEM_WARNING_POP

const string Network::NetworkSockAcceptor::GetAddress() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return string{};
}

int Network::NetworkSockAcceptor::GetPort() const noexcept
{
    NETWORK_CLASS_IS_VALID_CONST_9;

    return 0;
}
