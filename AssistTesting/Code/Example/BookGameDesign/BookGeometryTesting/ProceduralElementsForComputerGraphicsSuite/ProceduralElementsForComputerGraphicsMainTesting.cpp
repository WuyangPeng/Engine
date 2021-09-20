// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/06 23:13)

#include "ProceduralElementsForComputerGraphicsMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookGameDesign/BookGeometry/Helper/BookGeometryClassInvariantMacro.h"
#include "Example/BookGameDesign/BookGeometry/ProceduralElementsForComputerGraphics/ProceduralElementsForComputerGraphicsMain.h"

namespace BookGeometry
{
	using TestingType = ProceduralElementsForComputerGraphicsMain;
}

BookGeometry::ProceduralElementsForComputerGraphicsMainTesting
	::ProceduralElementsForComputerGraphicsMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_GEOMETRY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookGeometry, ProceduralElementsForComputerGraphicsMainTesting)

void BookGeometry::ProceduralElementsForComputerGraphicsMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookGeometry::ProceduralElementsForComputerGraphicsMainTesting
	::MainTest() 
{
	TestingType froceduralElementsForComputerGraphicsMain{ };

	ASSERT_TRUE(froceduralElementsForComputerGraphicsMain.Main());
	ASSERT_TRUE(froceduralElementsForComputerGraphicsMain.ExecuteChapter1());
}

