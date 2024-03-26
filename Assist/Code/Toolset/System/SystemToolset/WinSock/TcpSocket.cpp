/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 22:27)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "TcpSocket.h"
#include "Detail/ConnectParameter.h"
#include "Detail/TcpSocketConnect.h"
#include "Detail/TcpSocketSend.h"
#include "System/Helper/Tools.h"
#include "System/Network/SocketPrototypes.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "Toolset/System/SystemToolset/Helper/SystemToolsetClassInvariantMacro.h"

#include <iostream>

SystemToolset::TcpSocket SystemToolset::TcpSocket::Create()
{
    return TcpSocket{ DisableNotThrow::Disable };
}

SystemToolset::TcpSocket::TcpSocket(DisableNotThrow disableNotThrow)
    : winSocket{ System::CreateTcpSocket() }
{
    InitSocket();

    System::UnusedFunction(disableNotThrow);

    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;
}

void SystemToolset::TcpSocket::InitSocket() const
{
    if (!System::IsSocketValid(winSocket))
    {
        throw std::runtime_error("CreateTcpSocket 失败。\n");
    }
}

SystemToolset::TcpSocket::TcpSocket(TcpSocket&& rhs) noexcept
    : winSocket{ rhs.winSocket }
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;
}

SystemToolset::TcpSocket& SystemToolset::TcpSocket::operator=(TcpSocket&& rhs) noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_1;

    winSocket = rhs.winSocket;

    return *this;
}

SystemToolset::TcpSocket::~TcpSocket() noexcept
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::CloseSocket);
}

void SystemToolset::TcpSocket::CloseSocket() const
{
    if (!System::CloseSocket(winSocket))
    {
        std::cout << "WinSockCleanup失败\n";
    }
}

#ifdef OPEN_CLASS_INVARIANT

bool SystemToolset::TcpSocket::IsValid() const noexcept
{
    return System::IsSocketValid(winSocket);
}

#endif  // OPEN_CLASS_INVARIANT

System::WinSocket SystemToolset::TcpSocket::GetWinSocket() const noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    return winSocket;
}

void SystemToolset::TcpSocket::Connect() const
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    const TcpSocketConnect tcpSocketConnect{ winSocket };

    tcpSocketConnect.Connect();
}

void SystemToolset::TcpSocket::Send() const noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    TcpSocketSend tcpSocketSend{ winSocket };

    tcpSocketSend.Send();
}
