///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.0.10 (2022/07/05 17:14)

#ifndef SYSTEM_TOOLSET_TCP_SOCKET_H
#define SYSTEM_TOOLSET_TCP_SOCKET_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "System/Network/Using/SocketPrototypesUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Toolset/System/SystemToolset/Helper/UserMacro.h"

namespace SystemToolset
{
    class SYSTEM_TOOLSET_DEFAULT_DECLARE TcpSocket final
    {
    public:
        using ClassType = TcpSocket;
        using WinSocket = System::WinSocket;
        using WinSockAddrIn = System::WinSockAddrIn;

    public:
        explicit TcpSocket(CoreTools::DisableNotThrow disableNotThrow);
        ~TcpSocket() noexcept;
        TcpSocket(const TcpSocket& rhs) noexcept = delete;
        TcpSocket& operator=(const TcpSocket& rhs) noexcept = delete;
        TcpSocket(TcpSocket&& rhs) noexcept = delete;
        TcpSocket& operator=(TcpSocket&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

        NODISCARD WinSocket GetSocket() noexcept;

        void Connect();
        void Send() noexcept;

    private:
        void CloseSocket();
        void Connect(const WinSockAddrIn& addr, int connectTime);

    private:
        WinSocket winSocket;
    };
}

#endif  // SYSTEM_TOOLSET_TCP_SOCKET_H