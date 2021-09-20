// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨���汾��0.1.0.1 (2020/04/05 23:27)

#ifndef BOOK_UML_THE_UNIFIED_MODELING_LANGUAGE_REFERENCE_MANUAL_MAIN_H
#define BOOK_UML_THE_UNIFIED_MODELING_LANGUAGE_REFERENCE_MANUAL_MAIN_H

#include "Example/BookSoftwareDesign/BookUML/BookUMLDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace BookUML
{
	 class BOOK_UML_DEFAULT_DECLARE TheUnifiedModelingLanguageReferenceManualMain
	 {
	 public:
		 using ClassType = TheUnifiedModelingLanguageReferenceManualMain;

	 public:
		 CLASS_INVARIANT_DECLARE;

		 bool Main() noexcept;

		 bool ExecuteChapter1() noexcept;
	 };	
}

#endif // BOOK_UML_THE_UNIFIED_MODELING_LANGUAGE_REFERENCE_MANUAL_MAIN_H
