//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.1.1 (2020/10/12 13:52)

#include "CoreTools/CoreToolsExport.h"

#include "MultiByteConversionWideChar.h"
#include "System/CharacterString/StringConversion.h"
#include "System/Helper/PragmaWarning/NumericCast.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/MemoryTools/HeapAllocateDetail.h"

using std::make_shared;
using std::string;
using std::wstring;

CoreTools::MultiByteConversionWideChar::MultiByteConversionWideChar(const string& character, bool isUTF8)
    : m_Source{ character.begin(), character.end() }, m_LengthOfWideCharString{ 0 }, m_Heap{ nullptr }, m_ReadSize{ 0 }, m_IsUTF8{ isUTF8 }
{
    Conversion();

    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::MultiByteConversionWideChar::Conversion()
{
    FillNullChar();
    CreateHeap();
    FinishConversion();
}

// private
void CoreTools::MultiByteConversionWideChar::FillNullChar()
{
    m_Source.push_back('\0');
}

// private
int CoreTools::MultiByteConversionWideChar::GetReadSize(int lengthOfWideCharString)
{
    auto destSize = boost::numeric_cast<int>(m_Source.size());

    wchar_t* wideChar{ nullptr };
    if (0 < lengthOfWideCharString)
    {
        wideChar = m_Heap->GetPoint();
    }

    if (m_IsUTF8)
    {
        return System::UTF8ConversionWideChar(m_Source.data(), destSize, wideChar, lengthOfWideCharString);
    }
    else
    {
        return System::MultiByteConversionWideChar(m_Source.data(), destSize, wideChar, lengthOfWideCharString);
    }
}

// private
void CoreTools::MultiByteConversionWideChar::CreateHeap()
{
    m_LengthOfWideCharString = GetReadSize(0);

    if (0 < m_LengthOfWideCharString)
    {
        m_Heap = make_shared<WCharHeapAllocate>(m_LengthOfWideCharString);
    }
    else
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Multi Byte 转换为 Wide Char 失败！"s));
    }
}

// private
void CoreTools::MultiByteConversionWideChar::FinishConversion()
{
    m_ReadSize = GetReadSize(m_LengthOfWideCharString);

    if (m_ReadSize <= 0)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("Multi Byte 转换为 Wide Char 失败！"s));
    }
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::MultiByteConversionWideChar::IsValid() const noexcept
{
    if (m_Heap != nullptr && 0 < m_ReadSize && m_ReadSize <= m_LengthOfWideCharString)
    {
        return true;
    }
    else
    {
        return false;
    }
}
#endif  // OPEN_CLASS_INVARIANT

const wstring CoreTools::MultiByteConversionWideChar::GetWideCharRepresentation() const
{
    CORE_TOOLS_CLASS_IS_VALID_CONST_1;

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26481)
    return wstring{ m_Heap->GetPoint(), m_Heap->GetPoint() + m_ReadSize - 1 };
#include STSTEM_WARNING_POP
}
