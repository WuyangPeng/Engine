///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/14 21:36)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestFailPrintManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestFailReportOutput.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

using std::make_shared;
using std::string;

CoreTools::UnitTestFailPrintManager::UnitTestFailPrintManager(UnitTest& unitTest, const string& fileName, int lineNumber, const string& errorMessage)
    : reportOutput{ make_shared<UnitTestFailReportOutput>(typeid(unitTest).name(), fileName, lineNumber, errorMessage, unitTest.GetStream()) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT

bool CoreTools::UnitTestFailPrintManager::IsValid() const noexcept
{
    if (reportOutput != nullptr)
        return true;
    else
        return false;
}

#endif  // OPEN_CLASS_INVARIANT

void CoreTools::UnitTestFailPrintManager::PrintFailClassInformation()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    reportOutput->PrintNewLine();
    reportOutput->PrintFailClassInformation();
    reportOutput->PrintNewLine();
}

void CoreTools::UnitTestFailPrintManager::PrintFailFileName()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    reportOutput->PrintFailFileName();
    reportOutput->PrintNewLine();
}

void CoreTools::UnitTestFailPrintManager::PrintFailLineNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    reportOutput->PrintFailLineNumber();
    reportOutput->PrintNewLine();
}

void CoreTools::UnitTestFailPrintManager::PrintErrorMessage()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    reportOutput->PrintErrorMessage();
    reportOutput->PrintNewLine();
    reportOutput->PrintNewLine();
}
