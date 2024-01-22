/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 11:22)

#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/ReportOutput/ReportOutputFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteInternalFwd.h"

#include <memory>
#include <string>

// 单元测试类输出错误信息管理类，UnitTestFailPrintManage为内部接口类，可输出测试错误信息。
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
