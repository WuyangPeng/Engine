///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.2 (2023/07/28 10:18)

#include "Toolset/System/SystemToolset/SystemToolsetExport.h"

#include "WinSockStart.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Network/Flags/WindowsExtensionPrototypesFlags.h"
#include "System/Network/Using/WindowsExtensionPrototypesUsing.h"
#include "System/Network/WindowsExtensionPrototypes.h"
#include "CoreTools/Contract/Flags/DisableNotThrowFlags.h"
#include "CoreTools/Contract/Noexcept.h"
#include "Toolset/System/SystemToolset/Helper/SystemToolsetClassInvariantMacro.h"

#include <exception>
#include <iostream>

SystemToolset::WinSockStart SystemToolset::WinSockStart::Create()
{
    return WinSockStart{ DisableNotThrow::Disable };
}

SystemToolset::WinSockStart::WinSockStart(DisableNotThrow disableNotThrow)
{
    WinSockStartUp();

    System::UnusedFunction(disableNotThrow);

    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_9;
}

SystemToolset::WinSockStart::WinSockStart(WinSockStart&& rhs) noexcept
{
    System::UnusedFunction(rhs);

    SYSTEM_TOOLSET_SELF_CLASS_IS_VALID_9;
}

SystemToolset::WinSockStart& SystemToolset::WinSockStart::operator=(WinSockStart&& rhs) noexcept
{
    SYSTEM_TOOLSET_CLASS_IS_VALID_9;

    System::UnusedFunction(rhs);

    return *this;
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

    if (const auto startUp = System::WinSockStartUp(versionRequested, &wsaData);
        startUp != System::WinSockStartUpReturn::Successful)
    {
        throw std::runtime_error("StartUp ʧ�ܡ�\n");
    }
}

void SystemToolset::WinSockStart::WinSockCleanup()
{
    if (System::WinSockCleanup() != System::WinSockCleanupReturn::Successful)
    {
        std::cout << "WinSockCleanupʧ��\n";
    }
}
