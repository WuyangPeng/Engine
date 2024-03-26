/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.7 (2024/03/08 16:13)

#ifndef SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_PREVIOUSLY_BODY_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_PREVIOUSLY_BODY_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class GlUtilityPreviouslyBodyTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = GlUtilityPreviouslyBodyTesting;
        using ParentType = UnitTest;

    public:
        explicit GlUtilityPreviouslyBodyTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void PreviouslyBody0Test() const noexcept;
        void PreviouslyBody1Test() const noexcept;
        void PreviouslyBody2Test() const noexcept;
        void PreviouslyBody3Test() const noexcept;
        void PreviouslyBody4Test() const noexcept;
        void PreviouslyBody5Test() const noexcept;
        void PreviouslyBody6Test() const noexcept;
        void PreviouslyBody7Test() const noexcept;
        void PreviouslyBody8Test() const noexcept;
        void PreviouslyBody9Test() const noexcept;
        void PreviouslyBody10Test() const noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_PREVIOUSLY_BODY_TESTING_H
