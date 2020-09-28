//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/22 10:02)

#ifndef SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_H
#define SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_H

#include "System/SystemDll.h"

#include "Fwd/DynamicLinkDataFwd.h"
#include "Fwd/DynamicLinkFlagsFwd.h"
#include "Using/EnumResourceToolsUsing.h"
#include "Using/LoadLibraryUsing.h"
#include "System/SystemOutput/Fwd/SystemOutputDataFwd.h"
#include "System/Window/Using/WindowUsing.h"

namespace System
{
    // ö�ٶ�̬���ӿ��е���Դ��

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE EnumResourceLanguagesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name,
                                                                             EnumResourceLanguageProcess enumFunction, WindowPtrLong param) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE EnumResourceLanguagesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, const DynamicLinkCharType* name, EnumResourceLanguageProcess enumFunction,
                                                                             WindowPtrLong param, ResourceEnum flags, const LanguageIDData& language) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE EnumResourceNamesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type,
                                                                         EnumResourceNameProcess enumFunction, WindowPtrLong param) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE EnumResourceNamesInLibrary(DynamicLinkModule module, const DynamicLinkCharType* type, EnumResourceNameProcess enumFunction,
                                                                         WindowPtrLong param, ResourceEnum flags, const LanguageIDData& language) noexcept;

    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE EnumResourceTypesInLibrary(DynamicLinkModule module, EnumResourceTypeProcess enumFunction, WindowPtrLong param) noexcept;
    [[nodiscard]] bool SYSTEM_DEFAULT_DECLARE EnumResourceTypesInLibrary(DynamicLinkModule module, EnumResourceTypeProcess enumFunction, WindowPtrLong param,
                                                                         ResourceEnum flags, const LanguageIDData& language) noexcept;
}

#endif  // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_TOOLS_H
