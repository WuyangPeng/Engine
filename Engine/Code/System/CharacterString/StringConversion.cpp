///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/08/28 15:56)

#include "System/SystemExport.h"

#include "CodePage.h"
#include "StringConversion.h"
#include "Flags/CodePageFlags.h"
#include "Flags/StringConversionFlags.h"
#include "System/Helper/EnumCast.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/Tools.h"
#include "System/Helper/WindowsMacro.h"
#include "System/Windows/WindowsSystem.h"

#ifndef SYSTEM_PLATFORM_WIN32

    #include "Data/Locale.h"

    #ifdef SYSTEM_PLATFORM_ANDROID

        #include <iconv.h>

    #else  // !SYSTEM_PLATFORM_ANDROID

        #include <cstdlib>

    #endif  // SYSTEM_PLATFORM_ANDROID

    #include <gsl/util>

#endif  // SYSTEM_PLATFORM_WIN32

#ifndef SYSTEM_PLATFORM_WIN32

namespace System
{
    NODISCARD int SYSTEM_HIDDEN_DECLARE IncreaseNullNumber(int readSize) noexcept
    {
        // 错误统一返回0
        if (readSize < 0)
            return 0;
        else
            return readSize + 1;
    }

    NODISCARD int SYSTEM_HIDDEN_DECLARE MultiByteToWideCharUseMbstowcs(CodePage codePage, const char* multiByte, wchar_t* wideChar, int wideCharLength) noexcept
    {
        Locale locale{ codePage };

        const auto readSize = gsl::narrow_cast<int>(::mbstowcs(wideChar, multiByte, wideCharLength));

        // 返回值包括空终止符
        return IncreaseNullNumber(readSize);
    }

    NODISCARD int SYSTEM_HIDDEN_DECLARE WideCharToMultiByteUseWcstombs(CodePage codePage, const wchar_t* wideChar, char* multiByte, int multiByteLength) noexcept
    {
        Locale locale{ codePage };

        const auto readSize = gsl::narrow_cast<int>(::wcstombs(multiByte, wideChar, multiByteLength));

        // 返回值包括空终止符
        return IncreaseNullNumber(readSize);
    }

    template <typename T>
    NODISCARD ComparesStringReturn Compares(const T& lhs, const T& rhs)
    {
        if (lhs < rhs)
            return ComparesStringReturn::LessThan;
        else if (rhs < lhs)
            return ComparesStringReturn::GreaterThan;
        else
            return ComparesStringReturn::Equal;
    }
}

#endif  // SYSTEM_PLATFORM_WIN32

int System::MultiByteConversionWideChar(const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept
{
    const auto codePage = GetAnsiCodePage();
    constexpr auto defaultMultiByte = MultiByte::NoFlags;

    return MultiByteConversionWideChar(codePage, defaultMultiByte, multiByte, multiByteLength, wideChar, wideCharLength);
}

int System::MultiByteConversionWideChar(CodePage codePage, MultiByte flag, const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept
{
#ifdef SYSTEM_PLATFORM_WIN32

    return ::MultiByteToWideChar(EnumCastUnderlying(codePage), EnumCastUnderlying(flag), multiByte, multiByteLength, wideChar, wideCharLength);

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(flag);

    // 返回值包括空终止符
    if (wideChar != nullptr)
        return MultiByteToWideCharUseMbstowcs(codePage, multiByte, wideChar, wideCharLength);
    else
        return multiByteLength;

#endif  // SYSTEM_PLATFORM_WIN32
}

int System::WideCharConversionMultiByte(const wchar_t* wideChar, int wideCharLength, char* multiByte, int multiByteLength) noexcept
{
    const auto codePage = GetAnsiCodePage();
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

    auto result = gFalse;

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

int System::Utf8ConversionWideChar(const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept
{
    constexpr auto codePage = CodePage::Utf8;
    constexpr auto defaultMultiByte = MultiByte::NoFlags;

    return MultiByteConversionWideChar(codePage, defaultMultiByte, multiByte, multiByteLength, wideChar, wideCharLength);
}

int System::WideCharConversionUtf8(const wchar_t* wideChar, int wideCharLength, char* multiByte, int multiByteLength) noexcept
{
    constexpr auto codePage = CodePage::Utf8;
    constexpr auto defaultWideChar = WideChar::NoFlags;

    return WideCharConversionMultiByte(codePage, defaultWideChar, wideChar, wideCharLength, multiByte, multiByteLength, nullptr, nullptr);
}

System::ComparesStringReturn System::CompareStringUseLocale(LanguageLocale locale,
                                                            Compares compares,
                                                            const String& lhsString,
                                                            const String& rhsString)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<ComparesStringReturn>(::CompareString(EnumCastUnderlying(locale), EnumCastUnderlying(compares), lhsString.c_str(), boost::numeric_cast<int>(lhsString.size()), rhsString.c_str(), boost::numeric_cast<int>(rhsString.size())));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(locale, compares);

    return Compares(lhsString, rhsString);

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ComparesStringReturn System::CompareStringUseLocale(const wchar_t* localeName,
                                                            Compares compares,
                                                            const std::wstring& lhsString,
                                                            const std::wstring& rhsString)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<ComparesStringReturn>(::CompareStringEx(localeName, EnumCastUnderlying(compares), lhsString.c_str(), boost::numeric_cast<int>(lhsString.size()), rhsString.c_str(), boost::numeric_cast<int>(rhsString.size()), nullptr, nullptr, 0));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(localeName, compares);

    return Compares(lhsString, rhsString);

#endif  // SYSTEM_PLATFORM_WIN32
}

System::ComparesStringReturn System::CompareStringOrdinalUseBinary(const std::wstring& lhsString,
                                                                   const std::wstring& rhsString,
                                                                   bool ignoreCase)
{
#ifdef SYSTEM_PLATFORM_WIN32

    return UnderlyingCastEnum<ComparesStringReturn>(::CompareStringOrdinal(lhsString.c_str(), boost::numeric_cast<int>(lhsString.size()), rhsString.c_str(), boost::numeric_cast<int>(rhsString.size()), BoolConversion(ignoreCase)));

#else  // !SYSTEM_PLATFORM_WIN32

    UnusedFunction(ignoreCase);

    return Compares(lhsString, rhsString);

#endif  // SYSTEM_PLATFORM_WIN32
}
