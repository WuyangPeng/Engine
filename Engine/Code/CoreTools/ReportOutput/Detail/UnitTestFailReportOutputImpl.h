// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 17:54)

// 将信息输出至指定的ostream。UnitTestFailReportOutputImpl为内部接口子类。实现输出单元测试错误报告信息。

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