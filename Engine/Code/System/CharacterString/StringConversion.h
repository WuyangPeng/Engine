///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.1.2 (2021/03/31 18:25)

#ifndef SYSTEM_CHARACTER_STRING_STRING_CONVERSION_H
#define SYSTEM_CHARACTER_STRING_STRING_CONVERSION_H

#include "System/SystemDll.h"

#include "Fwd/CharacterStringFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // 字符串转换

    NODISCARD int SYSTEM_DEFAULT_DECLARE MultiByteConversionWideChar(CodePage codePage,
                                                                     MultiByte flag,
                                                                     const char* multiByte,
                                                                     int multiByteLength,
                                                                     wchar_t* wideChar,
                                                                     int wideCharLength) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE WideCharConversionMultiByte(CodePage codePage,
                                                                     WideChar flag,
                                                                     const wchar_t* wideChar,
                                                                     int wideCharLength,
                                                                     char* multiByte,
                                                                     int multiByteLength,
                                                                     const char* defaultChar,
                                                                     bool* usedDefaultChar) noexcept;

    NODISCARD int SYSTEM_DEFAULT_DECLARE MultiByteConversionWideChar(const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE UTF8ConversionWideChar(const char* multiByte, int multiByteLength, wchar_t* wideChar, int wideCharLength) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE WideCharConversionMultiByte(const wchar_t* wideChar, int wideCharLength, char* multiByte, int multiByteLength) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE WideCharConversionUTF8(const wchar_t* wideChar, int wideCharLength, char* multiByte, int multiByteLength) noexcept;

    // lhsCount和rhsCount不包括空终止符
    NODISCARD ComparesStringReturn SYSTEM_DEFAULT_DECLARE CompareStringUseLocale(LanguageLocale locale,
                                                                                 Compares comparesFlag,
                                                                                 const TChar* lhsString,
                                                                                 int lhsCount,
                                                                                 const TChar* rhsString,
                                                                                 int rhsCount) noexcept;

    NODISCARD ComparesStringReturn SYSTEM_DEFAULT_DECLARE CompareStringUseLocale(const wchar_t* localeName,
                                                                                 Compares comparesFlag,
                                                                                 const wchar_t* lhsString,
                                                                                 int lhsCount,
                                                                                 const wchar_t* rhsString,
                                                                                 int rhsCount) noexcept;

    NODISCARD ComparesStringReturn SYSTEM_DEFAULT_DECLARE CompareStringOrdinalUseBinary(const wchar_t* lhsString,
                                                                                        int lhsCount,
                                                                                        const wchar_t* rhsString,
                                                                                        int rhsCount,
                                                                                        bool ignoreCase) noexcept;
}

#endif  // SYSTEM_CHARACTER_STRING_STRING_CONVERSION_H
