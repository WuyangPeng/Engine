///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/20 14:00)

#ifndef CORE_TOOLS_HELPER_SUITE_EXCEPTION_CATCH_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_EXCEPTION_CATCH_MACRO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class ExceptionCatchMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ExceptionCatchMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ExceptionCatchMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void Catch0Test();
        void Catch1Test();
        void Catch2Test();
        void Catch3Test();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_EXCEPTION_CATCH_MACRO_TESTING_H