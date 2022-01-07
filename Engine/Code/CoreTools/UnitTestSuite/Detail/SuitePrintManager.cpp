///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/14 21:34)

#include "CoreTools/CoreToolsExport.h"

#include "SuiteImpl.h"
#include "SuitePrintManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestSuiteReportOutput.h"

using std::make_shared;
using std::string;
using namespace std::literals;

CoreTools::SuitePrintManager::SuitePrintManager(MasterType& suite, int borderLineLength)
    : suite{ suite }, unitTestSuiteReportOutput{ make_shared<UnitTestSuiteReportOutput>("测试"s, borderLineLength, suite.GetStream()) }
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
