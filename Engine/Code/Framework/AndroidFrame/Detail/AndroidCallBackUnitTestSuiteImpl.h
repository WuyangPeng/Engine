// Copyright (c) 2010-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.3.0.1 (2020/05/21 16:39)

#ifndef FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_IMPL_H
#define FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_IMPL_H

#include "Framework/FrameworkDll.h"

#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include "CoreTools/MainFunctionHelper/TestingInformationHelper.h"

#include <string> 

namespace Framework
{
	class FRAMEWORK_HIDDEN_DECLARE AndroidCallBackUnitTestSuiteImpl
	{
	public:
		using ClassType = AndroidCallBackUnitTestSuiteImpl;
		using Suite = CoreTools::Suite;
		using OStreamShared = CoreTools::OStreamShared;
		using UnitTestSharedPtr = std::shared_ptr<CoreTools::UnitTestComposite>;

	public:
		AndroidCallBackUnitTestSuiteImpl(const std::string& name, const OStreamShared& streamShared);

		CLASS_INVARIANT_DECLARE;

		void AddSuite(const Suite& suite);
		void RunUnitTest();
		void PrintReport();
		void ResetTestData();
		int GetPassedNumber() const noexcept;

		void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestSharedPtr& unitTest);

		bool IsPrintRun() const noexcept;

	private:
		using SuiteSharedPtr = std::shared_ptr<Suite> ;

	private:
		CoreTools::TestingInformationHelper m_TestingInformationHelper;
		SuiteSharedPtr m_Suite;
	};
}

#endif // FRAMEWORK_ANDROID_FRAME_ANDROID_CALL_BACK_UNIT_TEST_SUITE_IMPL_H
