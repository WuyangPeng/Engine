///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 18:58)

#include "System/SystemExport.h"

#include "EnumResourceTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Data/LanguageIDData.h"

bool System::EnumResourceLanguagesInLibrary(DynamicLinkModule module,
                                            const DynamicLinkCharType* type,
                                            const DynamicLinkCharType* name,
                                            EnumResourceLanguageProcess enumFunction,
                                            WindowsPtrLong param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EnumResourceLanguages(module, type, name, enumFunction, param) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, type, name, enumFunction, param);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnumResourceLanguagesInLibrary(DynamicLinkModule module,
                                            const DynamicLinkCharType* type,
                                            const DynamicLinkCharType* name,
                                            EnumResourceLanguageProcess enumFunction,
                                            WindowsPtrLong param,
                                            ResourceEnum flags,
                                            const LanguageIDData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EnumResourceLanguagesEx(module, type, name, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageID()) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, type, name, enumFunction, param, flags, language);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnumResourceNamesInLibrary(DynamicLinkModule module,
                                        const DynamicLinkCharType* type,
                                        EnumResourceNameProcess enumFunction,
                                        WindowsPtrLong param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EnumResourceNames(module, type, enumFunction, param) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, type, enumFunction, param);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnumResourceNamesInLibrary(DynamicLinkModule module,
                                        const DynamicLinkCharType* type,
                                        EnumResourceNameProcess enumFunction,
                                        WindowsPtrLong param,
                                        ResourceEnum flags,
                                        const LanguageIDData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EnumResourceNamesEx(module, type, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageID()) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, type, enumFunction, param, flags, language);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnumResourceTypesInLibrary(DynamicLinkModule module, EnumResourceTypeProcess enumFunction, WindowsPtrLong param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EnumResourceTypes(module, enumFunction, param) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, enumFunction, param);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnumResourceTypesInLibrary(DynamicLinkModule module,
                                        EnumResourceTypeProcess enumFunction,
                                        WindowsPtrLong param,
                                        ResourceEnum flags,
                                        const LanguageIDData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EnumResourceTypesEx(module, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageID()) != g_False)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, enumFunction, param, flags, language);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
