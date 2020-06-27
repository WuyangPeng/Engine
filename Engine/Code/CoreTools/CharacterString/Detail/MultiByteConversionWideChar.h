// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.1 (2020/01/19 10:21)

// ¶à×Ö½Ú×Ö·û´®×ª»»Îª¿í×Ö·û´®
#ifndef CORE_TOOLS_CHARACTER_STRING_MULTI_BYTE_CONVERSION_WIDE_CHAR_H
#define CORE_TOOLS_CHARACTER_STRING_MULTI_BYTE_CONVERSION_WIDE_CHAR_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/MemoryTools/HeapAllocate.h"

#include <string>
#include <vector>
#include <memory>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE MultiByteConversionWideChar
	{
	public:
		using ClassType = MultiByteConversionWideChar;

	public:
		explicit MultiByteConversionWideChar(const std::string& character, bool isUTF8);

		CLASS_INVARIANT_DECLARE;

		const std::wstring GetWideCharRepresentation() const;

	private:
		using CharContainer = std::vector<char>;
		using WCharHeapAllocate = HeapAllocate<wchar_t>;
		using WCharHeapAllocatePtr = std::shared_ptr<WCharHeapAllocate>;

	private:
		void Conversion();
		void FillNullChar();
		void CreateHeap();
		void FinishConversion();
		int GetReadSize(int lengthOfWideCharString);

	private:
		CharContainer m_Source; 
		int m_LengthOfWideCharString;
		WCharHeapAllocatePtr m_Heap;
		int m_ReadSize;
		bool m_IsUTF8;
	};
}

#endif // CORE_TOOLS_CHARACTER_STRING_MULTI_BYTE_CONVERSION_WIDE_CHAR_H