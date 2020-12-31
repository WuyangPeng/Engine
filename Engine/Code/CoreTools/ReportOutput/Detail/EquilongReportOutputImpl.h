//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 9:37)

// ����Ϣ�����ָ����ostream��EquilongReportOutputImplΪ�ڲ��ӿ����ࡣʵ������߽��ߵĹ��ܡ�

#ifndef CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_IMPL_H
#define CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_IMPL_H

#include "ReportOutput.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EquilongReportOutputImpl : public ReportOutput
    {
    public:
        using ClassType = EquilongReportOutputImpl;
        using ParentType = ReportOutput;

    public:
        explicit EquilongReportOutputImpl(int borderLineLength, const OStreamShared& streamShared) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void PrintBorderLine(char character);

    protected:
        [[nodiscard]] int GetBorderLineLength() const noexcept;

    private:
        int m_BorderLineLength;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_IMPL_H