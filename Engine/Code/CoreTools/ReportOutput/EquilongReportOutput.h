///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.0 (2021/12/21 18:18)

// ����Ϣ�����ָ����ostream��EquilongReportOutputΪ�ⲿ�ӿ��ࡣʵ������ַ������߽��ߺͻ��еĹ��ܡ�
#ifndef CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"
#include <boost/noncopyable.hpp>
#include <iostream>
#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(EquilongReportOutputImpl);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE EquilongReportOutput final
    {
    public:
        NON_COPY_TYPE_DECLARE(EquilongReportOutput);

    public:
        explicit EquilongReportOutput(int borderLineLength, const OStreamShared& streamShared);

        CLASS_INVARIANT_DECLARE;

        void PrintNewLine();
        void PrintBorderLine(char character);
        void PrintString(const std::string& characterString);

    private:
        PackageType impl;
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_H
