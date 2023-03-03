///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎版本：0.9.0.3 (2023/02/27 15:25)

#include "CoreTools/CoreToolsExport.h"

#include "StringConversion.h"
#include "Detail/MultiByteConversionWideChar.h"
#include "Detail/WideCharConversionMultiByte.h"
#include "System/CharacterString/StringConversion.h"

#include <gsl/util>

std::wstring CoreTools::StringConversion::MultiByteConversionWideChar(const std::string& character)
{
    const CoreTools::MultiByteConversionWideChar conversion{ character, false };

    return conversion.GetWideCharRepresentation();
}

std::string CoreTools::StringConversion::WideCharConversionMultiByte(const std::wstring& character)
{
    const CoreTools::WideCharConversionMultiByte conversion{ character, false };

    return conversion.GetMultiByteRepresentation();
}

std::wstring CoreTools::StringConversion::StandardConversionWideChar(const String& character)
{
#ifdef UNICODE

    return character;

#else  // !UNICODE

    return MultiByteConversionWideChar(character);

#endif  // UNICODE
}

std::string CoreTools::StringConversion::StandardConversionMultiByte(const String& character)
{
#ifdef UNICODE

    return WideCharConversionMultiByte(character);

#else  // !UNICODE

    return character;

#endif  // UNICODE
}

System::String CoreTools::StringConversion::WideCharConversionStandard(const std::wstring& character)
{
#ifdef UNICODE

    return character;

#else  // !UNICODE

    return WideCharConversionMultiByte(character);

#endif  // UNICODE
}

System::String CoreTools::StringConversion::MultiByteConversionStandard(const std::string& character)
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

std::string CoreTools::StringConversion::DynamicLinkStringConversionMultiByte(const DynamicLinkString& character)
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

std::wstring CoreTools::StringConversion::Utf8ConversionWideChar(const std::string& character)
{
    const CoreTools::MultiByteConversionWideChar conversion{ character, true };

    return conversion.GetWideCharRepresentation();
}

std::string CoreTools::StringConversion::WideCharConversionUtf8(const std::wstring& character)
{
    const CoreTools::WideCharConversionMultiByte conversion{ character, true };

    return conversion.GetMultiByteRepresentation();
}

System::String CoreTools::StringConversion::Utf8ConversionStandard(const std::string& character)
{
    const auto wideChar = Utf8ConversionWideChar(character);

    return WideCharConversionStandard(wideChar);
}

System::String CoreTools::StringConversion::Utf8ConversionStandard(const std::wstring& character)
{
    std::string multiByte{};

    for (auto c : character)
    {
        // 这里溢出不抛出异常，直接截断字符。
        multiByte += gsl::narrow_cast<char>(c);
    }

    return Utf8ConversionStandard(multiByte);
}

std::string CoreTools::StringConversion::StandardConversionUtf8(const String& character)
{
    const auto wideChar = StandardConversionWideChar(character);

    return WideCharConversionUtf8(wideChar);
}

std::string CoreTools::StringConversion::Utf8ConversionMultiByte(const std::string& character)
{
    const auto wideChar = Utf8ConversionWideChar(character);

    return WideCharConversionMultiByte(wideChar);
}

std::string CoreTools::StringConversion::MultiByteConversionUtf8(const std::string& character)
{
    const auto wideChar = MultiByteConversionWideChar(character);

    return WideCharConversionUtf8(wideChar);
}
