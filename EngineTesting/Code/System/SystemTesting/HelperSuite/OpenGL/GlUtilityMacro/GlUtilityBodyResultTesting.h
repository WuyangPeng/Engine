///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	������԰汾��0.7.1.1 (2021/03/18 13:17)

#ifndef SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_BODY_RESULT_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_BODY_RESULT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GlUtilityBodyResultTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GlUtilityBodyResultTesting;
        using ParentType = UnitTest;

    public:
        explicit GlUtilityBodyResultTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        int Body0Test(bool isNull) noexcept;
        int Body1Test(bool isNull) noexcept;
        int Body2Test(bool isNull) noexcept;
        int Body3Test(bool isNull) noexcept;
        int Body4Test(bool isNull) noexcept;
        int Body5Test(bool isNull) noexcept;
        int Body6Test(bool isNull) noexcept;
        int Body7Test(bool isNull) noexcept;
        int Body8Test(bool isNull) noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_BODY_RESULT_TESTING_H