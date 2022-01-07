///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.8.0.0 (2021/12/14 18:49)

// 单元测试套件类。SuiteImpl为内部接口类，可增加或删除单元测试，并获取测试的结果。
#ifndef CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H
#define CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H

#include "CoreTools/CoreToolsDll.h"

#include "CoreTools/UnitTestSuite/UnitTestComposite.h"

#include <iostream>
#include <string>
#include <vector>

namespace CoreTools
{
    class CORE_TOOLS_HIDDEN_DECLARE SuiteImpl final : public UnitTestComposite
    {
    public:
        using ClassType = SuiteImpl;
        using ParentType = UnitTestComposite;

    public:
        explicit SuiteImpl(const std::string& name, const OStreamShared& streamShared, bool printRunUnitTest);

        CLASS_INVARIANT_FINAL_DECLARE;

#ifdef OPEN_CLASS_INVARIANT
        NODISCARD bool IsUnitTestValid() const noexcept;
#endif  // OPEN_CLASS_INVARIANT

        void PrintReport() final;
        void ResetTestData() final;

        NODISCARD int GetPassedNumber() const noexcept final;
        NODISCARD int GetFailedNumber() const noexcept final;
        NODISCARD int GetErrorNumber() const noexcept final;
        NODISCARD std::string GetName() const final;

        void ClearUnitTestCollection() noexcept final;
        void AddUnitTest(const UnitTestCompositeSharedPtr& unitTest) final;
        void RunUnitTest() final;

        void PrintRunUnitTest() final;

    private:
        using UnitTestContainer = std::vector<UnitTestCompositeSharedPtr>;

    private:
        std::string suiteName;
        UnitTestContainer unitTestCollection;
        bool printRunUnitTest;
    };
}

#endif  // CORE_TOOLS_UNIT_TEST_SUITE_SUITE_IMPL_H
