/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 16:09)

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
    : ParentType{}, socketHandle{ CreateSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
    if (!System::IsSocketValid(socketHandle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�������ض˿�ʧ�ܣ�"s))
    }

    if (NetworkSockInternetAddress sockAddress{ port };
        !System::Bind(socketHandle, &sockAddress.GetWinSockInternetAddress()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ʧ�ܣ�"s))
    }

    if (!System::Listen(socketHandle, System::soMaxConn))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����ʧ�ܣ�"s))
    }

    NETWORK_SELF_CLASS_IS_VALID_9;
}

Network::NetworkSockAcceptor::NetworkSockAcceptor(const std::string& hostName, int port)
    : ParentType{}, socketHandle{ CreateSocket(System::ProtocolFamilies::Inet, System::SocketTypes::Stream, System::SocketProtocols::Tcp) }
{
    if (!System::IsSocketValid(socketHandle))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("�������ض˿�ʧ�ܣ�"s))
    }

    if (NetworkSockInternetAddress sockAddress{ hostName, port };
        !System::Bind(socketHandle, &sockAddress.GetWinSockInternetAddress()))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("��ʧ�ܣ�"s))
    }

    if (!System::Listen(socketHandle, System::soMaxConn))
    {
        THROW_EXCEPTION(SYSTEM_TEXT("����ʧ�ܣ�"s))
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
    return IoctlSocket(socketHandle, System::IoctlSocketCmd::FIonBlockingIO, &nonBlock);
}

System::WinSocket Network::NetworkSockAcceptor::GetWinSocket() noexcept
{
    NETWORK_CLASS_IS_VALID_9;

    return socketHandle;
}

void Network::NetworkSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, sockStream);

    MAYBE_UNUSED const auto result = Accept(*sockStream);
}

void Network::NetworkSockAcceptor::AsyncAccept(const EventInterfaceSharedPtr& eventInterface, const SockStreamSharedPtr& sockStream, const SockAddressSharedPtr& sockAddress)
{
    NETWORK_CLASS_IS_VALID_9;

    System::UnusedFunction(eventInterface, sockStream, sockAddress);

    MAYBE_UNUSED const auto result = Accept(*sockStream, *sockAddress);
}

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
