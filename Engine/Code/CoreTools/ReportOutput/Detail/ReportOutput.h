///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.11 (2023/05/30 09:40)

#ifndef CORE_TOOLS_REPORT_OUTPUT_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/LogManager/Flags/LogManagerFlags.h"
#include "CoreTools/UnitTestSuite/OStreamShared.h"

#include <string>

/// ����Ϣ�����ָ����stream��
/// ReportOutputΪ�ڲ��ӿڻ��ࡣ
/// ʵ������ַ����ͻ��еĹ��ܡ�
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