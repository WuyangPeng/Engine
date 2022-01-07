///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 18:18)

// 将信息输出至指定的ostream。UnitTestSuiteReportOutputImpl为内部接口子类。实现输出单元测试名、测试套件名和测试结果
#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_IMPL_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "TimeReportOutput.h"
#include "CoreTools/LogManager/LogManagerFwd.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UnitTestSuiteReportOutputImpl : public TimeReportOutput
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
        LogConsoleTextColorsManagerSharedPtr GetLogConsoleTextColorsManager(int failedNumber, int errorNumber);
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_IMPL_H