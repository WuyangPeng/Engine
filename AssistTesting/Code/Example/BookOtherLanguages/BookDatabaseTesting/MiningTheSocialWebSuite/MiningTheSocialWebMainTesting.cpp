// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.0 (2020/04/04 22:23)

#include "MiningTheSocialWebMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/Helper/BookDatabaseClassInvariantMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/MiningTheSocialWeb/MiningTheSocialWebMain.h"

namespace BookDatabase
{
	using TestingType = MiningTheSocialWebMain;
}

BookDatabase::MiningTheSocialWebMainTesting
	::MiningTheSocialWebMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookDatabase, MiningTheSocialWebMainTesting)

void BookDatabase::MiningTheSocialWebMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookDatabase::MiningTheSocialWebMainTesting
	::MainTest() 
{
	TestingType miningTheSocialWebMain{ };

	ASSERT_TRUE(miningTheSocialWebMain.Main());
	ASSERT_TRUE(miningTheSocialWebMain.ExecuteChapter1());
}

