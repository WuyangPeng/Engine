// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.1 (2020/04/05 23:27)

#ifndef BOOK_UML_UML_DISTILLED_MAIN_H
#define BOOK_UML_UML_DISTILLED_MAIN_H

#include "Example/BookSoftwareDesign/BookUML/BookUMLDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace BookUML
{
	 class BOOK_UML_DEFAULT_DECLARE UMLDistilledMain
	 {
	 public:
		 using ClassType = UMLDistilledMain;

	 public:
		 CLASS_INVARIANT_DECLARE;

		 bool Main() noexcept;

		 bool ExecuteChapter1() noexcept;
	 };	
}

#endif // BOOK_UML_UML_DISTILLED_MAIN_H
