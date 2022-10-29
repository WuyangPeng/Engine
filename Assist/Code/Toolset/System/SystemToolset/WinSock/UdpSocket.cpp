///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/27 1:03)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "UdpSocket.h"
#include "Detail/UdpSocketSend.h"
#include "System/Helper/Tools.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "Toolset/System/SystemToolset/Helper/SystemToolsetClassInvariantMacro.h"

#include <exception>
#include <iostream>

using std::cout;

SystemToolset::UdpSocket SystemToolset::UdpSocket::Create()
{
    return UdpSocket{ DisableNotThrow::Disable };
}

SystemToolset::UdpSocket::UdpSocket(DisableNotThrow disableNotThrow)
    : winSocket{ System::CreateUdpSocket() }
{
    InitSocket();

    System::UnusedFunction(disableNotThrow);

    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;
}

void SystemToolset::UdpSocket::InitSocket()
{
    if (!System::IsSocketValid(winSocket))
    {
        throw std::runtime_error("CreateUdpSocket 失败。\n");
    }
}

SystemToolset::UdpSocket::~UdpSocket() noexcept
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::CloseSocket);
}

void SystemToolset::UdpSocket::CloseSocket()
{
    if (!System::CloseSocket(winSocket))
    {
        cout << "WinSockCleanup失败\n";
    }
}

SystemToolset::UdpSocket::UdpSocket(UdpSocket&& rhs) noexcept
    : winSocket{ std::move(rhs.winSocket) }
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;
}

SystemToolset::UdpSocket& SystemToolset::UdpSocket::operator=(UdpSocket&& rhs) noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_1;

    winSocket = std::move(rhs.winSocket);

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

bool SystemToolset::UdpSocket::IsValid() const noexcept
{
    if (System::IsSocketValid(winSocket))
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

System::WinSocket SystemToolset::UdpSocket::GetWinSocket() noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    return winSocket;
}

void SystemToolset::UdpSocket::Send()
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    UdpSocketSend udpSocketSend{ winSocket };

    udpSocketSend.Send();
}
