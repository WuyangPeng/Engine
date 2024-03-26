/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 16:38)

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

    return ::EnumResourceLanguages(module, type, name, enumFunction, param) != gFalse;

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

    return ::EnumResourceLanguagesEx(module, type, name, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageId()) != gFalse;

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

    return ::EnumResourceNames(module, type, enumFunction, param) != gFalse;

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

    return ::EnumResourceNamesEx(module, type, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageId()) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, type, enumFunction, param, flags, language);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}

bool System::EnumResourceTypesInLibrary(DynamicLinkModule module, EnumResourceTypeProcess enumFunction, WindowsLongPtrSizeType param) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::EnumResourceTypes(module, enumFunction, param) != gFalse;

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

    return ::EnumResourceTypesEx(module, enumFunction, param, EnumCastUnderlying(flags), language.GetLanguageId()) != gFalse;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(module, enumFunction, param, flags, language);

    return false;

#endif  // SYSTEM_PLATFORM_WIN32
}
