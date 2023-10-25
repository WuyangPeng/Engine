///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:56)

#ifndef CORE_TOOLS_REPORT_OUTPUT_EQUIDISTANT_REPORT_OUTPUT_IMPL_H
#define CORE_TOOLS_REPORT_OUTPUT_EQUIDISTANT_REPORT_OUTPUT_IMPL_H

#include "ReportOutput.h"

/// 将信息输出至指定的stream。
/// EquidistantReportOutputImpl为内部接口子类。
/// 实现输出边界线的功能。
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