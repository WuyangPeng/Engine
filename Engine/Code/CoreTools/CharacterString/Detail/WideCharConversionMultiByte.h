///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.7.2.2 (2021/08/29 20:20)

#ifndef CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H
#define CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"

#include <memory>
#include <string>
#include <vector>

namespace CoreTools
{
    // ���ַ���ת��Ϊ���ֽ��ַ���
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