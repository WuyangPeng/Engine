/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:17)

#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_IMPL_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "ReportOutput.h"

/// 将信息输出至指定的stream。
/// UnitTestFailReportOutputImpl为内部接口子类。
/// 实现输出单元测试错误报告信息。
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UnitTestFailReportOutputImpl final : public ReportOutput
    {
    public:
        using ClassType = UnitTestFailReportOutputImpl;
        using ParentType = ReportOutput;

    public:
        UnitTestFailReportOutputImpl(std::string failClassName,
                                     std::string fileName,
                                     int lineNumber,
                                     std::string errorMessage,
                                     const OStreamShared& streamShared,
                                     LogLevel logLevel) noexcept;

        CLASS_INVARIANT_FINAL_DECLARE;

        void PrintFailClassInformation();
        void PrintFailFileName();
        void PrintFailLineNumber();
        void PrintErrorMessage();

    private:
        std::string failClassName;
        std::string fileName;
        int lineNumber;
        std::string errorMessage;
        LogLevel logLevel;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_IMPL_H