/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 10:18)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestFailReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

using namespace std::literals;

CoreTools::UnitTestFailReportOutputImpl::UnitTestFailReportOutputImpl(std::string failClassName, std::string fileName, int lineNumber, std::string errorMessage, const OStreamShared& streamShared, LogLevel logLevel) noexcept
    : ParentType{ streamShared }, failClassName{ std::move(failClassName) }, fileName{ std::move(fileName) }, lineNumber{ lineNumber }, errorMessage{ std::move(errorMessage) }, logLevel{ logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestFailReportOutputImpl)

void CoreTools::UnitTestFailReportOutputImpl::PrintFailClassInformation()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto failClassInformation = failClassName + " ����ʧ�ܣ�"s;
    PrintString(failClassInformation, logLevel);
}

void CoreTools::UnitTestFailReportOutputImpl::PrintFailFileName()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto failFileName = "�ļ� "s + fileName;
    PrintString(failFileName, logLevel);
}

void CoreTools::UnitTestFailReportOutputImpl::PrintFailLineNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    PrintString(" ��"s, logLevel);
    PrintNumber(lineNumber, logLevel);
    PrintString("��"s, logLevel);
}

void CoreTools::UnitTestFailReportOutputImpl::PrintErrorMessage()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    PrintString(errorMessage, logLevel);
}
