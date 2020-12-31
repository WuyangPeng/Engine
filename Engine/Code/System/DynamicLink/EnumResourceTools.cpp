//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 10:04)

#include "System/SystemExport.h"

#include "EnumResourceTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Data/LanguageIDData.h"

bool System::EnumResourceLanguagesInLibrary([[maybe_unused]] DynamicLinkModule module, [[maybe_unused]] const DynamicLinkCharType* type, [[maybe_unused]] const DynamicLinkCharType* name,
                                            [[maybe_unused]] EnumResourceLanguageProcess enumFunction, [[maybe_unused]] WindowPtrLong param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::EnumResourceLanguages(module, type, name, enumFunction, param) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnumResourceLanguagesInLibrary([[maybe_unused]] DynamicLinkModule module, [[maybe_unused]] const DynamicLinkCharType* type, [[maybe_unused]] const DynamicLinkCharType* name, [[maybe_unused]] EnumResourceLanguageProcess enumFunction,
                                            [[maybe_unused]] WindowPtrLong param, [[maybe_unused]] ResourceEnum flags, [[maybe_unused]] const LanguageIDData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::EnumResourceLanguagesEx(module, type, name, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageID()) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnumResourceNamesInLibrary([[maybe_unused]] DynamicLinkModule module, [[maybe_unused]] const DynamicLinkCharType* type, [[maybe_unused]] EnumResourceNameProcess enumFunction, [[maybe_unused]] WindowPtrLong param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::EnumResourceNames(module, type, enumFunction, param) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnumResourceNamesInLibrary([[maybe_unused]] DynamicLinkModule module, [[maybe_unused]] const DynamicLinkCharType* type, [[maybe_unused]] EnumResourceNameProcess enumFunction,
                                        [[maybe_unused]] WindowPtrLong param, [[maybe_unused]] ResourceEnum flags, [[maybe_unused]] const LanguageIDData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::EnumResourceNamesEx(module, type, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageID()) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnumResourceTypesInLibrary([[maybe_unused]] DynamicLinkModule module, [[maybe_unused]] EnumResourceTypeProcess enumFunction, [[maybe_unused]] WindowPtrLong param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::EnumResourceTypes(module, enumFunction, param) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnumResourceTypesInLibrary([[maybe_unused]] DynamicLinkModule module, [[maybe_unused]] EnumResourceTypeProcess enumFunction, [[maybe_unused]] WindowPtrLong param,
                                        [[maybe_unused]] ResourceEnum flags, [[maybe_unused]] const LanguageIDData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32
    if (::EnumResourceTypesEx(module, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageID()) != g_False)
        return true;
    else
        return false;
#else  // !SYSTEM_PLATFORM_WIN32
    return false;
#endif  // SYSTEM_PLATFORM_WIN32
}
