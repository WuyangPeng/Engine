/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 11:10)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestFailReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

CoreTools::UnitTestFailReportOutputImpl::UnitTestFailReportOutputImpl(std::string failClassName, std::string fileName, int lineNumber, std::string errorMessage, const OStreamShared& streamShared, LogLevel logLevel) noexcept
    : ParentType{ streamShared }, failClassName{ std::move(failClassName) }, fileName{ std::move(fileName) }, lineNumber{ lineNumber }, errorMessage{ std::move(errorMessage) }, logLevel{ logLevel }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestFailReportOutputImpl)

void CoreTools::UnitTestFailReportOutputImpl::PrintFailClassInformation() const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto failClassInformation = failClassName + " 测试失败：";
    PrintString(failClassInformation, logLevel);
}

void CoreTools::UnitTestFailReportOutputImpl::PrintFailFileName() const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto failFileName = "文件 " + fileName;
    PrintString(failFileName, logLevel);
}

void CoreTools::UnitTestFailReportOutputImpl::PrintFailLineNumber() const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    PrintString(" 第", logLevel);
    PrintNumber(lineNumber, logLevel);
    PrintString("行", logLevel);
}

void CoreTools::UnitTestFailReportOutputImpl::PrintErrorMessage() const
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    PrintString(errorMessage, logLevel);
}
