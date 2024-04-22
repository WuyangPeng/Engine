/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 11:05)

#ifndef CORE_TOOLS_REPORT_OUTPUT_EQUIDISTANT_REPORT_OUTPUT_IMPL_H
#define CORE_TOOLS_REPORT_OUTPUT_EQUIDISTANT_REPORT_OUTPUT_IMPL_H

#include "ReportOutput.h"

/// ����Ϣ�����ָ����stream��
/// EquidistantReportOutputImplΪ�ڲ��ӿ����ࡣ
/// ʵ������߽��ߵĹ��ܡ�
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE EquidistantReportOutputImpl : public ReportOutput
    {
    public:
        using ClassType = EquidistantReportOutputImpl;
        using ParentType = ReportOutput;

    public:
        explicit EquidistantReportOutputImpl(int borderLineLength, const OStreamShared& streamShared) noexcept;

        CLASS_INVARIANT_OVERRIDE_DECLARE;

        void PrintBorderLine(char character);

    protected:
        NODISCARD int GetBorderLineLength() const noexcept;

    private:
        int borderLineLength;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_EQUIDISTANT_REPORT_OUTPUT_IMPL_H