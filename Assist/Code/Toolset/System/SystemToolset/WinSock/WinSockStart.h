///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.2 (2023/07/28 10:20)

#ifndef SYSTEM_TOOLSET_WIN_SOCK_START_H
#define SYSTEM_TOOLSET_WIN_SOCK_START_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
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
        void WinSockStartUp();
        void WinSockCleanup();
    };
}

#endif  // SYSTEM_TOOLSET_WIN_SOCK_START_H