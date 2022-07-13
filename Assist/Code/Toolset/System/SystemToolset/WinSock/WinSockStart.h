///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎辅助版本：0.8.0.10 (2022/07/05 17:14)

#ifndef SYSTEM_TOOLSET_WIN_SOCK_START_H
#define SYSTEM_TOOLSET_WIN_SOCK_START_H

#include "Toolset/System/SystemToolset/SystemToolsetDll.h"

#include "CoreTools/Contract/ContractFwd.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/Helper/UserMacro.h"
#include "Toolset/System/SystemToolset/Helper/UserMacro.h"

namespace SystemToolset
{
    class SYSTEM_TOOLSET_DEFAULT_DECLARE WinSockStart final
    {
    public:
        using ClassType = WinSockStart;

    public:
        explicit WinSockStart(CoreTools::DisableNotThrow disableNotThrow);
        ~WinSockStart() noexcept;
        WinSockStart(const WinSockStart& rhs) noexcept = delete;
        WinSockStart& operator=(const WinSockStart& rhs) noexcept = delete;
        WinSockStart(WinSockStart&& rhs) noexcept = delete;
        WinSockStart& operator=(WinSockStart&& rhs) noexcept = delete;

        CLASS_INVARIANT_DECLARE;

    private:
        void WinSockStartUp();
        void WinSockCleanup();
    };
}

#endif  // SYSTEM_TOOLSET_WIN_SOCK_START_H