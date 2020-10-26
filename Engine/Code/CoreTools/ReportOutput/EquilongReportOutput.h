//	Copyright (c) 2011-2020
//	Threading Core Render Engine
//
//	���ߣ������������ʶ���������
//	��ϵ���ߣ�94458936@qq.com
//
//	��׼��std:c++17
//	����汾��0.5.2.0 (2020/10/23 9:48)

// ����Ϣ�����ָ����ostream��EquilongReportOutputΪ�ⲿ�ӿ��ࡣʵ������ַ������߽��ߺͻ��еĹ��ܡ�
#ifndef CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <boost/noncopyable.hpp>
#include <iostream>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(EquilongReportOutputImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE EquilongReportOutput final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(EquilongReportOutput);

    public:
        explicit EquilongReportOutput(int borderLineLength, const OStreamShared& streamShared);

        CLASS_INVARIANT_DECLARE;

        void PrintNewLine();
        void PrintBorderLine(char character);
        void PrintString(const std::string& characterString);

    private:
        IMPL_TYPE_DECLARE(EquilongReportOutput);
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_EQUILONG_REPORT_OUTPUT_H
