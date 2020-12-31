//	Copyright (c) 2010-2020
//	Threading Core Render Engine
//
//	作者：彭武阳，彭晔恩，彭晔泽
//	联系作者：94458936@qq.com
//
//	标准：std:c++17
//	引擎版本：0.5.2.0 (2020/10/23 11:30)

// 单元测试类输出错误信息管理类，UnitTestFailPrintManage为内部接口类，可输出测试错误信息。
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/ReportOutput/ReportOutputFwd.h"
#include "CoreTools/UnitTestSuite/UnitTestSuiteFwd.h"

#include <boost/noncopyable.hpp>
#include <memory>
#include <string>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE UnitTestFailPrintManager final : private boost::noncopyable
    {
    public:
        using ClassType = UnitTestFailPrintManager;

    public:
        UnitTestFailPrintManager(UnitTest& unitTest, const std::string& fileName, int lineNumber, const std::string& errorMessage);

        CLASS_INVARIANT_DECLARE;

        void PrintFailClassInformation();
        void PrintFailFileName();
        void PrintFailLineNumber();
        void PrintErrorMessage();

    private:
        using UnitTestFailReportOutputSharedPtr = std::shared_ptr<UnitTestFailReportOutput>;

    private:
        UnitTestFailReportOutputSharedPtr m_ReportOutputPtr;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_TEST_FAIL_PRINT_MANAGER_H
