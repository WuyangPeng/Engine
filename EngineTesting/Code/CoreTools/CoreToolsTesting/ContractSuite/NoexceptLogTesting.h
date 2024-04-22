/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// 作者：彭武阳，彭晔恩，彭晔泽
/// 联系作者：94458936@qq.com
///
/// 标准：std:c++20
/// 版本：1.0.0.8 (2024/04/15 09:58)

#ifndef CORE_TOOLS_CONTRACT_SUITE_NOEXCEPT_LOG_TESTING_H
#define CORE_TOOLS_CONTRACT_SUITE_NOEXCEPT_LOG_TESTING_H

#include "CoreTools/UnitTestSuite/UnitTest.h"

namespace CoreTools
{
    class NoexceptLogTesting final : public UnitTest
    {
    public:
        using ClassType = NoexceptLogTesting;
        using ParentType = UnitTest;

    public:
        explicit NoexceptLogTesting(const OStreamShared& stream);

        CLASS_INVARIANT_FINAL_DECLARE;

    protected:
        void PrintTipsMessage() override;

    private:
        void DoRunUnitTest() override;
        void MainTest();

        void NoexceptUseLogTest();

        void Function0();
        void Function1(int parameter);
        NODISCARD int Function2();
        NODISCARD int Function3(int parameter);

        void ConstFunction0() const;
        void ConstFunction1(int parameter) const;
        NODISCARD int ConstFunction2() const;
        NODISCARD int ConstFunction3(int parameter) const;

        static void StaticFunction0();
        static void StaticFunction1(int parameter);
        NODISCARD static int StaticFunction2();
        NODISCARD static int StaticFunction3(int parameter);
    };
}

#endif  // CORE_TOOLS_CONTRACT_SUITE_NOEXCEPT_LOG_TESTING_H