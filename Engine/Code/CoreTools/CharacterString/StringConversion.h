/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/03/29 22:36)

#ifndef CORE_TOOLS_CHARACTER_STRING_STRING_CONVERSION_H
#define CORE_TOOLS_CHARACTER_STRING_STRING_CONVERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/DynamicLink/Using/LoadLibraryUsing.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/Helper/UnicodeUsing.h"

#include <string>
#include <filesystem>

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

        NODISCARD static String FileSystemConversionStandard(const std::filesystem::path::string_type& character);
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_STRING_CONVERSION_H