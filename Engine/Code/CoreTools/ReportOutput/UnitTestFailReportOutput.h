///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	����汾��0.9.0.5 (2023/03/31 15:47)

#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(UnitTestFailReportOutputImpl);

/// ����Ϣ�����ָ����stream��
/// UnitTestFailReportOutputΪ�ⲿ�ӿ��ࡣ
/// ʵ�������Ԫ���Դ��󱨸���Ϣ��
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UnitTestFailReportOutput final
    {
    public:
        NON_COPY_TYPE_DECLARE(UnitTestFailReportOutput);

    public:
        UnitTestFailReportOutput(const std::string& failClassName,
                                 const std::string& fileName,
                                 int lineNumber,
                                 const std::string& errorMessage,
                                 const OStreamShared& streamShared);

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
