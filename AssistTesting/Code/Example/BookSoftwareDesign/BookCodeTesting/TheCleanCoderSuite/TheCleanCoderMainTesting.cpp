// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.3 (2020/04/28 21:41)

#include "TheCleanCoderMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookSoftwareDesign/BookCode/Helper/BookCodeClassInvariantMacro.h"
#include "Example/BookSoftwareDesign/BookCode/TheCleanCoder/TheCleanCoderMain.h"

namespace BookCode
{
	using TestingType = TheCleanCoderMain;
}

BookCode::TheCleanCoderMainTesting
	::TheCleanCoderMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_CODE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookCode, TheCleanCoderMainTesting)

void BookCode::TheCleanCoderMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookCode::TheCleanCoderMainTesting
	::MainTest() 
{
	TestingType theCleanCoderMain{ };

	ASSERT_TRUE(theCleanCoderMain.Main());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter1());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter2());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter3());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter4());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter5());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter6());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter7());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter8());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter9());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter10());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter11());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter12());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter13());
	ASSERT_TRUE(theCleanCoderMain.ExecuteChapter14());
	ASSERT_TRUE(theCleanCoderMain.ExecuteAppendix());
}

