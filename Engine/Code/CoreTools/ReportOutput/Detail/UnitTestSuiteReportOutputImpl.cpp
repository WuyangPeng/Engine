// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.1 (2020/01/21 17:57)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestSuiteReportOutputImpl.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/LogManager/LogConsoleTextColorsManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

#include <iomanip>

using std::setw;
using std::right;
using std::left;
using std::string;
using std::ostream;
using std::make_shared;

CoreTools::UnitTestSuiteReportOutputImpl
	::UnitTestSuiteReportOutputImpl(const string& timeDescribe, int borderLineLength, const OStreamShared& osPtr)
	:ParentType{ timeDescribe,borderLineLength,osPtr }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

 
CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestSuiteReportOutputImpl)

void CoreTools::UnitTestSuiteReportOutputImpl
	::PrintTestName(const string& testName)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto characterString = "≤‚ ‘ \"" + testName + "\"£∫";
	PrintString(characterString);
}

void CoreTools::UnitTestSuiteReportOutputImpl
	::PrintSuiteName(const string& suiteName)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto characterString = "≤‚ ‘Ã◊º˛ \"" + suiteName + "\"£∫";
	PrintString(characterString);
}

void CoreTools::UnitTestSuiteReportOutputImpl
	::PrintTestResult(int passedNumber, int failedNumber, int errorNumber, int characterWidth)
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	auto manager = GetLogConsoleTextColorsManager(failedNumber, errorNumber);

	GetStream() << setw(characterWidth) << right << "Õ®π˝£∫"
				 << setw(characterWidth) << left << passedNumber
				 << setw(characterWidth) << right << " ß∞‹: "
				 << setw(characterWidth) << left << failedNumber
				 << setw(characterWidth) << right << "¥ÌŒÛ: "
				 << setw(characterWidth) << left << errorNumber;
}

CoreTools::UnitTestSuiteReportOutputImpl::LogConsoleTextColorsManagerPtr CoreTools::UnitTestSuiteReportOutputImpl
	::GetLogConsoleTextColorsManager(int failedNumber, int errorNumber)
{
	if (0 < errorNumber)
		return make_shared<LogConsoleTextColorsManager>(GetStream(), LogLevel::Fatal);
	else if (0 < failedNumber)
		return make_shared<LogConsoleTextColorsManager>(GetStream(), LogLevel::Error);
	else
		return nullptr;
}

