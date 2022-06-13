///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/02 22:00)

#include "Minimize1Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Minimize1Detail.h"

namespace Mathematics
{
    template class Minimize1<float, Minimize1Testing>;
    template class Minimize1<double, Minimize1Testing>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Minimize1Testing)

void Mathematics::Minimize1Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(GetMinimumTest);
}

void Mathematics::Minimize1Testing::GetMinimumTest()
{
    const Minimize1<double, Minimize1Testing> minimize1(Function, 10, 10, this);

    const auto result = minimize1.GetMinimum(-100, 100, 20);

    ASSERT_APPROXIMATE(result.GetMinValue(), Function(result.GetMinLocation(), this), 1e-10);

    for (auto i = -100; i < 100; ++i)
    {
        ASSERT_TRUE(result.GetMinValue() <= Function(i, this));
    }
}

double Mathematics::Minimize1Testing::Function(double value, const Minimize1Testing* minimize1Testing) noexcept
{
    if (minimize1Testing != nullptr)
        return value * value * minimize1Testing->GetValue() + value * 5.0 + 3.0;
    else
        return 0.0;
}

double Mathematics::Minimize1Testing::GetValue() const noexcept
{
    return 1.0;
}
