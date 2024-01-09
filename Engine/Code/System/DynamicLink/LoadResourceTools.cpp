/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.3 (2023/12/21 19:17)

#include "System/SystemExport.h"

#include "LoadResourceTools.h"
#include "System/Helper/Tools.h"
#include "System/SystemOutput/Data/LanguageIdData.h"
#include "System/Windows/WindowsSystem.h"

System::DynamicLinkResource System::FindResourceInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::FindResource(module, name, type);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, type, name);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkResource System::FindResourceInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, const LanguageIdData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::FindResourceEx(module, type, name, language.GetLanguageId());

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, type, name, language);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkGlobal System::LoadResourceInLibrary(DynamicLinkModule module, DynamicLinkResource resourceInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LoadResource(module, resourceInfo);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, resourceInfo);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsVoidPtr System::LockResourceInLibrary(DynamicLinkGlobal resourceData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LockResource(resourceData);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(resourceData);

    return nullptr;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::SizeofResourceInLibrary(DynamicLinkModule module, DynamicLinkResource resourceInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SizeofResource(module, resourceInfo);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, resourceInfo);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::LoadStringInLibrary(WindowsHInstance instance, WindowsUInt id, DynamicLinkCharType* buffer, int size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LoadString(instance, id, buffer, size);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(instance, id, buffer, size);

    return 0;

#endif  // SYSTEM_PLATFORM_WIN32
}
