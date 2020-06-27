// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.1.3 (2019/12/23 13:20)
// ³õÊ¼°æ±¾£º0.0.1.3

#include "CoreTools/CoreToolsExport.h"

#include "WideCharConversionMultiByte.h"
#include "System/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MemoryTools/HeapAllocateDetail.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

using std::string;
using std::wstring;
using std::make_shared;
using namespace std::literals;

CoreTools::WideCharConversionMultiByte
	::WideCharConversionMultiByte(const wstring& character, bool isUTF8)
	:m_Source{ character.begin(),character.end() }, m_LengthOfMultiByteString{ 0 }, m_Heap{ nullptr }, m_ReadSize{ 0 }, m_IsUTF8{ isUTF8 }
{
	Conversion();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::WideCharConversionMultiByte
	::Conversion()
{
	FillNullWChar();
	CreateHeap();
	FinishConversion();
}

// private
void CoreTools::WideCharConversionMultiByte
	::FillNullWChar()
{
	m_Source.push_back(L'\0');
}

// private
int CoreTools::WideCharConversionMultiByte
	::GetReadSize(int lengthOfMultiByteString)
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
void CoreTools::WideCharConversionMultiByte
	::CreateHeap()
{
	m_LengthOfMultiByteString = GetReadSize(0);

	if (0 < m_LengthOfMultiByteString)
	{
		m_Heap = make_shared<CharHeapAllocate>(m_LengthOfMultiByteString);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Wide Char ×ª»»Îª Multi Byte Ê§°Ü£¡"s));
	}
}

// private
void CoreTools::WideCharConversionMultiByte
	::FinishConversion()
{
	m_ReadSize = GetReadSize(m_LengthOfMultiByteString);

	if (m_ReadSize <= 0)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Wide Char ×ª»»Îª Multi Byte Ê§°Ü£¡"s));
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::WideCharConversionMultiByte
	::IsValid() const noexcept
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
#endif // OPEN_CLASS_INVARIANT

const string CoreTools::WideCharConversionMultiByte
	::GetMultiByteRepresentation() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return string{ m_Heap->GetPoint(), m_Heap->GetPoint() + m_ReadSize - 1 };
}

