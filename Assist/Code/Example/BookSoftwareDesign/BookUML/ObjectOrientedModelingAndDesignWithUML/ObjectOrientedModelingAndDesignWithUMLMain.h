// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.1 (2020/04/05 17:54)

#ifndef BOOK_UML_OBJECT_ORIENTED_MODELING_AND_DESIGN_WITH_UML_MAIN_H
#define BOOK_UML_OBJECT_ORIENTED_MODELING_AND_DESIGN_WITH_UML_MAIN_H

#include "Example/BookSoftwareDesign/BookUML/BookUMLDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace BookUML
{
	 class BOOK_UML_DEFAULT_DECLARE ObjectOrientedModelingAndDesignWithUMLMain
	 {
	 public:
		 using ClassType = ObjectOrientedModelingAndDesignWithUMLMain;

	 public:
		 CLASS_INVARIANT_DECLARE;

		 bool Main() noexcept;

		 bool ExecuteChapter1() noexcept;
	 };	
}

#endif // BOOK_UML_OBJECT_ORIENTED_MODELING_AND_DESIGN_WITH_UML_MAIN_H
