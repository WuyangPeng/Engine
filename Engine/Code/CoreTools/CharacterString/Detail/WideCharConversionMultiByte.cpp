//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 13:55)

#include "CoreTools/CoreToolsExport.h"

#include "WideCharConversionMultiByte.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MemoryTools/HeapAllocateDetail.h"

using std::make_shared;
using std::string;
using std::wstring;

CoreTools::WideCharConversionMultiByte::WideCharConversionMultiByte(const wstring& character, bool isUTF8)
    : m_Source{ character.begin(), character.end() }, m_LengthOfMultiByteString{ 0 }, m_Heap{ nullptr }, m_ReadSize{ 0 }, m_IsUTF8{ isUTF8 }
{
    Conversion();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::WideCharConversionMultiByte::Conversion()
{
    FillNullWChar();
    CreateHeap();
    FinishConversion();
}

// private
void CoreTools::WideCharConversionMultiByte::FillNullWChar()
{
    m_Source.push_back(L'\0');
}

// private
int CoreTools::WideCharConversionMultiByte::GetReadSize(int lengthOfMultiByteString)
{
    auto destSize = boost::numeric_cast<int>(m_Source.size());

    char* multiByte{ nullptr };
    if (0 < lengthOfMultiByteString)
    {
        multiByte = m_Heap->GetPoint();
    }

    if (m_IsUTF8)
    {
        return System::WideCharConversionUTF8(m_Source.data(), destSize, multiByte, lengthOfMultiByteString);
    }
    else
    {
        return System::WideCharConversionMultiByte(m_Source.data(), destSize, multiByte, lengthOfMultiByteString);
    }
}

// private
void CoreTools::WideCharConversionMultiByte::CreateHeap()
{
    m_LengthOfMultiByteString = GetReadSize(0);

    if (0 < m_LengthOfMultiByteString)
    {
        m_Heap = make_shared<CharHeapAllocate>(m_LengthOfMultiByteString);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Wide Char 转换为 Multi Byte 失败！"s));
    }
}

// private
void CoreTools::WideCharConversionMultiByte::FinishConversion()
{
    m_ReadSize = GetReadSize(m_LengthOfMultiByteString);

    if (m_ReadSize <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Wide Char 转换为 Multi Byte 失败！"s));
    }
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::WideCharConversionMultiByte::IsValid() const noexcept
{
    if (m_Heap != nullptr && 0 < m_ReadSize && m_ReadSize <= m_LengthOfMultiByteString)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

const string CoreTools::WideCharConversionMultiByte::GetMultiByteRepresentation() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
    return string{ m_Heap->GetPoint(), m_Heap->GetPoint() + m_ReadSize - 1 };
#include STSTEM_WARNING_POP
}
