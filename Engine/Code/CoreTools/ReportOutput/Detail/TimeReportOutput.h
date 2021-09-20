//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 9:42)

// 将信息输出至指定的ostream。TimeReportOutput为内部接口子类。实现输出当前时间和指定时间的功能。

#ifndef CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H

#include "EquilongReportOutputImpl.h"

namespace boost
{
    namespace timer
    {
        class cpu_timer;
    }
}

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE TimeReportOutput : public EquilongReportOutputImpl
    {
    public:
        using ClassType = TimeReportOutput;
        using ParentType = EquilongReportOutputImpl;
        using CpuTimer = boost::timer::cpu_timer; 

    public:
        TimeReportOutput(const std::string& timeDescribe, int borderLineLength, const OStreamShared& streamShared);

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void PrintCurrentTime();
        void PrintCostTime(const CpuTimer& cpuTime);

    private:
        std::string m_TimeDescribe;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H