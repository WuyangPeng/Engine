//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 9:50)

// 将信息输出至指定的ostream。UnitTestSuiteReportOutput为外部接口类。
// 实现输出字符串、边界线、时间、单元测试名、测试套件名、测试结果和换行的功能。

#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <boost/noncopyable.hpp>
#include <iostream>
#include <string>

namespace boost
{
    namespace timer
    {
        class cpu_timer;
    }
}

CORE_TOOLS_EXPORT_SHARED_PTR(UnitTestSuiteReportOutputImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UnitTestSuiteReportOutput final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(UnitTestSuiteReportOutput);
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
        IMPL_TYPE_DECLARE(UnitTestSuiteReportOutput);
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_H
