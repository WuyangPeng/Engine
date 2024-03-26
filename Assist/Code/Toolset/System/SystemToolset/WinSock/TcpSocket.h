/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 22:23)

#ifndef SYSTEM_TOOLSET_TCP_SOCKET_H
#define SYSTEM_TOOLSET_TCP_SOCKET_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "System/Network/Using/SocketPrototypesUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/UserMacro.h"
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

        NODISCARD WinSocket GetWinSocket() const noexcept;

        void Connect() const;
        void Send() const noexcept;

    private:
        explicit TcpSocket(DisableNotThrow disableNotThrow);

        void InitSocket() const;
        void CloseSocket() const;

    private:
        WinSocket winSocket;
    };
}

#endif  // SYSTEM_TOOLSET_TCP_SOCKET_H