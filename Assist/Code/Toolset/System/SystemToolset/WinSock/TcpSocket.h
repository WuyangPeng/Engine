///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/27 0:59)

#ifndef SYSTEM_TOOLSET_TCP_SOCKET_H
#define SYSTEM_TOOLSET_TCP_SOCKET_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "System/Network/Using/SocketPrototypesUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h" 
#include "Toolset/System/SystemToolset/Helper/UserMacro.h"

namespace SystemToolset
{
    class SYSTEM_TOOLSET_DEFAULT_DECLARE TcpSocket final
    {
    public:
        using ClassType = TcpSocket;

        using WinSocket = System::WinSocket;
        using DisableNotThrow = CoreTools::DisableNotThrow;

    public:
        NODISCARD static TcpSocket Create();

        ~TcpSocket() noexcept;
        TcpSocket(const TcpSocket& rhs) noexcept = delete;
        TcpSocket& operator=(const TcpSocket& rhs) noexcept = delete;
        TcpSocket(TcpSocket&& rhs) noexcept;
        TcpSocket& operator=(TcpSocket&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD WinSocket GetWinSocket() noexcept;

        void Connect();
        void Send() noexcept;

    private:
        explicit TcpSocket(DisableNotThrow disableNotThrow);

        void InitSocket();
        void CloseSocket();

    private:
        WinSocket winSocket;
    };
}

#endif  // SYSTEM_TOOLSET_TCP_SOCKET_H