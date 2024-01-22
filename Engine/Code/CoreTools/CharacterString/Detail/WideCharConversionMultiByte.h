/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/10 20:19)

#ifndef CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H
#define CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <string>
#include <vector>

// 宽字符串转换为多字节字符串
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE WideCharConversionMultiByte final
    {
    public:
        using ClassType = WideCharConversionMultiByte;

    public:
        explicit WideCharConversionMultiByte(const std::wstring& character, bool isUtf8);

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetMultiByteRepresentation() const;

    private:
        using WCharContainer = std::vector<wchar_t>;
        using CharContainer = std::vector<char>;

    private:
        void Conversion();
        void FillNullWChar();
        void CreateTarget();
        void FinishConversion();
        NODISCARD int GetConversionLength();

    private:
        WCharContainer source;
        CharContainer target;
        int lengthOfMultiByteString;
        bool isUtf8;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H