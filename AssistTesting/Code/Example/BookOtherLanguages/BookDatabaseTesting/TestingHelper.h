// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙≤‚ ‘∞Ê±æ£∫0.1.0.0 (2020/04/04 20:34)

#ifndef BOOK_DATABASE_TESTING_HELPER_H
#define BOOK_DATABASE_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"

namespace BookDatabase
{
	class TestingHelper final : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		using ClassType = TestingHelper; 
		using ParentType = CMainFunctionTestingHelper;
		
	public:	
		TestingHelper(int argc, char** argv);

		CLASS_INVARIANT_FINAL_DECLARE;

	private: 
		void InitSuite(); 		

		void AddAFirstCourseInDatabaseSystemsSuite();
		void AddDatabaseSystemConceptsSuite();
		void AddDatabaseSystemImplementationSuite();
		void AddRefactoringDatabasesEvolutionaryDatabaseDesignSuite();
	
		void AddDatabaseDesignRelationalTheorySuite();
		void AddSevenDatabasesInSevenWeeksSuite();
		void AddDatabaseSystemsTheCompletsBookSuite();
		void AddDataMiningConceptsAndTechniquesSuite();

		void AddDataMiningPracticalMachineLearningToolsAndTechniquesSuite();
		void AddTransactionProcessingConceptsAndTechniquesSuite();
		void AddMiningTheSocialWebSuite(); 
	};
}

#endif // BOOK_DATABASE_TESTING_HELPER_H