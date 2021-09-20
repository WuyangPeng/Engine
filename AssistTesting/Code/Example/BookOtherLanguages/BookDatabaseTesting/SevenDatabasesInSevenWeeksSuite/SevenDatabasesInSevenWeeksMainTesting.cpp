// Copyright (c) 2011-2020
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
//
// ÒıÇæ¸¨Öú²âÊÔ°æ±¾£º0.1.0.0 (2020/04/04 22:23)

#include "SevenDatabasesInSevenWeeksMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/Helper/BookDatabaseClassInvariantMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/SevenDatabasesInSevenWeeks/SevenDatabasesInSevenWeeksMain.h"

namespace BookDatabase
{
	using TestingType = SevenDatabasesInSevenWeeksMain;
}

BookDatabase::SevenDatabasesInSevenWeeksMainTesting
	::SevenDatabasesInSevenWeeksMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookDatabase, SevenDatabasesInSevenWeeksMainTesting)

void BookDatabase::SevenDatabasesInSevenWeeksMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookDatabase::SevenDatabasesInSevenWeeksMainTesting
	::MainTest() 
{
	TestingType sevenDatabasesInSevenWeeksMain{ };

	ASSERT_TRUE(sevenDatabasesInSevenWeeksMain.Main());
	ASSERT_TRUE(sevenDatabasesInSevenWeeksMain.ExecuteChapter1());
}

