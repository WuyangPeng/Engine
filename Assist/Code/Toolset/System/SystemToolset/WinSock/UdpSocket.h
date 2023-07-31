///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:20)

#ifndef SYSTEM_TOOLSET_UDP_SOCKET_H
#define SYSTEM_TOOLSET_UDP_SOCKET_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "System/Network/Using/SocketPrototypesUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "Toolset/System/SystemToolset/Helper/UserMacro.h"

namespace SystemToolset
{
    class SYSTEM_TOOLSET_DEFAULT_DECLARE UdpSocket final
    {
    public:
        using ClassType = UdpSocket;

        using WinSocket = System::WinSocket;
        using DisableNotThrow = CoreTools::DisableNotThrow;

    public:
        NODISCARD static UdpSocket Create();

        ~UdpSocket() noexcept;
        UdpSocket(const UdpSocket& rhs) noexcept = delete;
        UdpSocket& operator=(const UdpSocket& rhs) noexcept = delete;
        UdpSocket(UdpSocket&& rhs) noexcept;
        UdpSocket& operator=(UdpSocket&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD WinSocket GetWinSocket() noexcept;

        void Send();

    private:
        explicit UdpSocket(DisableNotThrow disableNotThrow);

        void InitSocket();
        void CloseSocket();

    private:
        WinSocket winSocket;
    };
}

#endif  // SYSTEM_TOOLSET_UDP_SOCKET_H