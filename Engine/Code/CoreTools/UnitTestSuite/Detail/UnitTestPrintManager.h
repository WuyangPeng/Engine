///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 13:49)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_PRINT_MANAGER_H
#define CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_PRINT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ReportOutput/ReportOutputFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteInternalFwd.h"

#include <memory>
#include <string>

// 单元测试类输出测试结果管理类，UnitTestPrintManage为内部接口类，可输出测试结果。
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UnitTestPrintManager final
    {
    public:
        using ClassType = UnitTestPrintManager;
        using MasterType = UnitTest;
        using CpuTimer = boost::timer::cpu_timer;

    public:
        UnitTestPrintManager(MasterType& unitTest, const std::string& timeDescribe, int borderLineLength = 75);
        ~UnitTestPrintManager() noexcept = default;
        UnitTestPrintManager(const UnitTestPrintManager& rhs) = delete;
        UnitTestPrintManager& operator=(const UnitTestPrintManager& rhs) = delete;
        UnitTestPrintManager(UnitTestPrintManager&& rhs) = delete;
        UnitTestPrintManager& operator=(UnitTestPrintManager&& rhs) = delete;

        CLASS_INVARIANT_DECLARE;

        void PrintTestName();
        void PrintTestResult(int characterWidth);
        void PrintCostTime(const CpuTimer& timePtr);

    private:
        using UnitTestSuiteReportOutputSharedPtr = std::shared_ptr<UnitTestSuiteReportOutput>;

    private:
        MasterType& unitTest;
        UnitTestSuiteReportOutputSharedPtr reportOutput;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_UNIT_TEST_PRINT_MANAGER_H
