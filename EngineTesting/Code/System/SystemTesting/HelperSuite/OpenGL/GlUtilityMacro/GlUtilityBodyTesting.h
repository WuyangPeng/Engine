///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎测试版本：0.7.1.1 (2021/03/18 14:44)

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
        void DoRunUnitTest() final;
        void MainTest();

        void Body0Test() noexcept;
        void Body1Test() noexcept;
        void Body2Test() noexcept;
        void Body3Test() noexcept;
        void Body4Test() noexcept;
        void Body5Test() noexcept;
        void Body6Test() noexcept;
        void Body7Test() noexcept;
        void Body8Test() noexcept;
        void Body9Test() noexcept;
        void Body10Test() noexcept;
        void Body11Test() noexcept;
        void Body12Test() noexcept;
        void Body15Test() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_GL_UTILITY_BODY_TESTING_H
