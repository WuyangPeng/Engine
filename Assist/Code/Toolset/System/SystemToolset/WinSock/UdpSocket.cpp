/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 22:28)

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

void SystemToolset::UdpSocket::InitSocket() const
{
    if (!System::IsSocketValid(winSocket))
    {
        throw std::runtime_error("CreateUdpSocket ʧ�ܡ�\n");
    }
}

SystemToolset::UdpSocket::~UdpSocket() noexcept
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;

    CoreTools::NoexceptNoReturn(*this, &ClassType::CloseSocket);
}

void SystemToolset::UdpSocket::CloseSocket() const
{
    if (!System::CloseSocket(winSocket))
    {
        std::cout << "WinSockCleanupʧ��\n";
    }
}

SystemToolset::UdpSocket::UdpSocket(UdpSocket&& rhs) noexcept
    : winSocket{ rhs.winSocket }
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_1;
}

SystemToolset::UdpSocket& SystemToolset::UdpSocket::operator=(UdpSocket&& rhs) noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_1;

    winSocket = rhs.winSocket;

    return *this;
}

#ifdef OPEN_CLASS_INVARIANT

bool SystemToolset::UdpSocket::IsValid() const noexcept
{
    return System::IsSocketValid(winSocket);
}

#endif  // OPEN_CLASS_INVARIANT

System::WinSocket SystemToolset::UdpSocket::GetWinSocket() const noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    return winSocket;
}

void SystemToolset::UdpSocket::Send() const
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_CONST_1;

    UdpSocketSend udpSocketSend{ winSocket };

    udpSocketSend.Send();
}
