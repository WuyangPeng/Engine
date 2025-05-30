/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.1.2 (2024/10/26 17:27)

#ifndef SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H
#define SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H

#include "System/SystemDll.h"

#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/SystemOutput/Flags/PrimaryLanguageFlags.h"
#include "System/SystemOutput/Flags/SubLanguageFlags.h"

namespace System
{
    class SYSTEM_DEFAULT_DECLARE LanguageIdData final
    {
    public:
        using ClassType = LanguageIdData;

    public:
        constexpr LanguageIdData() noexcept
            : primaryLanguage{ PrimaryLanguage::Neutral }, subLanguage{ SubLanguage::Neutral }
        {
        }

        constexpr LanguageIdData(const PrimaryLanguage primaryLanguage, const SubLanguage subLanguage) noexcept
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

        NODISCARD constexpr auto GetLanguageId() const noexcept
        {
            return MakeLanguageId(EnumCastUnderlying<WindowsWord>(primaryLanguage), EnumCastUnderlying<WindowsWord>(subLanguage));
        }

    private:
        PrimaryLanguage primaryLanguage;
        SubLanguage subLanguage;
    };
}

#endif  // SYSTEM_SYSTEM_OUTPUT_LANGUAGE_ID_DATA_H