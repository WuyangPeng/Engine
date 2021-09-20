// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.0 (2020/04/04 22:23)

#include "TransactionProcessingConceptsAndTechniquesMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/Helper/BookDatabaseClassInvariantMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/TransactionProcessingConceptsAndTechniques/TransactionProcessingConceptsAndTechniquesMain.h"

namespace BookDatabase
{
	using TestingType = TransactionProcessingConceptsAndTechniquesMain;
}

BookDatabase::TransactionProcessingConceptsAndTechniquesMainTesting
	::TransactionProcessingConceptsAndTechniquesMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookDatabase, TransactionProcessingConceptsAndTechniquesMainTesting)

void BookDatabase::TransactionProcessingConceptsAndTechniquesMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookDatabase::TransactionProcessingConceptsAndTechniquesMainTesting
	::MainTest() 
{
	TestingType transactionProcessingConceptsAndTechniquesMain{ };

	ASSERT_TRUE(transactionProcessingConceptsAndTechniquesMain.Main());
	ASSERT_TRUE(transactionProcessingConceptsAndTechniquesMain.ExecuteChapter1());
}

