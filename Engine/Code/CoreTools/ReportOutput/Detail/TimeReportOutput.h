///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 16:58)

// ����Ϣ�����ָ����ostream��TimeReportOutputΪ�ڲ��ӿ����ࡣʵ�������ǰʱ���ָ��ʱ��Ĺ��ܡ�

#ifndef CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H

#include "EquilongReportOutputImpl.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteInternalFwd.h"

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
        std::string timeDescribe;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H