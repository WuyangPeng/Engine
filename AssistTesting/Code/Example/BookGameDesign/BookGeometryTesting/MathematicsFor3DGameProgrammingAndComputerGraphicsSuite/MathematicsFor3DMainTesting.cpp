// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/06 23:13)

#include "MathematicsFor3DMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookGameDesign/BookGeometry/Helper/BookGeometryClassInvariantMacro.h"
#include "Example/BookGameDesign/BookGeometry/MathematicsFor3DGameProgrammingAndComputerGraphics/MathematicsFor3DGameProgrammingAndComputerGraphicsMain.h"

namespace BookGeometry
{
	using TestingType = MathematicsFor3DGameProgrammingAndComputerGraphicsMain;
}

BookGeometry::MathematicsFor3DMainTesting
	::MathematicsFor3DMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_GEOMETRY_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookGeometry, MathematicsFor3DMainTesting)

void BookGeometry::MathematicsFor3DMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookGeometry::MathematicsFor3DMainTesting
	::MainTest() 
{
	TestingType mathematicsFor3DGameProgrammingAndComputerGraphicsMain{ };

	ASSERT_TRUE(mathematicsFor3DGameProgrammingAndComputerGraphicsMain.Main());
	ASSERT_TRUE(mathematicsFor3DGameProgrammingAndComputerGraphicsMain.ExecuteChapter1());
}

