// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.1 (2020/01/21 17:54)

// ����Ϣ�����ָ����ostream��EquilongReportOutputΪ�ⲿ�ӿ��ࡣʵ������ַ������߽��ߺͻ��еĹ��ܡ�
#ifndef CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"

#include <boost/noncopyable.hpp>
#include <string>
#include <iostream>

CORE_TOOLS_EXPORT_SHARED_PTR(EquilongReportOutputImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
	class OStreamShared;

	class CORE_TOOLS_DEFAULT_DECLARE EquilongReportOutput : private boost::noncopyable
	{
	public:
		NON_COPY_CLASSES_TYPE_DECLARE(EquilongReportOutput);

	public:
		explicit EquilongReportOutput(int borderLineLength, const OStreamShared& osPtr );

		CLASS_INVARIANT_DECLARE;

		void PrintNewLine();
		void PrintBorderLine(char character);
		void PrintString(const std::string& characterString);

	private:
		IMPL_TYPE_DECLARE(EquilongReportOutput);
	};
}

#endif // CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_H
