///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:41)

#include "Vector2DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"

#include <random>

Mathematics::Vector2Testing::Vector2Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Vector2Testing)

void Mathematics::Vector2Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Vector2Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(BarycentricsTest);
}

void Mathematics::Vector2Testing::ConstructionTest() noexcept
{
}

void Mathematics::Vector2Testing::AccessTest()
{
    Vector2 vector0(6.0, 9.0);

    ASSERT_APPROXIMATE(vector0.GetX(), 6.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetY(), 9.0, 1e-10);
    ASSERT_FALSE(vector0.IsZero());

    const Vector2D vector1;
    ASSERT_TRUE(vector1.IsZero());

    vector0.ZeroOut();
    ASSERT_TRUE(vector0.IsZero());

    vector0.SetCoordinate(9.0, 6.0);
    ASSERT_APPROXIMATE(vector0.GetX(), 9.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetY(), 6.0, 1e-10);

    vector0.SetX(3.0);
    vector0.SetY(7.0);
    ASSERT_APPROXIMATE(vector0.GetX(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetY(), 7.0, 1e-10);

    vector0.SetX(3.0);
    vector0.SetY(4.0);

    ASSERT_FALSE(vector0.IsNormalize());

    vector0.Normalize();

    ASSERT_TRUE(vector0.IsNormalize());

    ASSERT_APPROXIMATE(vector0.GetX(), 0.6, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetY(), 0.8, 1e-10);
}

void Mathematics::Vector2Testing::CalculateTest()
{
    const Vector2F vector0(26.0f, 91.0f);

    Vector2F vector1 = -vector0;
    ASSERT_APPROXIMATE(vector1.GetX(), -26.0, 1e-8f);
    ASSERT_APPROXIMATE(vector1.GetY(), -91.0, 1e-8f);

    vector1[0] = 3.0f;
    vector1[1] = 7.0f;

    ASSERT_APPROXIMATE(vector1.GetX(), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1.GetY(), 7.0f, 1e-8f);

    const Vector2 vector2(6.0, 5.0);

    ASSERT_APPROXIMATE(vector2[0], 6.0, 1e-10);
    ASSERT_APPROXIMATE(vector2[1], 5.0, 1e-10);

    Vector2 vector3(9.0, 3.0);
    vector3 += vector2;
    ASSERT_APPROXIMATE(vector3[0], 15.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 8.0, 1e-10);

    Vector2 vector4 = vector2 + vector3;

    ASSERT_APPROXIMATE(vector4[0], 21.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[1], 13.0, 1e-10);

    vector4 -= vector3;

    ASSERT_APPROXIMATE(vector4[0], 6.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[1], 5.0, 1e-10);

    vector3 = vector4 - vector2;

    ASSERT_APPROXIMATE(vector3[0], 0.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 0.0, 1e-10);

    vector4 *= 6.0;

    ASSERT_APPROXIMATE(vector4[0], 36.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[1], 30.0, 1e-10);

    vector3 = 0.5 * vector4;

    ASSERT_APPROXIMATE(vector3[0], 18.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 15.0, 1e-10);

    vector3 = vector4 * 2.0;

    ASSERT_APPROXIMATE(vector3[0], 72.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 60.0, 1e-10);

    vector3 /= 2.0;

    ASSERT_APPROXIMATE(vector3[0], 36.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 30.0, 1e-10);

    vector4 = vector3 / 3.0;

    ASSERT_APPROXIMATE(vector4[0], 12.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[1], 10.0, 1e-10);
}

void Mathematics::Vector2Testing::BarycentricsTest()
{
    const Vector2 vector0(1.0, 0.0);
    const Vector2 vector1(0.0, 0.0);
    const Vector2 vector2(0.0, 1.0);

    const Vector2D::BarycentricCoordinates firstCoordinates = vector0.GetBarycentrics(vector0, vector1, vector2);

    ASSERT_TRUE(firstCoordinates.IsBarycentricCoordinatesValid());
    ASSERT_APPROXIMATE(firstCoordinates[0], 1.0, 1e-10);
    ASSERT_APPROXIMATE(firstCoordinates[1], 0.0, 1e-10);
    ASSERT_APPROXIMATE(firstCoordinates[2], 0.0, 1e-10);

    const Vector2D::BarycentricCoordinates secondCoordinates = vector1.GetBarycentrics(vector0, vector1, vector2);

    ASSERT_TRUE(secondCoordinates.IsBarycentricCoordinatesValid());
    ASSERT_APPROXIMATE(secondCoordinates[0], 0.0, 1e-10);
    ASSERT_APPROXIMATE(secondCoordinates[1], 1.0, 1e-10);
    ASSERT_APPROXIMATE(secondCoordinates[2], 0.0, 1e-10);

    const Vector2D::BarycentricCoordinates thirdCoordinates = vector2.GetBarycentrics(vector0, vector1, vector2);

    ASSERT_TRUE(thirdCoordinates.IsBarycentricCoordinatesValid());
    ASSERT_APPROXIMATE(thirdCoordinates[0], 0.0, 1e-10);
    ASSERT_APPROXIMATE(thirdCoordinates[1], 0.0, 1e-10);
    ASSERT_APPROXIMATE(thirdCoordinates[2], 1.0, 1e-10);

    const Vector2 vector3(0.1, 0.1);

    const Vector2D::BarycentricCoordinates fourthCoordinates = vector3.GetBarycentrics(vector0, vector1, vector2);

    ASSERT_TRUE(fourthCoordinates.IsBarycentricCoordinatesValid());
    ASSERT_APPROXIMATE(fourthCoordinates[0] + fourthCoordinates[1] + fourthCoordinates[2], 1.0, 1e-10);

    std::default_random_engine generator{ GetEngineRandomSeed() };

    const std::uniform_real<double> randomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const Vector2 vector4(randomDistribution(generator), randomDistribution(generator));

        const Vector2D::BarycentricCoordinates fifthCoordinates = vector4.GetBarycentrics(vector0, vector1, vector2);

        ASSERT_TRUE(fifthCoordinates.IsBarycentricCoordinatesValid());

        Vector2D difference[3]{ vector0 - vector2, vector1 - vector2, vector4 - vector2 };

        const double det = Vector2ToolsD::DotPerp(difference[0], difference[1]);

        const double bary0 = Vector2ToolsD::DotPerp(difference[2], difference[1]) / det;
        const double bary1 = Vector2ToolsD::DotPerp(difference[0], difference[2]) / det;
        const double bary2 = 1.0 - bary0 - bary1;

        ASSERT_TRUE(fifthCoordinates.IsBarycentricCoordinatesValid());
        ASSERT_APPROXIMATE(fifthCoordinates[0], bary0, 1e-10);
        ASSERT_APPROXIMATE(fifthCoordinates[1], bary1, 1e-10);
        ASSERT_APPROXIMATE(fifthCoordinates[2], bary2, 1e-10);
    }
}
