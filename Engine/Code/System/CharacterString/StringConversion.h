///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.8.1.4 (2022/11/13 11:00)

#ifndef SYSTEM_CHARACTER_STRING_STRING_CONVERSION_H
#define SYSTEM_CHARACTER_STRING_STRING_CONVERSION_H

#include "System/SystemDll.h"

#include "Fwd/CharacterStringFlagsFwd.h"
#include "System/Helper/UnicodeUsing.h"
#include "System/Windows/Using/WindowsUsing.h"

namespace System
{
    // �ַ���ת��

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

    NODISCARD int SYSTEM_DEFAULT_DECLARE MultiByteConversionWideChar(const char* multiByte,
                                                                     int multiByteLength,
                                                                     wchar_t* wideChar,
                                                                     int wideCharLength) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE UTF8ConversionWideChar(const char* multiByte,
                                                                int multiByteLength,
                                                                wchar_t* wideChar,
                                                                int wideCharLength) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE WideCharConversionMultiByte(const wchar_t* wideChar,
                                                                     int wideCharLength,
                                                                     char* multiByte,
                                                                     int multiByteLength) noexcept;
    NODISCARD int SYSTEM_DEFAULT_DECLARE WideCharConversionUTF8(const wchar_t* wideChar,
                                                                int wideCharLength,
                                                                char* multiByte,
                                                                int multiByteLength) noexcept;

    // lhsCount��rhsCount����������ֹ��
    NODISCARD ComparesStringReturn SYSTEM_DEFAULT_DECLARE CompareStringUseLocale(LanguageLocale locale,
                                                                                 Compares comparesFlag,
                                                                                 const String& lhsString,
                                                                                 const String& rhsString);

    NODISCARD ComparesStringReturn SYSTEM_DEFAULT_DECLARE CompareStringUseLocale(const wchar_t* localeName,
                                                                                 Compares comparesFlag,
                                                                                 const std::wstring& lhsString,
                                                                                 const std::wstring& rhsString);

    NODISCARD ComparesStringReturn SYSTEM_DEFAULT_DECLARE CompareStringOrdinalUseBinary(const std::wstring& lhsString,
                                                                                        const std::wstring& rhsString,
                                                                                        bool ignoreCase);
}

#endif  // SYSTEM_CHARACTER_STRING_STRING_CONVERSION_H
