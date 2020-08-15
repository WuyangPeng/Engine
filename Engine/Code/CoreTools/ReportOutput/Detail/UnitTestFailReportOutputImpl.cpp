// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 17:57)

#include "CoreTools/CoreToolsExport.h"

#include "UnitTestFailReportOutputImpl.h"
#include "CoreTools/Helper/ClassInvariant/CoreToolsClassInvariantMacro.h"

using std::string;
using std::ostream;

CoreTools::UnitTestFailReportOutputImpl
	::UnitTestFailReportOutputImpl(const string& failClassName, const string& fileName, int lineNumber, const string& errorMessage, const OStreamShared& osPtr)
	:ParentType{ osPtr }, m_FailClassName{ failClassName }, m_FileName{ fileName }, m_LineNumber{ lineNumber }, m_ErrorMessage{ errorMessage }
{
	CORE_TOOLS_SELF_CLASS_IS_VALID_1;
}
 

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(CoreTools, UnitTestFailReportOutputImpl)

void CoreTools::UnitTestFailReportOutputImpl
	::PrintFailClassInformation()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	string failClassInformation{ m_FailClassName + " ����ʧ�ܣ�" };
	PrintString(failClassInformation);
}

void CoreTools::UnitTestFailReportOutputImpl
	::PrintFailFileName()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	string failFileName{ "�ļ� " + m_FileName };
	PrintString(failFileName);
}

void CoreTools::UnitTestFailReportOutputImpl
	::PrintFailLineNumber()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	PrintString(" ��");
	PrintNumber(m_LineNumber);
	PrintString("��");
}

void CoreTools::UnitTestFailReportOutputImpl
	::PrintErrorMessage()
{
	CORE_TOOLS_CLASS_IS_VALID_1;

	PrintString(m_ErrorMessage);
}
