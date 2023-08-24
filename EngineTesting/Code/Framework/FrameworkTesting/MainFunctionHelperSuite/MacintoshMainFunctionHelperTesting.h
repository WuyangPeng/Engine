///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	版本：0.9.1.3 (2023/08/11 19:27)

#ifndef FRAMEWORK_HELPER_SUITE_MACINTOSH_MAIN_FUNCTION_HELPER_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MACINTOSH_MAIN_FUNCTION_HELPER_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace Framework
{
    class MacintoshMainFunctionHelperTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = MacintoshMainFunctionHelperTesting;
        using ParentType = UnitTest;

    public:
        explicit MacintoshMainFunctionHelperTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;

        void MainTest();

        void MacintoshMainFunctionHelper1Test();
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_MACINTOSH_MAIN_FUNCTION_HELPER_TESTING_H