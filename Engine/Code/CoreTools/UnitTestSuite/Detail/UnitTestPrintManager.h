// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 10:13)

// ��Ԫ������������Խ�������࣬UnitTestPrintManageΪ�ڲ��ӿ��࣬��������Խ����

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_PRINT_MANAGER_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_PRINT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ReportOutput/ReportOutputFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <boost/noncopyable.hpp>
#include <memory>
#include <string>

namespace boost
{
	namespace timer
	{
		class cpu_timer;
	}
}

namespace CoreTools
{ 
	class CORE_TOOLS_HIDDEN_DECLARE UnitTestPrintManager : private boost::noncopyable
	{
	public:
		using ClassType = UnitTestPrintManager;
		using MasterType = UnitTest;
		using CpuTimer = boost::timer::cpu_timer;
		using CpuTimerPtr = std::shared_ptr<CpuTimer>;

	public:
		UnitTestPrintManager(MasterType& unitTest, const std::string& timeDescribe, int borderLineLength = 75);

		CLASS_INVARIANT_DECLARE;

		void PrintTestName();
		void PrintTestResult(int characterWidth);
		void PrintCostTime(CpuTimerPtr timePtr);

	private:
		using UnitTestSuiteReportOutputPtr = std::shared_ptr<UnitTestSuiteReportOutput>;

	private:
		MasterType& m_UnitTest;
		UnitTestSuiteReportOutputPtr m_ReportOutputPtr;
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_PRINT_MANAGER_H
