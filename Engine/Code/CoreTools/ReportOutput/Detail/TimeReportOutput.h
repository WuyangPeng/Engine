/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 11:05)

#ifndef CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_TIME_REPORT_OUTPUT_H

#include "EquidistantReportOutputImpl.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteInternalFwd.h"

/// ����Ϣ�����ָ����stream��
/// TimeReportOutputΪ�ڲ��ӿ����ࡣ
/// ʵ�������ǰʱ���ָ��ʱ��Ĺ��ܡ�
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