///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/13 18:57)

#ifndef SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_H
#define SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/DynamicLinkFlagsFwd.h"
#include "Using/EnumResourceToolsUsing.h"
#include "Using/LoadLibraryUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputDataFwd.h"

namespace System
{
    // ö�ٶ�̬���ӿ��е���Դ��

    NODISCARD bool SYSTEM_DEFAULT_DECLARE EnumResourceLanguagesInLibrary(DynamicLinkModule module,
                                                                         const DynamicLinkCharType* type,
                                                                         const DynamicLinkCharType* name,
                                                                         EnumResourceLanguageProcess enumFunction,
                                                                         WindowsPtrLong param) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE EnumResourceLanguagesInLibrary(DynamicLinkModule module,
                                                                         const DynamicLinkCharType* type,
                                                                         const DynamicLinkCharType* name,
                                                                         EnumResourceLanguageProcess enumFunction,
                                                                         WindowsPtrLong param,
                                                                         ResourceEnum flags,
                                                                         const LanguageIDData& language) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE EnumResourceNamesInLibrary(DynamicLinkModule module,
                                                                     const DynamicLinkCharType* type,
                                                                     EnumResourceNameProcess enumFunction,
                                                                     WindowsPtrLong param) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE EnumResourceNamesInLibrary(DynamicLinkModule module,
                                                                     const DynamicLinkCharType* type,
                                                                     EnumResourceNameProcess enumFunction,
                                                                     WindowsPtrLong param,
                                                                     ResourceEnum flags,
                                                                     const LanguageIDData& language) noexcept;

    NODISCARD bool SYSTEM_DEFAULT_DECLARE EnumResourceTypesInLibrary(DynamicLinkModule module,
                                                                     EnumResourceTypeProcess enumFunction,
                                                                     WindowsPtrLong param) noexcept;
    NODISCARD bool SYSTEM_DEFAULT_DECLARE EnumResourceTypesInLibrary(DynamicLinkModule module,
                                                                     EnumResourceTypeProcess enumFunction,
                                                                     WindowsPtrLong param,
                                                                     ResourceEnum flags,
                                                                     const LanguageIDData& language) noexcept;
}

#endif  // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_H
