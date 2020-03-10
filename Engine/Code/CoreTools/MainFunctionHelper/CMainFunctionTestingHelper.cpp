// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 11:59)

#include "CoreTools/CoreToolsExport.h"

#include "CMainFunctionTestingHelper.h"
#include "CoreTools/Helper/LogMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Exception/Error.h"
#include "CoreTools/UnitTestSuite/Suite.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

using std::string;

CoreTools::CMainFunctionTestingHelper
	::CMainFunctionTestingHelper(int argc, char* argv[])
	:ParentType{ argc, argv }, m_TestingInformationHelper{}
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CoreTools::CMainFunctionTestingHelper
	::~CMainFunctionTestingHelper()
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, CMainFunctionTestingHelper)

void CoreTools::CMainFunctionTestingHelper
	::AddTest(const string& suiteName, Suite& suite, const string& testName, const UnitTestPtr& unitTest)
{
	try
	{
		auto testLoopCount = m_TestingInformationHelper.GetLoopCount(suiteName, testName);

		if (0 < testLoopCount)
		{
			unitTest->SetTestLoopCount(testLoopCount);
			unitTest->SetRandomSeed(m_TestingInformationHelper.GetRandomSeed());
			suite.AddTest(unitTest);
		}
	}
	catch (Error& error)
	{
		LOG_SINGLETON_ENGINE_APPENDER(Warn, CoreTools)
			<< error
			<< LOG_SINGLETON_TRIGGER_ASSERT;
	}
}

bool CoreTools::CMainFunctionTestingHelper
	::IsPrintRun() const
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	return m_TestingInformationHelper.IsPrintRun();
}
