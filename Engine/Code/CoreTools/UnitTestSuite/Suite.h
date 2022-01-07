///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/14 19:05)

// 单元测试套件类。Suite为外部接口类，可增加或删除单元测试，并获取测试的结果。
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_H

#include "CoreTools/CoreToolsDll.h"

#include "UnitTestSuiteFwd.h"
#include "CoreTools/Contract/ImplStaticAssertHelper.h"
#include "CoreTools/Helper/ExportMacro.h"

#include <iostream>
#include <string>

EXPORT_SHARED_PTR(CoreTools, UnitTestComposite, CORE_TOOLS_DEFAULT_DECLARE);

namespace CoreTools
{
    class CORE_TOOLS_DEFAULT_DECLARE Suite final
    {
    public:
        using ClassType = Suite;
        using UnitTestSharedPtr = std::shared_ptr<UnitTestComposite>;
        using ClassShareType = NonCopyClasses;

    public:
        Suite(const std::string& name, const OStreamShared& streamShared, bool printRunUnitTest);

        ~Suite() noexcept = default;
        Suite(const Suite& rhs) noexcept = delete;
        Suite& operator=(const Suite& rhs) noexcept = delete;
        Suite(Suite&& rhs) noexcept;
        Suite& operator=(Suite&& rhs) noexcept;

        CLASS_INVARIANT_DECLARE;

        NODISCARD std::string GetName() const;
        NODISCARD int GetPassedNumber() const noexcept;
        NODISCARD int GetFailedNumber() const noexcept;
        NODISCARD int GetErrorNumber() const noexcept;

        NODISCARD OStreamShared& GetStream() noexcept;

        void PrintReport();
        void RunUnitTest();
        void ClearUnitTestCollection();
        void ResetTestData();
        void AddTest(const UnitTestSharedPtr& unitTest);
        void AddSuite(const Suite& suite);

    private:
        using SuiteImplSharedPtr = std::shared_ptr<UnitTestComposite>;

    private:
        SuiteImplSharedPtr impl;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_H
