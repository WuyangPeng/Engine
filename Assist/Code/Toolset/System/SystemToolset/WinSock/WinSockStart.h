///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	���渨���汾��0.8.1.3 (2022/10/27 23:45)

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