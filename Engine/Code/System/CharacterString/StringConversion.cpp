///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/13 22:48)

#include "System/SystemExport.h"

#include "CodePage.h"
#include "StringConversion.h"
#include "Flags/CodePageFlags.h"
#include "Flags/StringConversionFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

#ifndef SYSTEM_PLATFORM_WIN32

    #ifdef SYSTEM_PLATFORM_ANDROID
        #include <iconv.h>
    #else  // !SYSTEM_PLATFORM_ANDROID
        #include <cstdlib>
        #include <locale>
    #endif  // SYSTEM_PLATFORM_ANDROID

#endif  // SYSTEM_PLATFORM_WIN32

#ifndef SYSTEM_PLATFORM_WIN32

namespace System
{
    const char* SYSTEM_HIDDEN_DECLARE GetLocale(CodePage codePage) noexcept
    {
        if (codePage == CodePage::UTF8)
            return "zh_CN.utf8";
        else
            return "chs";
    }

    int SYSTEM_HIDDEN_DECLARE IncreaseNullNumber(int readSize) noexcept
    {
        // 错误统一返回0
        if (readSize < 0)
            return 0;
        else
            return readSize + 1;
    }

    int SYSTEM_HIDDEN_DECLARE MultiByteToWideCharUseMbstowcs(CodePage codePage, const char* multiByte, wchar_t* wideChar, int wideCharLength) noexcept
    {
        auto currentLocale = setlocale(LC_ALL, nullptr);

        setlocale(LC_ALL, GetLocale(codePage));

        auto readSize = static_cast<int>(::mbstowcs(wideChar, multiByte, wideCharLength));

        setlocale(LC_ALL, currentLocale);

        // 返回值包括空终止符
        return IncreaseNullNumber(readSize);
    }
}

#endif  // SYSTEM_PLATFORM_WIN32

int System::MultiByteConversionWideChar(const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept
{
    // 代码页
    const auto codePage = GetANSICodePage();
    constexpr auto defaultMultiByte = MultiByte::NoFlags;

    return MultiByteConversionWideChar(codePage, defaultMultiByte, multiByte, multiByteLength, wideChar, wideCharLength);
}

int System::UTF8ConversionWideChar(const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept
{
    const auto codePage = CodePage::UTF8;
    constexpr auto defaultMultiByte = MultiByte::NoFlags;

    return MultiByteConversionWideChar(codePage, defaultMultiByte, multiByte, multiByteLength, wideChar, wideCharLength);
}

int System::MultiByteConversionWideChar(CodePage codePage, MAYBE_UNUSED MultiByte flag, const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::MultiByteToWideChar(EnumCastUnderlying(codePage), EnumCastUnderlying(flag), multiByte, multiByteLength, wideChar, wideCharLength);

#else  // !SYSTEM_PLATFORM_WIN32

    // 返回值包括空终止符
    if (wideChar != nullptr)
        return MultiByteToWideCharUseMbstowcs(codePage, multiByte, wideChar, wideCharLength);
    else
        return multiByteLength;

#endif  // SYSTEM_PLATFORM_WIN32
}

#ifndef SYSTEM_PLATFORM_WIN32

namespace System
{
    int SYSTEM_HIDDEN_DECLARE WideCharToMultiByteUseWcstombs(CodePage codePage, const wchar_t* wideChar, char* multiByte, int multiByteLength) noexcept
    {
        auto currentLocale = setlocale(LC_ALL, nullptr);

        setlocale(LC_ALL, GetLocale(codePage));

        auto readSize = static_cast<int>(::wcstombs(multiByte, wideChar, multiByteLength));

        setlocale(LC_ALL, currentLocale);

        // 返回值包括空终止符
        return IncreaseNullNumber(readSize);
    }
}

#endif  // SYSTEM_PLATFORM_WIN32

int System::WideCharConversionMultiByte(const wchar_t* wideChar, int wideCharLength, char* multiByte, int multiByteLength) noexcept
{
    // 代码页
    const auto codePage = GetANSICodePage();
    constexpr auto defaultWideChar = WideChar::NoFlags;

    return WideCharConversionMultiByte(codePage, defaultWideChar, wideChar, wideCharLength, multiByte, multiByteLength, nullptr, nullptr);
}

int System::WideCharConversionUTF8(const wchar_t* wideChar, int wideCharLength, char* multiByte, int multiByteLength) noexcept
{
    const auto codePage = CodePage::UTF8;
    constexpr auto defaultWideChar = WideChar::NoFlags;

    return WideCharConversionMultiByte(codePage, defaultWideChar, wideChar, wideCharLength, multiByte, multiByteLength, nullptr, nullptr);
}

int System::WideCharConversionMultiByte(CodePage codePage,
                                        WideChar flag,
                                        const wchar_t* wideChar,
                                        int wideCharLength,
                                        char* multiByte,
                                        int multiByteLength,
                                        const char* defaultChar,
                                        bool* usedDefaultChar) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    auto result = g_False;

    const auto size = ::WideCharToMultiByte(EnumCastUnderlying(codePage), EnumCastUnderlying(flag), wideChar, wideCharLength, multiByte, multiByteLength, defaultChar, defaultChar != nullptr ? &result : nullptr);
    BoolConversion(result, usedDefaultChar);

    return size;

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(flag, defaultChar, usedDefaultChar);

    // 返回值包括空终止符
    if (multiByte != nullptr)
        return WideCharToMultiByteUseWcstombs(codePage, wideChar, multiByte, multiByteLength);
    else
        return wideCharLength * 2;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ComparesStringReturn System::CompareStringUseLocale(LanguageLocale locale,
                                                            Compares comparesFlag,
                                                            const TChar* lhsString,
                                                            int lhsCount,
                                                            const TChar* rhsString,
                                                            int rhsCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<ComparesStringReturn>(::CompareString(EnumCastUnderlying(locale), EnumCastUnderlying(comparesFlag), lhsString, lhsCount, rhsString, rhsCount));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(locale, comparesFlag);

    const auto minCount = std::min(lhsCount, rhsCount);
    for (auto i = 0; i < minCount; ++i)
    {
        if (lhsString[i] < rhsString[i])
            return ComparesStringReturn::LessThan;
        else if (rhsString[i] < lhsString[i])
            return ComparesStringReturn::GreaterThan;
    }

    if (lhsCount < rhsCount)
        return ComparesStringReturn::LessThan;
    else if (rhsCount < lhsCount)
        return ComparesStringReturn::GreaterThan;
    else
        return ComparesStringReturn::Equal;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ComparesStringReturn System::CompareStringUseLocale(const wchar_t* localeName,
                                                            Compares comparesFlag,
                                                            const wchar_t* lhsString,
                                                            int lhsCount,
                                                            const wchar_t* rhsString,
                                                            int rhsCount) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<ComparesStringReturn>(::CompareStringEx(localeName, EnumCastUnderlying(comparesFlag), lhsString, lhsCount, rhsString, rhsCount, nullptr, nullptr, 0));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(localeName, comparesFlag);

    const auto minCount = std::min(lhsCount, rhsCount);
    for (auto i = 0; i < minCount; ++i)
    {
        if (lhsString[i] < rhsString[i])
            return ComparesStringReturn::LessThan;
        else if (rhsString[i] < lhsString[i])
            return ComparesStringReturn::GreaterThan;
    }

    if (lhsCount < rhsCount)
        return ComparesStringReturn::LessThan;
    else if (rhsCount < lhsCount)
        return ComparesStringReturn::GreaterThan;
    else
        return ComparesStringReturn::Equal;

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ComparesStringReturn System::CompareStringOrdinalUseBinary(const wchar_t* lhsString,
                                                                   int lhsCount,
                                                                   const wchar_t* rhsString,
                                                                   int rhsCount,
                                                                   bool ignoreCase) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<ComparesStringReturn>(::CompareStringOrdinal(lhsString, lhsCount, rhsString, rhsCount, BoolConversion(ignoreCase)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(ignoreCase);

    const auto minCount = std::min(lhsCount, rhsCount);
    for (auto i = 0; i < minCount; ++i)
    {
        if (lhsString[i] < rhsString[i])
            return ComparesStringReturn::LessThan;
        else if (rhsString[i] < lhsString[i])
            return ComparesStringReturn::GreaterThan;
    }

    if (lhsCount < rhsCount)
        return ComparesStringReturn::LessThan;
    else if (rhsCount < lhsCount)
        return ComparesStringReturn::GreaterThan;
    else
        return ComparesStringReturn::Equal;

#endif  // SYSTEM_PLATFORM_WIN32
}
