///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 16:36)

#include "System/SystemExport.h"

#include "EnumResourceTools.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Data/LanguageIdData.h"

bool System::EnumResourceLanguagesInLibrary(DynamicLinkModule module,
                                            const DynamicLinkCharType* type,
                                            const DynamicLinkCharType* name,
                                            EnumResourceLanguageProcess enumFunction,
                                            WindowsLongPtrSizeType param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EnumResourceLanguages(module, type, name, enumFunction, param) != gFalse)
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
                                            WindowsLongPtrSizeType param,
                                            ResourceEnum flags,
                                            const LanguageIdData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EnumResourceLanguagesEx(module, type, name, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageId()) != gFalse)
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
                                        WindowsLongPtrSizeType param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EnumResourceNames(module, type, enumFunction, param) != gFalse)
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
                                        WindowsLongPtrSizeType param,
                                        ResourceEnum flags,
                                        const LanguageIdData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EnumResourceNamesEx(module, type, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageId()) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, type, enumFunction, param, flags, language);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnumResourceTypesInLibrary(DynamicLinkModule module, EnumResourceTypeProcess enumFunction, WindowsLongPtrSizeType param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EnumResourceTypes(module, enumFunction, param) != gFalse)
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
                                        WindowsLongPtrSizeType param,
                                        ResourceEnum flags,
                                        const LanguageIdData& language) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    if (::EnumResourceTypesEx(module, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageId()) != gFalse)
        return true;
    else
        return false;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, enumFunction, param, flags, language);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
