///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/16 21:28)

#ifndef SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_DATA_H
#define SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_DATA_H

#include "System/SystemDll.h"

#include "System/DynamicLink/Using/EnumResourceToolsUsing.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/SystemOutput/Data/LanguageIDData.h"

namespace System
{
    class SYSTEM_DEFAULT_DECLARE EnumResourceData final
    {
    public:
        using ClassType = EnumResourceData;

    public:
        // const DynamicLinkCharType*�����ʹ�ú�MAKEINTRESOURCEǿת��ָ�룬���ܽ����úʹ�ӡ��
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

        NODISCARD constexpr const LanguageIDData GetLanguage() const noexcept
        {
            return LanguageIDData{ UnderlyingCastEnum<PrimaryLanguage>(GetPrimaryLanguageID(language)), UnderlyingCastEnum<SubLanguage>(GetSubLanguageID(language)) };
        }

    private:
        const DynamicLinkCharType* resourceType;
        const DynamicLinkCharType* name;
        WindowsWord language;
    };
}

#endif  // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_DATA_H