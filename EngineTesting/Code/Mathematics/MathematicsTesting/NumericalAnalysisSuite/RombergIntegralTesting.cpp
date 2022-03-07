// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 09:56)

#include "RombergIntegralTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/NumericalAnalysis/RombergIntegralDetail.h"

#include <vector>

using std::vector;
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26429)
namespace Mathematics
{
    template class RombergIntegral<float, RombergIntegralTesting>;
    template class RombergIntegral<double, RombergIntegralTesting>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, RombergIntegralTesting)

void Mathematics::RombergIntegralTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ValueTest);
}

void Mathematics::RombergIntegralTesting ::ValueTest()
{
    double end = 3.5;
    double begin = 1.5;

    double difference = end - begin;
    int order = 5;
    vector<double> rom0(order);
    vector<double> rom1(order);

    rom0[0] = (0.5 * difference * (Solution(begin, this) + Solution(end, this)));

    int p0 = 1;
    for (int orderIndex = 2; orderIndex <= order; ++orderIndex)
    {
        double sum = 0.0;

        for (int i = 1; i <= p0; ++i)
        {
            sum += Solution(begin + difference * (i - 0.5), this);
        }

        rom1[0] = (0.5 * (rom0[0] + difference * sum));

        int p2 = 4;
        for (int i = 1; i < orderIndex; ++i)
        {
            auto temp = i - 1;
            auto temp1 = p2 - 1;
            rom1[i] = (p2 * rom1[temp] - rom0[temp]) / (temp1);

            p2 *= 4;
        }

        for (int i = 0; i < orderIndex; ++i)
        {
            rom0[i] = rom1[i];
        }

        p0 *= 2;
        difference *= 0.5;
    }
    auto temp = order - 1;
    double result = rom0[temp];

    RombergIntegral<double, RombergIntegralTesting> rombergIntegral(order, begin, end, Solution, this);

    ASSERT_APPROXIMATE(result, rombergIntegral.GetValue(), 1e-10);
}

double Mathematics::RombergIntegralTesting ::Solution(double input, const RombergIntegralTesting* userData) noexcept
{
    return input * userData->GetUserData() + 13;
}

double Mathematics::RombergIntegralTesting ::GetUserData() const noexcept
{
    return 6;
}
