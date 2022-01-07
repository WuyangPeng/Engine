///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/14 18:55)

// ��Ԫ���������������Ϣ�����࣬UnitTestFailPrintManageΪ�ڲ��ӿ��࣬��������Դ�����Ϣ��
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ReportOutput/ReportOutputFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteInternalFwd.h"

#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UnitTestFailPrintManager final
    {
    public:
        using ClassType = UnitTestFailPrintManager;

    public:
        UnitTestFailPrintManager(UnitTest& unitTest, const std::string& fileName, int lineNumber, const std::string& errorMessage);
        ~UnitTestFailPrintManager() noexcept = default;
        UnitTestFailPrintManager(const UnitTestFailPrintManager& rhs) = delete;
        UnitTestFailPrintManager& operator=(const UnitTestFailPrintManager& rhs) = delete;
        UnitTestFailPrintManager(UnitTestFailPrintManager&& rhs) = delete;
        UnitTestFailPrintManager& operator=(UnitTestFailPrintManager&& rhs) = delete;

        CLASS_INVARIANT_DECLARE;

        void PrintFailClassInformation();
        void PrintFailFileName();
        void PrintFailLineNumber();
        void PrintErrorMessage();

    private:
        using UnitTestFailReportOutputSharedPtr = std::shared_ptr<UnitTestFailReportOutput>;

    private:
        UnitTestFailReportOutputSharedPtr reportOutput;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H
