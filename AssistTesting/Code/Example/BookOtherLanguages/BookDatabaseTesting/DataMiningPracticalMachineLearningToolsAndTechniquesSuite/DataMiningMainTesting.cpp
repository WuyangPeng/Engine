// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.0 (2020/04/04 22:23)

#include "DataMiningMainTesting.h" 
#include "CoreTools/Helper/AssertMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/Helper/BookDatabaseClassInvariantMacro.h"
#include "Example/BookOtherLanguages/BookDatabase/DataMiningPracticalMachineLearningToolsAndTechniques/DataMiningPracticalMachineLearningToolsAndTechniquesMain.h"

namespace BookDatabase
{
	using TestingType = DataMiningPracticalMachineLearningToolsAndTechniquesMain;
}

BookDatabase::DataMiningMainTesting
	::DataMiningMainTesting(const OStreamShared& stream)
	:ParentType{ stream }
{
	BOOK_DATABASE_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookDatabase, DataMiningMainTesting)

void BookDatabase::DataMiningMainTesting
	::DoRunUnitTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookDatabase::DataMiningMainTesting
	::MainTest() 
{
	TestingType dataMiningPracticalMachineLearningToolsAndTechniquesMain{ };

	ASSERT_TRUE(dataMiningPracticalMachineLearningToolsAndTechniquesMain.Main());
	ASSERT_TRUE(dataMiningPracticalMachineLearningToolsAndTechniquesMain.ExecuteChapter1());
}

