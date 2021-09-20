// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.1.0.1 (2020/04/06 20:57)

#ifndef BOOK_GEOMETRY_PROCEDURAL_ELEMENTS_FOR_COMPUTER_GRAPHICS_MAIN_H
#define BOOK_GEOMETRY_PROCEDURAL_ELEMENTS_FOR_COMPUTER_GRAPHICS_MAIN_H

#include "Example/BookGameDesign/BookGeometry/BookGeometryDll.h" 

#include "CoreTools/Helper/ExportMacro.h" 

namespace BookGeometry
{
	 class BOOK_GEOMETRY_DEFAULT_DECLARE ProceduralElementsForComputerGraphicsMain
	 {
	 public:
		 using ClassType = ProceduralElementsForComputerGraphicsMain;

	 public:
		 CLASS_INVARIANT_DECLARE;

		 bool Main() noexcept;

		 bool ExecuteChapter1() noexcept;
	 };	
}

#endif // BOOK_GEOMETRY_PROCEDURAL_ELEMENTS_FOR_COMPUTER_GRAPHICS_MAIN_H
