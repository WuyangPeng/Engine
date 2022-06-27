///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.8.0.9 (2022/06/27 10:48)

#ifndef FRAMEWORK_HELPER_SUITE_MACINTOSH_MAIN_FUNCTION_HELPER_TESTING_H
#define FRAMEWORK_HELPER_SUITE_MACINTOSH_MAIN_FUNCTION_HELPER_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

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
        void DoRunUnitTest() final;

        void MainTest();

        void MacintoshMainFunctionHelper1Test();
    };
}

#endif  // FRAMEWORK_HELPER_SUITE_MACINTOSH_MAIN_FUNCTION_HELPER_TESTING_H