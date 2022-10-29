///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/27 23:44)

#ifndef SYSTEM_TOOLSET_SOCKET_SEND_H
#define SYSTEM_TOOLSET_SOCKET_SEND_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "System/Network/Using/SocketPrototypesUsing.h"
#include "CoreTools/Helper/UserMacro.h"

#include <array>

namespace SystemToolset
{
    class SYSTEM_TOOLSET_HIDDEN_DECLARE SocketSend
    {
    public:
        using ClassType = SocketSend;

        using WinSocket = System::WinSocket;

    public:
        explicit SocketSend(WinSocket winSocket) noexcept;
        virtual ~SocketSend() noexcept = default;
        SocketSend(const SocketSend& rhs) noexcept = default;
        SocketSend& operator=(const SocketSend& rhs) noexcept = default;
        SocketSend(SocketSend&& rhs) noexcept = default;
        SocketSend& operator=(SocketSend&& rhs) noexcept = default;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        virtual void Send() = 0;

    protected:
        static constexpr auto bufferSize = 256;
        using BufferType = std::array<char, bufferSize>;

    protected:
        NODISCARD WinSocket GetWinSocket() const noexcept;
        NODISCARD const char* GetBuffer() const noexcept;

    private:
        WinSocket winSocket;
        BufferType buffer;
    };
}

#endif  // SYSTEM_TOOLSET_SOCKET_SEND_H