// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.1 (2020/01/19 10:31)

#include "CoreTools/CoreToolsExport.h"

#include "MultiByteConversionWideChar.h"
#include "System/CharacterString/StringConversion.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/MemoryTools/HeapAllocateDetail.h"

#include <boost/numeric/conversion/cast.hpp>

using std::string;
using std::wstring;
using std::make_shared;

CoreTools::MultiByteConversionWideChar
	::MultiByteConversionWideChar(const string& character, bool isUTF8)
	:m_Source{ character.begin(),character.end() }, m_LengthOfWideCharString{ 0 }, m_Heap{ nullptr }, m_ReadSize{ 0 }, m_IsUTF8{ isUTF8 }
{
	Conversion();

	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

// private
void CoreTools::MultiByteConversionWideChar
	::Conversion()
{
	FillNullChar();
	CreateHeap();
	FinishConversion();
}

// private
void CoreTools::MultiByteConversionWideChar
	::FillNullChar()
{
	m_Source.push_back('\0');	
}

// private
int CoreTools::MultiByteConversionWideChar
	::GetReadSize(int lengthOfWideCharString)
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
void CoreTools::MultiByteConversionWideChar
	::CreateHeap()
{
	m_LengthOfWideCharString = GetReadSize(0);

	if (0 < m_LengthOfWideCharString)
	{
		m_Heap = make_shared<WCharHeapAllocate>(m_LengthOfWideCharString);
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Multi Byte ×ª»»Îª Wide Char Ê§°Ü£¡"));
	}
}

// private
void CoreTools::MultiByteConversionWideChar
	::FinishConversion()
{
	m_ReadSize = GetReadSize(m_LengthOfWideCharString); 

	if (m_ReadSize <= 0)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Multi Byte ×ª»»Îª Wide Char Ê§°Ü£¡"));
	}
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::MultiByteConversionWideChar
	::IsValid() const noexcept
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
#endif // OPEN_CLASS_INVARIANT

const wstring CoreTools::MultiByteConversionWideChar
	::GetWideCharRepresentation() const
{
	CORE_TOOLS_CLASS_IS_VALID_CONST_1;

	return wstring{ m_Heap->GetPoint(), m_Heap->GetPoint() + m_ReadSize - 1 };
}

