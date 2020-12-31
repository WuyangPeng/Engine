//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 9:48)

// 将信息输出至指定的ostream。UnitTestFailReportOutput为外部接口类。实现输出单元测试错误报告信息。
#ifndef CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H
#define CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <boost/noncopyable.hpp>
#include <iostream>
#include <string>

CORE_TOOLS_EXPORT_SHARED_PTR(UnitTestFailReportOutputImpl);
EXPORT_NONCOPYABLE_CLASS(CORE_TOOLS);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE UnitTestFailReportOutput final : private boost::noncopyable
    {
    public:
        NON_COPY_CLASSES_TYPE_DECLARE(UnitTestFailReportOutput);

    public:
        UnitTestFailReportOutput(const std::string& failClassName, const std::string& fileName, int lineNumber,
                                 const std::string& errorMessage, const OStreamShared& streamShared);

        CLASS_INVARIANT_DECLARE;

        void PrintNewLine();
        void PrintFailClassInformation();
        void PrintFailFileName();
        void PrintFailLineNumber();
        void PrintErrorMessage();

    private:
        IMPL_TYPE_DECLARE(UnitTestFailReportOutput);
    };
}

#endif  // CORE_TOOLS_REPORT_OUTPUT_CORE_TOOLS_FAIL_REPORT_OUTPUT_H
