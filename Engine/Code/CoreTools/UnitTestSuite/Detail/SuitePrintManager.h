/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 11:20)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_PRINT_MANAGER_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_PRINT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ReportOutput/ReportOutputFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteInternalFwd.h"

#include <memory>

/// 单元测试套件类输出信息管理类，SuitePrintManage为内部接口类，可输出信息头、名称、测试结果和当前时间。
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE SuitePrintManager final
    {
    public:
        using ClassType = SuitePrintManager;
        using MasterType = SuiteImpl;

    public:
        explicit SuitePrintManager(MasterType& suite, int borderLineLength = 75);
        ~SuitePrintManager() noexcept = default;
        SuitePrintManager(const SuitePrintManager& rhs) = delete;
        SuitePrintManager& operator=(const SuitePrintManager& rhs) = delete;
        SuitePrintManager(SuitePrintManager&& rhs) = delete;
        SuitePrintManager& operator=(SuitePrintManager&& rhs) = delete;

        CLASS_INVARIANT_DECLARE;

        void PrintCoreToolsHeader();
        void PrintSuiteName();
        void PrintSuiteResult();
        void PrintCurrentTime();

    private:
        using UnitTestSuiteReportOutputSharedPtr = std::shared_ptr<UnitTestSuiteReportOutput>;

    private:
        static constexpr auto characterWidth = 8;

    private:
        MasterType& suite;
        UnitTestSuiteReportOutputSharedPtr unitTestSuiteReportOutput;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_PRINT_MANAGER_H
