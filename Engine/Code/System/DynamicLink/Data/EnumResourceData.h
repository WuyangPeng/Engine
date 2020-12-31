//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.1.0 (2020/09/22 9:57)

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
        constexpr EnumResourceData(const DynamicLinkCharType* type, const DynamicLinkCharType* name, WindowWord language) noexcept
            : m_Type{ type }, m_Name{ name }, m_Language{ language }
        {
        }

        [[nodiscard]] constexpr const DynamicLinkCharType* GetType() const noexcept
        {
            return m_Type;
        }

        [[nodiscard]] constexpr const DynamicLinkCharType* GetName() const noexcept
        {
            return m_Name;
        }

        [[nodiscard]] constexpr const LanguageIDData GetLanguage() const noexcept
        {
            return LanguageIDData{ UnderlyingCastEnum<PrimaryLanguage>(GetPrimaryLanguageID(m_Language)), UnderlyingCastEnum<SubLanguage>(GetSubLanguageID(m_Language)) };
        }

    private:
        const DynamicLinkCharType* m_Type;
        const DynamicLinkCharType* m_Name;
        WindowWord m_Language;
    };
}

#endif  // SYSTEM_DYNAMIC_LINK_ENUM_RESOURCE_DATA_H