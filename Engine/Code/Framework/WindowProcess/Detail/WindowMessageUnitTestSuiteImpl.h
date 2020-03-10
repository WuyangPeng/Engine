// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 09:52)

#ifndef FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_IMPL_H
#define FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/Console/ConsoleAlloc.h"
#include "CoreTools/MainFunctionHelper/TestingInformationHelper.h"

#include <string>
#include <iosfwd>

namespace CoreTools
{
	class Suite;
	class UnitTestComposite;
}

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE WindowMessageUnitTestSuiteImpl
	{
	public:	
		using ClassType = WindowMessageUnitTestSuiteImpl;
		using Suite = CoreTools::Suite;
		using UnitTestPtr = std::shared_ptr<CoreTools::UnitTestComposite>;

	public:
		WindowMessageUnitTestSuiteImpl(const std::string& name, std::ostream* osPtr);		
	
 		CLASS_INVARIANT_DECLARE;	

		void AddSuite(const Suite& suite);
		void RunUnitTest();
		void PrintReport();
		void ResetTestData();
		int GetPassedNumber() const;

		void AddTest(const std::string& suiteName, Suite& suite,const std::string& testName, const UnitTestPtr& unitTest);

	private:
		using SuitePtr = std::shared_ptr<Suite>;

	private:
		SuitePtr m_SuitePtr;
		CoreTools::ConsoleAlloc m_Alloc;
		CoreTools::TestingInformationHelper m_TestingInformationHelper;
	};
}

#endif // FRAMEWORK_WINDOW_PROCESS_WINDOW_MESSAGE_UNIT_TEST_SUITE_IMPL_H
