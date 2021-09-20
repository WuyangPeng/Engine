///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/18 13:17)

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
        void DoRunUnitTest() final;
        void MainTest();

        void PreviouslyBody0Test() noexcept;
        void PreviouslyBody1Test() noexcept;
        void PreviouslyBody2Test() noexcept;
        void PreviouslyBody3Test() noexcept;
        void PreviouslyBody4Test() noexcept;
        void PreviouslyBody5Test() noexcept;
        void PreviouslyBody6Test() noexcept;
        void PreviouslyBody7Test() noexcept;
        void PreviouslyBody8Test() noexcept;
        void PreviouslyBody9Test() noexcept;
        void PreviouslyBody10Test() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_PREVIOUSLY_BODY_TESTING_H
