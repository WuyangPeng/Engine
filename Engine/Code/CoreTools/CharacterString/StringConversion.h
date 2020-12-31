//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 13:50)

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
        [[nodiscard]] static std::wstring MultiByteConversionWideChar(const std::string& character);
        [[nodiscard]] static std::string WideCharConversionMultiByte(const std::wstring& character);

        [[nodiscard]] static std::wstring StandardConversionWideChar(const String& character);
        [[nodiscard]] static std::string StandardConversionMultiByte(const String& character);
        [[nodiscard]] static String WideCharConversionStandard(const std::wstring& character);
        [[nodiscard]] static String MultiByteConversionStandard(const std::string& character);

        [[nodiscard]] static DynamicLinkString StandardConversionDynamicLinkString(const String& character);
        [[nodiscard]] static std::string DynamicLinkStringConversionMultiByte(const DynamicLinkString& character);
        [[nodiscard]] static String DynamicLinkStringConversionStandard(const DynamicLinkString& character);

        [[nodiscard]] static CFileString StandardConversionCFileString(const String& character);

        [[nodiscard]] static std::wstring UTF8ConversionWideChar(const std::string& character);
        [[nodiscard]] static std::string WideCharConversionUTF8(const std::wstring& character);
        [[nodiscard]] static String UTF8ConversionStandard(const std::string& character);
        [[nodiscard]] static std::string StandardConversionUTF8(const String& character);
        [[nodiscard]] static std::string UTF8ConversionMultiByte(const std::string& character);
        [[nodiscard]] static std::string MultiByteConversionUTF8(const std::string& character);
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_STRING_CONVERSION_H