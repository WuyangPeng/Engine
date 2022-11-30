///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/26 10:55)

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
    System::MemoryCopy(result.data(), locale, std::min(size, boost::numeric_cast<int>(System::Strlen(locale))));

    return result;
}

const char* System::Locale::GetLocale(CodePage codePage) noexcept
{
    if (codePage == CodePage::UTF8)
        return "zh_CN.utf8";
    else
        return "chs";
}