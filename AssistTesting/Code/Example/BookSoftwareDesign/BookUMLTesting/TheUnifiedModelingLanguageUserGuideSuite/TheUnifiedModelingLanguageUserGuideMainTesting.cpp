// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/05 18:10)

#include "TheUnifiedModelingLanguageUserGuideMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookSoftwareDesign/BookUML/Helper/BookUMLClassInvariantMacro.h"
#include "Example/BookSoftwareDesign/BookUML/TheUnifiedModelingLanguageUserGuide/TheUnifiedModelingLanguageUserGuideMain.h"

namespace BookUML
{
	using TestingType = TheUnifiedModelingLanguageUserGuideMain;
}

BookUML::TheUnifiedModelingLanguageUserGuideMainTesting
	::TheUnifiedModelingLanguageUserGuideMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_UML_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookUML, TheUnifiedModelingLanguageUserGuideMainTesting)

void BookUML::TheUnifiedModelingLanguageUserGuideMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookUML::TheUnifiedModelingLanguageUserGuideMainTesting
	::MainTest() 
{
	TestingType theUnifiedModelingLanguageUserGuideMain{ };

	ASSERT_TRUE(theUnifiedModelingLanguageUserGuideMain.Main());
	ASSERT_TRUE(theUnifiedModelingLanguageUserGuideMain.ExecuteChapter1());
}

