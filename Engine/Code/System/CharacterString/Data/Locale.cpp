/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/05 17:08)

#include "System/SystemExport.h"

#include "Locale.h"
#include "System/CharacterString/Flags/CodePageFlags.h"
#include "System/CharacterString/FormatString.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/MemoryTools/MemoryHelper.h"

#include <locale>
#include <utility>

System::Locale::Locale(CodePage codePage)
    : currentLocale{ GetLocaleType(setlocale(LC_ALL, nullptr)) }
{
    setlocale(LC_ALL, GetLocale(codePage));
}

System::Locale::~Locale() noexcept
{
    setlocale(LC_ALL, currentLocale.data());
}

System::Locale::LocaleType System::Locale::GetLocaleType(const char* locale)
{
    LocaleType result{};
    MemoryCopy(result.data(), locale, std::min(defaultBufferSize, boost::numeric_cast<int>(System::StringLength(locale))));

    return result;
}

const char* System::Locale::GetLocale(CodePage codePage) noexcept
{
    if (codePage == CodePage::Utf8)
        return "zh_CN.utf8";
    else
        return "chs";
}