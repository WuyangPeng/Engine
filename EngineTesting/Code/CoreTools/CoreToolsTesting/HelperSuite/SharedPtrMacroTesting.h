///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.6 (2023/04/11 21:00)

#ifndef CORE_TOOLS_HELPER_SUITE_SHARED_PTR_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_SHARED_PTR_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SharedPtrMacroTesting final : public UnitTest
    {
    public:
        using ClassType = SharedPtrMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit SharedPtrMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void MacroTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_SHARED_PTR_MACRO_TESTING_H