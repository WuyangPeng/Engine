///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 18:19)

// 将信息输出至指定的ostream。UnitTestSuiteReportOutput为外部接口类。
// 实现输出字符串、边界线、时间、单元测试名、测试套件名、测试结果和换行的功能。
#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteInternalFwd.h"

#include <iostream>
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(UnitTestSuiteReportOutputImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UnitTestSuiteReportOutput final
    {
    public:
        NON_COPY_TYPE_DECLARE(UnitTestSuiteReportOutput);
        using CpuTimer = boost::timer::cpu_timer;

    public:
        UnitTestSuiteReportOutput(const std::string& timeDescribe, int borderLineLength, const OStreamShared& streamShared);

        CLASS_INVARIANT_DECLARE;

        void PrintString(const std::string& characterString);
        void PrintNewLine();
        void PrintBorderLine(char character);
        void PrintCurrentTime();
        void PrintCostTime(const CpuTimer& cpuTime);
        void PrintSuiteName(const std::string& suiteName);
        void PrintTestName(const std::string& testName);
        void PrintTestResult(int passedNumber, int failedNumber, int errorNumber, int characterWidth);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_H
