///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.1.2 (2022/09/25 19:59)

#ifndef SYSTEM_TESTING_HELPER_SUITE_ENUM_NEGATE_TESTING_H
#define SYSTEM_TESTING_HELPER_SUITE_ENUM_NEGATE_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace System
{
    class EnumNegateTesting final : public CoreTools::UnitTest
    {
    public:
        using ClassType = EnumNegateTesting;
        using ParentType = UnitTest;

    public:
        explicit EnumNegateTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void SignedConstexprOperatorTest() noexcept;
    };
}

#endif  // SYSTEM_TESTING_HELPER_SUITE_ENUM_NEGATE_TESTING_H
