///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	���渨���汾��0.7.1.4 (2021/06/05 15:04)

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