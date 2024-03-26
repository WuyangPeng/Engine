/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.7 (2024/03/05 17:03)

#ifndef SYSTEM_CHARACTER_STRING_LOCALE_H
#define SYSTEM_CHARACTER_STRING_LOCALE_H

#include "System/SystemDll.h"

#include "System/CharacterString/Fwd/CharacterStringFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"

#include <array>

namespace System
{
    /// @brief ���ػ�
    /// ���棺Locale�಻���̰߳�ȫ�ġ�
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