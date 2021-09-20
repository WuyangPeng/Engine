///	Copyright (c) 2010-2021
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎辅助测试版本：0.7.1.1 (2021/03/20 20:24)

#include "DiscoveringModernCppGradientTesting.h"
#include "CoreTools/Helper/UnitTest/AssertExceptionMacro.h"
#include "CoreTools/Helper/UnitTest/AssertTestMacro.h"
#include "Mathematics/Base/MathDetail.h"
#include "Example/BookCpp/DiscoveringModernCpp/Helper/DiscoveringModernCppClassInvariantMacro.h"
#include "Example/BookCpp/DiscoveringModernCpp/Preface/GradientDetail.h"

BookAdvanced::DiscoveringModernCpp::DiscoveringModernCppGradientTesting::DiscoveringModernCppGradientTesting(const OStreamShared& stream)
    : ParentType{ stream }
{
    DISCOVERING_MODERN_CPP_SELF_CLASS_IS_VALID_9;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(BookAdvanced::DiscoveringModernCpp, DiscoveringModernCppGradientTesting)

void BookAdvanced::DiscoveringModernCpp::DiscoveringModernCppGradientTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void BookAdvanced::DiscoveringModernCpp::DiscoveringModernCppGradientTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GradientTest);
    ASSERT_NOT_THROW_EXCEPTION_0(GradientTemplateTest);
}

void BookAdvanced::DiscoveringModernCpp::DiscoveringModernCppGradientTesting::GradientTest()
{
    const Gradient gradient{};

    auto x = 4.0;
    auto y = 3.0;
    const auto proportion = x / y;

    gradient.GradientDescent(&x, &y, 0.9, 0.001, &ClassType::F, &ClassType::Gx, &ClassType::Gy);

    ASSERT_APPROXIMATE(x / y, proportion, Mathematics::DoubleMath::GetZeroTolerance());
}

void BookAdvanced::DiscoveringModernCpp::DiscoveringModernCppGradientTesting::GradientTemplateTest()
{
    const Gradient gradient{};

    constexpr auto x = 4.0;
    constexpr auto eps = 0.001;

    const auto result = gradient.GradientDescent(x, 0.9, eps, &ClassType::F1, &ClassType::G1);

    ASSERT_LESS(result, eps);
}
