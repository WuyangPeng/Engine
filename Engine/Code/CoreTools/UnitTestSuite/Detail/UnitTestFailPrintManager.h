// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.2 (2020/01/22 10:13)

// ��Ԫ���������������Ϣ�����࣬UnitTestFailPrintManageΪ�ڲ��ӿ��࣬��������Դ�����Ϣ��
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ReportOutput/ReportOutputFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <boost/noncopyable.hpp>
#include <string>
#include <memory>

namespace CoreTools
{ 
	class CORE_TOOLS_HIDDEN_DECLARE UnitTestFailPrintManager : private boost::noncopyable
	{
	public:
		using ClassType = UnitTestFailPrintManager;

	public:
		UnitTestFailPrintManager(UnitTest& unitTest, const std::string& fileName, int lineNumber, const std::string& errorMessage);

		CLASS_INVARIANT_DECLARE;

		void PrintFailClassInformation();
		void PrintFailFileName();
		void PrintFailLineNumber();
		void PrintErrorMessage();

	private:
		using UnitTestFailReportOutputPtr = std::shared_ptr<UnitTestFailReportOutput>;

	private:
		UnitTestFailReportOutputPtr m_ReportOutputPtr;
	};
}

#endif // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H
