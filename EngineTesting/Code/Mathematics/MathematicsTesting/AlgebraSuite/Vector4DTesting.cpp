///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 23:07)

#include "Vector4DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

namespace Mathematics
{
    template class Vector4<float>;
    template class Vector4<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Vector4Testing)

void Mathematics::Vector4Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CalculateTest);
}

void Mathematics::Vector4Testing::ConstructionTest() noexcept
{
}

void Mathematics::Vector4Testing::AccessTest()
{
    Vector4D firstVector(6.0, 9.0, 4.0, 89.0);

    ASSERT_APPROXIMATE(firstVector.GetX(), 6.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetY(), 9.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetZ(), 4.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetW(), 89.0, 1e-10);
    ASSERT_FALSE(firstVector.IsZero());

    const Vector3D secondVector;
    ASSERT_TRUE(secondVector.IsZero());

    firstVector.ZeroOut();
    ASSERT_TRUE(firstVector.IsZero());

    firstVector.SetCoordinate(9.0, 6.0, 8.0, 1.0);
    ASSERT_APPROXIMATE(firstVector.GetX(), 9.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetY(), 6.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetZ(), 8.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetW(), 1.0, 1e-10);

    firstVector.SetX(3.0);
    firstVector.SetY(7.0);
    firstVector.SetZ(17.0);
    firstVector.SetW(8.0);
    ASSERT_APPROXIMATE(firstVector.GetX(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetY(), 7.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetZ(), 17.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetW(), 8.0, 1e-10);

    firstVector.SetX(6.0);
    firstVector.SetY(9.0);
    firstVector.SetZ(18.0);
    firstVector.SetW(3.0);
    firstVector.ProjectionNormalization();

    ASSERT_APPROXIMATE(firstVector.GetX(), 2.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetY(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetZ(), 6.0, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetW(), 1.0, 1e-10);

    firstVector.SetX(3.0);
    firstVector.SetY(4.0);
    firstVector.SetZ(1.0);
    firstVector.SetW(2.0);
    firstVector.Normalize();

    const double magnitude = MathD::Sqrt(30.0);

    ASSERT_APPROXIMATE(firstVector.GetX(), 3.0 / magnitude, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetY(), 4.0 / magnitude, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetZ(), 1.0 / magnitude, 1e-10);
    ASSERT_APPROXIMATE(firstVector.GetW(), 2.0 / magnitude, 1e-10);
}

void Mathematics::Vector4Testing::CalculateTest()
{
    const Vector4F firstVector(26.0f, 91.0f, 8.0f, -5.0f);

    Vector4F secondVector = -firstVector;
    ASSERT_APPROXIMATE(secondVector.GetX(), -26.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector.GetY(), -91.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector.GetZ(), -8.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector.GetW(), 5.0f, 1e-8f);

    secondVector[0] = 3.0f;
    secondVector[1] = 7.0f;
    secondVector[2] = 17.0f;
    secondVector[3] = -187.0f;

    ASSERT_APPROXIMATE(secondVector.GetX(), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector.GetY(), 7.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector.GetZ(), 17.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondVector.GetW(), -187.0f, 1e-8f);

    const Vector4D thirdVector(6.0, 5.0, 15.0, -8.0);

    ASSERT_APPROXIMATE(thirdVector[0], 6.0, 1e-10);
    ASSERT_APPROXIMATE(thirdVector[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(thirdVector[2], 15.0, 1e-10);
    ASSERT_APPROXIMATE(thirdVector[3], -8.0, 1e-10);

    Vector4D fourthVector(9.0, 3.0, 3.0, -7.0);
    fourthVector += thirdVector;
    ASSERT_APPROXIMATE(fourthVector[0], 15.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 8.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 18.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[3], -15.0, 1e-10);

    Vector4D fifthVector = thirdVector + fourthVector;

    ASSERT_APPROXIMATE(fifthVector[0], 21.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[1], 13.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[2], 33.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[3], -23.0, 1e-10);

    fifthVector -= fourthVector;

    ASSERT_APPROXIMATE(fifthVector[0], 6.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[2], 15.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[3], -8.0, 1e-10);

    fourthVector = fifthVector - thirdVector;

    ASSERT_APPROXIMATE(fourthVector[0], 0.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 0.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 0.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[3], 0.0, 1e-10);

    fifthVector *= 6.0;

    ASSERT_APPROXIMATE(fifthVector[0], 36.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[1], 30.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[2], 90.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[3], -48.0, 1e-10);

    fourthVector = 0.5 * fifthVector;

    ASSERT_APPROXIMATE(fourthVector[0], 18.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 15.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 45.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[3], -24.0, 1e-10);

    fourthVector = fifthVector * 2.0;

    ASSERT_APPROXIMATE(fourthVector[0], 72.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 60.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 180.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[3], -96.0, 1e-10);

    fourthVector /= 2.0;

    ASSERT_APPROXIMATE(fourthVector[0], 36.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[1], 30.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[2], 90.0, 1e-10);
    ASSERT_APPROXIMATE(fourthVector[3], -48.0, 1e-10);

    fifthVector = fourthVector / 3.0;

    ASSERT_APPROXIMATE(fifthVector[0], 12.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[1], 10.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[2], 30.0, 1e-10);
    ASSERT_APPROXIMATE(fifthVector[3], -16.0, 1e-10);
}
