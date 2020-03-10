// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 17:54)

// ����Ϣ�����ָ����ostream��UnitTestSuiteReportOutputImplΪ�ڲ��ӿ����ࡣʵ�������Ԫ�������������׼����Ͳ��Խ��

#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_IMPL_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "TimeReportOutput.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE UnitTestSuiteReportOutputImpl : public TimeReportOutput
	{
	public:
		using ClassType = UnitTestSuiteReportOutputImpl;
		using ParentType = TimeReportOutput;

	public:
		UnitTestSuiteReportOutputImpl(const std::string& timeDescribe, int borderLineLength, std::ostream* osPtr = &std::cout);
		virtual ~UnitTestSuiteReportOutputImpl();

		CLASS_INVARIANT_VIRTUAL_OVERRIDE_DECLARE;

		void PrintTestName(const std::string& testName);
		void PrintSuiteName(const std::string& suiteName);
		void PrintTestResult(int passedNumber, int failedNumber, int errorNumber, int characterWidth);
	};
}

#endif // CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_IMPL_H