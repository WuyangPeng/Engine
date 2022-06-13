///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/05/19 14:30)

#ifndef CORE_TOOLS_CONTRACT_SUITE_NOEXCEPT_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_NOEXCEPT_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class NoexceptTesting final : public UnitTest
    {
    public:
        using ClassType = NoexceptTesting;
        using ParentType = UnitTest;

    public:
        explicit NoexceptTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    private:
        void DoRunUnitTest() final;
        void MainTest();

        void DisableNoexceptTest();
        void NoexceptTest();

        void Function0();
        void Function1(MAYBE_UNUSED int parameter);
        NODISCARD int Function2();
        NODISCARD int Function3(MAYBE_UNUSED int parameter);

        void ConstFunction0() const;
        void ConstFunction1(MAYBE_UNUSED int parameter) const;
        NODISCARD int ConstFunction2() const;
        NODISCARD int ConstFunction3(MAYBE_UNUSED int parameter) const;
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_NOEXCEPT_TESTING_H