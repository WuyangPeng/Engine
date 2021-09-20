///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.7.2.2 (2021/08/29 20:20)

#ifndef CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H
#define CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <string>
#include <vector>

namespace CoreTools
{
    // 宽字符串转换为多字节字符串
    class CORE_TOOLS_HIDDEN_DECLARE WideCharConversionMultiByte final
    {
    public:
        using ClassType = WideCharConversionMultiByte;

    public:
        explicit WideCharConversionMultiByte(const std::wstring& character, bool isUTF8);

        CLASS_INVARIANT_DECLARE;

        NODISCARD const std::string GetMultiByteRepresentation() const;

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
        bool isUTF8;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H