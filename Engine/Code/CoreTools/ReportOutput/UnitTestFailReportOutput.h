// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 17:54)

// ����Ϣ�����ָ����ostream��UnitTestFailReportOutputΪ�ⲿ�ӿ��ࡣʵ�������Ԫ���Դ��󱨸���Ϣ��
#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>
#include <iostream>

CORE_TOOLS_EXPORT_SHARED_PTR(UnitTestFailReportOutputImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class CORE_TOOLS_DEFAULT_DECLARE UnitTestFailReportOutput : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(UnitTestFailReportOutput);

	public:
		UnitTestFailReportOutput(const std::string& failClassName, const std::string& fileName, int lineNumber,
								 const std::string& errorMessage, std::ostream* osPtr = &std::cout);

		CLASS_INVARIANT_DECLARE;

		void PrintNewLine();
		void PrintFailClassInformation();
		void PrintFailFileName();
		void PrintFailLineNumber();
		void PrintErrorMessage();

	private:
		IMPL_TYPE_DECLARE(UnitTestFailReportOutput);
	};
}

#endif // CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H
