/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:12)

#ifndef SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_BODY_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_BODY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GlUtilityBodyTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GlUtilityBodyTesting;
        using ParentType = UnitTest;

    public:
        explicit GlUtilityBodyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void Body0Test() const noexcept;
        void Body1Test() const noexcept;
        void Body2Test() const noexcept;
        void Body3Test() const noexcept;
        void Body4Test() const noexcept;
        void Body5Test() const noexcept;
        void Body6Test() const noexcept;
        void Body7Test() const noexcept;
        void Body8Test() const noexcept;
        void Body9Test() const noexcept;
        void Body10Test() const noexcept;
        void Body11Test() const noexcept;
        void Body12Test() const noexcept;
        void Body15Test() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_BODY_TESTING_H
