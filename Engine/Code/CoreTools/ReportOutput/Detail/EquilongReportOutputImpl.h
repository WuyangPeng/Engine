///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/21 16:57)

// 将信息输出至指定的ostream。EquilongReportOutputImpl为内部接口子类。实现输出边界线的功能。
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
        NODISCARD int GetBorderLineLength() const noexcept;

    private:
        int borderLineLength;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_IMPL_H