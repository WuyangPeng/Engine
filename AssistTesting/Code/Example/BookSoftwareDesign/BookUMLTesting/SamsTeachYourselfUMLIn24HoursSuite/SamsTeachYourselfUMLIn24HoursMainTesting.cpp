// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/05 18:10)

#include "SamsTeachYourselfUMLIn24HoursMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookSoftwareDesign/BookUML/Helper/BookUMLClassInvariantMacro.h"
#include "Example/BookSoftwareDesign/BookUML/SamsTeachYourselfUMLIn24Hours/SamsTeachYourselfUMLIn24HoursMain.h"

namespace BookUML
{
	using TestingType = SamsTeachYourselfUMLIn24HoursMain;
}

BookUML::SamsTeachYourselfUMLIn24HoursMainTesting
	::SamsTeachYourselfUMLIn24HoursMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_UML_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookUML, SamsTeachYourselfUMLIn24HoursMainTesting)

void BookUML::SamsTeachYourselfUMLIn24HoursMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookUML::SamsTeachYourselfUMLIn24HoursMainTesting
	::MainTest() 
{
	TestingType samsTeachYourselfUMLIn24HoursMain{ };

	ASSERT_TRUE(samsTeachYourselfUMLIn24HoursMain.Main());
	ASSERT_TRUE(samsTeachYourselfUMLIn24HoursMain.ExecuteChapter1());
}

