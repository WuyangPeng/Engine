//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 9:42)

// ����Ϣ�����ָ����ostream��UnitTestFailReportOutputImplΪ�ڲ��ӿ����ࡣʵ�������Ԫ���Դ��󱨸���Ϣ��

#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_IMPL_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "ReportOutput.h"

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UnitTestFailReportOutputImpl final : public ReportOutput
    {
    public:
        using ClassType = UnitTestFailReportOutputImpl;
        using ParentType = ReportOutput;

    public:
        UnitTestFailReportOutputImpl(const std::string& failClassName, const std::string& fileName, int lineNumber,
                                     const std::string& errorMessage, const OStreamShared& streamShared);

        CLASS_INVARIANT_FINAL_DECLARE;

        void PrintFailClassInformation();
        void PrintFailFileName();
        void PrintFailLineNumber();
        void PrintErrorMessage();

    private:
        std::string m_FailClassName;
        std::string m_FileName;
        int m_LineNumber;
        std::string m_ErrorMessage;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_IMPL_H