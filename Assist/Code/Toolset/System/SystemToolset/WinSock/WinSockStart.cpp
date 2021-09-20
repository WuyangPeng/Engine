///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助版本：0.7.1.4 (2021/06/05 15:03)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "WinSockStart.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/Using/WindowsExtensionPrototypesUsing.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/Contract/Noexcept.h"
#include "Toolset/System/SystemToolset/Helper/SystemToolsetClassInvariantMacro.h"

#include <exception>
#include <iostream>

using std::cout;
using std::exception;

SystemToolset::WinSockStart::WinSockStart(MAYBE_UNUSED CoreTools::DisableNotThrow disableNotThrow)
{
    WinSockStartUp();

    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_9;
}

SystemToolset::WinSockStart::~WinSockStart() noexcept
{
    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_9;

    CoreTools::NoexceptNoReturn(*this, &ClassType::WinSockCleanup);
}

CLASS_INVARIANT_STUB_DEFINE(SystemToolset, WinSockStart)

void SystemToolset::WinSockStart::WinSockStartUp()
{
    System::WinSockData wsaData{};

    constexpr auto versionRequested = System::MakeWord(2, 2);
    const auto startUp = System::WinSockStartUp(versionRequested, &wsaData);

    if (startUp != System::WinSockStartUpReturn::Successful)
    {
        throw exception("StartUp 失败。\n");
    }
}

void SystemToolset::WinSockStart::WinSockCleanup()
{
    if (System::WinSockCleanup() != System::WinSockCleanupReturn::Successful)
    {
        cout << "WinSockCleanup失败\n";
    }
}
