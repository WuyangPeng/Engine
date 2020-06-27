// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.2.1 (2020/01/19 10:22)

// ¿í×Ö·û´®×ª»»Îª¶à×Ö½Ú×Ö·û´®
#ifndef CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H
#define CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H

#include "CoreTools/CoreToolsDll.h"

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/MemoryTools/HeapAllocate.h"

#include <string>
#include <vector>
#include <memory>

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE WideCharConversionMultiByte
	{
	public:
		using ClassType = WideCharConversionMultiByte;

	public:
		explicit WideCharConversionMultiByte(const std::wstring& character, bool isUTF8);

		CLASS_INVARIANT_DECLARE;

		const std::string GetMultiByteRepresentation() const;

	private:
		using WCharContainer = std::vector<wchar_t>;
		using CharHeapAllocate = HeapAllocate<char>;
		using CharHeapAllocatePtr = std::shared_ptr<CharHeapAllocate>;

	private:
		void Conversion();
		void FillNullWChar();
		void CreateHeap();
		void FinishConversion();
		int GetReadSize(int lengthOfMultiByteString);

	private:
		WCharContainer m_Source;
		int m_LengthOfMultiByteString;
		CharHeapAllocatePtr m_Heap;
		int m_ReadSize;
		bool m_IsUTF8;
	};
}

#endif // CORE_TOOLS_CHARACTER_STRING_WIDE_CHAR_CONVERSION_MULTI_BYTE_H