///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/20 20:23)

#ifndef BOOK_ADVANCED_DISCOVERING_MODERN_CPP_GRADIENT_TESTING_H
#define BOOK_ADVANCED_DISCOVERING_MODERN_CPP_GRADIENT_TESTING_H

#include "CoreTools/Helper/UnitTestSuiteMacro.h"

namespace BookAdvanced
{
    namespace DiscoveringModernCpp
    {
        class DiscoveringModernCppGradientTesting final : public CoreTools::UnitTest
        {
        public:
            using ClassType = DiscoveringModernCppGradientTesting;
            using ParentType = UnitTest;

        public:
            explicit DiscoveringModernCppGradientTesting(const OStreamShared& stream);

            CLASS_INVARIANT_FINAL_DECLARE;

        private:
            void DoRunUnitTest() final;

            void MainTest();

            void GradientTest();
            void GradientTemplateTest();

            NODISCARD constexpr static double F(double x, double y) noexcept
            {
                return x * y;
            }

            NODISCARD constexpr static double Gx(double x, MAYBE_UNUSED double y) noexcept
            {
                return x;
            }

            NODISCARD constexpr static double Gy(MAYBE_UNUSED double x, double y) noexcept
            {
                return y;
            }

            NODISCARD constexpr static double F1(double x) noexcept
            {
                return x;
            }

            NODISCARD constexpr static double G1(double x) noexcept
            {
                return x * 0.9;
            }
        };
    }
}

#endif  // BOOK_ADVANCED_DISCOVERING_MODERN_CPP_GRADIENT_TESTING_H