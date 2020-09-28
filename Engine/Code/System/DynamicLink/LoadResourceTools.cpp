//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 10:13)

#include "System/SystemExport.h"

#include "LoadResourceTools.h"
#include "System/SystemOutput/Data/LanguageIDData.h"
#include "System/Window/WindowSystem.h"

System::DynamicLinkResource System::FindResourceInLibrary([[maybe_unused]] DynamicLinkModule module, [[maybe_unused]] const DynamicLinkCharType* type, [[maybe_unused]] const DynamicLinkCharType* name) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::FindResource(module, name, type);
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkResource System::FindResourceInLibrary([[maybe_unused]] DynamicLinkModule module, [[maybe_unused]] const DynamicLinkCharType* type, [[maybe_unused]] const DynamicLinkCharType* name, [[maybe_unused]] const LanguageIDData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::FindResourceEx(module, type, name, language.GetLanguageID());
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::DynamicLinkGlobal System::LoadResourceInLibrary([[maybe_unused]] DynamicLinkModule module, [[maybe_unused]] DynamicLinkResource resourceInfo) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::LoadResource(module, resourceInfo);
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowVoidPtr System::LockResourceInLibrary([[maybe_unused]] DynamicLinkGlobal resourceData) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::LockResource(resourceData);
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowDWord System::SizeofResourceInLibrary([[maybe_unused]] DynamicLinkModule module, [[maybe_unused]] DynamicLinkResource resourceInfo) noexcept
{
#ifdef WIN32
    return ::SizeofResource(module, resourceInfo);
#else  // !WIN32
    return false;
#endif  // WIN32
}

bool System::UpdateResourceInLibrary([[maybe_unused]] WindowHandle update, [[maybe_unused]] const DynamicLinkCharType* type, [[maybe_unused]] const DynamicLinkCharType* name,
                                     [[maybe_unused]] const LanguageIDData& language, [[maybe_unused]] WindowVoidPtr resourceLock, [[maybe_unused]] WindowDWord size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::UpdateResource(update, type, name, language.GetLanguageID(), resourceLock, size) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::WindowHandle System::BeginUpdateResourceInLibrary([[maybe_unused]] const DynamicLinkCharType* fileName, [[maybe_unused]] bool deleteExistingResources) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::BeginUpdateResource(fileName, BoolConversion(deleteExistingResources));
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EndUpdateResourceInLibrary([[maybe_unused]] WindowHandle update, [[maybe_unused]] bool discard) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::EndUpdateResource(update, BoolConversion(discard)) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

int System::LoadStringInLibrary([[maybe_unused]] WindowHInstance instance, [[maybe_unused]] WindowUInt id, [[maybe_unused]] DynamicLinkCharType* buffer, [[maybe_unused]] int size) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    return ::LoadString(instance, id, buffer, size);
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
