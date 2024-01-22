/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/11 11:22)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/ReportOutput/ReportOutputFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteInternalFwd.h"

#include <memory>
#include <string>

// ��Ԫ���������������Ϣ�����࣬UnitTestFailPrintManageΪ�ڲ��ӿ��࣬��������Դ�����Ϣ��
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UnitTestFailPrintManager final
    {
    public:
        using ClassType = UnitTestFailPrintManager;

    public:
        UnitTestFailPrintManager(UnitTest& unitTest, const std::string& fileName, int lineNumber, const std::string& errorMessage, LogLevel logLevel = LogLevel::Trace);
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
