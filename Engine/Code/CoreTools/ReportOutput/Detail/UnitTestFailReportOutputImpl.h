// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 17:54)

// ����Ϣ�����ָ����ostream��UnitTestFailReportOutputImplΪ�ڲ��ӿ����ࡣʵ�������Ԫ���Դ��󱨸���Ϣ��

#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_IMPL_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "ReportOutput.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE UnitTestFailReportOutputImpl : public ReportOutput
	{
	public:
		using ClassType = UnitTestFailReportOutputImpl;
		using ParentType = ReportOutput;

	public:
		UnitTestFailReportOutputImpl(const std::string& failClassName, const std::string& fileName, int lineNumber,
									 const std::string& errorMessage, std::ostream* osPtr = &std::cout);
		virtual ~UnitTestFailReportOutputImpl();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		void PrintFailClassInformation();
		void PrintFailFileName();
		void PrintFailLineNumber();
		void PrintErrorMessage();

	private:
		std::string m_FailClassName;
		std::string m_FileName;
		int m_LineNumber;
		std::string m_ErrorMessage;
	};
}

#endif // CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_IMPL_H