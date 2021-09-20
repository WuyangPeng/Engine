//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 9:50)

// ����Ϣ�����ָ����ostream��UnitTestSuiteReportOutputΪ�ⲿ�ӿ��ࡣ
// ʵ������ַ������߽��ߡ�ʱ�䡢��Ԫ�������������׼��������Խ���ͻ��еĹ��ܡ�

#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_SUITE_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"

#include <iostream>
#include <string>

namespace boost
{
    namespace timer
    {
        class cpu_timer;
    }
}

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
        ~UnitTestSuiteReportOutput() noexcept = default;
        UnitTestSuiteReportOutput(const UnitTestSuiteReportOutput& rhs) noexcept = delete;
        UnitTestSuiteReportOutput& operator=(const UnitTestSuiteReportOutput& rhs) noexcept = delete;
        UnitTestSuiteReportOutput(UnitTestSuiteReportOutput&& rhs) noexcept = delete;
        UnitTestSuiteReportOutput& operator=(UnitTestSuiteReportOutput&& rhs) noexcept = delete;

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
