/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.8 (2024/04/12 11:05)

#ifndef CORE_TOOLS_REPORT_OUTPUT_EQUIDISTANT_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_EQUIDISTANT_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(EquidistantReportOutputImpl);

/// ����Ϣ�����ָ����stream��
/// EquidistantReportOutputΪ�ⲿ�ӿ��ࡣ
/// ʵ������ַ������߽��ߺͻ��еĹ��ܡ�
namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE EquidistantReportOutput final
    {
    public:
        NON_COPY_TYPE_DECLARE(EquidistantReportOutput);

    public:
        explicit EquidistantReportOutput(int borderLineLength, const OStreamShared& streamShared);

        CLASS_INVARIANT_DECLARE;

        void PrintNewLine();
        void PrintBorderLine(char character);
        void PrintString(const std::string& characterString);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_EQUIDISTANT_REPORT_OUTPUT_H
