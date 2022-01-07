///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 16:58)

// ����Ϣ�����ָ����ostream��ReportOutputΪ�ڲ��ӿڻ��ࡣʵ������ַ����ͻ��еĹ��ܡ�
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
        NODISCARD OStreamShared GetStream() noexcept;

    private:
        OStreamShared streamShared;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_REPORT_OUTPUT_H