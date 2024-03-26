/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 22:24)

#ifndef SYSTEM_TOOLSET_WIN_SOCK_START_H
#define SYSTEM_TOOLSET_WIN_SOCK_START_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Toolset/System/SystemToolset/Helper/UserMacro.h"

namespace SystemToolset
{
    class SYSTEM_TOOLSET_DEFAULT_DECLARE WinSockStart final
    {
    public:
        using ClassType = WinSockStart;

        using DisableNotThrow = CoreTools::DisableNotThrow;

    public:
        NODISCARD static WinSockStart Create();

        ~WinSockStart() noexcept;
        WinSockStart(const WinSockStart& rhs) noexcept = delete;
        WinSockStart& operator=(const WinSockStart& rhs) noexcept = delete;
        WinSockStart(WinSockStart&& rhs) noexcept;
        WinSockStart& operator=(WinSockStart&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

    private:
        explicit WinSockStart(DisableNotThrow disableNotThrow);

    private:
        static void WinSockStartUp();
        static void WinSockCleanup();
    };
}

#endif  // SYSTEM_TOOLSET_WIN_SOCK_START_H