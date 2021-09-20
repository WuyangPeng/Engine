// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê∏®÷˙∞Ê±æ£∫0.0.2.0 (2020/01/03 22:49)

#ifndef C_MAIN_FUNCTION_HELPER_UNIT_TEST_HELPER_H
#define C_MAIN_FUNCTION_HELPER_UNIT_TEST_HELPER_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CMainFunctionHelper
{
    class UnitTestHelper : public CoreTools::UnitTest
    {
    public:
        using ClassType = UnitTestHelper;
        using ParentType = UnitTest;

    public:
        UnitTestHelper();

        CLASS_INVARIANT_OVERRIDE_DECLARE;

    private:
        void DoRunUnitTest() noexcept override;
    };
}

#endif  // C_MAIN_FUNCTION_HELPER_UNIT_TEST_HELPER_H