///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 14:33)

#include "Matrix4Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/APoint.h"
#include "Mathematics/Algebra/AVector.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4Detail.h"
#include "Mathematics/Algebra/Vector4ToolsDetail.h"

#include <random>

Mathematics::Matrix4Testing::Matrix4Testing(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, Matrix4Testing)

void Mathematics::Matrix4Testing::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::Matrix4Testing::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectionTest);
}

void Mathematics::Matrix4Testing::ConstructionTest()
{
    Matrix4F matrix0(MatrixInitType::Zero);

    ASSERT_APPROXIMATE(matrix0(0, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 3), 0.0f, 1e-8f);

    Matrix4F matrix1(MatrixInitType::Identity);

    ASSERT_APPROXIMATE(matrix1(0, 0), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 1), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 2), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 3), 1.0f, 1e-8f);

    Matrix4D matrix2(3.0, 6.0, 1.0, 2.0,
                     13.0, 16.0, 11.0, 12.0,
                     23.0, 26.0, 21.0, 22.0,
                     33.0, 63.0, 13.0, 23.0);

    ASSERT_APPROXIMATE(matrix2(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(0, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(0, 3), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 0), 13.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 1), 16.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 2), 11.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(1, 3), 12.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 0), 23.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 1), 26.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 2), 21.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(2, 3), 22.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(3, 0), 33.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(3, 1), 63.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(3, 2), 13.0, 1e-10);
    ASSERT_APPROXIMATE(matrix2(3, 3), 23.0, 1e-10);

    std::vector<double> doubleVector{ 6.0, 6.2, 9.0, 2.0, 32.0, 5.0, 6.1, 5.5, 3.0, 0.5, 9.99, 6.22, 3.33, 2.22, 3.22, 2.5 };

    Matrix4D matrix3(doubleVector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(matrix3(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(0, 1), 6.2, 1e-10);
    ASSERT_APPROXIMATE(matrix3(0, 2), 9.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(0, 3), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 0), 32.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 2), 6.1, 1e-10);
    ASSERT_APPROXIMATE(matrix3(1, 3), 5.5, 1e-10);
    ASSERT_APPROXIMATE(matrix3(2, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(matrix3(2, 1), 0.5, 1e-10);
    ASSERT_APPROXIMATE(matrix3(2, 2), 9.99, 1e-10);
    ASSERT_APPROXIMATE(matrix3(2, 3), 6.22, 1e-10);
    ASSERT_APPROXIMATE(matrix3(3, 0), 3.33, 1e-10);
    ASSERT_APPROXIMATE(matrix3(3, 1), 2.22, 1e-10);
    ASSERT_APPROXIMATE(matrix3(3, 2), 3.22, 1e-10);
    ASSERT_APPROXIMATE(matrix3(3, 3), 2.5, 1e-10);

    Matrix4D matrix4(doubleVector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(matrix4(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 1), 32.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 2), 3.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 3), 3.33, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 2), 0.5, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 3), 2.22, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 0), 9.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 1), 6.1, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 2), 9.99, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 3), 3.22, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 0), 2.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 1), 5.5, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 2), 6.22, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 3), 2.5, 1e-10);

    matrix4.MakeZero();

    ASSERT_APPROXIMATE(matrix4(0, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 3), 0.0, 1e-10);

    matrix4.MakeIdentity();

    ASSERT_APPROXIMATE(matrix4(0, 0), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(0, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(1, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(2, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(matrix4(3, 3), 1.0, 1e-10);
}

void Mathematics::Matrix4Testing::AccessTest()
{
    const Matrix4F matrix0(3.0f, 4.0f, 8.1f, 3.2f, 6.0f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.0f, 55.0f, 6.3f, 3.21f);

    ASSERT_APPROXIMATE(matrix0(0, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 1), 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 2), 8.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(0, 3), 3.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 1), 3.3f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 2), 4.4f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(1, 3), 5.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 0), 6.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 1), 7.7f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 2), 8.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(2, 3), 9.9f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 0), 10.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 1), 55.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 2), 6.3f, 1e-8f);
    ASSERT_APPROXIMATE(matrix0(3, 3), 3.21f, 1e-8f);

    Matrix4D matrix1(9.2, 1.0, 4.2, 5.2, 8.0, 5.5, 3.3, 4.4, 100.0, 5.6, 9.8, 7.3, 3.33, 4.44, 5.55, 6.66);

    ASSERT_APPROXIMATE(matrix1(0, 0), 9.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 2), 4.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(0, 3), 5.2, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 0), 8.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 1), 5.5, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 2), 3.3, 1e-10);
    ASSERT_APPROXIMATE(matrix1(1, 3), 4.4, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 0), 100.0, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 1), 5.6, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 2), 9.8, 1e-10);
    ASSERT_APPROXIMATE(matrix1(2, 3), 7.3, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 0), 3.33, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 1), 4.44, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 2), 5.55, 1e-10);
    ASSERT_APPROXIMATE(matrix1(3, 3), 6.66, 1e-10);
}

void Mathematics::Matrix4Testing::OperatorCalculateTest()
{
    const Matrix4F matrix0(3.0f, 4.0f, 8.1f, 3.2f,
                           13.0f, 14.0f, 18.1f, 13.2f,
                           23.0f, 24.0f, 28.1f, 23.2f,
                           33.0f, 34.0f, 38.1f, 33.2f);

    Matrix4F matrix1 = -matrix0;

    ASSERT_APPROXIMATE(matrix1(0, 0), -3.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 1), -4.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 2), -8.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(0, 3), -3.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 0), -13.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 1), -14.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 2), -18.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(1, 3), -13.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 0), -23.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 1), -24.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 2), -28.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(2, 3), -23.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 0), -33.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 1), -34.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 2), -38.1f, 1e-8f);
    ASSERT_APPROXIMATE(matrix1(3, 3), -33.2f, 1e-8f);

    Matrix4F matrix2(9.2f, 3.0f, 2.0f, 9.0f, 19.2f, 13.0f, 12.0f, 19.0f,
                     29.2f, 23.0f, 22.0f, 29.0f, 9.23f, 3.03f, 2.03f, 9.03f);

    matrix2 += matrix1;

    ASSERT_APPROXIMATE(matrix2(0, 0), 6.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 2), -6.1f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(0, 3), 5.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 0), 6.2f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(1, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 2), -6.1f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(1, 3), 5.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 0), 6.2f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(2, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 2), -6.1f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(2, 3), 5.8f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(3, 0), -23.77f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 1), -30.97f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 2), -36.07f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 3), -24.17f, 1e-5f);

    matrix2 -= matrix0;

    ASSERT_APPROXIMATE(matrix2(0, 0), 3.2f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -5.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 2), -14.2f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(0, 3), 2.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(1, 0), -6.8f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(1, 1), -15.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 2), -24.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 3), -7.4f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(2, 0), -16.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 1), -25.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 2), -34.2f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 3), -17.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(3, 0), -56.77f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 1), -64.97f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 2), -74.17f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 3), -57.37f, 1e-5f);

    matrix2 *= 6.0f;

    ASSERT_APPROXIMATE(matrix2(0, 0), 19.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -30.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 2), -85.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(0, 3), 15.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 0), -40.8f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(1, 1), -90.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 2), -145.2f, 1e-4f);
    ASSERT_APPROXIMATE(matrix2(1, 3), -44.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 0), -100.8f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 1), -150.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 2), -205.2f, 1e-4f);
    ASSERT_APPROXIMATE(matrix2(2, 3), -104.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(3, 0), -340.62f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 1), -389.82f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 2), -445.02f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 3), -344.22f, 1e-4f);

    matrix2 /= 2.0f;

    ASSERT_APPROXIMATE(matrix2(0, 0), 9.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix2(0, 1), -15.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(0, 2), -42.6f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(0, 3), 7.8f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 0), -20.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(1, 1), -45.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(1, 2), -72.6f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(1, 3), -22.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 0), -50.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 1), -75.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(2, 2), -102.6f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(2, 3), -52.2f, 1e-5f);
    ASSERT_APPROXIMATE(matrix2(3, 0), -170.31f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 1), -194.91f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 2), -222.51f, 1e-8f);
    ASSERT_APPROXIMATE(matrix2(3, 3), -172.11f, 1e-4f);

    Matrix4F matrix3 = matrix0 + matrix2;

    ASSERT_APPROXIMATE(matrix3(0, 0), 12.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix3(0, 1), -11.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 2), -34.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 3), 11.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 0), -7.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(1, 1), -31.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 2), -54.5f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(1, 3), -9.0f, 1e-6f);
    ASSERT_APPROXIMATE(matrix3(2, 0), -27.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(2, 1), -51.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 2), -74.5f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(2, 3), -29.0f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(3, 0), -137.31f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 1), -160.91f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 2), -184.41f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 3), -138.91f, 1e-4f);

    matrix3 = matrix0 - matrix2;

    ASSERT_APPROXIMATE(matrix3(0, 0), -6.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix3(0, 1), 19.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 2), 50.7f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(0, 3), -4.6f, 1e-6f);
    ASSERT_APPROXIMATE(matrix3(1, 0), 33.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(1, 1), 59.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 2), 90.7f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(1, 3), 35.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(2, 0), 73.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(2, 1), 99.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 2), 130.7f, 1e-4f);
    ASSERT_APPROXIMATE(matrix3(2, 3), 75.4f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(3, 0), 203.31f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 1), 228.91f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 2), 260.61f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 3), 205.31f, 1e-4f);

    matrix3 = matrix0 * 5.0f;

    ASSERT_APPROXIMATE(matrix3(0, 0), 15.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 1), 20.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 2), 40.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 3), 16.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 0), 65.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 1), 70.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 2), 90.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 3), 66.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 0), 115.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 1), 120.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 2), 140.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 3), 116.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 0), 165.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 1), 170.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 2), 190.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 3), 166.0f, 1e-8f);

    matrix3 = 3.0f * matrix0;

    ASSERT_APPROXIMATE(matrix3(0, 0), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 1), 12.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 2), 24.3f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(0, 3), 9.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 0), 39.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 1), 42.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 2), 54.3f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(1, 3), 39.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 0), 69.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 1), 72.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 2), 84.3f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 3), 69.6f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(3, 0), 99.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 1), 102.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 2), 114.3f, 1e-5f);
    ASSERT_APPROXIMATE(matrix3(3, 3), 99.6f, 1e-5f);

    matrix3 = matrix0 / (-2.0f);

    ASSERT_APPROXIMATE(matrix3(0, 0), -1.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 1), -2.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 2), -4.05f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(0, 3), -1.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 0), -6.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 1), -7.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 2), -9.05f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(1, 3), -6.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 0), -11.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 1), -12.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 2), -14.05f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(2, 3), -11.6f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 0), -16.5f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 1), -17.0f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 2), -19.05f, 1e-8f);
    ASSERT_APPROXIMATE(matrix3(3, 3), -16.6f, 1e-8f);

    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution{ -10.0f, 10.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Matrix4F matrix4(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        Matrix4F matrix5(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        Matrix4F matrix6(matrix5);

        matrix6 *= matrix4;

        const Matrix4F matrix31(matrix5(0, 0) * matrix4(0, 0) +
                                    matrix5(0, 1) * matrix4(1, 0) +
                                    matrix5(0, 2) * matrix4(2, 0) +
                                    matrix5(0, 3) * matrix4(3, 0),

                                matrix5(0, 0) * matrix4(0, 1) +
                                    matrix5(0, 1) * matrix4(1, 1) +
                                    matrix5(0, 2) * matrix4(2, 1) +
                                    matrix5(0, 3) * matrix4(3, 1),

                                matrix5(0, 0) * matrix4(0, 2) +
                                    matrix5(0, 1) * matrix4(1, 2) +
                                    matrix5(0, 2) * matrix4(2, 2) +
                                    matrix5(0, 3) * matrix4(3, 2),

                                matrix5(0, 0) * matrix4(0, 3) +
                                    matrix5(0, 1) * matrix4(1, 3) +
                                    matrix5(0, 2) * matrix4(2, 3) +
                                    matrix5(0, 3) * matrix4(3, 3),

                                matrix5(1, 0) * matrix4(0, 0) +
                                    matrix5(1, 1) * matrix4(1, 0) +
                                    matrix5(1, 2) * matrix4(2, 0) +
                                    matrix5(1, 3) * matrix4(3, 0),

                                matrix5(1, 0) * matrix4(0, 1) +
                                    matrix5(1, 1) * matrix4(1, 1) +
                                    matrix5(1, 2) * matrix4(2, 1) +
                                    matrix5(1, 3) * matrix4(3, 1),

                                matrix5(1, 0) * matrix4(0, 2) +
                                    matrix5(1, 1) * matrix4(1, 2) +
                                    matrix5(1, 2) * matrix4(2, 2) +
                                    matrix5(1, 3) * matrix4(3, 2),

                                matrix5(1, 0) * matrix4(0, 3) +
                                    matrix5(1, 1) * matrix4(1, 3) +
                                    matrix5(1, 2) * matrix4(2, 3) +
                                    matrix5(1, 3) * matrix4(3, 3),

                                matrix5(2, 0) * matrix4(0, 0) +
                                    matrix5(2, 1) * matrix4(1, 0) +
                                    matrix5(2, 2) * matrix4(2, 0) +
                                    matrix5(2, 3) * matrix4(3, 0),

                                matrix5(2, 0) * matrix4(0, 1) +
                                    matrix5(2, 1) * matrix4(1, 1) +
                                    matrix5(2, 2) * matrix4(2, 1) +
                                    matrix5(2, 3) * matrix4(3, 1),

                                matrix5(2, 0) * matrix4(0, 2) +
                                    matrix5(2, 1) * matrix4(1, 2) +
                                    matrix5(2, 2) * matrix4(2, 2) +
                                    matrix5(2, 3) * matrix4(3, 2),

                                matrix5(2, 0) * matrix4(0, 3) +
                                    matrix5(2, 1) * matrix4(1, 3) +
                                    matrix5(2, 2) * matrix4(2, 3) +
                                    matrix5(2, 3) * matrix4(3, 3),

                                matrix5(3, 0) * matrix4(0, 0) +
                                    matrix5(3, 1) * matrix4(1, 0) +
                                    matrix5(3, 2) * matrix4(2, 0) +
                                    matrix5(3, 3) * matrix4(3, 0),

                                matrix5(3, 0) * matrix4(0, 1) +
                                    matrix5(3, 1) * matrix4(1, 1) +
                                    matrix5(3, 2) * matrix4(2, 1) +
                                    matrix5(3, 3) * matrix4(3, 1),

                                matrix5(3, 0) * matrix4(0, 2) +
                                    matrix5(3, 1) * matrix4(1, 2) +
                                    matrix5(3, 2) * matrix4(2, 2) +
                                    matrix5(3, 3) * matrix4(3, 2),

                                matrix5(3, 0) * matrix4(0, 3) +
                                    matrix5(3, 1) * matrix4(1, 3) +
                                    matrix5(3, 2) * matrix4(2, 3) +
                                    matrix5(3, 3) * matrix4(3, 3));

        ASSERT_TRUE(Approximate(matrix31, matrix6, 1e-8f));

        matrix6 = matrix5 * matrix4;

        ASSERT_TRUE(Approximate(matrix31, matrix6, 1e-8f));

        Matrix4F::Vector4Type vector0(randomDistribution(generator),
                                      randomDistribution(generator),
                                      randomDistribution(generator),
                                      randomDistribution(generator));

        const Matrix4F::Vector4Type vector1 = matrix6 * vector0;
        const Matrix4F::Vector4Type vector2 = vector0 * matrix6;

        Matrix4F::Vector4Type vector3(matrix6(0, 0) * vector0[0] +
                                          matrix6(0, 1) * vector0[1] +
                                          matrix6(0, 2) * vector0[2] +
                                          matrix6(0, 3) * vector0[3],
                                      matrix6(1, 0) * vector0[0] +
                                          matrix6(1, 1) * vector0[1] +
                                          matrix6(1, 2) * vector0[2] +
                                          matrix6(1, 3) * vector0[3],
                                      matrix6(2, 0) * vector0[0] +
                                          matrix6(2, 1) * vector0[1] +
                                          matrix6(2, 2) * vector0[2] +
                                          matrix6(2, 3) * vector0[3],
                                      matrix6(3, 0) * vector0[0] +
                                          matrix6(3, 1) * vector0[1] +
                                          matrix6(3, 2) * vector0[2] +
                                          matrix6(3, 3) * vector0[3]);

        ASSERT_TRUE(Vector4ToolsF::Approximate(vector1, vector3, 1e-2f));

        vector3[0] = matrix6(0, 0) * vector0[0] +
                     matrix6(1, 0) * vector0[1] +
                     matrix6(2, 0) * vector0[2] +
                     matrix6(3, 0) * vector0[3];

        vector3[1] = matrix6(0, 1) * vector0[0] +
                     matrix6(1, 1) * vector0[1] +
                     matrix6(2, 1) * vector0[2] +
                     matrix6(3, 1) * vector0[3];

        vector3[2] = matrix6(0, 2) * vector0[0] +
                     matrix6(1, 2) * vector0[1] +
                     matrix6(2, 2) * vector0[2] +
                     matrix6(3, 2) * vector0[3];

        vector3[3] = matrix6(0, 3) * vector0[0] +
                     matrix6(1, 3) * vector0[1] +
                     matrix6(2, 3) * vector0[2] +
                     matrix6(3, 3) * vector0[3];

        ASSERT_TRUE(Vector4ToolsF::Approximate(vector2, vector3, 1e-2f));

        Matrix4F matrix7 = TransposeTimes(matrix4, matrix5);
        Matrix4F matrix8 = matrix4.Transpose() * matrix5;

        ASSERT_TRUE(Approximate(matrix7, matrix8, 1e-8f));

        matrix7 = TimesTranspose(matrix4, matrix5);
        matrix8 = matrix4 * matrix5.Transpose();

        ASSERT_TRUE(Approximate(matrix7, matrix8, 1e-8f));

        matrix7 = TransposeTimesTranspose(matrix4, matrix5);
        matrix8 = matrix4.Transpose() * matrix5.Transpose();

        ASSERT_TRUE(Approximate(matrix7, matrix8, 1e-8f));
    }
}

void Mathematics::Matrix4Testing::ArithmeticCalculateTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution{ -10.0f, 10.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        const Matrix4F::Vector4Type vector0(randomDistribution(generator),
                                            randomDistribution(generator),
                                            randomDistribution(generator),
                                            randomDistribution(generator));

        const Matrix4F::Vector4Type vector1(randomDistribution(generator),
                                            randomDistribution(generator),
                                            randomDistribution(generator),
                                            randomDistribution(generator));

        Matrix4F matrix0(randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator),
                         randomDistribution(generator));

        const float qForm = matrix0.QuadraticForm(vector0, vector1);

        const float testQFormValue = Vector4Tools<float>::DotProduct(vector0, matrix0 * vector1);

        ASSERT_APPROXIMATE(qForm, testQFormValue, 1e-2f);

        Matrix4F matrix1 = matrix0.Transpose();

        for (int row = 0; row < 4; ++row)
        {
            for (int colomn = 0; colomn < 4; ++colomn)
            {
                ASSERT_APPROXIMATE(matrix1(row, colomn), matrix0(colomn, row), 1e-8f);
            }
        }

        const Matrix3F matrix03(matrix1(1, 1), matrix1(1, 2), matrix1(1, 3),
                                matrix1(2, 1), matrix1(2, 2), matrix1(2, 3),
                                matrix1(3, 1), matrix1(3, 2), matrix1(3, 3));

        const Matrix3F matrix13(matrix1(1, 0), matrix1(1, 2), matrix1(1, 3),
                                matrix1(2, 0), matrix1(2, 2), matrix1(2, 3),
                                matrix1(3, 0), matrix1(3, 2), matrix1(3, 3));

        const Matrix3F matrix23(matrix1(1, 0), matrix1(1, 1), matrix1(1, 3),
                                matrix1(2, 0), matrix1(2, 1), matrix1(2, 3),
                                matrix1(3, 0), matrix1(3, 1), matrix1(3, 3));

        const Matrix3F matrix33(matrix1(1, 0), matrix1(1, 1), matrix1(1, 2),
                                matrix1(2, 0), matrix1(2, 1), matrix1(2, 2),
                                matrix1(3, 0), matrix1(3, 1), matrix1(3, 2));

        const float determinant = matrix1(0, 0) * matrix03.Determinant() -
                                  matrix1(0, 1) * matrix13.Determinant() +
                                  matrix1(0, 2) * matrix23.Determinant() -
                                  matrix1(0, 3) * matrix33.Determinant();

        ASSERT_APPROXIMATE(determinant, matrix1.Determinant(), 1e-2f);

        if (MathF::GetZeroTolerance() < MathF::FAbs(determinant))
        {
            const Matrix4F matrix2 = matrix1.Inverse();

            Matrix4F matrix3 = matrix1 * matrix2;

            ASSERT_TRUE(Approximate(matrix3, Matrix4F::GetIdentity(), 1e-3f));

            Matrix4F matrix4 = matrix1.Adjoint();
            matrix4 /= determinant;

            matrix3 = matrix4 * matrix1;

            ASSERT_TRUE(Approximate(matrix3, Matrix4F::GetIdentity(), 1e-4f));
        }
    }
}

void Mathematics::Matrix4Testing::ProjectionTest()
{
    std::default_random_engine generator{ GetEngineRandomSeed() };
    std::uniform_real_distribution<float> randomDistribution{ -100.0f, 100.0f };

    for (auto loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        Matrix3F::Vector3Type vector0(randomDistribution(generator),
                                      randomDistribution(generator),
                                      randomDistribution(generator));

        Matrix3F::Vector3Type vector1(randomDistribution(generator),
                                      randomDistribution(generator),
                                      randomDistribution(generator));

        Matrix3F::Vector3Type vector2(randomDistribution(generator),
                                      randomDistribution(generator),
                                      randomDistribution(generator));

        Matrix4F::Vector4Type vector3(randomDistribution(generator),
                                      randomDistribution(generator),
                                      randomDistribution(generator),
                                      1.0f);

        vector0.Normalize();
        vector2.Normalize();

        if (MathF::GetZeroTolerance() < Vector3ToolsF::DotProduct(vector0, vector2))
        {
            Matrix4F matrix0;
            matrix0.MakeObliqueProjection(vector0, vector1, vector2);

            Matrix4F::Vector4Type vector4 = matrix0 * vector3;

            vector4.ProjectionNormalization();

            const PlaneF firstPlane = PlaneF(AVectorF(vector0), APointF(vector1));

            // 转换后的点的平面上。
            const float distance = firstPlane.DistanceTo(APointF(vector4[0], vector4[1], vector4[2]));

            ASSERT_APPROXIMATE(distance, 0.0f, 1e-2f);

            // 原来的点与转换后的点的差是direction或-direction
            Matrix4F::Vector4Type vector5 = vector3 - vector4;

            vector5.Normalize();

            ASSERT_APPROXIMATE(vector5[3], 0.0f, 1e-8f);

            const Matrix3F::Vector3Type seventhVector(vector5);
            const Matrix3F::Vector3Type eighthVector(-seventhVector);

            ASSERT_TRUE(Vector3ToolsF::Approximate(seventhVector, vector2, 1e-5f) ||
                        Vector3ToolsF::Approximate(eighthVector, vector2, 1e-5f));
        }

        const Matrix3F::Vector3Type ninthVector(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        Matrix4F matrix1;
        matrix1.MakePerspectiveProjection(vector0, vector1, ninthVector);

        Matrix4F::Vector4Type tenthVector = matrix1 * vector3;

        tenthVector.ProjectionNormalization();

        const PlaneF secondPlane = PlaneF(AVectorF(vector0), APointF(vector1));

        // 原来的点与转换后的点和点eye在同一直线上
        Matrix4F::Vector4Type eleventhVector = vector3 - tenthVector;

        ASSERT_APPROXIMATE(eleventhVector[3], 0.0f, 1e-8f);

        eleventhVector.Normalize();

        Matrix4F::Vector3Type twelfthVector = ninthVector - Vector3F(tenthVector);

        twelfthVector.Normalize();

        matrix1.MakeReflection(vector0, vector1);

        Matrix4F::Vector4Type thirteenVector = matrix1 * vector3;

        const float firstDistance = secondPlane.DistanceTo(APointF(thirteenVector[0], thirteenVector[1], thirteenVector[2]));

        const float secondDistance = secondPlane.DistanceTo(APointF(vector3[0], vector3[1], vector3[2]));

        ASSERT_APPROXIMATE(firstDistance, -secondDistance, 1e-4f);

        // MakeFrustumMatrix44测试
        const float left = -MathF::FAbs(randomDistribution(generator));
        const float right = MathF::FAbs(randomDistribution(generator));
        const float bottom = -MathF::FAbs(randomDistribution(generator));
        const float top = MathF::FAbs(randomDistribution(generator));
        const float nearDistance = -MathF::FAbs(randomDistribution(generator));
        const float farDistance = MathF::FAbs(randomDistribution(generator));

        matrix1.MakeFrustumMatrix44(left, right, bottom, top, nearDistance, farDistance);

        ASSERT_APPROXIMATE(matrix1(0, 0), 2.0f * nearDistance / (right - left), 1e-5f);
        ASSERT_APPROXIMATE(matrix1(0, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(0, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(0, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(matrix1(1, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(1, 1), (2.0f * nearDistance) / (top - bottom), 1e-6f);
        ASSERT_APPROXIMATE(matrix1(1, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(1, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(matrix1(2, 0), (right + left) / (right - left), 1e-7f);
        ASSERT_APPROXIMATE(matrix1(2, 1), (top + bottom) / (top - bottom), 1e-7f);
        ASSERT_APPROXIMATE(matrix1(2, 2), -(farDistance + nearDistance) / (farDistance - nearDistance), 1e-7f);
        ASSERT_APPROXIMATE(matrix1(2, 3), -1.0f, 1e-8f);

        ASSERT_APPROXIMATE(matrix1(3, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(3, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(3, 2), (-2.0f * farDistance * nearDistance) / (farDistance - nearDistance), 1e-5f);
        ASSERT_APPROXIMATE(matrix1(3, 3), 0.0f, 1e-8f);

        // MakePerspectiveMatrix44测试
        constexpr float fieldOfViewY = 60.0f;
        constexpr float aspect = 0.6f;

        matrix1.MakePerspectiveMatrix44(fieldOfViewY, aspect, nearDistance, farDistance);

        float angle = fieldOfViewY / 2.0f;
        // 角度转换成弧度
        angle *= MathF::GetDegreeToRadian();

        const float cot = MathF::Cos(angle) / MathF::Sin(angle);

        ASSERT_APPROXIMATE(matrix1(0, 0), cot / aspect, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(0, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(0, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(0, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(matrix1(1, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(1, 1), cot, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(1, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(1, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(matrix1(2, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(2, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(2, 2), -(farDistance + nearDistance) / (farDistance - nearDistance), 1e-8f);
        ASSERT_APPROXIMATE(matrix1(2, 3), -1.0f, 1e-8f);

        ASSERT_APPROXIMATE(matrix1(3, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(3, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(3, 2), (-2.0f * farDistance * nearDistance) / (farDistance - nearDistance), 1e-8f);
        ASSERT_APPROXIMATE(matrix1(3, 3), 0.0f, 1e-8f);

        // MakeOrthoMatrix44测试
        matrix1.MakeOrthoMatrix44(left, right, bottom, top, nearDistance, farDistance);

        ASSERT_APPROXIMATE(matrix1(0, 0), 2.0f / (right - left), 1e-7f);
        ASSERT_APPROXIMATE(matrix1(0, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(0, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(0, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(matrix1(1, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(1, 1), 2.0f / (top - bottom), 1e-7f);
        ASSERT_APPROXIMATE(matrix1(1, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(1, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(matrix1(2, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(2, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(2, 2), -2.0f / (farDistance - nearDistance), 1e-8f);
        ASSERT_APPROXIMATE(matrix1(2, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(matrix1(3, 0), -(right + left) / (right - left), 1e-7f);
        ASSERT_APPROXIMATE(matrix1(3, 1), -(top + bottom) / (top - bottom), 1e-7f);
        ASSERT_APPROXIMATE(matrix1(3, 2), -(farDistance + nearDistance) / (farDistance - nearDistance), 1e-7f);
        ASSERT_APPROXIMATE(matrix1(3, 3), 1.0f, 1e-8f);

        // MakeOrthoNormalMatrix44测试
        vector0.Normalize();
        vector1.Normalize();
        vector2.Normalize();

        matrix1.MakeOrthoNormalMatrix44(vector0, vector1, vector2);

        ASSERT_APPROXIMATE(matrix1(0, 0), vector0[0], 1e-8f);
        ASSERT_APPROXIMATE(matrix1(0, 1), vector1[0], 1e-8f);
        ASSERT_APPROXIMATE(matrix1(0, 2), vector2[0], 1e-8f);
        ASSERT_APPROXIMATE(matrix1(0, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(matrix1(1, 0), vector0[1], 1e-8f);
        ASSERT_APPROXIMATE(matrix1(1, 1), vector1[1], 1e-8f);
        ASSERT_APPROXIMATE(matrix1(1, 2), vector2[1], 1e-8f);
        ASSERT_APPROXIMATE(matrix1(1, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(matrix1(2, 0), vector0[2], 1e-8f);
        ASSERT_APPROXIMATE(matrix1(2, 1), vector1[2], 1e-8f);
        ASSERT_APPROXIMATE(matrix1(2, 2), vector2[2], 1e-8f);
        ASSERT_APPROXIMATE(matrix1(2, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(matrix1(3, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(3, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(3, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(matrix1(3, 3), 1.0f, 1e-8f);
    }
}
