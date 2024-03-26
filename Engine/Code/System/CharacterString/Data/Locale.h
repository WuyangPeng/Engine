/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:03)

#ifndef SYSTEM_CHARACTER_STRING_LOCALE_H
#define SYSTEM_CHARACTER_STRING_LOCALE_H

#include "System/SystemDll.h"

#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <array>

namespace System
{
    /// @brief 本地化
    /// 警告：Locale类不是线程安全的。
    class SYSTEM_DEFAULT_DECLARE Locale
    {
    public:
        using ClassType = Locale;

        using LocaleType = CharBufferType;

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