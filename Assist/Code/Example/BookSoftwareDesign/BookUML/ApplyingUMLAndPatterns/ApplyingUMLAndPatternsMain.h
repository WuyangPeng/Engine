// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.1 (2020/04/05 23:27)

#ifndef BOOK_UML_APPLYING_UML_AND_PATTERNS_MAIN_H
#define BOOK_UML_APPLYING_UML_AND_PATTERNS_MAIN_H

#include "Example/BookSoftwareDesign/BookUML/BookUMLDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace BookUML
{
	 class BOOK_UML_DEFAULT_DECLARE ApplyingUMLAndPatternsMain
	 {
	 public:
		 using ClassType = ApplyingUMLAndPatternsMain;

	 public:
		 CLASS_INVARIANT_DECLARE;

		 bool Main() noexcept;

		 bool ExecuteChapter1() noexcept;
	 };	
}

#endif // BOOK_UML_APPLYING_UML_AND_PATTERNS_MAIN_H
