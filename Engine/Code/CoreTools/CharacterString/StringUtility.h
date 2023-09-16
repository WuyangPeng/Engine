///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	�汾��0.9.1.4 (2023/09/13 10:44)

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

        /// ��C++�ַ�����Ĭ�����������У��հ��ַ��ǿո�(0x20, ' ')�����з�(0x0C, '\f')������(0x0A, '\n')���س���(0x0D, '\r')��ˮƽ�Ʊ��(0x09, '\t') �ʹ�ֱ�Ʊ��(0x0B, '\v')��
        /// �� https://en.cppreference.com/w/cpp/string/byte/isspace
        /// ����ASCIIֵ���Լ���ص�is*��isw*������������'int ch'���룩������0��!0
        NODISCARD static TokensType GetTokens(const std::string& input, const std::string& whiteSpace);

        /// ���ڻ����ı���ȡ����GetTokens(...)��ѡ��'whiteSpace'ΪASCIIֵ0x00-0x20,0x7F-0xFF��
        NODISCARD static TokensType GetTextTokens(const std::string& input);

        /// ���ڸ߼��ı���ȡ����GetTokens(...)��ѡ��'whiteSpace'ΪASCIIֵ0x00-0x20,0x7F��
        /// ASCIIֵ0x80�������κ������ַ���������Ϊ�ı���
        NODISCARD static TokensType GetAdvancedTextTokens(const std::string& input);

        NODISCARD static String ToFirstLetterUpper(const String& character);
        NODISCARD static String ToFirstLetterLower(const String& character);
        NODISCARD static String ToUpperMacro(const String& character);
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_STRING_UTILITY_H
