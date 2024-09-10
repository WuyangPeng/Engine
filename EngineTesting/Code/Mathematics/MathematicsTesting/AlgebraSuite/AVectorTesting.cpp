///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 13:28)

#include "AVectorTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Base/Float.h"

#include <random>

namespace Mathematics
{
    template class AVector<float>;
    template class AVector<double>;
}

Mathematics::AVectorTesting::AVectorTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, AVectorTesting)

void Mathematics::AVectorTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::AVectorTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(VectorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OtherCalculateTest);
}

void Mathematics::AVectorTesting::ConstructionTest()
{
    const Float3 tuple{ 3.0f, 5.0f, 9.0f };
    constexpr Vector3F vector{ 9.0f, 6.0f, 1.0f };

    AVectorF vector0{};

    ASSERT_APPROXIMATE(vector0[0], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector0[1], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector0[2], 0.0f, 1e-8f);

    AVectorF vector1{ 6.0f, 9.0f, 1.0f };

    ASSERT_APPROXIMATE(vector1[0], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1[1], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1[2], 1.0f, 1e-8f);

    AVectorF vector2{};

    ASSERT_APPROXIMATE(vector2[0], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector2[1], 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector2[2], 0.0f, 1e-8f);

    AVectorF vector3{ vector };

    ASSERT_APPROXIMATE(vector3[0], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector3[1], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector3[2], 1.0f, 1e-8f);

    AVectorF vector4{ vector3 };

    ASSERT_APPROXIMATE(vector4[0], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector4[1], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector4[2], 1.0f, 1e-8f);

    vector2 = vector1;

    ASSERT_APPROXIMATE(vector2[0], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector2[1], 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector2[2], 1.0f, 1e-8f);
}

void Mathematics::AVectorTesting::AccessTest() noexcept
{
}

void Mathematics::AVectorTesting::ArithmeticCalculateTest()
{
    constexpr AVectorF vector0{ 26.0f, 91.0f, 8.0f };

    auto vector1 = -vector0;
    ASSERT_APPROXIMATE(vector1[0], -26.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1[1], -91.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1[2], -8.0f, 1e-8f);

    vector1[0] = 3.0f;
    vector1[1] = 7.0f;
    vector1[2] = 17.0f;

    ASSERT_APPROXIMATE(vector1[0], 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1[1], 7.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1[2], 17.0f, 1e-8f);

    const AVectorD vector2{ 6.0, 5.0, 15.0 };

    ASSERT_APPROXIMATE(vector2[0], 6.0, 1e-10);
    ASSERT_APPROXIMATE(vector2[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(vector2[2], 15.0, 1e-10);

    AVectorD vector3{ 9.0, 3.0, 3.0 };
    vector3 += vector2;
    ASSERT_APPROXIMATE(vector3[0], 15.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 8.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[2], 18.0, 1e-10);

    auto vector4 = vector2 + vector3;

    ASSERT_APPROXIMATE(vector4[0], 21.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[1], 13.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[2], 33.0, 1e-10);

    vector4 -= vector3;

    ASSERT_APPROXIMATE(vector4[0], 6.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[2], 15.0, 1e-10);

    vector3 = vector4 - vector2;

    ASSERT_APPROXIMATE(vector3[0], 0.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 0.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[2], 0.0, 1e-10);

    vector4 *= 6.0;

    ASSERT_APPROXIMATE(vector4[0], 36.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[1], 30.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[2], 90.0, 1e-10);

    vector3 = 0.5 * vector4;

    ASSERT_APPROXIMATE(vector3[0], 18.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 15.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[2], 45.0, 1e-10);

    vector3 = vector4 * 2.0;

    ASSERT_APPROXIMATE(vector3[0], 72.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 60.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[2], 180.0, 1e-10);

    vector3 /= 2.0;

    ASSERT_APPROXIMATE(vector3[0], 36.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 30.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[2], 90.0, 1e-10);

    vector4 = vector3 / 3.0;

    ASSERT_APPROXIMATE(vector4[0], 12.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[1], 10.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[2], 30.0, 1e-10);
}

void Mathematics::AVectorTesting::VectorCalculateTest()
{
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution{ -100.0, 100.0 };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        AVectorD vector0{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

        AVectorD vector1{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

        auto dotProduct = vector0[0] * vector1[0] + vector0[1] * vector1[1] + vector0[2] * vector1[2];

        ASSERT_APPROXIMATE(Dot(vector0, vector1), dotProduct, 1e-10);

        AVectorD crossProduct{ vector0[1] * vector1[2] - vector0[2] * vector1[1],
                               vector0[2] * vector1[0] - vector0[0] * vector1[2],
                               vector0[0] * vector1[1] - vector0[1] * vector1[0] };

        auto testCross = Cross(vector0, vector1);

        ASSERT_TRUE(Approximate(testCross, crossProduct, 1e-10));

        crossProduct.Normalize();
        testCross = UnitCross(vector0, vector1);

        ASSERT_TRUE(Approximate(testCross, crossProduct, 1e-10));
    }

    AVectorF vector2{ 3.0f, 4.0f, 5.0f };

    ASSERT_APPROXIMATE(vector2.Length(), MathF::Sqrt(50.0f), 1e-8f);
    ASSERT_APPROXIMATE(vector2.SquaredLength(), 50.0f, 1e-8f);

    vector2.Normalize();

    ASSERT_APPROXIMATE(vector2[0], 3.0f / sqrt(50.0f), 1e-8f);
    ASSERT_APPROXIMATE(vector2[1], 4.0f / sqrt(50.0f), 1e-8f);
    ASSERT_APPROXIMATE(vector2[2], 5.0f / sqrt(50.0f), 1e-7f);
}

void Mathematics::AVectorTesting::OtherCalculateTest()
{
    std::default_random_engine randomEngine{ GetEngineRandomSeed() };
    std::uniform_real_distribution<double> randomDistribution{ -100.0, 100.0 };

    AVectorD vector0{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };
    AVectorD vector1{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

    AVectorD vector2{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

    std::vector<AVectorD> vectors{ vector0, vector1, vector2 };

    const auto orthonormalize0 = Orthonormalize(vector0, vector1, vector2);

    const auto orthonormalize1 = Orthonormalize(vectors);

    vector0.Normalize();
    auto dot0 = Dot(vector0, vector1);
    vector1 -= dot0 * vector0;
    vector1.Normalize();

    auto dot1 = Dot(vector1, vector2);
    dot0 = Dot(vector0, vector2);
    vector2 -= dot0 * vector0 + dot1 * vector1;
    vector2.Normalize();

    ASSERT_TRUE(Approximate(vector0, orthonormalize0.GetUVector(), 1e-10));
    ASSERT_TRUE(Approximate(vector1, orthonormalize0.GetVVector(), 1e-10));
    ASSERT_TRUE(Approximate(vector2, orthonormalize0.GetWVector(), 1e-10));
    ASSERT_TRUE(Approximate(vector0, orthonormalize1.GetUVector(), 1e-10));
    ASSERT_TRUE(Approximate(vector1, orthonormalize1.GetVVector(), 1e-10));
    ASSERT_TRUE(Approximate(vector2, orthonormalize1.GetWVector(), 1e-10));

    AVectorD vector3{ randomDistribution(randomEngine), randomDistribution(randomEngine), randomDistribution(randomEngine) };

    const auto orthonormalBasis0 = GenerateOrthonormalBasis(vector3);

    vector3.Normalize();

    const auto orthonormalBasis1 = GenerateComplementBasis(vector3);

    ASSERT_TRUE(Approximate(vector3, orthonormalBasis0.GetWVector(), 1e-10));
    ASSERT_TRUE(Approximate(vector3, orthonormalBasis1.GetWVector(), 1e-10));

    const auto vector4 = Cross(orthonormalBasis0.GetUVector(), orthonormalBasis0.GetVVector());

    ASSERT_TRUE(Approximate(orthonormalBasis0.GetWVector(), vector4, 1e-10));

    const auto vector5 = Cross(orthonormalBasis0.GetVVector(), orthonormalBasis0.GetWVector());

    ASSERT_TRUE(Approximate(orthonormalBasis0.GetUVector(), vector5, 1e-10));

    const auto vector6 = Cross(orthonormalBasis0.GetWVector(), orthonormalBasis0.GetUVector());

    ASSERT_TRUE(Approximate(orthonormalBasis0.GetVVector(), vector6));
}
