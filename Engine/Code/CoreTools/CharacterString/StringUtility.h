///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.4 (2023/09/13 10:44)

#ifndef CORE_TOOLS_CHARACTER_STRING_STRING_UTILITY_H
#define CORE_TOOLS_CHARACTER_STRING_STRING_UTILITY_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE StringUtility final
    {
    public:
        using ClassType = StringUtility;

        using String = System::String;
        using TokensType = std::vector<std::string>;

    public:
        NODISCARD static std::wstring ConvertNarrowToWide(const std::string& input);
        NODISCARD static std::string ConvertWideToNarrow(const std::wstring& input);
        NODISCARD static std::string ToLower(const std::string& input);
        NODISCARD static std::string ToUpper(const std::string& input);

        /// 在C++字符串的默认区域设置中，空白字符是空格(0x20, ' ')、换行符(0x0C, '\f')、换行(0x0A, '\n')、回车符(0x0D, '\r')、水平制表符(0x09, '\t') 和垂直制表符(0x0B, '\v')。
        /// 见 https://en.cppreference.com/w/cpp/string/byte/isspace
        /// 对于ASCII值表以及相关的is*和isw*函数，（带有'int ch'输入），返回0或!0
        NODISCARD static TokensType GetTokens(const std::string& input, const std::string& whiteSpace);

        /// 对于基础文本提取，在GetTokens(...)中选择'whiteSpace'为ASCII值0x00-0x20,0x7F-0xFF。
        NODISCARD static TokensType GetTextTokens(const std::string& input);

        /// 对于高级文本提取，在GetTokens(...)中选择'whiteSpace'为ASCII值0x00-0x20,0x7F。
        /// ASCII值0x80或更大的任何特殊字符都将保留为文本。
        NODISCARD static TokensType GetAdvancedTextTokens(const std::string& input);

        NODISCARD static String ToFirstLetterUpper(const String& character);
        NODISCARD static String ToFirstLetterLower(const String& character);
        NODISCARD static String ToUpperMacro(const String& character);
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_STRING_UTILITY_H
