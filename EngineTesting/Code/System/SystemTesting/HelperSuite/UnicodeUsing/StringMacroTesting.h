/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/07 15:22)

#ifndef SYSTEM_TESTING_HELPER_SUITE_STRING_MACRO_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_STRING_MACRO_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class StringMacroTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = StringMacroTesting;
        using ParentType = UnitTest;

    public:
        explicit StringMacroTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void StringMacroTest();
        void RegexTest();
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_STRING_MACRO_TESTING_H
