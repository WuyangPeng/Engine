///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 14:10)

#include "CoreTools/CoreToolsExport.h"

#include "StringConversion.h"
#include "Detail/MultiByteConversionWideChar.h"
#include "Detail/WideCharConversionMultiByte.h"
#include "System/CharacterString/StringConversion.h"

#include <gsl/util>
#include <locale>

using std::string;
using std::wstring;

wstring CoreTools::StringConversion::MultiByteConversionWideChar(const string& character)
{
    const CoreTools::MultiByteConversionWideChar conversion{ character, false };

    return conversion.GetWideCharRepresentation();
}

string CoreTools::StringConversion::WideCharConversionMultiByte(const wstring& character)
{
    const CoreTools::WideCharConversionMultiByte conversion{ character, false };

    return conversion.GetMultiByteRepresentation();
}

wstring CoreTools::StringConversion::StandardConversionWideChar(const String& character)
{
#ifdef UNICODE
    return character;
#else  // !UNICODE
    return MultiByteConversionWideChar(character);
#endif  // UNICODE
}

string CoreTools::StringConversion::StandardConversionMultiByte(const String& character)
{
#ifdef UNICODE
    return WideCharConversionMultiByte(character);
#else  // !UNICODE
    return character;
#endif  // UNICODE
}

System::String CoreTools::StringConversion::WideCharConversionStandard(const wstring& character)
{
#ifdef UNICODE
    return character;
#else  // !UNICODE
    return WideCharConversionMultiByte(character);
#endif  // UNICODE
}

System::String CoreTools::StringConversion::MultiByteConversionStandard(const string& character)
{
#ifdef UNICODE
    return MultiByteConversionWideChar(character);
#else  // !UNICODE
    return character;
#endif  // UNICODE
}

System::DynamicLinkString CoreTools::StringConversion::StandardConversionDynamicLinkString(const String& character)
{
#ifdef SYSTEM_PLATFORM_WIN32
    return character;
#else  // !SYSTEM_PLATFORM_WIN32
    return StandardConversionMultiByte(character);
#endif  // SYSTEM_PLATFORM_WIN32
}

System::CFileString CoreTools::StringConversion::StandardConversionCFileString(const String& character)
{
#if !defined(TCRE_USE_GCC)
    return character;
#else  // defined(TCRE_USE_GCC)
    return StandardConversionMultiByte(character);
#endif  // !defined(TCRE_USE_GCC)
}

string CoreTools::StringConversion::DynamicLinkStringConversionMultiByte(const DynamicLinkString& character)
{
#ifdef SYSTEM_PLATFORM_WIN32
    return StandardConversionMultiByte(character);
#else  // !SYSTEM_PLATFORM_WIN32
    return character;
#endif  // SYSTEM_PLATFORM_WIN32
}

System::String CoreTools::StringConversion::DynamicLinkStringConversionStandard(const DynamicLinkString& character)
{
#ifdef SYSTEM_PLATFORM_WIN32
    return character;
#else  // !SYSTEM_PLATFORM_WIN32
    return MultiByteConversionStandard(character);
#endif  // SYSTEM_PLATFORM_WIN32
}

wstring CoreTools::StringConversion::UTF8ConversionWideChar(const string& character)
{
    const CoreTools::MultiByteConversionWideChar conversion{ character, true };

    return conversion.GetWideCharRepresentation();
}

string CoreTools::StringConversion::WideCharConversionUTF8(const wstring& character)
{
    const CoreTools::WideCharConversionMultiByte conversion{ character, true };

    return conversion.GetMultiByteRepresentation();
}

System::String CoreTools::StringConversion::UTF8ConversionStandard(const string& character)
{
    const auto wideChar = UTF8ConversionWideChar(character);

    return WideCharConversionStandard(wideChar);
}

System::String CoreTools::StringConversion::UTF8ConversionStandard(const std::wstring& character)
{
    string multiByte{};

    for (auto c : character)
    {
        // 这里溢出不抛出异常，直接截断字符。
        multiByte += gsl::narrow_cast<char>(c);
    }

    return UTF8ConversionStandard(multiByte);
}

string CoreTools::StringConversion::StandardConversionUTF8(const String& character)
{
    const auto wideChar = StandardConversionWideChar(character);

    return WideCharConversionUTF8(wideChar);
}

string CoreTools::StringConversion::UTF8ConversionMultiByte(const string& character)
{
    const auto wideChar = UTF8ConversionWideChar(character);

    return WideCharConversionMultiByte(wideChar);
}

string CoreTools::StringConversion::MultiByteConversionUTF8(const string& character)
{
    const auto wideChar = MultiByteConversionWideChar(character);

    return WideCharConversionUTF8(wideChar);
}

System::String CoreTools::StringConversion::ToFirstLetterUpper(const String& character)
{
    auto result = character;

    if (result.empty())
    {
        return result;
    }

    const std::locale locale{};
    result.at(0) = std::toupper(result.at(0), locale);

    return result;
}

System::String CoreTools::StringConversion::ToFirstLetterLower(const String& character)
{
    auto result = character;

    if (result.empty())
    {
        return result;
    }

    const std::locale locale{};
    result.at(0) = std::tolower(result.at(0), locale);

    return result;
}

System::String CoreTools::StringConversion::ToUpperMacro(const String& character)
{
    String result{};

    const std::locale locale{};

    auto firstChar = true;
    for (auto value : character)
    {
        if (value == SYSTEM_TEXT(' '))
        {
            continue;
        }

        if (!firstChar && std::isupper(value, locale))
        {
            result += SYSTEM_TEXT('_');
            result += value;
        }
        else if (value == SYSTEM_TEXT('.'))
        {
            result += SYSTEM_TEXT('_');
        }
        else
        {
            result += std::toupper(value, locale);
        }

        firstChar = false;
    }

    return result;
}
