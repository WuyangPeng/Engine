///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++20
///	������԰汾��0.9.0.12 (2023/06/09 16:04)

#include "Minimize1Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/Minimize1Detail.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"

namespace Mathematics
{
    template class Minimize1<float, Minimize1Testing>;
    template class Minimize1<double, Minimize1Testing>;
}

Mathematics::Minimize1Testing::Minimize1Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Minimize1Testing)

void Mathematics::Minimize1Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
