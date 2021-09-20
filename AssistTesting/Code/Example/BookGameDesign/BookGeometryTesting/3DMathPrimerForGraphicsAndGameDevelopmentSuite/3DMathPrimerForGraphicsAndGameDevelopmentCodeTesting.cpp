// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/05 18:10)

#include "3DMathPrimerForGraphicsAndGameDevelopmentCodeTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookGameDesign/3DMathPrimerForGraphicsAndGameDevelopment/Helper/3DMathPrimerForGraphicsAndGameDevelopmentClassInvariantMacro.h"
#include "Example/BookGameDesign/3DMathPrimerForGraphicsAndGameDevelopment/Code/CodeMain.h"

namespace BookGeometry
{
	using TestingType = ThreeDMathPrimerForGraphicsAndGameDevelopment::CodeMain;
}

BookGeometry::ThreeDMathPrimerForGraphicsAndGameDevelopmentCodeTesting
	::ThreeDMathPrimerForGraphicsAndGameDevelopmentCodeTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	THREE_D_MATH_PRIMER_FOR_GRAPHICS_AND_GAME_DEVELOPMENT_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookGeometry, ThreeDMathPrimerForGraphicsAndGameDevelopmentCodeTesting)

void BookGeometry::ThreeDMathPrimerForGraphicsAndGameDevelopmentCodeTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookGeometry::ThreeDMathPrimerForGraphicsAndGameDevelopmentCodeTesting
	::MainTest() 
{
	TestingType codeMain{ };

	ASSERT_TRUE(codeMain.Main());
	ASSERT_TRUE(codeMain.ExecuteChapter1());
}

