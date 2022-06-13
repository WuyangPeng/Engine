///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/03 16:08)

#include "RombergIntegralTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/RombergIntegralDetail.h"

#include <vector>

using std::vector;

namespace Mathematics
{
    template class RombergIntegral<float, RombergIntegralTesting>;
    template class RombergIntegral<double, RombergIntegralTesting>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, RombergIntegralTesting)

void Mathematics::RombergIntegralTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
}

void Mathematics::RombergIntegralTesting::ValueTest()
{
    constexpr double end = 3.5;
    constexpr double begin = 1.5;

    double difference = end - begin;
    constexpr int order = 5;
    vector<double> rom0(order);
    vector<double> rom1(order);

    rom0.at(0) = (0.5 * difference * (Solution(begin, this) + Solution(end, this)));

    int p0 = 1;
    for (int orderIndex = 2; orderIndex <= order; ++orderIndex)
    {
        double sum = 0.0;

        for (int i = 1; i <= p0; ++i)
        {
            sum += Solution(begin + difference * (i - 0.5), this);
        }

        rom1.at(0) = (0.5 * (rom0.at(0) + difference * sum));

        int p2 = 4;
        for (int i = 1; i < orderIndex; ++i)
        {
            const auto temp = i - 1;
            auto temp1 = p2 - 1;
            rom1.at(i) = (p2 * rom1.at(temp) - rom0.at(temp)) / (temp1);

            p2 *= 4;
        }

        for (int i = 0; i < orderIndex; ++i)
        {
            rom0.at(i) = rom1.at(i);
        }

        p0 *= 2;
        difference *= 0.5;
    }
    constexpr auto temp = order - 1;
    const double result = rom0.at(temp);

    RombergIntegral<double, RombergIntegralTesting> rombergIntegral(order, begin, end, Solution, this);

    ASSERT_APPROXIMATE(result, rombergIntegral.GetValue(), 1e-10);
}

double Mathematics::RombergIntegralTesting::Solution(double input, const RombergIntegralTesting* userData) noexcept
{
    if (userData != nullptr)
        return input * userData->GetUserData() + 13;
    else
        return 0.0;
}

double Mathematics::RombergIntegralTesting::GetUserData() const noexcept
{
    return 6;
}
