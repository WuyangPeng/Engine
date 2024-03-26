/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:11)

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
        void DoRunUnitTest() override;
        void MainTest();

        NODISCARD int Body0Test(bool isNull) const noexcept;
        NODISCARD int Body1Test(bool isNull) const noexcept;
        NODISCARD int Body2Test(bool isNull) const noexcept;
        NODISCARD int Body3Test(bool isNull) const noexcept;
        NODISCARD int Body4Test(bool isNull) const noexcept;
        NODISCARD int Body5Test(bool isNull) const noexcept;
        NODISCARD int Body6Test(bool isNull) const noexcept;
        NODISCARD int Body7Test(bool isNull) const noexcept;
        NODISCARD int Body8Test(bool isNull) const noexcept;
        NODISCARD int Body17Test(bool isNull) const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_BODY_RESULT_TESTING_H
