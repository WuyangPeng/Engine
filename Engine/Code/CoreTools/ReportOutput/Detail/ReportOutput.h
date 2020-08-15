// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.1 (2020/01/21 17:53)

// 将信息输出至指定的ostream。ReportOutput为内部接口基类。实现输出字符串和换行的功能。
#ifndef CORE_TOOLS_REPORT_OUTPUT_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include <boost/noncopyable.hpp>
#include <string>
#include <iostream>
#include "CoreTools/UnitTestSuite/OStreamShared.h"

namespace CoreTools
{
	class CORE_TOOLS_HIDDEN_DECLARE ReportOutput : private boost::noncopyable
	{
	public:
		using ClassType = ReportOutput;

	public:
		explicit ReportOutput(const OStreamShared& osPtr) noexcept;
		virtual ~ReportOutput();
		ReportOutput(const ReportOutput&) = delete;
		ReportOutput& operator=(const ReportOutput&) = delete;
		ReportOutput(ReportOutput&&) noexcept = delete;
		ReportOutput& operator=(ReportOutput&&) noexcept = delete;

		CLASS_INVARIANT_VIRTUAL_DECLARE;

		void PrintString(const std::string& characterString);
		void PrintNewLine();
		void PrintNumber(int number);

	protected:
		OStreamShared GetStream() noexcept;

	private:
		OStreamShared m_OsPtr;   
	};
}

#endif // CORE_TOOLS_REPORT_OUTPUT_REPORT_OUTPUT_H