///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.3 (2022/10/05 21:21)

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
            : primaryLanguage{ PrimaryLanguage::Neutral }, subLanguage{ SubLanguage::Neutral }
        {
        }

        constexpr LanguageIDData(PrimaryLanguage primaryLanguage, SubLanguage subLanguage) noexcept
            : primaryLanguage{ primaryLanguage }, subLanguage{ subLanguage }
        {
        }

        NODISCARD constexpr auto GetPrimaryLanguage() const noexcept
        {
            return primaryLanguage;
        }

        NODISCARD constexpr auto GetSubLanguage() const noexcept
        {
            return subLanguage;
        }

        NODISCARD constexpr auto GetLanguageID() const noexcept
        {
            return MakeLanguageID(EnumCastUnderlying<WindowsWord>(primaryLanguage), EnumCastUnderlying<WindowsWord>(subLanguage));
        }

    private:
        PrimaryLanguage primaryLanguage;
        SubLanguage subLanguage;
    };
}

#endif  // SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H