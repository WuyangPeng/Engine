// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.4 (2019/08/01 13:22)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_IMPL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_IMPL_H

#include "Framework/FrameworkDll.h"

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
	class FRAMEWORK_HIDDEN_DECLARE AndroidCallBackUnitTestSuiteImpl
	{
	public:	
		typedef AndroidCallBackUnitTestSuiteImpl ClassType;
		typedef CoreTools::Suite Suite;
		typedef std::shared_ptr<CoreTools::UnitTestComposite> UnitTestPtr;

	public:
		AndroidCallBackUnitTestSuiteImpl(const std::string& name,
			                             std::ostream* osPtr);		
	
		CLASS_INVARIANT_DECLARE;	

		void AddSuite(const Suite& suite);
		void RunUnitTest();
		void PrintReport();
		void ResetTestData();
		int GetPassedNumber() const;

		void AddTest(const std::string& suiteName,Suite& suite, 
			         const std::string& testName,const UnitTestPtr& unitTest);

	private:
		typedef std::shared_ptr<Suite> SuitePtr;

	private:
		SuitePtr m_SuitePtr;
		CoreTools::TestingInformationHelper m_TestingInformationHelper;
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_IMPL_H
