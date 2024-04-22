/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/12 11:06)

#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/Export/NonCopyMacro.h"
#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/LogManager/LogManagerFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <string>

CORE_TOOLS_NON_COPY_EXPORT_IMPL(UnitTestFailReportOutputImpl);

/// 将信息输出至指定的stream。
/// UnitTestFailReportOutput为外部接口类。
/// 实现输出单元测试错误报告信息。
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
                                 const OStreamShared& streamShared,
                                 LogLevel logLevel);

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
