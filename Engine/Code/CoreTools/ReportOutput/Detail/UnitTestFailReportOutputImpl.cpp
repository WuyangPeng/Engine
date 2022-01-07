///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 18:20)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestFailReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/OStreamSharedDetail.h"

using std::string;
using namespace std::literals;

CoreTools::UnitTestFailReportOutputImpl::UnitTestFailReportOutputImpl(const string& failClassName, const string& fileName, int lineNumber, const string& errorMessage, const OStreamShared& streamShared)
    : ParentType{ streamShared }, failClassName{ failClassName }, fileName{ fileName }, lineNumber{ lineNumber }, errorMessage{ errorMessage }
{
    CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestFailReportOutputImpl)

void CoreTools::UnitTestFailReportOutputImpl::PrintFailClassInformation()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto failClassInformation = failClassName + " ����ʧ�ܣ�"s;
    PrintString(failClassInformation);
}

void CoreTools::UnitTestFailReportOutputImpl::PrintFailFileName()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    const auto failFileName = "�ļ� "s + fileName;
    PrintString(failFileName);
}

void CoreTools::UnitTestFailReportOutputImpl::PrintFailLineNumber()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    PrintString(" ��"s);
    PrintNumber(lineNumber);
    PrintString("��"s);
}

void CoreTools::UnitTestFailReportOutputImpl::PrintErrorMessage()
{
    CORE_TOOLS_CLASS_IS_VALID_1;

    PrintString(errorMessage);
}
