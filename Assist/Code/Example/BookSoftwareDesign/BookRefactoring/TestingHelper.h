// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ���渨���汾��0.0.0.2 (2019/09/29 09:49)

#ifndef BOOK_REFACTORING_TESTING_HELPER_H
#define BOOK_REFACTORING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BookRefactoring
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites(); 	

		void AddRefactoringImprovingTheDesignofExistingCodeSuite();

		void AddRefactoringToPatternsSuite();

		void AddRefactoringWorkbookSuite();
	
	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_REFACTORING_TESTING_HELPER_H