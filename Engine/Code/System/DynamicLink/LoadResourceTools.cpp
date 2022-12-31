///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.5 (2022/12/08 18:40)

#include "System/SystemExport.h"

#include "LoadResourceTools.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "System/Windows/WindowsSystem.h"

System::DynamicLinkResource System::FindResourceInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::FindResource(module, name, type);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, type, name);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkResource System::FindResourceInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, const LanguageIDData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::FindResourceEx(module, type, name, language.GetLanguageID());

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, type, name, language);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkGlobal System::LoadResourceInLibrary(DynamicLinkModule module, DynamicLinkResource resourceInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LoadResource(module, resourceInfo);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, resourceInfo);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsVoidPtr System::LockResourceInLibrary(DynamicLinkGlobal resourceData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LockResource(resourceData);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(resourceInfo);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowsDWord System::SizeofResourceInLibrary(DynamicLinkModule module, DynamicLinkResource resourceInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::SizeofResource(module, resourceInfo);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, resourceInfo);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::LoadStringInLibrary(WindowsHInstance instance, WindowsUInt id, DynamicLinkCharType* buffer, int size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::LoadString(instance, id, buffer, size);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(instance, id, buffer, size);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
