//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 14:46)

#include "CoreTools/CoreToolsExport.h"

#include "SuiteImpl.h"
#include "SuitePrintManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestSuiteReportOutput.h"

using std::make_shared;
using std::string;
using namespace std::literals;

CoreTools::SuitePrintManager::SuitePrintManager(MasterType& suite, int borderLineLength)
    : m_Suite{ suite }, m_UnitTestSuiteReportOutputPtr{ make_shared<UnitTestSuiteReportOutput>("测试"s, borderLineLength, m_Suite.GetStream()) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SuitePrintManager)

void CoreTools::SuitePrintManager::PrintCoreToolsHeader()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_UnitTestSuiteReportOutputPtr->PrintBorderLine('=');
    m_UnitTestSuiteReportOutputPtr->PrintNewLine();
}

void CoreTools::SuitePrintManager::PrintSuiteName()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_UnitTestSuiteReportOutputPtr->PrintNewLine();
    m_UnitTestSuiteReportOutputPtr->PrintSuiteName(m_Suite.GetName());
    m_UnitTestSuiteReportOutputPtr->PrintNewLine();
}

void CoreTools::SuitePrintManager::PrintSuiteResult()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_UnitTestSuiteReportOutputPtr->PrintTestResult(m_Suite.GetPassedNumber(), m_Suite.GetFailedNumber(), m_Suite.GetErrorNumber(), sm_CharacterWidth);
    m_UnitTestSuiteReportOutputPtr->PrintNewLine();
    m_UnitTestSuiteReportOutputPtr->PrintNewLine();
    m_UnitTestSuiteReportOutputPtr->PrintBorderLine('=');
    m_UnitTestSuiteReportOutputPtr->PrintNewLine();
}

void CoreTools::SuitePrintManager::PrintCurrentTime()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    m_UnitTestSuiteReportOutputPtr->PrintCurrentTime();
    m_UnitTestSuiteReportOutputPtr->PrintNewLine();
    m_UnitTestSuiteReportOutputPtr->PrintBorderLine('=');
    m_UnitTestSuiteReportOutputPtr->PrintNewLine();
}
