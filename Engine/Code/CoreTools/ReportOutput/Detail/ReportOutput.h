//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.7.1.1 (2020/10/23 9:40)

// 将信息输出至指定的ostream。ReportOutput为内部接口基类。实现输出字符串和换行的功能。
#ifndef CORE_TOOLS_REPORT_OUTPUT_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/UnitTestSuite/OStreamShared.h"

#include <iostream>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE ReportOutput
    {
    public:
        using ClassType = ReportOutput;

    public:
        explicit ReportOutput(const OStreamShared& streamShared) noexcept;
        virtual ~ReportOutput() = default;
        ReportOutput(const ReportOutput&) = delete;
        ReportOutput& operator=(const ReportOutput&) = delete;
        ReportOutput(ReportOutput&&) noexcept = delete;
        ReportOutput& operator=(ReportOutput&&) noexcept = delete;

        CLASS_INVARIANT_VIRTUAL_DECLARE;

        void PrintString(const std::string& characterString);
        void PrintNewLine();
        void PrintNumber(int number);

    protected:
        [[nodiscard]] OStreamShared GetStream() noexcept;

    private:
        OStreamShared m_StreamShared;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_REPORT_OUTPUT_H