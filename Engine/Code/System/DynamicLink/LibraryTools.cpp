/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 16:39)

#include "System/SystemExport.h"

#include "LibraryTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"

#include <array>
#include <filesystem>

System::DynamicLinkModule System::GetDynamicLinkHandle(const DynamicLinkCharType* moduleName) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetModuleHandle(moduleName);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(moduleName);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::GetDynamicLinkHandle(GetModuleHandleType flags, const DynamicLinkCharType* moduleName, DynamicLinkModule* module) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetModuleHandleEx(EnumCastUnderlying(flags), moduleName, module) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(flags, moduleName, module);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::GetDynamicLinkFileName(DynamicLinkModule module, DynamicLinkCharType* filename, WindowsDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::GetModuleFileName(module, filename, size);

#else  // !SYSTEM_PLATFORM_WIN32

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkString System::GetDynamicLinkFileName(DynamicLinkModule module)
{
    DynamicLinkCharBufferType moduleFileName{};

    if (const auto maxFileNameLength = GetDynamicLinkFileName(module, moduleFileName.data(), gMaxPath - 1);
        0 < maxFileNameLength)
    {
        return DynamicLinkString{ moduleFileName.data() };
    }
    else
    {
        return DynamicLinkString{};
    }
}

std::string System::GetExecutableName()
{
#ifdef SYSTEM_PLATFORM_WIN32

    const auto exePath = GetDynamicLinkFileName(nullptr);

    const std::filesystem::path filesystemPath{ exePath };
    return filesystemPath.stem().string();

#else  // !SYSTEM_PLATFORM_WIN32

    const auto exePath = std::filesystem::read_symlink("/proc/self/exe");

    return exePath.stem().string();

#endif  // SYSTEM_PLATFORM_WIN32
}

std::string System::GetExecutableNameRemoveSuffix()
{
    auto executableName = GetExecutableName();

    if (executableName.empty())
    {
        return executableName;
    }

#ifdef _DEBUG

    if (executableName.back() == 'D')
    {
        executableName = executableName.substr(0, executableName.size() - 1);
    }

#endif  // _DEBUG

#ifdef BUILDING_SYSTEM_STATIC

    if (const auto position = executableName.find("Static");
        position != std::string::npos)
    {
        executableName = executableName.substr(0, position);
    }

#endif  // BUILDING_SYSTEM_STATIC

    return executableName;
}
