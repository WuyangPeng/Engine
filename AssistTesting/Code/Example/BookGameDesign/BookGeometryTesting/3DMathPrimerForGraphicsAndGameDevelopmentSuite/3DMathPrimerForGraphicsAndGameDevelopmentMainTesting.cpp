// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/05 18:10)

#include "3DMathPrimerForGraphicsAndGameDevelopmentMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookGameDesign/BookGeometry/Helper/BookGeometryClassInvariantMacro.h"
#include "Example/BookGameDesign/BookGeometry/3DMathPrimerForGraphicsAndGameDevelopment/3DMathPrimerForGraphicsAndGameDevelopmentMain.h"

namespace BookGeometry
{
	using TestingType = ThreeDMathPrimerForGraphicsAndGameDevelopmentMain;
}

BookGeometry::ThreeDMathPrimerForGraphicsAndGameDevelopmentMainTesting
	::ThreeDMathPrimerForGraphicsAndGameDevelopmentMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_GEOMETRY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookGeometry, ThreeDMathPrimerForGraphicsAndGameDevelopmentMainTesting)

void BookGeometry::ThreeDMathPrimerForGraphicsAndGameDevelopmentMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookGeometry::ThreeDMathPrimerForGraphicsAndGameDevelopmentMainTesting
	::MainTest() 
{
	TestingType threeDMathPrimerForGraphicsAndGameDevelopmentMain{ };

	ASSERT_TRUE(threeDMathPrimerForGraphicsAndGameDevelopmentMain.Main());
	ASSERT_TRUE(threeDMathPrimerForGraphicsAndGameDevelopmentMain.ExecuteChapter1());
}

