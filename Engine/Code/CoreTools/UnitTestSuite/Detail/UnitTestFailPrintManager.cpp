//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 14:47)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestFailPrintManager.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/ReportOutput/UnitTestFailReportOutput.h"
#include "CoreTools/UnitTestSuite/UnitTest.h"

using std::make_shared;
using std::string;

CoreTools::UnitTestFailPrintManager::UnitTestFailPrintManager(UnitTest& unitTest, const string& fileName, int lineNumber, const string& errorMessage)
    : m_ReportOutputPtr{ make_shared<UnitTestFailReportOutput>(typeid(unitTest).name(), fileName, lineNumber, errorMessage, unitTest.GetStream()) }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
bool CoreTools::UnitTestFailPrintManager::IsValid() const noexcept
{
    if (m_ReportOutputPtr != nullptr)
        return true;
    else
        return false;
}
#endif  // OPEN_CLASS_INVARIANT

void CoreTools::UnitTestFailPrintManager::PrintFailClassInformation()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_ReportOutputPtr->PrintNewLine();
    m_ReportOutputPtr->PrintFailClassInformation();
    m_ReportOutputPtr->PrintNewLine();
}

void CoreTools::UnitTestFailPrintManager::PrintFailFileName()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_ReportOutputPtr->PrintFailFileName();
    m_ReportOutputPtr->PrintNewLine();
}

void CoreTools::UnitTestFailPrintManager::PrintFailLineNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_ReportOutputPtr->PrintFailLineNumber();
    m_ReportOutputPtr->PrintNewLine();
}

void CoreTools::UnitTestFailPrintManager::PrintErrorMessage()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    m_ReportOutputPtr->PrintErrorMessage();
    m_ReportOutputPtr->PrintNewLine();
    m_ReportOutputPtr->PrintNewLine();
}
