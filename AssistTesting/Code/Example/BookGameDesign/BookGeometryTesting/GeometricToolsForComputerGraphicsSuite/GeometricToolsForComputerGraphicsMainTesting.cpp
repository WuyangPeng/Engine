// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/06 23:13)

#include "GeometricToolsForComputerGraphicsMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookGameDesign/BookGeometry/Helper/BookGeometryClassInvariantMacro.h"
#include "Example/BookGameDesign/BookGeometry/GeometricToolsForComputerGraphics/GeometricToolsForComputerGraphicsMain.h"

namespace BookGeometry
{
	using TestingType = GeometricToolsForComputerGraphicsMain;
}

BookGeometry::GeometricToolsForComputerGraphicsMainTesting
	::GeometricToolsForComputerGraphicsMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_GEOMETRY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookGeometry, GeometricToolsForComputerGraphicsMainTesting)

void BookGeometry::GeometricToolsForComputerGraphicsMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookGeometry::GeometricToolsForComputerGraphicsMainTesting
	::MainTest() 
{
	TestingType geometricToolsForComputerGraphicsMain{ };

	ASSERT_TRUE(geometricToolsForComputerGraphicsMain.Main());
	ASSERT_TRUE(geometricToolsForComputerGraphicsMain.ExecuteChapter1());
}

