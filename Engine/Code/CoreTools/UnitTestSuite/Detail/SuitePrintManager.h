// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.2 (2020/01/22 10:12)

// 单元测试套件类输出信息管理类，SuitePrintManage为内部接口类，可输出信息头、名称、测试结果和当前时间。
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_PRINT_MANAGER_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_PRINT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ReportOutput/ReportOutputFwd.h"

#include <boost/noncopyable.hpp>
#include <memory>
#include <string>

namespace CoreTools
{
	class SuiteImpl; 

	class CORE_TOOLS_HIDDEN_DECLARE SuitePrintManager : private boost::noncopyable
	{
	public:
		using ClassType = SuitePrintManager;
		using MasterType = SuiteImpl;

	public:
		explicit SuitePrintManager(MasterType& suite, int borderLineLength = 75);

		CLASS_INVARIANT_DECLARE;

		void PrintCoreToolsHeader();
		void PrintSuiteName();
		void PrintSuiteResult();
		void PrintCurrentTime();

	private:
		using UnitTestSuiteReportOutputPtr = std::shared_ptr<UnitTestSuiteReportOutput>;

	private:
		static constexpr auto sm_CharacterWidth = 8;
		static const std::string sm_TimeDescribe;

		MasterType& m_Suite;
		UnitTestSuiteReportOutputPtr m_UnitTestSuiteReportOutputPtr;
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_PRINT_MANAGER_H
