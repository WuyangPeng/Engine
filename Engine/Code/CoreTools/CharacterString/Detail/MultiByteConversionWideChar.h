/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/10 20:19)

#ifndef CORE_TOOLS_CHARACTER_STRING_MULTI_BYTE_CONVERSION_WIDE_CHAR_H
#define CORE_TOOLS_CHARACTER_STRING_MULTI_BYTE_CONVERSION_WIDE_CHAR_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>
#include <vector>

// ���ֽ��ַ���ת��Ϊ���ַ���
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE MultiByteConversionWideChar final
    {
    public:
        using ClassType = MultiByteConversionWideChar;

    public:
        explicit MultiByteConversionWideChar(const std::string& character, bool isUtf8);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::wstring GetWideCharRepresentation() const;

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
        bool isUtf8;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_MULTI_BYTE_CONVERSION_WIDE_CHAR_H