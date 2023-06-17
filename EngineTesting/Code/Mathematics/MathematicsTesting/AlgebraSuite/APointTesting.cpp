///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 11:16)

#include "APointTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Base/Float.h"

#include <random>

namespace Mathematics
{
    template class APoint<float>;
    template class APoint<double>;
}

Mathematics::APointTesting::APointTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, APointTesting)

void Mathematics::APointTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::APointTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
}

void Mathematics::APointTesting::ConstructionTest()
{
    const Float3 tuple{ 3.0f, 5.0f, 9.0f };
    constexpr Vector3F vector{ 9.0f, 6.0f, 1.0f };

    APointF point0;

    ASSERT_APPROXIMATE(point0[0], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[1], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[2], 0.0f, 1e-8f);

    APointF point1{ 6.0f, 9.0f, 1.0f };

    ASSERT_APPROXIMATE(point1[0], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(point1[1], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(point1[2], 1.0f, 1e-8f);

    APointF point2{};

    ASSERT_APPROXIMATE(point2[0], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(point2[1], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(point2[2], 0.0f, 1e-8f);

    APointF point3{ vector };

    ASSERT_APPROXIMATE(point3[0], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(point3[1], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(point3[2], 1.0f, 1e-8f);

    const APointF point4{ point3 };

    ASSERT_APPROXIMATE(point4[0], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(point4[1], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(point4[2], 1.0f, 1e-8f);

    point2 = point1;

    ASSERT_APPROXIMATE(point2[0], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(point2[1], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(point2[2], 1.0f, 1e-8f);
}

void Mathematics::APointTesting::AccessTest() noexcept
{
}

void Mathematics::APointTesting::CalculateTest()
{
    APointF point0{ 6.1f, 3.0f, 8.2f };
    constexpr AVectorF point1{ 16.1f, 23.0f, 18.2f };

    point0 += point1;

    ASSERT_APPROXIMATE(point0[0], 22.2f, 1e-8f);
    ASSERT_APPROXIMATE(point0[1], 26.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[2], 26.4f, 1e-5f);

    constexpr AVectorF point2{ 22.1f, 123.0f, 118.2f };

    point0 -= point2;

    ASSERT_APPROXIMATE(point0[0], 0.1f, 1e-6f);
    ASSERT_APPROXIMATE(point0[1], -97.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[2], -91.8f, 1e-5f);

    APointF point3{ 26.1f, 31.0f, 8.22f };

    point0 += point3;

    ASSERT_APPROXIMATE(point0[0], 26.2f, 1e-8f);
    ASSERT_APPROXIMATE(point0[1], -66.0f, 1e-8f);
    ASSERT_APPROXIMATE(point0[2], -83.58f, 1e-5f);

    constexpr APointF point4{ 26.3f, -66.1f, -83.57f };

    point0 -= point4;

    ASSERT_APPROXIMATE(point0[0], -0.1f, 1e-5f);
    ASSERT_APPROXIMATE(point0[1], 0.1f, 1e-5f);
    ASSERT_APPROXIMATE(point0[2], -0.01f, 1e-5f);

    point0 *= 0.7f;

    ASSERT_APPROXIMATE(point0[0], -0.07f, 1e-5f);
    ASSERT_APPROXIMATE(point0[1], 0.07f, 1e-5f);
    ASSERT_APPROXIMATE(point0[2], -0.007f, 1e-5f);

    point0 /= 0.1f;

    ASSERT_APPROXIMATE(point0[0], -0.7f, 1e-4f);
    ASSERT_APPROXIMATE(point0[1], 0.7f, 1e-4f);
    ASSERT_APPROXIMATE(point0[2], -0.07f, 1e-4f);

    point3 = -point0;

    ASSERT_APPROXIMATE(point3[0], 0.7f, 1e-4f);
    ASSERT_APPROXIMATE(point3[1], -0.7f, 1e-4f);
    ASSERT_APPROXIMATE(point3[2], 0.07f, 1e-4f);

    auto point5 = point0 - point3;

    ASSERT_APPROXIMATE(point5[0], -1.4f, 1e-4f);
    ASSERT_APPROXIMATE(point5[1], 1.4f, 1e-4f);
    ASSERT_APPROXIMATE(point5[2], -0.14f, 1e-4f);

    auto point6 = point0 + point5;

    ASSERT_APPROXIMATE(point6[0], -2.1f, 1e-4f);
    ASSERT_APPROXIMATE(point6[1], 2.1f, 1e-4f);
    ASSERT_APPROXIMATE(point6[2], -0.21f, 1e-3f);

    point6 = point0 - point5;

    ASSERT_APPROXIMATE(point6[0], 0.7f, 1e-4f);
    ASSERT_APPROXIMATE(point6[1], -0.7f, 1e-4f);
    ASSERT_APPROXIMATE(point6[2], 0.07f, 1e-4f);

    point6 = point3 + point4;

    ASSERT_APPROXIMATE(point6[0], 27.0f, 1e-4f);
    ASSERT_APPROXIMATE(point6[1], -66.8f, 1e-4f);
    ASSERT_APPROXIMATE(point6[2], -83.5f, 1e-4f);

    point6 = point3 * 2.0f;

    ASSERT_APPROXIMATE(point6[0], 1.4f, 1e-4f);
    ASSERT_APPROXIMATE(point6[1], -1.4f, 1e-4f);
    ASSERT_APPROXIMATE(point6[2], 0.14f, 1e-4f);

    point6 = point3 / 0.5f;

    ASSERT_APPROXIMATE(point6[0], 1.4f, 1e-4f);
    ASSERT_APPROXIMATE(point6[1], -1.4f, 1e-4f);
    ASSERT_APPROXIMATE(point6[2], 0.14f, 1e-4f);

    point6 = 2.0f * point3;

    ASSERT_APPROXIMATE(point6[0], 1.4f, 1e-4f);
    ASSERT_APPROXIMATE(point6[1], -1.4f, 1e-4f);
    ASSERT_APPROXIMATE(point6[2], 0.14f, 1e-4f);

    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    const std::uniform_real randomDistribution{ -100.0f, 100.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        APointF point7{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

        AVectorF point8{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

        auto dotProduct = point7[0] * point8[0] + point7[1] * point8[1] + point7[2] * point8[2];

        ASSERT_APPROXIMATE(Dot(point7, point8), dotProduct, 1e-10f);

        const auto sixthPoint = point7 + APointF{ 0.001f, 0.001f, 0.001f };

        ASSERT_TRUE(Approximate(point7, point7, 1e-10f));
        ASSERT_TRUE(Approximate(point7, sixthPoint, 1e-2f));
        ASSERT_FALSE(Approximate(point7, sixthPoint, 1e-4f));

        ASSERT_TRUE(Approximate(point7, point7));
    }
}
