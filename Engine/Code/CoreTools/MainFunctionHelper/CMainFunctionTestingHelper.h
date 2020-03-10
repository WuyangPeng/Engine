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

	public:
		CMainFunctionTestingHelper(int argc, char* argv[]);
		virtual ~CMainFunctionTestingHelper();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

	protected:
		void AddTest(const std::string& suiteName, Suite& suite, const std::string& testName, const UnitTestPtr& unitTest);

		bool IsPrintRun() const;

	private:
		TestingInformationHelper m_TestingInformationHelper;
	};
}

#endif // CORE_TOOLS_MAIN_FUNCTION_HELPER_C_MAIN_FUNCTION_TESTING_HELPER_H