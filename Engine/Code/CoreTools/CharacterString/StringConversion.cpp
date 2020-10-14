//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 14:00)

#include "CoreTools/CoreToolsExport.h"

#include "StringConversion.h"
#include "Detail/MultiByteConversionWideChar.h"
#include "Detail/WideCharConversionMultiByte.h"
#include "System/CharacterString/StringConversion.h"

using std::string;
using std::wstring;

wstring CoreTools::StringConversion::MultiByteConversionWideChar(const string& character)
{
    CoreTools::MultiByteConversionWideChar conversion{ character, false };

    return conversion.GetWideCharRepresentation();
}

string CoreTools::StringConversion::WideCharConversionMultiByte(const wstring& character)
{
    CoreTools::WideCharConversionMultiByte conversion{ character, false };

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
    CoreTools::MultiByteConversionWideChar conversion{ character, true };

    return conversion.GetWideCharRepresentation();
}

string CoreTools::StringConversion::WideCharConversionUTF8(const wstring& character)
{
    CoreTools::WideCharConversionMultiByte conversion{ character, true };

    return conversion.GetMultiByteRepresentation();
}

System::String CoreTools::StringConversion::UTF8ConversionStandard(const string& character)
{
    auto wideChar = UTF8ConversionWideChar(character);

    return WideCharConversionStandard(wideChar);
}

string CoreTools::StringConversion::StandardConversionUTF8(const String& character)
{
    auto wideChar = StandardConversionWideChar(character);

    return WideCharConversionUTF8(wideChar);
}

string CoreTools::StringConversion::UTF8ConversionMultiByte(const string& character)
{
    auto wideChar = UTF8ConversionWideChar(character);

    return WideCharConversionMultiByte(wideChar);
}

string CoreTools::StringConversion::MultiByteConversionUTF8(const string& character)
{
    auto wideChar = MultiByteConversionWideChar(character);

    return WideCharConversionUTF8(wideChar);
}
