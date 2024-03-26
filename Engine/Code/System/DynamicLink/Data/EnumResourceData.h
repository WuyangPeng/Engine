/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 16:33)

#ifndef SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_DATA_H
#define SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_DATA_H

#include "System/SystemDll.h"

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/SystemOutput/Data/LanguageIdData.h"

namespace System
{
    class SYSTEM_DEFAULT_DECLARE EnumResourceData final
    {
    public:
        using ClassType = EnumResourceData;

    public:
        /// const DynamicLinkCharType*存的是使用宏MAKEINTRESOURCE强转的指针，不能解引用和打印。
        constexpr EnumResourceData(const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowsWord language) noexcept
            : resourceType{ type }, name{ name }, language{ language }
        {
        }

        NODISCARD constexpr const DynamicLinkCharType* GetType() const noexcept
        {
            return resourceType;
        }

        NODISCARD constexpr const DynamicLinkCharType* GetName() const noexcept
        {
            return name;
        }

        NODISCARD constexpr LanguageIdData GetLanguage() const noexcept
        {
            return LanguageIdData{ UnderlyingCastEnum<PrimaryLanguage>(GetPrimaryLanguageId(language)), UnderlyingCastEnum<SubLanguage>(GetSubLanguageId(language)) };
        }

    private:
        const DynamicLinkCharType* resourceType;
        const DynamicLinkCharType* name;
        WindowsWord language;
    };
}

#endif  // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_DATA_H