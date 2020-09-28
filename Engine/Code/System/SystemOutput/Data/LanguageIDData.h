//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.0 (2020/09/22 9:26)

#ifndef SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H
#define SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H

#include "System/SystemDll.h"

#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Flags/PrimaryLanguageFlags.h"
#include "System/SystemOutput/Flags/SubLanguageFlags.h"

namespace System
{
    class SYSTEM_DEFAULT_DECLARE LanguageIDData final
    {
    public:
        using ClassType = LanguageIDData;

    public:
        constexpr LanguageIDData() noexcept
            : m_PrimaryLanguage{ PrimaryLanguage::Neutral }, m_SubLanguage{ SubLanguage::Neutral }
        {
        }

        constexpr LanguageIDData(PrimaryLanguage primaryLanguage, SubLanguage subLanguage) noexcept
            : m_PrimaryLanguage{ primaryLanguage }, m_SubLanguage{ subLanguage }
        {
        }

        [[nodiscard]] constexpr auto GetPrimaryLanguage() const noexcept
        {
            return m_PrimaryLanguage;
        }

        [[nodiscard]] constexpr auto GetSubLanguage() const noexcept
        {
            return m_SubLanguage;
        }

        [[nodiscard]] constexpr auto GetLanguageID() const noexcept
        {
            return MakeLanguageID(EnumCastUnderlying<WindowWord>(m_PrimaryLanguage), EnumCastUnderlying<WindowWord>(m_SubLanguage));
        }

    private:
        PrimaryLanguage m_PrimaryLanguage;
        SubLanguage m_SubLanguage;
    };
}

#endif  // SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H