///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.1 (2022/01/12 14:07)

#ifndef CORE_TOOLS_CHARACTER_STRING_MULTI_BYTE_CONVERSION_WIDE_CHAR_H
#define CORE_TOOLS_CHARACTER_STRING_MULTI_BYTE_CONVERSION_WIDE_CHAR_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>
#include <vector>

namespace CoreTools
{
    // ���ֽ��ַ���ת��Ϊ���ַ���
    class CORE_TOOLS_HIDDEN_DECLARE MultiByteConversionWideChar final
    {
    public:
        using ClassType = MultiByteConversionWideChar;

    public:
        explicit MultiByteConversionWideChar(const std::string& character, bool isUTF8);

        CLASS_INVARIANT_DECLARE;

        NODISCARD const std::wstring GetWideCharRepresentation() const;

    private:
        using CharContainer = std::vector<char>;
        using WCharContainer = std::vector<wchar_t>;

    private:
        void Conversion();
        void FillNullChar();
        void CreateTarget();
        void FinishConversion();
        NODISCARD int GetConversionLength();

    private:
        CharContainer source;
        WCharContainer target;
        int lengthOfWideCharString;
        bool isUTF8;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_MULTI_BYTE_CONVERSION_WIDE_CHAR_H