/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 22:23)

#ifndef SYSTEM_TOOLSET_UDP_SOCKET_H
#define SYSTEM_TOOLSET_UDP_SOCKET_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "System/Network/Using/SocketPrototypesUsing.h"
#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/UserMacro.h"
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

        NODISCARD WinSocket GetWinSocket() const noexcept;

        void Send() const;

    private:
        explicit UdpSocket(DisableNotThrow disableNotThrow);

        void InitSocket() const;
        void CloseSocket() const;

    private:
        WinSocket winSocket;
    };
}

#endif  // SYSTEM_TOOLSET_UDP_SOCKET_H