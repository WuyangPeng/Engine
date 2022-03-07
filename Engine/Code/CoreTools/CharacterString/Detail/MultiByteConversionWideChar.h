///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.1 (2022/01/12 14:07)

#ifndef CORE_TOOLS_CHARACTER_STRING_MULTI_BYTE_CONVERSION_WIDE_CHAR_H
#define CORE_TOOLS_CHARACTER_STRING_MULTI_BYTE_CONVERSION_WIDE_CHAR_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>
#include <vector>

namespace CoreTools
{
    // 多字节字符串转换为宽字符串
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