///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:56)

#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_IMPL_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "TimeReportOutput.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

/// 将信息输出至指定的stream。
/// UnitTestSuiteReportOutputImpl为内部接口子类。
/// 实现输出单元测试名、测试套件名和测试结果。
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UnitTestSuiteReportOutputImpl final : public TimeReportOutput
    {
    public:
        using ClassType = UnitTestSuiteReportOutputImpl;
        using ParentType = TimeReportOutput;

    public:
        UnitTestSuiteReportOutputImpl(const std::string& timeDescribe, int borderLineLength, const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void PrintTestName(const std::string& testName);
        void PrintSuiteName(const std::string& suiteName);
        void PrintTestResult(int passedNumber, int failedNumber, int errorNumber, int characterWidth);

    private:
        using LogConsoleTextColorsManagerSharedPtr = std::shared_ptr<LogConsoleTextColorsManager>;

    private:
        NODISCARD static LogLevel GetLogLevel(int failedNumber, int errorNumber) noexcept;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_IMPL_H