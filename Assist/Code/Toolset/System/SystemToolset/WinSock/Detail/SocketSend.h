///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 10:21)

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