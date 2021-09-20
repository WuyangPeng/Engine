//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 10:15)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestFailReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

using std::string;
using namespace std::literals;

CoreTools::UnitTestFailReportOutputImpl::UnitTestFailReportOutputImpl(const string& failClassName, const string& fileName, int lineNumber, const string& errorMessage, const OStreamShared& streamShared)
    : ParentType{ streamShared }, m_FailClassName{ failClassName }, m_FileName{ fileName }, m_LineNumber{ lineNumber }, m_ErrorMessage{ errorMessage }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestFailReportOutputImpl)

void CoreTools::UnitTestFailReportOutputImpl::PrintFailClassInformation()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto failClassInformation = m_FailClassName + " 测试失败："s;
    PrintString(failClassInformation);
}

void CoreTools::UnitTestFailReportOutputImpl::PrintFailFileName()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    auto failFileName = "文件 "s + m_FileName;
    PrintString(failFileName);
}

void CoreTools::UnitTestFailReportOutputImpl::PrintFailLineNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    PrintString(" 第"s);
    PrintNumber(m_LineNumber);
    PrintString("行"s);
}

void CoreTools::UnitTestFailReportOutputImpl::PrintErrorMessage()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    PrintString(m_ErrorMessage);
}
