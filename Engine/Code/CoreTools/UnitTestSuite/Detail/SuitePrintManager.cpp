// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.2 (2020/01/22 10:20)

#include "CoreTools/CoreToolsExport.h"

#include "SuitePrintManager.h"
#include "SuiteImpl.h"
#include "CoreTools/ReportOutput/UnitTestSuiteReportOutput.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::make_shared;

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
const string CoreTools::SuitePrintManager
	::sm_TimeDescribe{ "≤‚ ‘" };
#include STSTEM_WARNING_POP
CoreTools::SuitePrintManager
	::SuitePrintManager(MasterType& suite, int borderLineLength)
	:m_Suite{ suite },
	 m_UnitTestSuiteReportOutputPtr{ make_shared<UnitTestSuiteReportOutput>(sm_TimeDescribe, borderLineLength, m_Suite.GetStream()) }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SuitePrintManager)

void CoreTools::SuitePrintManager
	::PrintCoreToolsHeader()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_UnitTestSuiteReportOutputPtr->PrintBorderLine('=');
	m_UnitTestSuiteReportOutputPtr->PrintNewLine();
}

void CoreTools::SuitePrintManager
	::PrintSuiteName()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_UnitTestSuiteReportOutputPtr->PrintNewLine();
	m_UnitTestSuiteReportOutputPtr->PrintSuiteName(m_Suite.GetName());
	m_UnitTestSuiteReportOutputPtr->PrintNewLine();
}

void CoreTools::SuitePrintManager
	::PrintSuiteResult()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_UnitTestSuiteReportOutputPtr->PrintTestResult(m_Suite.GetPassedNumber(), m_Suite.GetFailedNumber(), m_Suite.GetErrorNumber(), sm_CharacterWidth);
	m_UnitTestSuiteReportOutputPtr->PrintNewLine();
	m_UnitTestSuiteReportOutputPtr->PrintNewLine();
	m_UnitTestSuiteReportOutputPtr->PrintBorderLine('=');
	m_UnitTestSuiteReportOutputPtr->PrintNewLine();
}

void CoreTools::SuitePrintManager
	::PrintCurrentTime()
{
	CORE_TOOLS_CLASS_IS_VALID_9;

	m_UnitTestSuiteReportOutputPtr->PrintCurrentTime();
	m_UnitTestSuiteReportOutputPtr->PrintNewLine();
	m_UnitTestSuiteReportOutputPtr->PrintBorderLine('=');
	m_UnitTestSuiteReportOutputPtr->PrintNewLine();
}
