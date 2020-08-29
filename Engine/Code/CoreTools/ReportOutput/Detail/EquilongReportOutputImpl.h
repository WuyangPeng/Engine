// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 17:52)

// 将信息输出至指定的ostream。EquilongReportOutputImpl为内部接口子类。实现输出边界线的功能。

#ifndef CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_IMPL_H
#define CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_IMPL_H

#include "ReportOutput.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE EquilongReportOutputImpl : public ReportOutput
	{
	public:
		using ClassType = EquilongReportOutputImpl;
		using ParentType = ReportOutput;

	public:
		explicit EquilongReportOutputImpl(int borderLineLength, const OStreamShared& osPtr ) noexcept;
 

		CLASS_INVARIANT_OVERRIDE_DECLARE;

		void PrintBorderLine(char character);

	protected:
		int GetBorderLineLength() const noexcept;

	private:
		int m_BorderLineLength;
	};
}

#endif // CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_IMPL_H