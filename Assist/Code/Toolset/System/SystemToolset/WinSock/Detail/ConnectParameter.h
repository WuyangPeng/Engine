///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.1.3 (2022/10/27 0:56)

#ifndef SYSTEM_TOOLSET_CONNECT_PARAMETER_H
#define SYSTEM_TOOLSET_CONNECT_PARAMETER_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "System/Network/Using/SocketPrototypesUsing.h"
#include "CoreTools/Helper/UserMacro.h"

#include <string>

namespace SystemToolset
{
    class SYSTEM_TOOLSET_HIDDEN_DECLARE ConnectParameter final
    {
    public:
        using ClassType = ConnectParameter;

        using WinSockInternetAddress = System::WinSockInternetAddress;

    public:
        ConnectParameter(const std::string& jsonRoute, const std::string& portName);

        CLASS_INVARIANT_DECLARE;

        NODISCARD WinSockInternetAddress GetWinSockInternetAddress() const;
        NODISCARD int GetConnectTime() const noexcept;

    private:
        void Init(const std::string& jsonRoute, const std::string& portName);

    private:
        int port;
        std::string address;
        int connectTime;
    };
}

#endif  // SYSTEM_TOOLSET_CONNECT_PARAMETER_H