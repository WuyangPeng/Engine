///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.3 (2023/02/28 15:54)

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