// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.1 (2020/04/05 18:10)

#include "UMLDistilledMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookSoftwareDesign/BookUML/Helper/BookUMLClassInvariantMacro.h"
#include "Example/BookSoftwareDesign/BookUML/UMLDistilled/UMLDistilledMain.h"

namespace BookUML
{
	using TestingType = UMLDistilledMain;
}

BookUML::UMLDistilledMainTesting
	::UMLDistilledMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_UML_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookUML, UMLDistilledMainTesting)

void BookUML::UMLDistilledMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookUML::UMLDistilledMainTesting
	::MainTest() 
{
	TestingType umlDistilledMain{ };

	ASSERT_TRUE(umlDistilledMain.Main());
	ASSERT_TRUE(umlDistilledMain.ExecuteChapter1());
}

