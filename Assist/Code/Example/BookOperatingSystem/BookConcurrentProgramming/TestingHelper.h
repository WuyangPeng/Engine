// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.0.2 (2019/09/27 21:41)

#ifndef BOOK_CONCURRENT_PROGRAMMING_TESTING_HELPER_H
#define BOOK_CONCURRENT_PROGRAMMING_TESTING_HELPER_H

#include "CoreTools/MainFunctionHelper/CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
	class Suite;
}

namespace BookConcurrentProgramming
{
	class TestingHelper : public CoreTools::CMainFunctionTestingHelper
	{
	public:
		CMAIN_FUNCTION_TESTING_HELPER_SUBCLASS_COMPLETE_DECLARE(TestingHelper); 

	private:
        virtual int DoRun() override;

		void AddSuites();   
		 
		void AddConcurrentProgrammingOnWindowsSuite();

		void AddParallelAndDistributedProgrammingUsingCppSuite();

		void AddCppConcurrencyInActionSuite();

		void AddMultithreadingApplicationsInWin32Suite();

		void AddProfessionalMulticoreProgrammingSuite();

		void AddObjectOrientedMultithreadingUsingCppSuite();

	private:
		CMAIN_FUNCTION_HELPER_SUBCLASS_SUITE_PTR_DECLARE;
	};
}

#endif // BOOK_CONCURRENT_PROGRAMMING_TESTING_HELPER_H