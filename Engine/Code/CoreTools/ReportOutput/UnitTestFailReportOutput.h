//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.7.1.1 (2020/10/23 9:48)

// ����Ϣ�����ָ����ostream��UnitTestFailReportOutputΪ�ⲿ�ӿ��ࡣʵ�������Ԫ���Դ��󱨸���Ϣ��
#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include "CoreTools/Helper/Export/NonCopyMacro.h"
 
#include <iostream>
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(UnitTestFailReportOutputImpl);


namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UnitTestFailReportOutput final  
    {
    public:
        NON_COPY_TYPE_DECLARE(UnitTestFailReportOutput);

    public:
        UnitTestFailReportOutput(const std::string& failClassName, const std::string& fileName, int lineNumber,
                                 const std::string& errorMessage, const OStreamShared& streamShared);
        ~UnitTestFailReportOutput() noexcept = default;
        UnitTestFailReportOutput(const UnitTestFailReportOutput& rhs) noexcept = delete;
        UnitTestFailReportOutput& operator=(const UnitTestFailReportOutput& rhs) noexcept = delete;
        UnitTestFailReportOutput(UnitTestFailReportOutput&& rhs) noexcept = delete;
        UnitTestFailReportOutput& operator=(UnitTestFailReportOutput&& rhs) noexcept = delete;
        CLASS_INVARIANT_DECLARE;

        void PrintNewLine();
        void PrintFailClassInformation();
        void PrintFailFileName();
        void PrintFailLineNumber();
        void PrintErrorMessage();

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H
