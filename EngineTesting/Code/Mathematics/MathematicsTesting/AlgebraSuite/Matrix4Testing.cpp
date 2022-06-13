///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:00)

#include "Matrix4Testing.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
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

using std::default_random_engine;
using std::uniform_real;
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Matrix4Testing)

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
    Matrix4F firstMatrix(MatrixInitType::Zero);

    ASSERT_APPROXIMATE(firstMatrix(0, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(0, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(0, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(3, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(3, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(3, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(3, 3), 0.0f, 1e-8f);

    Matrix4F secondMatrix(MatrixInitType::Identity);

    ASSERT_APPROXIMATE(secondMatrix(0, 0), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(0, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(0, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 1), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 2), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(3, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(3, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(3, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(3, 3), 1.0f, 1e-8f);

    Matrix4D thirdMatrix(3.0, 6.0, 1.0, 2.0,
                         13.0, 16.0, 11.0, 12.0,
                         23.0, 26.0, 21.0, 22.0,
                         33.0, 63.0, 13.0, 23.0);

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(0, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(0, 3), 2.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), 13.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), 16.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(1, 2), 11.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(1, 3), 12.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(2, 0), 23.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(2, 1), 26.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(2, 2), 21.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(2, 3), 22.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(3, 0), 33.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(3, 1), 63.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(3, 2), 13.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(3, 3), 23.0, 1e-10);

    vector<double> doubleVector{ 6.0, 6.2, 9.0, 2.0, 32.0, 5.0, 6.1, 5.5, 3.0, 0.5, 9.99, 6.22, 3.33, 2.22, 3.22, 2.5 };

    Matrix4D fourthMatrix(doubleVector, MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(fourthMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(0, 1), 6.2, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(0, 2), 9.0, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(0, 3), 2.0, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(1, 0), 32.0, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(1, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(1, 2), 6.1, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(1, 3), 5.5, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(2, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(2, 1), 0.5, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(2, 2), 9.99, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(2, 3), 6.22, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(3, 0), 3.33, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(3, 1), 2.22, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(3, 2), 3.22, 1e-10);
    ASSERT_APPROXIMATE(fourthMatrix(3, 3), 2.5, 1e-10);

    Matrix4D fifthMatrix(doubleVector, MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(fifthMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(0, 1), 32.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(0, 2), 3.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(0, 3), 3.33, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 2), 0.5, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 3), 2.22, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 0), 9.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 1), 6.1, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 2), 9.99, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 3), 3.22, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(3, 0), 2.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(3, 1), 5.5, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(3, 2), 6.22, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(3, 3), 2.5, 1e-10);

    fifthMatrix.MakeZero();

    ASSERT_APPROXIMATE(fifthMatrix(0, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(0, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(3, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(3, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(3, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(3, 3), 0.0, 1e-10);

    fifthMatrix.MakeIdentity();

    ASSERT_APPROXIMATE(fifthMatrix(0, 0), 1.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(0, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(1, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(2, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(3, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(3, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(3, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(fifthMatrix(3, 3), 1.0, 1e-10);
}

void Mathematics::Matrix4Testing::AccessTest()
{
    const Matrix4F firstMatrix(3.0f, 4.0f, 8.1f, 3.2f, 6.0f, 3.3f, 4.4f, 5.5f, 6.6f, 7.7f, 8.8f, 9.9f, 10.0f, 55.0f, 6.3f, 3.21f);

    ASSERT_APPROXIMATE(firstMatrix(0, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(0, 1), 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(0, 2), 8.1f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(0, 3), 3.2f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 1), 3.3f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 2), 4.4f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(1, 3), 5.5f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 0), 6.6f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 1), 7.7f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 2), 8.8f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(2, 3), 9.9f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(3, 0), 10.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(3, 1), 55.0f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(3, 2), 6.3f, 1e-8f);
    ASSERT_APPROXIMATE(firstMatrix(3, 3), 3.21f, 1e-8f);

    Matrix4D secondMatrix(9.2, 1.0, 4.2, 5.2, 8.0, 5.5, 3.3, 4.4, 100.0, 5.6, 9.8, 7.3, 3.33, 4.44, 5.55, 6.66);

    ASSERT_APPROXIMATE(secondMatrix(0, 0), 9.2, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 2), 4.2, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 3), 5.2, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 0), 8.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 1), 5.5, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 2), 3.3, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 3), 4.4, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 0), 100.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 1), 5.6, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 2), 9.8, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 3), 7.3, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 0), 3.33, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 1), 4.44, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 2), 5.55, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 3), 6.66, 1e-10);
}

void Mathematics::Matrix4Testing::OperatorCalculateTest()
{
    const Matrix4F firstMatrix(3.0f, 4.0f, 8.1f, 3.2f,
                               13.0f, 14.0f, 18.1f, 13.2f,
                               23.0f, 24.0f, 28.1f, 23.2f,
                               33.0f, 34.0f, 38.1f, 33.2f);

    Matrix4F secondMatrix = -firstMatrix;

    ASSERT_APPROXIMATE(secondMatrix(0, 0), -3.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), -4.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(0, 2), -8.1f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(0, 3), -3.2f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 0), -13.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 1), -14.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 2), -18.1f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(1, 3), -13.2f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 0), -23.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 1), -24.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 2), -28.1f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(2, 3), -23.2f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(3, 0), -33.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(3, 1), -34.0f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(3, 2), -38.1f, 1e-8f);
    ASSERT_APPROXIMATE(secondMatrix(3, 3), -33.2f, 1e-8f);

    Matrix4F thirdMatrix(9.2f, 3.0f, 2.0f, 9.0f, 19.2f, 13.0f, 12.0f, 19.0f,
                         29.2f, 23.0f, 22.0f, 29.0f, 9.23f, 3.03f, 2.03f, 9.03f);

    thirdMatrix += secondMatrix;

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 6.2f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 2), -6.1f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 3), 5.8f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), 6.2f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 2), -6.1f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 3), 5.8f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 0), 6.2f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 1), -1.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 2), -6.1f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 3), 5.8f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 0), -23.77f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 1), -30.97f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 2), -36.07f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 3), -24.17f, 1e-5f);

    thirdMatrix -= firstMatrix;

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 3.2f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), -5.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 2), -14.2f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 3), 2.6f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), -6.8f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), -15.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 2), -24.2f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 3), -7.4f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 0), -16.8f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 1), -25.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 2), -34.2f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 3), -17.4f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 0), -56.77f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 1), -64.97f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 2), -74.17f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 3), -57.37f, 1e-5f);

    thirdMatrix *= 6.0f;

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 19.2f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), -30.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 2), -85.2f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 3), 15.6f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), -40.8f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), -90.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 2), -145.2f, 1e-4f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 3), -44.4f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 0), -100.8f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 1), -150.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 2), -205.2f, 1e-4f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 3), -104.4f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 0), -340.62f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 1), -389.82f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 2), -445.02f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 3), -344.22f, 1e-4f);

    thirdMatrix /= 2.0f;

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 9.6f, 1e-6f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), -15.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 2), -42.6f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(0, 3), 7.8f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), -20.4f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), -45.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 2), -72.6f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(1, 3), -22.2f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 0), -50.4f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 1), -75.0f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 2), -102.6f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(2, 3), -52.2f, 1e-5f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 0), -170.31f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 1), -194.91f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 2), -222.51f, 1e-8f);
    ASSERT_APPROXIMATE(thirdMatrix(3, 3), -172.11f, 1e-4f);

    Matrix4F fourthMatrix = firstMatrix + thirdMatrix;

    ASSERT_APPROXIMATE(fourthMatrix(0, 0), 12.6f, 1e-6f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 1), -11.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 2), -34.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 3), 11.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 0), -7.4f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 1), -31.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 2), -54.5f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 3), -9.0f, 1e-6f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 0), -27.4f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 1), -51.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 2), -74.5f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 3), -29.0f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 0), -137.31f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 1), -160.91f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 2), -184.41f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 3), -138.91f, 1e-4f);

    fourthMatrix = firstMatrix - thirdMatrix;

    ASSERT_APPROXIMATE(fourthMatrix(0, 0), -6.6f, 1e-6f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 1), 19.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 2), 50.7f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 3), -4.6f, 1e-6f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 0), 33.4f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 1), 59.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 2), 90.7f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 3), 35.4f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 0), 73.4f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 1), 99.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 2), 130.7f, 1e-4f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 3), 75.4f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 0), 203.31f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 1), 228.91f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 2), 260.61f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 3), 205.31f, 1e-4f);

    fourthMatrix = firstMatrix * 5.0f;

    ASSERT_APPROXIMATE(fourthMatrix(0, 0), 15.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 1), 20.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 2), 40.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 3), 16.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 0), 65.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 1), 70.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 2), 90.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 3), 66.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 0), 115.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 1), 120.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 2), 140.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 3), 116.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 0), 165.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 1), 170.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 2), 190.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 3), 166.0f, 1e-8f);

    fourthMatrix = 3.0f * firstMatrix;

    ASSERT_APPROXIMATE(fourthMatrix(0, 0), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 1), 12.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 2), 24.3f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 3), 9.6f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 0), 39.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 1), 42.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 2), 54.3f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 3), 39.6f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 0), 69.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 1), 72.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 2), 84.3f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 3), 69.6f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 0), 99.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 1), 102.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 2), 114.3f, 1e-5f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 3), 99.6f, 1e-5f);

    fourthMatrix = firstMatrix / (-2.0f);

    ASSERT_APPROXIMATE(fourthMatrix(0, 0), -1.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 1), -2.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 2), -4.05f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(0, 3), -1.6f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 0), -6.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 1), -7.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 2), -9.05f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(1, 3), -6.6f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 0), -11.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 1), -12.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 2), -14.05f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(2, 3), -11.6f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 0), -16.5f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 1), -17.0f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 2), -19.05f, 1e-8f);
    ASSERT_APPROXIMATE(fourthMatrix(3, 3), -16.6f, 1e-8f);

    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -10.0f, 10.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Matrix4F fifthMatrix(randomDistribution(generator),
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

        Matrix4F sixthMatrix(randomDistribution(generator),
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

        Matrix4F seventhMatrix(sixthMatrix);

        seventhMatrix *= fifthMatrix;

        const Matrix4F fourthMatrix1(sixthMatrix(0, 0) * fifthMatrix(0, 0) +
                                         sixthMatrix(0, 1) * fifthMatrix(1, 0) +
                                         sixthMatrix(0, 2) * fifthMatrix(2, 0) +
                                         sixthMatrix(0, 3) * fifthMatrix(3, 0),

                                     sixthMatrix(0, 0) * fifthMatrix(0, 1) +
                                         sixthMatrix(0, 1) * fifthMatrix(1, 1) +
                                         sixthMatrix(0, 2) * fifthMatrix(2, 1) +
                                         sixthMatrix(0, 3) * fifthMatrix(3, 1),

                                     sixthMatrix(0, 0) * fifthMatrix(0, 2) +
                                         sixthMatrix(0, 1) * fifthMatrix(1, 2) +
                                         sixthMatrix(0, 2) * fifthMatrix(2, 2) +
                                         sixthMatrix(0, 3) * fifthMatrix(3, 2),

                                     sixthMatrix(0, 0) * fifthMatrix(0, 3) +
                                         sixthMatrix(0, 1) * fifthMatrix(1, 3) +
                                         sixthMatrix(0, 2) * fifthMatrix(2, 3) +
                                         sixthMatrix(0, 3) * fifthMatrix(3, 3),

                                     sixthMatrix(1, 0) * fifthMatrix(0, 0) +
                                         sixthMatrix(1, 1) * fifthMatrix(1, 0) +
                                         sixthMatrix(1, 2) * fifthMatrix(2, 0) +
                                         sixthMatrix(1, 3) * fifthMatrix(3, 0),

                                     sixthMatrix(1, 0) * fifthMatrix(0, 1) +
                                         sixthMatrix(1, 1) * fifthMatrix(1, 1) +
                                         sixthMatrix(1, 2) * fifthMatrix(2, 1) +
                                         sixthMatrix(1, 3) * fifthMatrix(3, 1),

                                     sixthMatrix(1, 0) * fifthMatrix(0, 2) +
                                         sixthMatrix(1, 1) * fifthMatrix(1, 2) +
                                         sixthMatrix(1, 2) * fifthMatrix(2, 2) +
                                         sixthMatrix(1, 3) * fifthMatrix(3, 2),

                                     sixthMatrix(1, 0) * fifthMatrix(0, 3) +
                                         sixthMatrix(1, 1) * fifthMatrix(1, 3) +
                                         sixthMatrix(1, 2) * fifthMatrix(2, 3) +
                                         sixthMatrix(1, 3) * fifthMatrix(3, 3),

                                     sixthMatrix(2, 0) * fifthMatrix(0, 0) +
                                         sixthMatrix(2, 1) * fifthMatrix(1, 0) +
                                         sixthMatrix(2, 2) * fifthMatrix(2, 0) +
                                         sixthMatrix(2, 3) * fifthMatrix(3, 0),

                                     sixthMatrix(2, 0) * fifthMatrix(0, 1) +
                                         sixthMatrix(2, 1) * fifthMatrix(1, 1) +
                                         sixthMatrix(2, 2) * fifthMatrix(2, 1) +
                                         sixthMatrix(2, 3) * fifthMatrix(3, 1),

                                     sixthMatrix(2, 0) * fifthMatrix(0, 2) +
                                         sixthMatrix(2, 1) * fifthMatrix(1, 2) +
                                         sixthMatrix(2, 2) * fifthMatrix(2, 2) +
                                         sixthMatrix(2, 3) * fifthMatrix(3, 2),

                                     sixthMatrix(2, 0) * fifthMatrix(0, 3) +
                                         sixthMatrix(2, 1) * fifthMatrix(1, 3) +
                                         sixthMatrix(2, 2) * fifthMatrix(2, 3) +
                                         sixthMatrix(2, 3) * fifthMatrix(3, 3),

                                     sixthMatrix(3, 0) * fifthMatrix(0, 0) +
                                         sixthMatrix(3, 1) * fifthMatrix(1, 0) +
                                         sixthMatrix(3, 2) * fifthMatrix(2, 0) +
                                         sixthMatrix(3, 3) * fifthMatrix(3, 0),

                                     sixthMatrix(3, 0) * fifthMatrix(0, 1) +
                                         sixthMatrix(3, 1) * fifthMatrix(1, 1) +
                                         sixthMatrix(3, 2) * fifthMatrix(2, 1) +
                                         sixthMatrix(3, 3) * fifthMatrix(3, 1),

                                     sixthMatrix(3, 0) * fifthMatrix(0, 2) +
                                         sixthMatrix(3, 1) * fifthMatrix(1, 2) +
                                         sixthMatrix(3, 2) * fifthMatrix(2, 2) +
                                         sixthMatrix(3, 3) * fifthMatrix(3, 2),

                                     sixthMatrix(3, 0) * fifthMatrix(0, 3) +
                                         sixthMatrix(3, 1) * fifthMatrix(1, 3) +
                                         sixthMatrix(3, 2) * fifthMatrix(2, 3) +
                                         sixthMatrix(3, 3) * fifthMatrix(3, 3));

        ASSERT_TRUE(Approximate(fourthMatrix1, seventhMatrix, 1e-8f));

        seventhMatrix = sixthMatrix * fifthMatrix;

        ASSERT_TRUE(Approximate(fourthMatrix1, seventhMatrix, 1e-8f));

        Matrix4F::Vector4 firstVector(randomDistribution(generator),
                                      randomDistribution(generator),
                                      randomDistribution(generator),
                                      randomDistribution(generator));

        const Matrix4F::Vector4 secondVector = seventhMatrix * firstVector;
        const Matrix4F::Vector4 thirdVector = firstVector * seventhMatrix;

        Matrix4F::Vector4 fourthVector(seventhMatrix(0, 0) * firstVector[0] +
                                           seventhMatrix(0, 1) * firstVector[1] +
                                           seventhMatrix(0, 2) * firstVector[2] +
                                           seventhMatrix(0, 3) * firstVector[3],
                                       seventhMatrix(1, 0) * firstVector[0] +
                                           seventhMatrix(1, 1) * firstVector[1] +
                                           seventhMatrix(1, 2) * firstVector[2] +
                                           seventhMatrix(1, 3) * firstVector[3],
                                       seventhMatrix(2, 0) * firstVector[0] +
                                           seventhMatrix(2, 1) * firstVector[1] +
                                           seventhMatrix(2, 2) * firstVector[2] +
                                           seventhMatrix(2, 3) * firstVector[3],
                                       seventhMatrix(3, 0) * firstVector[0] +
                                           seventhMatrix(3, 1) * firstVector[1] +
                                           seventhMatrix(3, 2) * firstVector[2] +
                                           seventhMatrix(3, 3) * firstVector[3]);

        ASSERT_TRUE(Vector4ToolsF::Approximate(secondVector, fourthVector, 1e-2f));

        fourthVector[0] = seventhMatrix(0, 0) * firstVector[0] +
                          seventhMatrix(1, 0) * firstVector[1] +
                          seventhMatrix(2, 0) * firstVector[2] +
                          seventhMatrix(3, 0) * firstVector[3];

        fourthVector[1] = seventhMatrix(0, 1) * firstVector[0] +
                          seventhMatrix(1, 1) * firstVector[1] +
                          seventhMatrix(2, 1) * firstVector[2] +
                          seventhMatrix(3, 1) * firstVector[3];

        fourthVector[2] = seventhMatrix(0, 2) * firstVector[0] +
                          seventhMatrix(1, 2) * firstVector[1] +
                          seventhMatrix(2, 2) * firstVector[2] +
                          seventhMatrix(3, 2) * firstVector[3];

        fourthVector[3] = seventhMatrix(0, 3) * firstVector[0] +
                          seventhMatrix(1, 3) * firstVector[1] +
                          seventhMatrix(2, 3) * firstVector[2] +
                          seventhMatrix(3, 3) * firstVector[3];

        ASSERT_TRUE(Vector4ToolsF::Approximate(thirdVector, fourthVector, 1e-2f));

        Matrix4F eighthMatrix = TransposeTimes(fifthMatrix, sixthMatrix);
        Matrix4F ninthMatrix = fifthMatrix.Transpose() * sixthMatrix;

        ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix, 1e-8f));

        eighthMatrix = TimesTranspose(fifthMatrix, sixthMatrix);
        ninthMatrix = fifthMatrix * sixthMatrix.Transpose();

        ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix, 1e-8f));

        eighthMatrix = TransposeTimesTranspose(fifthMatrix, sixthMatrix);
        ninthMatrix = fifthMatrix.Transpose() * sixthMatrix.Transpose();

        ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix, 1e-8f));
    }
}

void Mathematics::Matrix4Testing::ArithmeticCalculateTest()
{
    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -10.0f, 10.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        const Matrix4F::Vector4 firstVector(randomDistribution(generator),
                                            randomDistribution(generator),
                                            randomDistribution(generator),
                                            randomDistribution(generator));

        const Matrix4F::Vector4 secondVector(randomDistribution(generator),
                                             randomDistribution(generator),
                                             randomDistribution(generator),
                                             randomDistribution(generator));

        Matrix4F firstMatrix(randomDistribution(generator),
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

        const float qForm = firstMatrix.QuadraticForm(firstVector, secondVector);

        const float testQFormValue = Vector4Tools<float>::DotProduct(firstVector, firstMatrix * secondVector);

        ASSERT_APPROXIMATE(qForm, testQFormValue, 1e-2f);

        Matrix4F secondMatrix = firstMatrix.Transpose();

        for (int row = 0; row < 4; ++row)
        {
            for (int colomn = 0; colomn < 4; ++colomn)
            {
                ASSERT_APPROXIMATE(secondMatrix(row, colomn), firstMatrix(colomn, row), 1e-8f);
            }
        }

        const Matrix3F firstMatrix3(secondMatrix(1, 1), secondMatrix(1, 2), secondMatrix(1, 3),
                                    secondMatrix(2, 1), secondMatrix(2, 2), secondMatrix(2, 3),
                                    secondMatrix(3, 1), secondMatrix(3, 2), secondMatrix(3, 3));

        const Matrix3F secondMatrix3(secondMatrix(1, 0), secondMatrix(1, 2), secondMatrix(1, 3),
                                     secondMatrix(2, 0), secondMatrix(2, 2), secondMatrix(2, 3),
                                     secondMatrix(3, 0), secondMatrix(3, 2), secondMatrix(3, 3));

        const Matrix3F thirdMatrix3(secondMatrix(1, 0), secondMatrix(1, 1), secondMatrix(1, 3),
                                    secondMatrix(2, 0), secondMatrix(2, 1), secondMatrix(2, 3),
                                    secondMatrix(3, 0), secondMatrix(3, 1), secondMatrix(3, 3));

        const Matrix3F fourthMatrix3(secondMatrix(1, 0), secondMatrix(1, 1), secondMatrix(1, 2),
                                     secondMatrix(2, 0), secondMatrix(2, 1), secondMatrix(2, 2),
                                     secondMatrix(3, 0), secondMatrix(3, 1), secondMatrix(3, 2));

        const float determinant = secondMatrix(0, 0) * firstMatrix3.Determinant() -
                                  secondMatrix(0, 1) * secondMatrix3.Determinant() +
                                  secondMatrix(0, 2) * thirdMatrix3.Determinant() -
                                  secondMatrix(0, 3) * fourthMatrix3.Determinant();

        ASSERT_APPROXIMATE(determinant, secondMatrix.Determinant(), 1e-2f);

        if (MathF::GetZeroTolerance() < MathF::FAbs(determinant))
        {
            const Matrix4F thirdMatrix = secondMatrix.Inverse();

            Matrix4F fourthMatrix = secondMatrix * thirdMatrix;

            ASSERT_TRUE(Approximate(fourthMatrix, Matrix4F::GetIdentity(), 1e-4f));

            Matrix4F fifthMatrix = secondMatrix.Adjoint();
            fifthMatrix /= determinant;

            fourthMatrix = fifthMatrix * secondMatrix;

            ASSERT_TRUE(Approximate(fourthMatrix, Matrix4F::GetIdentity(), 1e-4f));
        }
    }
}

void Mathematics::Matrix4Testing::ProjectionTest()
{
    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -100.0f, 100.0f };

    const auto testLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < testLoopCount; ++loop)
    {
        Matrix3F::Vector3 firstVector(randomDistribution(generator),
                                      randomDistribution(generator),
                                      randomDistribution(generator));

        Matrix3F::Vector3 secondVector(randomDistribution(generator),
                                       randomDistribution(generator),
                                       randomDistribution(generator));

        Matrix3F::Vector3 thirdVector(randomDistribution(generator),
                                      randomDistribution(generator),
                                      randomDistribution(generator));

        Matrix4F::Vector4 fourthVector(randomDistribution(generator),
                                       randomDistribution(generator),
                                       randomDistribution(generator),
                                       1.0f);

        firstVector.Normalize();
        thirdVector.Normalize();

        if (MathF::GetZeroTolerance() < Vector3ToolsF::DotProduct(firstVector, thirdVector))
        {
            Matrix4F firstMatrix;
            firstMatrix.MakeObliqueProjection(firstVector, secondVector, thirdVector);

            Matrix4F::Vector4 fifthVector = firstMatrix * fourthVector;

            fifthVector.ProjectionNormalization();

            const PlaneF firstPlane = PlaneF(AVectorF(firstVector), APointF(secondVector));

            // 转换后的点的平面上。
            const float distance = firstPlane.DistanceTo(APointF(fifthVector[0], fifthVector[1], fifthVector[2]));

            ASSERT_APPROXIMATE(distance, 0.0f, 1e-3f);

            // 原来的点与转换后的点的差是direction或-direction
            Matrix4F::Vector4 sixthVector = fourthVector - fifthVector;

            sixthVector.Normalize();

            ASSERT_APPROXIMATE(sixthVector[3], 0.0f, 1e-8f);

            const Matrix3F::Vector3 seventhVector(sixthVector);
            const Matrix3F::Vector3 eighthVector(-seventhVector);

            ASSERT_TRUE(Vector3ToolsF::Approximate(seventhVector, thirdVector, 1e-5f) ||
                        Vector3ToolsF::Approximate(eighthVector, thirdVector, 1e-5f));
        }

        const Matrix3F::Vector3 ninthVector(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        Matrix4F secondMatrix;
        secondMatrix.MakePerspectiveProjection(firstVector, secondVector, ninthVector);

        Matrix4F::Vector4 tenthVector = secondMatrix * fourthVector;

        tenthVector.ProjectionNormalization();

        const PlaneF secondPlane = PlaneF(AVectorF(firstVector), APointF(secondVector));

        // 原来的点与转换后的点和点eye在同一直线上
        Matrix4F::Vector4 eleventhVector = fourthVector - tenthVector;

        ASSERT_APPROXIMATE(eleventhVector[3], 0.0f, 1e-8f);

        eleventhVector.Normalize();

        Matrix4F::Vector3 twelfthVector = ninthVector - Vector3F(tenthVector);

        twelfthVector.Normalize();

        secondMatrix.MakeReflection(firstVector, secondVector);

        Matrix4F::Vector4 thirteenVector = secondMatrix * fourthVector;

        const float firstDistance = secondPlane.DistanceTo(APointF(thirteenVector[0], thirteenVector[1], thirteenVector[2]));

        const float secondDistance = secondPlane.DistanceTo(APointF(fourthVector[0], fourthVector[1], fourthVector[2]));

        ASSERT_APPROXIMATE(firstDistance, -secondDistance, 1e-4f);

        // MakeFrustumMatrix44测试
        const float left = -MathF::FAbs(randomDistribution(generator));
        const float right = MathF::FAbs(randomDistribution(generator));
        const float bottom = -MathF::FAbs(randomDistribution(generator));
        const float top = MathF::FAbs(randomDistribution(generator));
        const float nearDistance = -MathF::FAbs(randomDistribution(generator));
        const float farDistance = MathF::FAbs(randomDistribution(generator));

        secondMatrix.MakeFrustumMatrix44(left, right, bottom, top, nearDistance, farDistance);

        ASSERT_APPROXIMATE(secondMatrix(0, 0), 2.0f * nearDistance / (right - left), 1e-5f);
        ASSERT_APPROXIMATE(secondMatrix(0, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(0, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(0, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(secondMatrix(1, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(1, 1), (2.0f * nearDistance) / (top - bottom), 1e-6f);
        ASSERT_APPROXIMATE(secondMatrix(1, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(1, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(secondMatrix(2, 0), (right + left) / (right - left), 1e-7f);
        ASSERT_APPROXIMATE(secondMatrix(2, 1), (top + bottom) / (top - bottom), 1e-7f);
        ASSERT_APPROXIMATE(secondMatrix(2, 2), -(farDistance + nearDistance) / (farDistance - nearDistance), 1e-7f);
        ASSERT_APPROXIMATE(secondMatrix(2, 3), -1.0f, 1e-8f);

        ASSERT_APPROXIMATE(secondMatrix(3, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(3, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(3, 2), (-2.0f * farDistance * nearDistance) / (farDistance - nearDistance), 1e-5f);
        ASSERT_APPROXIMATE(secondMatrix(3, 3), 0.0f, 1e-8f);

        // MakePerspectiveMatrix44测试
        constexpr float fieldOfViewY = 60.0f;
        constexpr float aspect = 0.6f;

        secondMatrix.MakePerspectiveMatrix44(fieldOfViewY, aspect, nearDistance, farDistance);

        float angle = fieldOfViewY / 2.0f;
        // 角度转换成弧度
        angle *= MathF::GetDegreeToRadian();

        const float cot = MathF::Cos(angle) / MathF::Sin(angle);

        ASSERT_APPROXIMATE(secondMatrix(0, 0), cot / aspect, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(0, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(0, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(0, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(secondMatrix(1, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(1, 1), cot, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(1, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(1, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(secondMatrix(2, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(2, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(2, 2), -(farDistance + nearDistance) / (farDistance - nearDistance), 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(2, 3), -1.0f, 1e-8f);

        ASSERT_APPROXIMATE(secondMatrix(3, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(3, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(3, 2), (-2.0f * farDistance * nearDistance) / (farDistance - nearDistance), 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(3, 3), 0.0f, 1e-8f);

        // MakeOrthoMatrix44测试
        secondMatrix.MakeOrthoMatrix44(left, right, bottom, top, nearDistance, farDistance);

        ASSERT_APPROXIMATE(secondMatrix(0, 0), 2.0f / (right - left), 1e-7f);
        ASSERT_APPROXIMATE(secondMatrix(0, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(0, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(0, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(secondMatrix(1, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(1, 1), 2.0f / (top - bottom), 1e-7f);
        ASSERT_APPROXIMATE(secondMatrix(1, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(1, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(secondMatrix(2, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(2, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(2, 2), -2.0f / (farDistance - nearDistance), 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(2, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(secondMatrix(3, 0), -(right + left) / (right - left), 1e-7f);
        ASSERT_APPROXIMATE(secondMatrix(3, 1), -(top + bottom) / (top - bottom), 1e-7f);
        ASSERT_APPROXIMATE(secondMatrix(3, 2), -(farDistance + nearDistance) / (farDistance - nearDistance), 1e-7f);
        ASSERT_APPROXIMATE(secondMatrix(3, 3), 1.0f, 1e-8f);

        // MakeOrthoNormalMatrix44测试
        firstVector.Normalize();
        secondVector.Normalize();
        thirdVector.Normalize();

        secondMatrix.MakeOrthoNormalMatrix44(firstVector, secondVector, thirdVector);

        ASSERT_APPROXIMATE(secondMatrix(0, 0), firstVector[0], 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(0, 1), secondVector[0], 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(0, 2), thirdVector[0], 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(0, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(secondMatrix(1, 0), firstVector[1], 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(1, 1), secondVector[1], 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(1, 2), thirdVector[1], 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(1, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(secondMatrix(2, 0), firstVector[2], 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(2, 1), secondVector[2], 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(2, 2), thirdVector[2], 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(2, 3), 0.0f, 1e-8f);

        ASSERT_APPROXIMATE(secondMatrix(3, 0), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(3, 1), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(3, 2), 0.0f, 1e-8f);
        ASSERT_APPROXIMATE(secondMatrix(3, 3), 1.0f, 1e-8f);
    }
}
