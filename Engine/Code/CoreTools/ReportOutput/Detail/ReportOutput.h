/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.4 (2024/01/11 10:17)

#ifndef CORE_TOOLS_REPORT_OUTPUT_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"

#include <string>

/// 将信息输出至指定的stream。
/// ReportOutput为内部接口基类。
/// 实现输出字符串和换行的功能。
namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ReportOutput
    {
    public:
        using ClassType = ReportOutput;

    public:
        explicit ReportOutput(OStreamShared streamShared) noexcept;
        virtual ~ReportOutput() = default;
        ReportOutput(const ReportOutput&) = delete;
        ReportOutput& operator=(const ReportOutput&) = delete;
        ReportOutput(ReportOutput&&) noexcept = delete;
        ReportOutput& operator=(ReportOutput&&) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void PrintString(const std::string& characterString, LogLevel logLevel = LogLevel::Trace);
        void PrintNewLine();
        void PrintNumber(int number, LogLevel logLevel = LogLevel::Trace);

    protected:
        NODISCARD OStreamShared GetStream() noexcept;

    private:
        OStreamShared streamShared;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_REPORT_OUTPUT_H