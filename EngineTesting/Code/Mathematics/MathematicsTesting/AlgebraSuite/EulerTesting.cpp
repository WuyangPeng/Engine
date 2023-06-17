///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:20)

#include "EulerTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/EulerDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"

#include <random>

#ifndef BUILDING_MATHEMATICS_STATIC

namespace Mathematics
{
    template class Euler<float>;
    template class Euler<double>;
}

#endif  // BUILDING_MATHEMATICS_STATIC

Mathematics::EulerTesting::EulerTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, EulerTesting)

void Mathematics::EulerTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::EulerTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(EulerXYZTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerXZYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerYXZTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerYZXTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerZXYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerZYXTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerXYXTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerXZXTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerYXYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerYZYTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerZXZTest);
    ASSERT_NOT_THROW_EXCEPTION_0(EulerZYZTest);
}

void Mathematics::EulerTesting::EulerXYZTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> angleDistribution0{ -MathD::GetPI(), MathD::GetPI() };
    const std::uniform_real<double> angleDistribution1{ -MathD::GetHalfPI(), MathD::GetHalfPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto xAngle = angleDistribution0(generator);
        const auto yAngle = angleDistribution1(generator);
        const auto zAngle = angleDistribution0(generator);

        Matrix3D matrix0{};

        matrix0.MakeEulerXYZ(xAngle, yAngle, zAngle);

        EulerD euler0 = matrix0.ExtractEulerXYZ();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), xAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), yAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), zAngle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Unique);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::XYZ);

        matrix0.MakeEulerXYZ(xAngle - zAngle, MathD::GetHalfPI(), zAngle);

        euler0 = matrix0.ExtractEulerXYZ();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), xAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), MathD::GetHalfPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Sum);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::XYZ);

        matrix0.MakeEulerXYZ(xAngle + zAngle, -MathD::GetHalfPI(), zAngle);

        euler0 = matrix0.ExtractEulerXYZ();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), xAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), -MathD::GetHalfPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Difference);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::XYZ);
    }
}

void Mathematics::EulerTesting::EulerXZYTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> angleDistribution0{ -MathD::GetPI(), MathD::GetPI() };
    const std::uniform_real<double> angleDistribution1{ -MathD::GetHalfPI(), MathD::GetHalfPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto xAngle = angleDistribution0(generator);
        const auto yAngle = angleDistribution0(generator);
        const auto zAngle = angleDistribution1(generator);

        Matrix3D matrix0;

        matrix0.MakeEulerXZY(xAngle, zAngle, yAngle);

        EulerD euler0 = matrix0.ExtractEulerXZY();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), xAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), yAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), zAngle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Unique);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::XZY);

        matrix0.MakeEulerXZY(xAngle + yAngle, MathD::GetHalfPI(), yAngle);

        euler0 = matrix0.ExtractEulerXZY();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), xAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), MathD::GetHalfPI(), 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Difference);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::XZY);

        matrix0.MakeEulerXZY(xAngle - yAngle, -MathD::GetHalfPI(), yAngle);

        euler0 = matrix0.ExtractEulerXZY();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), xAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), -MathD::GetHalfPI(), 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Sum);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::XZY);
    }
}

void Mathematics::EulerTesting::EulerYXZTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> angleDistribution0{ -MathD::GetPI(), MathD::GetPI() };
    const std::uniform_real<double> angleDistribution1{ -MathD::GetHalfPI(), MathD::GetHalfPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto xAngle = angleDistribution1(generator);
        const auto yAngle = angleDistribution0(generator);
        const auto zAngle = angleDistribution0(generator);

        Matrix3D matrix0;

        matrix0.MakeEulerYXZ(yAngle, xAngle, zAngle);

        EulerD euler0 = matrix0.ExtractEulerYXZ();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), xAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), yAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), zAngle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Unique);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::YXZ);

        matrix0.MakeEulerYXZ(yAngle + zAngle, MathD::GetHalfPI(), zAngle);

        euler0 = matrix0.ExtractEulerYXZ();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), MathD::GetHalfPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), yAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Difference);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::YXZ);

        matrix0.MakeEulerYXZ(yAngle - zAngle, -MathD::GetHalfPI(), zAngle);

        euler0 = matrix0.ExtractEulerYXZ();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), -MathD::GetHalfPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), yAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Sum);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::YXZ);
    }
}

void Mathematics::EulerTesting::EulerYZXTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> angleDistribution0{ -MathD::GetPI(), MathD::GetPI() };
    const std::uniform_real<double> angleDistribution1{ -MathD::GetHalfPI(), MathD::GetHalfPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto xAngle = angleDistribution0(generator);
        const auto yAngle = angleDistribution0(generator);
        const auto zAngle = angleDistribution1(generator);

        Matrix3D matrix0;

        matrix0.MakeEulerYZX(yAngle, zAngle, xAngle);

        EulerD euler0 = matrix0.ExtractEulerYZX();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), xAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), yAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), zAngle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Unique);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::YZX);

        matrix0.MakeEulerYZX(yAngle + xAngle, -MathD::GetHalfPI(), xAngle);

        euler0 = matrix0.ExtractEulerYZX();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), yAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), -MathD::GetHalfPI(), 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Difference);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::YZX);

        matrix0.MakeEulerYZX(yAngle - xAngle, MathD::GetHalfPI(), xAngle);

        euler0 = matrix0.ExtractEulerYZX();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), yAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), MathD::GetHalfPI(), 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Sum);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::YZX);
    }
}

void Mathematics::EulerTesting::EulerZXYTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> angleDistribution0{ -MathD::GetPI(), MathD::GetPI() };
    const std::uniform_real<double> angleDistribution1{ -MathD::GetHalfPI(), MathD::GetHalfPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto xAngle = angleDistribution1(generator);
        const auto yAngle = angleDistribution0(generator);
        const auto zAngle = angleDistribution0(generator);

        Matrix3D matrix0;

        matrix0.MakeEulerZXY(zAngle, xAngle, yAngle);

        EulerD euler0 = matrix0.ExtractEulerZXY();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), xAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), yAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), zAngle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Unique);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::ZXY);

        matrix0.MakeEulerZXY(zAngle + yAngle, -MathD::GetHalfPI(), yAngle);

        euler0 = matrix0.ExtractEulerZXY();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), -MathD::GetHalfPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), zAngle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Difference);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::ZXY);

        matrix0.MakeEulerZXY(zAngle - yAngle, MathD::GetHalfPI(), yAngle);

        euler0 = matrix0.ExtractEulerZXY();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), MathD::GetHalfPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), zAngle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Sum);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::ZXY);
    }
}

void Mathematics::EulerTesting::EulerZYXTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> angleDistribution0{ -MathD::GetPI(), MathD::GetPI() };
    const std::uniform_real<double> angleDistribution1{ -MathD::GetHalfPI(), MathD::GetHalfPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto xAngle = angleDistribution0(generator);
        const auto yAngle = angleDistribution1(generator);
        const auto zAngle = angleDistribution0(generator);

        Matrix3D matrix0;

        matrix0.MakeEulerZYX(zAngle, yAngle, xAngle);

        EulerD euler0 = matrix0.ExtractEulerZYX();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), xAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), yAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), zAngle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Unique);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::ZYX);

        matrix0.MakeEulerZYX(zAngle + xAngle, MathD::GetHalfPI(), xAngle);

        euler0 = matrix0.ExtractEulerZYX();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), MathD::GetHalfPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), zAngle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Difference);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::ZYX);

        matrix0.MakeEulerZYX(zAngle - xAngle, -MathD::GetHalfPI(), xAngle);

        euler0 = matrix0.ExtractEulerZYX();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), -MathD::GetHalfPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), zAngle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Sum);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::ZYX);
    }
}

void Mathematics::EulerTesting::EulerXYXTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> angleDistribution0{ -MathD::GetPI(), MathD::GetPI() };
    const std::uniform_real<double> angleDistribution1{ 0, MathD::GetPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto x0Angle = angleDistribution0(generator);
        const auto yAngle = angleDistribution1(generator);
        const auto x1Angle = angleDistribution0(generator);

        Matrix3D matrix0;

        matrix0.MakeEulerXYX(x0Angle, yAngle, x1Angle);

        EulerD euler0 = matrix0.ExtractEulerXYX();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), x0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), yAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetX1Angle(), x1Angle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Unique);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::XYX);

        matrix0.MakeEulerXYX(x0Angle - x1Angle, 0.0, x1Angle);

        euler0 = matrix0.ExtractEulerXYX();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), x0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetX1Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Sum);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::XYX);

        matrix0.MakeEulerXYX(x0Angle + x1Angle, MathD::GetPI(), x1Angle);

        euler0 = matrix0.ExtractEulerXYX();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), x0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), MathD::GetPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetX1Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Difference);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::XYX);
    }
}

void Mathematics::EulerTesting::EulerXZXTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> angleDistribution0{ -MathD::GetPI(), MathD::GetPI() };
    const std::uniform_real<double> angleDistribution1{ 0, MathD::GetPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto x0Angle = angleDistribution0(generator);
        const auto zAngle = angleDistribution1(generator);
        const auto x1Angle = angleDistribution0(generator);

        Matrix3D matrix0;

        matrix0.MakeEulerXZX(x0Angle, zAngle, x1Angle);

        EulerD euler0 = matrix0.ExtractEulerXZX();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), x0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), zAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetX1Angle(), x1Angle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Unique);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::XZX);

        matrix0.MakeEulerXZX(x0Angle + x1Angle, MathD::GetPI(), x1Angle);

        euler0 = matrix0.ExtractEulerXZX();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), x0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), MathD::GetPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetX1Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Difference);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::XZX);

        matrix0.MakeEulerXZX(x0Angle - x1Angle, 0.0, x1Angle);

        euler0 = matrix0.ExtractEulerXZX();

        ASSERT_APPROXIMATE(euler0.GetX0Angle(), x0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetX1Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Sum);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::XZX);
    }
}

void Mathematics::EulerTesting::EulerYXYTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> angleDistribution0{ -MathD::GetPI(), MathD::GetPI() };
    const std::uniform_real<double> angleDistribution1{ 0, MathD::GetPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto y0Angle = angleDistribution0(generator);
        const auto xAngle = angleDistribution1(generator);
        const auto y1Angle = angleDistribution0(generator);

        Matrix3D matrix0;

        matrix0.MakeEulerYXY(y0Angle, xAngle, y1Angle);

        EulerD euler0 = matrix0.ExtractEulerYXY();

        ASSERT_APPROXIMATE(euler0.GetY0Angle(), y0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetX0Angle(), xAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY1Angle(), y1Angle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Unique);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::YXY);

        matrix0.MakeEulerYXY(y0Angle + y1Angle, MathD::GetPI(), y1Angle);

        euler0 = matrix0.ExtractEulerYXY();

        ASSERT_APPROXIMATE(euler0.GetY0Angle(), y0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetX0Angle(), MathD::GetPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY1Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Difference);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::YXY);

        matrix0.MakeEulerYXY(y0Angle - y1Angle, 0.0, y1Angle);

        euler0 = matrix0.ExtractEulerYXY();

        ASSERT_APPROXIMATE(euler0.GetY0Angle(), y0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetX0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY1Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Sum);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::YXY);
    }
}

void Mathematics::EulerTesting::EulerYZYTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> angleDistribution0{ -MathD::GetPI(), MathD::GetPI() };
    const std::uniform_real<double> angleDistribution1{ 0, MathD::GetPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto y0Angle = angleDistribution0(generator);
        const auto zAngle = angleDistribution1(generator);
        const auto y1Angle = angleDistribution0(generator);

        Matrix3D matrix0;

        matrix0.MakeEulerYZY(y0Angle, zAngle, y1Angle);

        EulerD euler0 = matrix0.ExtractEulerYZY();

        ASSERT_APPROXIMATE(euler0.GetY0Angle(), y0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), zAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY1Angle(), y1Angle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Unique);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::YZY);

        matrix0.MakeEulerYZY(y0Angle + y1Angle, MathD::GetPI(), y1Angle);

        euler0 = matrix0.ExtractEulerYZY();

        ASSERT_APPROXIMATE(euler0.GetY0Angle(), y0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), MathD::GetPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY1Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Difference);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::YZY);

        matrix0.MakeEulerYZY(y0Angle - y1Angle, 0.0, y1Angle);

        euler0 = matrix0.ExtractEulerYZY();

        ASSERT_APPROXIMATE(euler0.GetY0Angle(), y0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY1Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Sum);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::YZY);
    }
}

void Mathematics::EulerTesting::EulerZXZTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> angleDistribution0{ -MathD::GetPI(), MathD::GetPI() };
    const std::uniform_real<double> angleDistribution1{ 0, MathD::GetPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto z0Angle = angleDistribution0(generator);
        const auto xAngle = angleDistribution1(generator);
        const auto z1Angle = angleDistribution0(generator);

        Matrix3D matrix0;

        matrix0.MakeEulerZXZ(z0Angle, xAngle, z1Angle);

        EulerD euler0 = matrix0.ExtractEulerZXZ();

        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), z0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetX0Angle(), xAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ1Angle(), z1Angle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Unique);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::ZXZ);

        matrix0.MakeEulerZXZ(z0Angle + z1Angle, MathD::GetPI(), z1Angle);

        euler0 = matrix0.ExtractEulerZXZ();

        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), z0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetX0Angle(), MathD::GetPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ1Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Difference);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::ZXZ);

        matrix0.MakeEulerZXZ(z0Angle - z1Angle, 0.0, z1Angle);

        euler0 = matrix0.ExtractEulerZXZ();

        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), z0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetX0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ1Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Sum);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::ZXZ);
    }
}

void Mathematics::EulerTesting::EulerZYZTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    const std::uniform_real<double> angleDistribution0{ -MathD::GetPI(), MathD::GetPI() };
    const std::uniform_real<double> angleDistribution1{ 0, MathD::GetPI() };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const auto z0Angle = angleDistribution0(generator);
        const auto yAngle = angleDistribution1(generator);
        const auto z1Angle = angleDistribution0(generator);

        Matrix3D matrix0;

        matrix0.MakeEulerZYZ(z0Angle, yAngle, z1Angle);

        EulerD euler0 = matrix0.ExtractEulerZYZ();

        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), z0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), yAngle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ1Angle(), z1Angle, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Unique);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::ZYZ);

        matrix0.MakeEulerZYZ(z0Angle + z1Angle, MathD::GetPI(), z1Angle);

        euler0 = matrix0.ExtractEulerZYZ();

        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), z0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), MathD::GetPI(), 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ1Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Difference);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::ZYZ);

        matrix0.MakeEulerZYZ(z0Angle - z1Angle, 0.0, z1Angle);

        euler0 = matrix0.ExtractEulerZYZ();

        ASSERT_APPROXIMATE(euler0.GetZ0Angle(), z0Angle, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetY0Angle(), 0.0, 1e-10);
        ASSERT_APPROXIMATE(euler0.GetZ1Angle(), 0.0, 1e-10);
        ASSERT_ENUM_EQUAL(euler0.GetType(), ExtractEulerResultType::Sum);
        ASSERT_ENUM_EQUAL(euler0.GetOrder(), ExtractEulerResultOrder::ZYZ);
    }
}