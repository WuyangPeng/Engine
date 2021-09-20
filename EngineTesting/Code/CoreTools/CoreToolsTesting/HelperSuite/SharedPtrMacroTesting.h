///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/20 13:42)

#ifndef CORE_TOOLS_HELPER_SUITE_SHARED_PTR_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_SHARED_PTR_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class SharedPtrMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = SharedPtrMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit SharedPtrMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void MacroTest() noexcept;
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_SHARED_PTR_MACRO_TESTING_H