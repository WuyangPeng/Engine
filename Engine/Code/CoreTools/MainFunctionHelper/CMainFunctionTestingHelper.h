// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:53)

#ifndef CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_H
#define CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include "CMainFunctionHelper.h"
#include "TestingInformationHelper.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include "CoreTools/UnitTestSuite/Suite.h"

namespace CoreTools
{
	class Suite;
	class UnitTestComposite;

	class CORE_TOOLS_DEFAULT_DECLARE CMainFunctionTestingHelper : public CMainFunctionHelper
	{
	public:
		using ClassType = CMainFunctionTestingHelper;
		using ParentType = CMainFunctionHelper;
		using UnitTestPtr = std::shared_ptr<UnitTestComposite>;		
		using Suite = CoreTools::Suite;

	public:
		CMainFunctionTestingHelper(int argc, char* argv[]);
		CMainFunctionTestingHelper(int argc, char* argv[],const std::string& suiteName);
		~CMainFunctionTestingHelper() = 0; 

		CMainFunctionTestingHelper(const CMainFunctionTestingHelper& rhs) = delete;
		CMainFunctionTestingHelper& operator=(const CMainFunctionTestingHelper& rhs) = delete;
		CMainFunctionTestingHelper(CMainFunctionTestingHelper&& rhs) noexcept = delete;
		CMainFunctionTestingHelper& operator=(CMainFunctionTestingHelper&& rhs) noexcept = delete;

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	protected:
		using SuiteSharedPtr = std::shared_ptr<Suite>;

	protected:
		void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestPtr& unitTest);

		bool IsPrintRun() const;

		int RunSuite();

		void AddSuite(const Suite& suite);

		template<typename TestType, typename... Types>
		void AddTest(Suite& suite, const std::string& suiteName, const std::string& testName, Types&&... args)
		{
			auto unitTest = std::make_shared<TestType>(GetStreamShared(), std::forward<Types>(args)...);

			AddTest(suiteName, suite, testName, unitTest);
		} 

		Suite GenerateSuite(const std::string& name); 

	private:
		int DoRun() override;

	private:
		TestingInformationHelper m_TestingInformationHelper;
		Suite m_Suite;
	};
}

#endif // CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_H