/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:18)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestFailReportOutput.h"
#include "Detail/UnitTestFailReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"

CoreTools::UnitTestFailReportOutput::UnitTestFailReportOutput(const std::string& failClassName, const std::string& fileName, int lineNumber, const std::string& errorMessage, const OStreamShared& streamShared, LogLevel logLevel)
    : impl{ failClassName, fileName, lineNumber, errorMessage, streamShared, logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_STUB_DEFINE(CoreTools, UnitTestFailReportOutput)

void CoreTools::UnitTestFailReportOutput::PrintNewLine()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintNewLine();
}

void CoreTools::UnitTestFailReportOutput::PrintFailClassInformation()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintFailClassInformation();
}

void CoreTools::UnitTestFailReportOutput::PrintFailFileName()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintFailFileName();
}

void CoreTools::UnitTestFailReportOutput::PrintFailLineNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintFailLineNumber();
}

void CoreTools::UnitTestFailReportOutput::PrintErrorMessage()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    return impl->PrintErrorMessage();
}
