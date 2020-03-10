// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/19 10:23)

#ifndef CORE_TOOLS_CHARACTER_STRING_STRING_CONVERSION_H
#define CORE_TOOLS_CHARACTER_STRING_STRING_CONVERSION_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "System/FileManager/Using/CFileUsing.h"
#include "System/DynamicLink/Using/LoadLibraryUsing.h"

#include <string>

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE StringConversion
	{
	public:
		using ClassType = StringConversion;
		using String = System::String;
		using CFileString = System::CFileString;
		using DynamicLinkString = System::DynamicLinkString;

		static std::wstring MultiByteConversionWideChar(const std::string& character);
		static std::string WideCharConversionMultiByte(const std::wstring& character);

		static std::wstring StandardConversionWideChar(const String& character);
		static std::string StandardConversionMultiByte(const String& character);
		static String WideCharConversionStandard(const std::wstring& character);
		static String MultiByteConversionStandard(const std::string& character);

		static DynamicLinkString StandardConversionDynamicLinkString(const String& character);
		static std::string DynamicLinkStringConversionMultiByte(const DynamicLinkString& character);
		static String DynamicLinkStringConversionStandard(const DynamicLinkString& character);

		static CFileString StandardConversionCFileString(const String& character);

		static std::wstring UTF8ConversionWideChar(const std::string& character);
		static std::string WideCharConversionUTF8(const std::wstring& character);
		static String UTF8ConversionStandard(const std::string& character);
		static std::string StandardConversionUTF8(const String& character);
		static std::string UTF8ConversionMultiByte(const std::string& character);
		static std::string MultiByteConversionUTF8(const std::string& character);
	};
}

#endif // CORE_TOOLS_CHARACTER_STRING_STRING_CONVERSION_H