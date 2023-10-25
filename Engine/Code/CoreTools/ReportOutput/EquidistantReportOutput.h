///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.5 (2023/09/20 14:56)

#ifndef CORE_TOOLS_REPORT_OUTPUT_EQUIDISTANT_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_EQUIDISTANT_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(EquidistantReportOutputImpl);

/// 将信息输出至指定的stream。
/// EquidistantReportOutput为外部接口类。
/// 实现输出字符串、边界线和换行的功能。
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
