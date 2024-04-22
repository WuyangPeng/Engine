/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 11:05)

#ifndef CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H

#include "EquidistantReportOutputImpl.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteInternalFwd.h"

/// 将信息输出至指定的stream。
/// TimeReportOutput为内部接口子类。
/// 实现输出当前时间和指定时间的功能。
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE TimeReportOutput : public EquidistantReportOutputImpl
    {
    public:
        using ClassType = TimeReportOutput;
        using ParentType = EquidistantReportOutputImpl;

        using CpuTimer = boost::timer::cpu_timer;

    public:
        TimeReportOutput(std::string timeDescribe, int borderLineLength, const OStreamShared& streamShared) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void PrintCurrentTime();
        void PrintCostTime(const CpuTimer& cpuTime);

    private:
        std::string timeDescribe;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H