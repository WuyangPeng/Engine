///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:44)

#include "Vector4DTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/Vector3.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

namespace Mathematics
{
    template class Vector4<float>;
    template class Vector4<double>;
}

Mathematics::Vector4Testing::Vector4Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Vector4Testing)

void Mathematics::Vector4Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

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
    Vector4D vector0(6.0, 9.0, 4.0, 89.0);

    ASSERT_APPROXIMATE(vector0.GetX(), 6.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetY(), 9.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetZ(), 4.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetW(), 89.0, 1e-10);
    ASSERT_FALSE(vector0.IsZero());

    const Vector3D vector1;
    ASSERT_TRUE(vector1.IsZero());

    vector0.ZeroOut();
    ASSERT_TRUE(vector0.IsZero());

    vector0.SetCoordinate(9.0, 6.0, 8.0, 1.0);
    ASSERT_APPROXIMATE(vector0.GetX(), 9.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetY(), 6.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetZ(), 8.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetW(), 1.0, 1e-10);

    vector0.SetX(3.0);
    vector0.SetY(7.0);
    vector0.SetZ(17.0);
    vector0.SetW(8.0);
    ASSERT_APPROXIMATE(vector0.GetX(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetY(), 7.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetZ(), 17.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetW(), 8.0, 1e-10);

    vector0.SetX(6.0);
    vector0.SetY(9.0);
    vector0.SetZ(18.0);
    vector0.SetW(3.0);
    vector0.ProjectionNormalization();

    ASSERT_APPROXIMATE(vector0.GetX(), 2.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetY(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetZ(), 6.0, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetW(), 1.0, 1e-10);

    vector0.SetX(3.0);
    vector0.SetY(4.0);
    vector0.SetZ(1.0);
    vector0.SetW(2.0);
    vector0.Normalize();

    const double magnitude = MathD::Sqrt(30.0);

    ASSERT_APPROXIMATE(vector0.GetX(), 3.0 / magnitude, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetY(), 4.0 / magnitude, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetZ(), 1.0 / magnitude, 1e-10);
    ASSERT_APPROXIMATE(vector0.GetW(), 2.0 / magnitude, 1e-10);
}

void Mathematics::Vector4Testing::CalculateTest()
{
    const Vector4F vector0(26.0f, 91.0f, 8.0f, -5.0f);

    Vector4F vector1 = -vector0;
    ASSERT_APPROXIMATE(vector1.GetX(), -26.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1.GetY(), -91.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1.GetZ(), -8.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1.GetW(), 5.0f, 1e-8f);

    vector1[0] = 3.0f;
    vector1[1] = 7.0f;
    vector1[2] = 17.0f;
    vector1[3] = -187.0f;

    ASSERT_APPROXIMATE(vector1.GetX(), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1.GetY(), 7.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1.GetZ(), 17.0f, 1e-8f);
    ASSERT_APPROXIMATE(vector1.GetW(), -187.0f, 1e-8f);

    const Vector4D vector2(6.0, 5.0, 15.0, -8.0);

    ASSERT_APPROXIMATE(vector2[0], 6.0, 1e-10);
    ASSERT_APPROXIMATE(vector2[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(vector2[2], 15.0, 1e-10);
    ASSERT_APPROXIMATE(vector2[3], -8.0, 1e-10);

    Vector4D vector3(9.0, 3.0, 3.0, -7.0);
    vector3 += vector2;
    ASSERT_APPROXIMATE(vector3[0], 15.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 8.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[2], 18.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[3], -15.0, 1e-10);

    Vector4D vector4 = vector2 + vector3;

    ASSERT_APPROXIMATE(vector4[0], 21.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[1], 13.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[2], 33.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[3], -23.0, 1e-10);

    vector4 -= vector3;

    ASSERT_APPROXIMATE(vector4[0], 6.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[1], 5.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[2], 15.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[3], -8.0, 1e-10);

    vector3 = vector4 - vector2;

    ASSERT_APPROXIMATE(vector3[0], 0.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 0.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[2], 0.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[3], 0.0, 1e-10);

    vector4 *= 6.0;

    ASSERT_APPROXIMATE(vector4[0], 36.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[1], 30.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[2], 90.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[3], -48.0, 1e-10);

    vector3 = 0.5 * vector4;

    ASSERT_APPROXIMATE(vector3[0], 18.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 15.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[2], 45.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[3], -24.0, 1e-10);

    vector3 = vector4 * 2.0;

    ASSERT_APPROXIMATE(vector3[0], 72.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 60.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[2], 180.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[3], -96.0, 1e-10);

    vector3 /= 2.0;

    ASSERT_APPROXIMATE(vector3[0], 36.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[1], 30.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[2], 90.0, 1e-10);
    ASSERT_APPROXIMATE(vector3[3], -48.0, 1e-10);

    vector4 = vector3 / 3.0;

    ASSERT_APPROXIMATE(vector4[0], 12.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[1], 10.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[2], 30.0, 1e-10);
    ASSERT_APPROXIMATE(vector4[3], -16.0, 1e-10);
}
