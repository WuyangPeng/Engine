///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.3 (2022/10/03 11:46)

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

        NODISCARD int Body0Test(bool isNull) noexcept;
        NODISCARD int Body1Test(bool isNull) noexcept;
        NODISCARD int Body2Test(bool isNull) noexcept;
        NODISCARD int Body3Test(bool isNull) noexcept;
        NODISCARD int Body4Test(bool isNull) noexcept;
        NODISCARD int Body5Test(bool isNull) noexcept;
        NODISCARD int Body6Test(bool isNull) noexcept;
        NODISCARD int Body7Test(bool isNull) noexcept;
        NODISCARD int Body8Test(bool isNull) noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_BODY_RESULT_TESTING_H
