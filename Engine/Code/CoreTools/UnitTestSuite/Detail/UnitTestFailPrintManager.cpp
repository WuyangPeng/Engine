///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/30 09:40)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestFailPrintManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestFailReportOutput.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

CoreTools::UnitTestFailPrintManager::UnitTestFailPrintManager(UnitTest& unitTest, const std::string& fileName, int lineNumber, const std::string& errorMessage, LogLevel logLevel)
    : reportOutput{ make_shared<UnitTestFailReportOutput>(typeid(unitTest).name(), fileName, lineNumber, errorMessage, unitTest.GetStream(), logLevel) }
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
