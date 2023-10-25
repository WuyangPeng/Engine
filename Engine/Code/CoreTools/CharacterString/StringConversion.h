///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/23 10:25)

#ifndef CORE_TOOLS_CHARACTER_STRING_STRING_CONVERSION_H
#define CORE_TOOLS_CHARACTER_STRING_STRING_CONVERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE StringConversion final
    {
    public:
        using ClassType = StringConversion;

        using String = System::String;
        using CFileString = System::CFileString;
        using DynamicLinkString = System::DynamicLinkString;

    public:
        NODISCARD static std::wstring MultiByteConversionWideChar(const std::string& character);
        NODISCARD static std::string WideCharConversionMultiByte(const std::wstring& character);

        NODISCARD static std::wstring StandardConversionWideChar(const String& character);
        NODISCARD static std::string StandardConversionMultiByte(const String& character);
        NODISCARD static String WideCharConversionStandard(const std::wstring& character);
        NODISCARD static String MultiByteConversionStandard(const std::string& character);

        NODISCARD static DynamicLinkString StandardConversionDynamicLinkString(const String& character);
        NODISCARD static std::string DynamicLinkStringConversionMultiByte(const DynamicLinkString& character);
        NODISCARD static String DynamicLinkStringConversionStandard(const DynamicLinkString& character);

        NODISCARD static CFileString StandardConversionCFileString(const String& character);

        NODISCARD static std::wstring Utf8ConversionWideChar(const std::string& character);
        NODISCARD static std::string WideCharConversionUtf8(const std::wstring& character);
        NODISCARD static String Utf8ConversionStandard(const std::string& character);
        NODISCARD static String Utf8ConversionStandard(const std::wstring& character);
        NODISCARD static std::string StandardConversionUtf8(const String& character);
        NODISCARD static std::string Utf8ConversionMultiByte(const std::string& character);
        NODISCARD static std::string MultiByteConversionUtf8(const std::string& character);
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_STRING_CONVERSION_H