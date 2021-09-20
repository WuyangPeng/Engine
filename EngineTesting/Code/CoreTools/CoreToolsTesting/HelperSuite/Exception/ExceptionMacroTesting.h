///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.2.1 (2021/08/20 14:00)

#ifndef CORE_TOOLS_HELPER_SUITE_EXCEPTION_MACRO_TESTING_H
#define CORE_TOOLS_HELPER_SUITE_EXCEPTION_MACRO_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace CoreTools
{
    class ExceptionMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = ExceptionMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit ExceptionMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void ThrowErrorTest();
        void ThrowWindowsErrorTest();
        void ThrowComErrorTest();
    };
}

#endif  // CORE_TOOLS_HELPER_SUITE_EXCEPTION_MACRO_TESTING_H