/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.3 (2023/12/21 19:16)

#ifndef SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_H
#define SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/DynamicLinkFlagsFwd.h"
#include "Using/EnumResourceToolsUsing.h"
#include "Using/LoadLibraryUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputDataFwd.h"
#include "System/Windows/Using/WindowsUsing.h"

// ö�ٶ�̬���ӿ��е���Դ��
namespace System
{
    NODISCARD bool SYSTEM_DEFAULT_DECLARE EnumResourceLanguagesInLibrary(DynamicLinkModule module,
                                                                         const DynamicLinkCharType* type,
                                                                         const DynamicLinkCharType* name,
                                                                         EnumResourceLanguageProcess enumFunction,
                                                                         WindowsLongPtrSizeType param) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE EnumResourceLanguagesInLibrary(DynamicLinkModule module,
                                                                         const DynamicLinkCharType* type,
                                                                         const DynamicLinkCharType* name,
                                                                         EnumResourceLanguageProcess enumFunction,
                                                                         WindowsLongPtrSizeType param,
                                                                         ResourceEnum flags,
                                                                         const LanguageIdData& language) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE EnumResourceNamesInLibrary(DynamicLinkModule module,
                                                                     const DynamicLinkCharType* type,
                                                                     EnumResourceNameProcess enumFunction,
                                                                     WindowsLongPtrSizeType param) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE EnumResourceNamesInLibrary(DynamicLinkModule module,
                                                                     const DynamicLinkCharType* type,
                                                                     EnumResourceNameProcess enumFunction,
                                                                     WindowsLongPtrSizeType param,
                                                                     ResourceEnum flags,
                                                                     const LanguageIdData& language) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE EnumResourceTypesInLibrary(DynamicLinkModule module,
                                                                     EnumResourceTypeProcess enumFunction,
                                                                     WindowsLongPtrSizeType param) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE EnumResourceTypesInLibrary(DynamicLinkModule module,
                                                                     EnumResourceTypeProcess enumFunction,
                                                                     WindowsLongPtrSizeType param,
                                                                     ResourceEnum flags,
                                                                     const LanguageIdData& language) noexcept;
}

#endif  // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_H
