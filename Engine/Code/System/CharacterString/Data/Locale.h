///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.8.1.4 (2022/11/26 10:54)

#ifndef SYSTEM_CHARACTER_STRING_LOCALE_H
#define SYSTEM_CHARACTER_STRING_LOCALE_H

#include "System/SystemDll.h"

#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"

#include <array>

namespace System
{
    class SYSTEM_DEFAULT_DECLARE Locale
    {
    public:
        using ClassType = Locale;
        constexpr static auto size = 256;
        using LocaleType = std::array<char, size>;

    public:
        explicit Locale(CodePage codePage);
        ~Locale() noexcept;

        Locale(const Locale& rhs) = delete;
        Locale& operator=(const Locale& rhs) = delete;
        Locale(Locale&& rhs) noexcept = delete;

        Locale& operator=(Locale&& rhs) noexcept = delete;

        NODISCARD static LocaleType GetLocaleType(const char* locale);

    private:
        NODISCARD static const char* GetLocale(CodePage codePage) noexcept;

    private:
        LocaleType currentLocale;
    };
}

#endif  // SYSTEM_CHARACTER_STRING_LOCALE_H