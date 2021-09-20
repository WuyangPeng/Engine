///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/05 15:04)

#ifndef SYSTEM_TOOLSET_UDP_SOCKET_H
#define SYSTEM_TOOLSET_UDP_SOCKET_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "System/Network/Using/SocketPrototypesUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Toolset/System/SystemToolset/Helper/UserMacro.h"

namespace SystemToolset
{
    class SYSTEM_TOOLSET_DEFAULT_DECLARE UdpSocket final
    {
    public:
        using ClassType = UdpSocket;
        using WinSocket = System::WinSocket;
        using WinSockAddrIn = System::WinSockAddrIn;

    public:
        explicit UdpSocket(CoreTools::DisableNotThrow disableNotThrow);
        ~UdpSocket() noexcept;
        UdpSocket(const UdpSocket& rhs) noexcept = delete;
        UdpSocket& operator=(const UdpSocket& rhs) noexcept = delete;
        UdpSocket(UdpSocket&& rhs) noexcept = delete;
        UdpSocket& operator=(UdpSocket&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD WinSocket GetSocket() noexcept;
        void Send();

    private:
        void CloseSocket();
        void Send(const WinSockAddrIn& addr);

    private:
        WinSocket winSocket;
    };
}

#endif  // SYSTEM_TOOLSET_UDP_SOCKET_H