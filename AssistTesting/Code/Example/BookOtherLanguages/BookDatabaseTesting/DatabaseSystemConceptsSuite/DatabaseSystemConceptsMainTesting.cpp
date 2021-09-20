// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ���渨�����԰汾��0.1.0.0 (2020/04/04 22:23)

#include "DatabaseSystemConceptsMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/Helper/BookDatabaseClassInvariantMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/DatabaseSystemConcepts/DatabaseSystemConceptsMain.h"

namespace BookDatabase
{
	using TestingType = DatabaseSystemConceptsMain;
}

BookDatabase::DatabaseSystemConceptsMainTesting
	::DatabaseSystemConceptsMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookDatabase, DatabaseSystemConceptsMainTesting)

void BookDatabase::DatabaseSystemConceptsMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookDatabase::DatabaseSystemConceptsMainTesting
	::MainTest() 
{
	TestingType databaseSystemConceptsMain{ };

	ASSERT_TRUE(databaseSystemConceptsMain.Main());
	ASSERT_TRUE(databaseSystemConceptsMain.ExecuteChapter1());
}

