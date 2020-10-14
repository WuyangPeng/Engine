//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 13:49)

// 宽字符串转换为多字节字符串
#ifndef CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H
#define CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/MemoryTools/HeapAllocate.h"

#include <memory>
#include <string>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE WideCharConversionMultiByte final
    {
    public:
        using ClassType = WideCharConversionMultiByte;

    public:
        explicit WideCharConversionMultiByte(const std::wstring& character, bool isUTF8);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] const std::string GetMultiByteRepresentation() const;

    private:
        using WCharContainer = std::vector<wchar_t>;
        using CharHeapAllocate = HeapAllocate<char>;
        using CharHeapAllocatePtr = std::shared_ptr<CharHeapAllocate>;

    private:
        void Conversion();
        void FillNullWChar();
        void CreateHeap();
        void FinishConversion();
        [[nodiscard]] int GetReadSize(int lengthOfMultiByteString);

    private:
        WCharContainer m_Source;
        int m_LengthOfMultiByteString;
        CharHeapAllocatePtr m_Heap;
        int m_ReadSize;
        bool m_IsUTF8;
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H