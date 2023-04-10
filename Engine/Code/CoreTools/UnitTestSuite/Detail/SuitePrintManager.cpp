///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/04/03 17:42)

#include "CoreTools/CoreToolsExport.h"

#include "SuiteImpl.h"
#include "SuitePrintManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestSuiteReportOutput.h"

using namespace std::literals;

CoreTools::SuitePrintManager::SuitePrintManager(MasterType& suite, int borderLineLength)
    : suite{ suite }, unitTestSuiteReportOutput{ make_shared<UnitTestSuiteReportOutput>("����"s, borderLineLength, suite.GetStream()) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, SuitePrintManager)

void CoreTools::SuitePrintManager::PrintCoreToolsHeader()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    unitTestSuiteReportOutput->PrintBorderLine('=');
    unitTestSuiteReportOutput->PrintNewLine();
}

void CoreTools::SuitePrintManager::PrintSuiteName()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    unitTestSuiteReportOutput->PrintNewLine();
    unitTestSuiteReportOutput->PrintSuiteName(suite.GetName());
    unitTestSuiteReportOutput->PrintNewLine();
}

void CoreTools::SuitePrintManager::PrintSuiteResult()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    unitTestSuiteReportOutput->PrintTestResult(suite.GetPassedNumber(), suite.GetFailedNumber(), suite.GetErrorNumber(), characterWidth);
    unitTestSuiteReportOutput->PrintNewLine();
    unitTestSuiteReportOutput->PrintNewLine();
    unitTestSuiteReportOutput->PrintBorderLine('=');
    unitTestSuiteReportOutput->PrintNewLine();
}

void CoreTools::SuitePrintManager::PrintCurrentTime()
{
    CORE_TOOLS_CLASS_IS_VALID_9;

    unitTestSuiteReportOutput->PrintCurrentTime();
    unitTestSuiteReportOutput->PrintNewLine();
    unitTestSuiteReportOutput->PrintBorderLine('=');
    unitTestSuiteReportOutput->PrintNewLine();
}
