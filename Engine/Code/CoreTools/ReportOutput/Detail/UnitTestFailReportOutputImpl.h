/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 11:05)

#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_IMPL_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "ReportOutput.h"

/// ����Ϣ�����ָ����stream��
/// UnitTestFailReportOutputImplΪ�ڲ��ӿ����ࡣ
/// ʵ�������Ԫ���Դ��󱨸���Ϣ��
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

        void PrintFailClassInformation() const;
        void PrintFailFileName() const;
        void PrintFailLineNumber() const;
        void PrintErrorMessage() const;

    private:
        std::string failClassName;
        std::string fileName;
        int lineNumber;
        std::string errorMessage;
        LogLevel logLevel;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_IMPL_H