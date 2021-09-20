// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.0 (2020/04/04 22:23)

#include "DatabaseSystemsTheCompletsBookMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/Helper/BookDatabaseClassInvariantMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/DatabaseSystemsTheCompletsBook/DatabaseSystemsTheCompletsBookMain.h"

namespace BookDatabase
{
	using TestingType = DatabaseSystemsTheCompletsBookMain;
}

BookDatabase::DatabaseSystemsTheCompletsBookMainTesting
	::DatabaseSystemsTheCompletsBookMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookDatabase, DatabaseSystemsTheCompletsBookMainTesting)

void BookDatabase::DatabaseSystemsTheCompletsBookMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookDatabase::DatabaseSystemsTheCompletsBookMainTesting
	::MainTest() 
{
	TestingType databaseSystemsTheCompletsBookMain{ };

	ASSERT_TRUE(databaseSystemsTheCompletsBookMain.Main());
	ASSERT_TRUE(databaseSystemsTheCompletsBookMain.ExecuteChapter1());
}

