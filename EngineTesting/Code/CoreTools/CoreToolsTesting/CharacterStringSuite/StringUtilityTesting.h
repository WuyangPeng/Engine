///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.3 (2023/02/28 15:54)

#ifndef CORE_TOOLS_CHARACTER_STRING_SUITE_STRING_UTILITY_TESTING_H
#define CORE_TOOLS_CHARACTER_STRING_SUITE_STRING_UTILITY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class StringUtilityTesting final : public UnitTest
    {
    public:
        using ClassType = StringUtilityTesting;
        using ParentType = UnitTest;

    public:
        explicit StringUtilityTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void ToFirstLetterUpperTest();
        void ToFirstLetterLowerTest();
        void ToUpperMacroTest();

        void ConvertNarrowToWideTest();
        void ConvertWideToNarrowTest();
        void ToLowerTest();
        void ToUpperTest();

        void GetTextTokensTest();
        void GetAdvancedTextTokensTest();
        void GetTokensTest();
    };
}

#endif  // CORE_TOOLS_CHARACTER_STRING_SUITE_STRING_UTILITY_TESTING_H