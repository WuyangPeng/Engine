///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 22:07)

#include "MatrixTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/MatrixDetail.h"
#include "Mathematics/Algebra/PlaneDetail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Algebra/Vector4.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include <random>

using std::default_random_engine;
using std::uniform_real;
using std::vector;

Mathematics::MatrixTesting::MatrixTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, MatrixTesting)

void Mathematics::MatrixTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::MatrixTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(ConstructionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(AccessTest);
    ASSERT_NOT_THROW_EXCEPTION_0(OperatorCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ArithmeticCalculateTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ProjectionTest);
    ASSERT_NOT_THROW_EXCEPTION_0(CompareTest);
    ASSERT_NOT_THROW_EXCEPTION_0(HomogeneousPointTest);
    ASSERT_NOT_THROW_EXCEPTION_0(Invert3x3Test);
}

void Mathematics::MatrixTesting::ConstructionTest()
{
    MatrixF firstMatrix(MatrixInitType::Zero);

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

    MatrixF secondMatrix(MatrixInitType::Identity);

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

    MatrixD thirdMatrix(3.0, 6.0, 1.0, 2.0,
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

    MatrixD fourthMatrix(doubleVector, MatrixMajorFlags::Row);

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

    MatrixD fifthMatrix(doubleVector, MatrixMajorFlags::Column);

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

    const Matrix3D sixthMatrix(3.0, 6.0, 1.0,
                               6.2, 5.2, 1.01,
                               3.1, 2.0, 6.06);

    MatrixD seventhMatrix(sixthMatrix);

    ASSERT_APPROXIMATE(seventhMatrix(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(0, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(0, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(1, 1), 5.2, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(1, 2), 1.01, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(1, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(2, 0), 3.1, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(2, 1), 2.0, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(2, 2), 6.06, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(2, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(3, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(3, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(3, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(seventhMatrix(3, 3), 1.0, 1e-10);

    MatrixD eighthMatrix(thirdMatrix);

    ASSERT_APPROXIMATE(eighthMatrix(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(0, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(0, 3), 2.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(1, 0), 13.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(1, 1), 16.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(1, 2), 11.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(1, 3), 12.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(2, 0), 23.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(2, 1), 26.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(2, 2), 21.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(2, 3), 22.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(3, 0), 33.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(3, 1), 63.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(3, 2), 13.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(3, 3), 23.0, 1e-10);

    const Vector4F firstVector(6.0f, 3.0f, 5.0f, 3.0f);
    const Vector4F secondVector(8.0f, 3.1f, 9.0f, 13.0f);
    const Vector4F thirdVector(18.0f, 13.1f, 19.0f, 32.0f);
    const Vector4F fourthVector(-18.0f, -13.1f, -19.0f, -32.0f);

    MatrixF ninthMatrix(firstVector, secondVector,
                        thirdVector, fourthVector,
                        MatrixMajorFlags::Row);

    ASSERT_APPROXIMATE(ninthMatrix(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(0, 1), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(0, 2), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(0, 3), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(1, 0), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(1, 1), 3.1f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(1, 2), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(1, 3), 13.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(2, 0), 18.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(2, 1), 13.1f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(2, 2), 19.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(2, 3), 32.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(3, 0), -18.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(3, 1), -13.1f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(3, 2), -19.0f, 1e-8f);
    ASSERT_APPROXIMATE(ninthMatrix(3, 3), -32.0f, 1e-8f);

    MatrixF tenthMatrix(firstVector, secondVector,
                        thirdVector, fourthVector,
                        MatrixMajorFlags::Column);

    ASSERT_APPROXIMATE(tenthMatrix(0, 0), 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(0, 1), 8.0f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(0, 2), 18.0f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(0, 3), -18.0f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(1, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(1, 1), 3.1f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(1, 2), 13.1f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(1, 3), -13.1f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(2, 0), 5.0f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(2, 1), 9.0f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(2, 2), 19.0f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(2, 3), -19.0f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(3, 0), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(3, 1), 13.0f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(3, 2), 32.0f, 1e-8f);
    ASSERT_APPROXIMATE(tenthMatrix(3, 3), -32.0f, 1e-8f);

    MatrixF eleventhMatrix(4.0, 2.0f, 3.0f);

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 2), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(3, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(3, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(3, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(3, 3), 1.0f, 1e-8f);

    AVectorF fifthVector(1.0f, 3.0f, 3.5f);

    fifthVector.Normalize();
    MatrixF twelfthMatrix(fifthVector, MathF::GetHalfPI() / 3.0f);

    const double cosValue = MathD::Cos(MathD::GetHalfPI() / 3.0);
    const double sinValue = MathD::Sin(MathD::GetHalfPI() / 3.0);
    const double oneMinusCos = 1.0 - cosValue;

    ASSERT_APPROXIMATE(twelfthMatrix(0, 0), static_cast<double>(fifthVector[0]) * fifthVector[0] * oneMinusCos + cosValue, 1e-7);
    ASSERT_APPROXIMATE(twelfthMatrix(0, 1), static_cast<double>(fifthVector[0]) * fifthVector[1] * oneMinusCos - fifthVector[2] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(0, 2), static_cast<double>(fifthVector[0]) * fifthVector[2] * oneMinusCos + fifthVector[1] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(0, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(1, 0), static_cast<double>(fifthVector[0]) * fifthVector[1] * oneMinusCos + fifthVector[2] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(1, 1), static_cast<double>(fifthVector[1]) * fifthVector[1] * oneMinusCos + cosValue, 1e-7);
    ASSERT_APPROXIMATE(twelfthMatrix(1, 2), static_cast<double>(fifthVector[1]) * fifthVector[2] * oneMinusCos - fifthVector[0] * sinValue, 1e-7);
    ASSERT_APPROXIMATE(twelfthMatrix(1, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(2, 0), static_cast<double>(fifthVector[0]) * fifthVector[2] * oneMinusCos - fifthVector[1] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(2, 1), static_cast<double>(fifthVector[1]) * fifthVector[2] * oneMinusCos + fifthVector[0] * sinValue, 1e-7);
    ASSERT_APPROXIMATE(twelfthMatrix(2, 2), static_cast<double>(fifthVector[2]) * fifthVector[2] * oneMinusCos + cosValue, 1e-7);
    ASSERT_APPROXIMATE(twelfthMatrix(2, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(3, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(3, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(3, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(twelfthMatrix(3, 3), 1.0f, 1e-8f);

    eleventhMatrix = twelfthMatrix;

    ASSERT_TRUE(Approximate(eleventhMatrix, twelfthMatrix, 1e-8f));

    eighthMatrix = sixthMatrix;

    ASSERT_APPROXIMATE(eighthMatrix(0, 0), 3.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(0, 1), 6.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(0, 2), 1.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(0, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(1, 0), 6.2, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(1, 1), 5.2, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(1, 2), 1.01, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(1, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(2, 0), 3.1, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(2, 1), 2.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(2, 2), 6.06, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(2, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(3, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(3, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(3, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(3, 3), 1.0, 1e-10);

    eighthMatrix.MakeDiagonal(2.0, 3.0, 5.0);

    ASSERT_APPROXIMATE(eighthMatrix(0, 0), 2.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(0, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(0, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(0, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(1, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(1, 1), 3.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(1, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(1, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(2, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(2, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(2, 2), 5.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(2, 3), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(3, 0), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(3, 1), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(3, 2), 0.0, 1e-10);
    ASSERT_APPROXIMATE(eighthMatrix(3, 3), 1.0, 1e-10);

    eleventhMatrix.MakeRotation(fifthVector, MathF::GetHalfPI() / 3.0f);

    ASSERT_APPROXIMATE(eleventhMatrix(0, 0), static_cast<double>(fifthVector[0]) * fifthVector[0] * oneMinusCos + cosValue, 1e-7);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 1), static_cast<double>(fifthVector[0]) * fifthVector[1] * oneMinusCos - fifthVector[2] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 2), static_cast<double>(fifthVector[0]) * fifthVector[2] * oneMinusCos + fifthVector[1] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(0, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 0), static_cast<double>(fifthVector[0]) * fifthVector[1] * oneMinusCos + fifthVector[2] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 1), static_cast<double>(fifthVector[1]) * fifthVector[1] * oneMinusCos + cosValue, 1e-7);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 2), static_cast<double>(fifthVector[1]) * fifthVector[2] * oneMinusCos - fifthVector[0] * sinValue, 1e-7);
    ASSERT_APPROXIMATE(eleventhMatrix(1, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 0), static_cast<double>(fifthVector[0]) * fifthVector[2] * oneMinusCos - fifthVector[1] * sinValue, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 1), static_cast<double>(fifthVector[1]) * fifthVector[2] * oneMinusCos + fifthVector[0] * sinValue, 1e-7);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 2), static_cast<double>(fifthVector[2]) * fifthVector[2] * oneMinusCos + cosValue, 1e-7);
    ASSERT_APPROXIMATE(eleventhMatrix(2, 3), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(3, 0), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(3, 1), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(3, 2), 0.0f, 1e-8f);
    ASSERT_APPROXIMATE(eleventhMatrix(3, 3), 1.0f, 1e-8f);
}

void Mathematics::MatrixTesting::AccessTest()
{
    const MatrixF firstMatrix(3.0f, 4.0f, 8.1f, 3.2f,
                              6.0f, 3.3f, 4.4f, 5.5f,
                              6.6f, 7.7f, 8.8f, 9.9f,
                              10.0f, 55.0f, 6.3f, 3.21f);

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

    MatrixD secondMatrix(9.2, 1.0, 4.2, 5.2, 8.0, 5.5, 3.3, 4.4, 100.0, 5.6, 9.8, 7.3, 3.33, 4.44, 5.55, 6.66);

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

    Matrix3D thirdMatrix = secondMatrix.GetMatrix3();

    ASSERT_APPROXIMATE(thirdMatrix(0, 0), 9.2, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(0, 1), 1.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(0, 2), 4.2, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(1, 0), 8.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(1, 1), 5.5, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(1, 2), 3.3, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(2, 0), 100.0, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(2, 1), 5.6, 1e-10);
    ASSERT_APPROXIMATE(thirdMatrix(2, 2), 9.8, 1e-10);

    HomogeneousPointD firstPoint = secondMatrix.GetRow(0);

    ASSERT_APPROXIMATE(firstPoint[0], 9.2, 1e-10);
    ASSERT_APPROXIMATE(firstPoint[1], 1.0, 1e-10);
    ASSERT_APPROXIMATE(firstPoint[2], 4.2, 1e-10);
    ASSERT_APPROXIMATE(firstPoint[3], 5.2, 1e-10);

    HomogeneousPointD secondPoint(6.0, 5.0, 6.9, 2.2);
    secondMatrix.SetRow(0, secondPoint);

    ASSERT_APPROXIMATE(secondMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 2), 6.9, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 3), 2.2, 1e-10);
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

    secondPoint[0] = 9.99;
    secondPoint[1] = 19.99;
    secondPoint[2] = 29.99;
    secondPoint[3] = 39.99;

    secondMatrix.SetRow(1, secondPoint);

    ASSERT_APPROXIMATE(secondMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 2), 6.9, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 3), 2.2, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 0), 9.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 1), 19.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 2), 29.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 3), 39.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 0), 100.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 1), 5.6, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 2), 9.8, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 3), 7.3, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 0), 3.33, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 1), 4.44, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 2), 5.55, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 3), 6.66, 1e-10);

    firstPoint = secondMatrix.GetRow(1);

    ASSERT_APPROXIMATE(firstPoint[0], 9.99, 1e-10);
    ASSERT_APPROXIMATE(firstPoint[1], 19.99, 1e-10);
    ASSERT_APPROXIMATE(firstPoint[2], 29.99, 1e-10);
    ASSERT_APPROXIMATE(firstPoint[3], 39.99, 1e-10);

    secondPoint[0] = -9.99;
    secondPoint[1] = -19.99;
    secondPoint[2] = -29.99;
    secondPoint[3] = -39.99;

    secondMatrix.SetRow(2, secondPoint);

    ASSERT_APPROXIMATE(secondMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 2), 6.9, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 3), 2.2, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 0), 9.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 1), 19.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 2), 29.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 3), 39.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 0), -9.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 1), -19.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 2), -29.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 3), -39.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 0), 3.33, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 1), 4.44, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 2), 5.55, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 3), 6.66, 1e-10);

    firstPoint = secondMatrix.GetRow(2);

    ASSERT_APPROXIMATE(firstPoint[0], -9.99, 1e-10);
    ASSERT_APPROXIMATE(firstPoint[1], -19.99, 1e-10);
    ASSERT_APPROXIMATE(firstPoint[2], -29.99, 1e-10);
    ASSERT_APPROXIMATE(firstPoint[3], -39.99, 1e-10);

    secondPoint[0] = 1.993;
    secondPoint[1] = 1.992;
    secondPoint[2] = 1.991;
    secondPoint[3] = 1.99;

    secondMatrix.SetRow(3, secondPoint);

    ASSERT_APPROXIMATE(secondMatrix(0, 0), 6.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 1), 5.0, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 2), 6.9, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(0, 3), 2.2, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 0), 9.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 1), 19.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 2), 29.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(1, 3), 39.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 0), -9.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 1), -19.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 2), -29.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(2, 3), -39.99, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 0), 1.993, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 1), 1.992, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 2), 1.991, 1e-10);
    ASSERT_APPROXIMATE(secondMatrix(3, 3), 1.99, 1e-10);

    firstPoint = secondMatrix.GetRow(3);

    ASSERT_APPROXIMATE(firstPoint[0], 1.993, 1e-10);
    ASSERT_APPROXIMATE(firstPoint[1], 1.992, 1e-10);
    ASSERT_APPROXIMATE(firstPoint[2], 1.991, 1e-10);
    ASSERT_APPROXIMATE(firstPoint[3], 1.99, 1e-10);

    std::vector<float> floatVector = firstMatrix.GetColumnMajor();

#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26446)

    ASSERT_APPROXIMATE(floatVector[0], 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[4], 4.0f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[8], 8.1f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[12], 3.2f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[1], 6.0f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[5], 3.3f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[9], 4.4f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[13], 5.5f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[2], 6.6f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[6], 7.7f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[10], 8.8f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[14], 9.9f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[3], 10.0f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[7], 55.0f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[11], 6.3f, 1e-8f);
    ASSERT_APPROXIMATE(floatVector[15], 3.21f, 1e-8f);

#include STSTEM_WARNING_POP
}

void Mathematics::MatrixTesting::OperatorCalculateTest()
{
    const MatrixF firstMatrix(3.0f, 4.0f, 8.1f, 3.2f, 13.0f, 14.0f, 18.1f, 13.2f, 23.0f, 24.0f, 28.1f, 23.2f, 33.0f, 34.0f, 38.1f, 33.2f);

    MatrixF secondMatrix = -firstMatrix;

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

    MatrixF thirdMatrix(9.2f, 3.0f, 2.0f, 9.0f, 19.2f, 13.0f, 12.0f, 19.0f, 29.2f, 23.0f, 22.0f, 29.0f, 9.23f, 3.03f, 2.03f, 9.03f);

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

    MatrixF fourthMatrix = firstMatrix + thirdMatrix;

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

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        MatrixF fifthMatrix(randomDistribution(generator),
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

        MatrixF sixthMatrix(randomDistribution(generator),
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

        MatrixF seventhMatrix(sixthMatrix);

        seventhMatrix *= fifthMatrix;

        const MatrixF fourthMatrix1(sixthMatrix(0, 0) * fifthMatrix(0, 0) +
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

        HomogeneousPointF firstPoint(randomDistribution(generator),
                                     randomDistribution(generator),
                                     randomDistribution(generator),
                                     randomDistribution(generator));

        const HomogeneousPointF secondPoint = seventhMatrix * firstPoint;
        const HomogeneousPointF thirdPoint = firstPoint * seventhMatrix;

        HomogeneousPointF fourthPoint(seventhMatrix(0, 0) * firstPoint[0] +
                                          seventhMatrix(0, 1) * firstPoint[1] +
                                          seventhMatrix(0, 2) * firstPoint[2] +
                                          seventhMatrix(0, 3) * firstPoint[3],
                                      seventhMatrix(1, 0) * firstPoint[0] +
                                          seventhMatrix(1, 1) * firstPoint[1] +
                                          seventhMatrix(1, 2) * firstPoint[2] +
                                          seventhMatrix(1, 3) * firstPoint[3],
                                      seventhMatrix(2, 0) * firstPoint[0] +
                                          seventhMatrix(2, 1) * firstPoint[1] +
                                          seventhMatrix(2, 2) * firstPoint[2] +
                                          seventhMatrix(2, 3) * firstPoint[3],
                                      seventhMatrix(3, 0) * firstPoint[0] +
                                          seventhMatrix(3, 1) * firstPoint[1] +
                                          seventhMatrix(3, 2) * firstPoint[2] +
                                          seventhMatrix(3, 3) * firstPoint[3]);

        ASSERT_TRUE(Approximate(secondPoint, fourthPoint, 1e-2f));

        fourthPoint[0] = seventhMatrix(0, 0) * firstPoint[0] +
                         seventhMatrix(1, 0) * firstPoint[1] +
                         seventhMatrix(2, 0) * firstPoint[2] +
                         seventhMatrix(3, 0) * firstPoint[3];

        fourthPoint[1] = seventhMatrix(0, 1) * firstPoint[0] +
                         seventhMatrix(1, 1) * firstPoint[1] +
                         seventhMatrix(2, 1) * firstPoint[2] +
                         seventhMatrix(3, 1) * firstPoint[3];

        fourthPoint[2] = seventhMatrix(0, 2) * firstPoint[0] +
                         seventhMatrix(1, 2) * firstPoint[1] +
                         seventhMatrix(2, 2) * firstPoint[2] +
                         seventhMatrix(3, 2) * firstPoint[3];

        fourthPoint[3] = seventhMatrix(0, 3) * firstPoint[0] +
                         seventhMatrix(1, 3) * firstPoint[1] +
                         seventhMatrix(2, 3) * firstPoint[2] +
                         seventhMatrix(3, 3) * firstPoint[3];

        ASSERT_TRUE(Approximate(thirdPoint, fourthPoint, 1e-3f));

        MatrixF eighthMatrix = TransposeTimes(fifthMatrix, sixthMatrix);
        MatrixF ninthMatrix = fifthMatrix.Transpose() * sixthMatrix;

        ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix, 1e-8f));

        eighthMatrix = TimesTranspose(fifthMatrix, sixthMatrix);
        ninthMatrix = fifthMatrix * sixthMatrix.Transpose();

        ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix, 1e-8f));

        eighthMatrix = TransposeTimesTranspose(fifthMatrix, sixthMatrix);
        ninthMatrix = fifthMatrix.Transpose() * sixthMatrix.Transpose();

        ASSERT_TRUE(Approximate(eighthMatrix, ninthMatrix, 1e-8f));
    }
}

void Mathematics::MatrixTesting::ArithmeticCalculateTest()
{
    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        HomogeneousPointF firstPoint(randomDistribution(generator),
                                     randomDistribution(generator),
                                     randomDistribution(generator),
                                     randomDistribution(generator));

        const HomogeneousPointF secondPoint(randomDistribution(generator),
                                            randomDistribution(generator),
                                            randomDistribution(generator),
                                            randomDistribution(generator));

        MatrixF firstMatrix(randomDistribution(generator),
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

        const float qForm = firstMatrix.QuadraticForm(firstPoint, secondPoint);

        HomogeneousPointF thirdPoint = firstMatrix * secondPoint;

        const float testQFormValue = firstPoint[0] * thirdPoint[0] + firstPoint[1] * thirdPoint[1] + firstPoint[2] * thirdPoint[2] + firstPoint[3] * thirdPoint[3];

        ASSERT_APPROXIMATE(qForm, testQFormValue, 1e-2f);

        MatrixF secondMatrix = firstMatrix.Transpose();

        for (int row = 0; row < 4; ++row)
        {
            for (int colomn = 0; colomn < 4; ++colomn)
            {
                ASSERT_APPROXIMATE(firstMatrix(row, colomn), secondMatrix(colomn, row), 1e-8f);
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
            const MatrixF thirdMatrix = secondMatrix.Inverse();

            MatrixF fourthMatrix = secondMatrix * thirdMatrix;

            MatrixF fifthMatrix = secondMatrix.Adjoint();
            fifthMatrix /= determinant;

            fourthMatrix = fifthMatrix * secondMatrix;
        }

        APointF fourthPoint(6.0f, 5.4f, 3.3f);

        secondMatrix = firstMatrix.TimesDiagonal(fourthPoint);

        const MatrixF fifthMatrix = firstMatrix * MatrixF(fourthPoint[0], fourthPoint[1], fourthPoint[2]);

        ASSERT_TRUE(Approximate(fifthMatrix, secondMatrix, 1e-8f));

        secondMatrix = firstMatrix.DiagonalTimes(fourthPoint);

        Matrix3F sixthMatrix = Matrix3F(fourthPoint[0], fourthPoint[1], fourthPoint[2]) * firstMatrix.GetMatrix3();

        ASSERT_APPROXIMATE(sixthMatrix(0, 0), secondMatrix(0, 0), 0.00001f);
        ASSERT_APPROXIMATE(sixthMatrix(0, 1), secondMatrix(0, 1), 0.00001f);
        ASSERT_APPROXIMATE(sixthMatrix(0, 2), secondMatrix(0, 2), 0.00001f);
        ASSERT_APPROXIMATE(sixthMatrix(1, 0), secondMatrix(1, 0), 0.00001f);
        ASSERT_APPROXIMATE(sixthMatrix(1, 1), secondMatrix(1, 1), 0.00001f);
        ASSERT_APPROXIMATE(sixthMatrix(1, 2), secondMatrix(1, 2), 0.00001f);
        ASSERT_APPROXIMATE(sixthMatrix(2, 0), secondMatrix(2, 0), 0.00001f);
        ASSERT_APPROXIMATE(sixthMatrix(2, 1), secondMatrix(2, 1), 0.00001f);
        ASSERT_APPROXIMATE(sixthMatrix(2, 2), secondMatrix(2, 2), 0.00001f);

        const uniform_real<float> angleRandomDistribution(0.0f, MathF::GetPI() - 0.01f);

        const float angle = angleRandomDistribution(generator);
        AVectorF firstVector(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        firstVector.Normalize();

        MatrixF seventhMatrix(firstVector, angle);

        MatrixF eighthMatrix(seventhMatrix);

        seventhMatrix.Orthonormalize();

        Vector3F thirdVector(eighthMatrix(0, 0), eighthMatrix(1, 0), eighthMatrix(2, 0));
        const Vector3F fourthVector(seventhMatrix(0, 0), seventhMatrix(1, 0), seventhMatrix(2, 0));

        thirdVector.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(thirdVector, fourthVector, 1e-7f));

        Vector3F fifthVector(eighthMatrix(0, 1), eighthMatrix(1, 1), eighthMatrix(2, 1));
        const Vector3F sixthVector(seventhMatrix(0, 1), seventhMatrix(1, 1), seventhMatrix(2, 1));

        fifthVector -= (Vector3ToolsF::DotProduct(fourthVector, fifthVector)) * fourthVector;

        fifthVector.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(fifthVector, sixthVector, 1e-3f));

        Vector3F seventhVector(eighthMatrix(0, 2), eighthMatrix(1, 2), eighthMatrix(2, 2));
        const Vector3F eighthVector(seventhMatrix(0, 2), seventhMatrix(1, 2), seventhMatrix(2, 2));

        seventhVector -= (Vector3ToolsF::DotProduct(fourthVector, seventhVector)) * fourthVector;

        seventhVector -= (Vector3ToolsF::DotProduct(sixthVector, seventhVector)) * sixthVector;

        seventhVector.Normalize();

        ASSERT_TRUE(Vector3ToolsF::Approximate(seventhVector, eighthVector, 1e-6f));
    }
}

void Mathematics::MatrixTesting::ProjectionTest()
{
    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -100.0f, 100.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        AVectorF firstVector(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        const APointF firstPoint(randomDistribution(generator),
                                 randomDistribution(generator),
                                 randomDistribution(generator));

        AVectorF secondVector(randomDistribution(generator),
                              randomDistribution(generator),
                              randomDistribution(generator));

        const APointF secondPoint(randomDistribution(generator),
                                  randomDistribution(generator),
                                  randomDistribution(generator));

        firstVector.Normalize();
        secondVector.Normalize();

        if (MathF::GetZeroTolerance() < Dot(firstVector, secondVector))
        {
            MatrixF firstMatrix;
            firstMatrix.MakeObliqueProjection(firstPoint, firstVector, secondVector);

            APointF thirdPoint = firstMatrix * secondPoint;

            thirdPoint /= -Dot(firstVector, secondVector);

            const PlaneF firstPlane = PlaneF(firstVector, firstPoint);

            // 转换后的点的平面上。
            const float distance = firstPlane.DistanceTo(thirdPoint);

            ASSERT_APPROXIMATE(distance, 0.0f, 1e-2f);

            // 原来的点与转换后的点的差是direction或-direction
            AVectorF sixthVector = secondPoint - thirdPoint;

            sixthVector.Normalize();

            const Vector3F seventhVector(sixthVector[0], sixthVector[1], sixthVector[2]);
            const Vector3F eighthVector(-seventhVector);
            const Vector3F ninthVector(secondVector[0], secondVector[1], secondVector[2]);

            ASSERT_TRUE(Vector3ToolsF::Approximate(seventhVector, ninthVector, 1e-4f) || Vector3ToolsF::Approximate(eighthVector, ninthVector, 1e-4f));
        }

        const APointF fourthPoint(randomDistribution(generator), randomDistribution(generator), randomDistribution(generator));

        MatrixF secondMatrix;
        secondMatrix.MakePerspectiveProjection(firstPoint, firstVector, fourthPoint);

        APointF fifthPoint = secondMatrix * secondPoint;

        fifthPoint /= (-Dot(secondPoint, firstVector) + Dot(fourthPoint, firstVector));

        const PlaneF secondPlane = PlaneF(firstVector, firstPoint);

        // 原来的点与转换后的点和点eye在同一直线上
        AVectorF eleventhVector = secondPoint - fifthPoint;

        eleventhVector.Normalize();

        AVectorF twelfthVector = fifthPoint - fourthPoint;

        twelfthVector.Normalize();

        const Vector3F thirteenthVector(twelfthVector[0], twelfthVector[1], twelfthVector[2]);

        const Vector3F FourteenthVector(eleventhVector[0], eleventhVector[1], eleventhVector[2]);

        secondMatrix.MakeReflection(firstPoint, firstVector);

        const APointF sixthPoint = secondMatrix * secondPoint;

        const float firstDistance = secondPlane.DistanceTo(secondPoint);

        const float secondDistance = secondPlane.DistanceTo(sixthPoint);

        ASSERT_APPROXIMATE(firstDistance, -secondDistance, 1e-4f);
    }
}

void Mathematics::MatrixTesting::CompareTest()
{
    const MatrixF firstMatrix(MatrixInitType::Zero);
    const MatrixF secondMatrix(MatrixInitType::Identity);

    ASSERT_TRUE(firstMatrix == firstMatrix);
    ASSERT_FALSE(firstMatrix == secondMatrix);
    ASSERT_TRUE(firstMatrix != secondMatrix);

    ASSERT_TRUE(firstMatrix < secondMatrix);
    ASSERT_TRUE(firstMatrix <= secondMatrix);
    ASSERT_FALSE(firstMatrix > secondMatrix);
    ASSERT_FALSE(firstMatrix >= secondMatrix);

    ASSERT_TRUE(Approximate(firstMatrix, firstMatrix, 1e-8f));
    ASSERT_TRUE(Approximate(secondMatrix, secondMatrix));
    ASSERT_FALSE(Approximate(firstMatrix, secondMatrix));
}

void Mathematics::MatrixTesting::HomogeneousPointTest()
{
    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -100.0f, 100.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        HomogeneousPointF firstPoint(randomDistribution(generator),
                                     randomDistribution(generator),
                                     randomDistribution(generator),
                                     randomDistribution(generator));

        MatrixF firstMatrix(randomDistribution(generator),
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

        const HomogeneousPointF secondPoint = firstMatrix * firstPoint;
        const HomogeneousPointF thirdPoint = firstPoint * firstMatrix;

        HomogeneousPointF fourthPoint(firstMatrix(0, 0) * firstPoint[0] +
                                          firstMatrix(0, 1) * firstPoint[1] +
                                          firstMatrix(0, 2) * firstPoint[2] +
                                          firstMatrix(0, 3) * firstPoint[3],

                                      firstMatrix(1, 0) * firstPoint[0] +
                                          firstMatrix(1, 1) * firstPoint[1] +
                                          firstMatrix(1, 2) * firstPoint[2] +
                                          firstMatrix(1, 3) * firstPoint[3],

                                      firstMatrix(2, 0) * firstPoint[0] +
                                          firstMatrix(2, 1) * firstPoint[1] +
                                          firstMatrix(2, 2) * firstPoint[2] +
                                          firstMatrix(2, 3) * firstPoint[3],

                                      firstMatrix(3, 0) * firstPoint[0] +
                                          firstMatrix(3, 1) * firstPoint[1] +
                                          firstMatrix(3, 2) * firstPoint[2] +
                                          firstMatrix(3, 3) * firstPoint[3]);

        ASSERT_TRUE(Approximate(secondPoint, fourthPoint, 1e-02f));

        fourthPoint[0] = firstMatrix(0, 0) * firstPoint[0] +
                         firstMatrix(1, 0) * firstPoint[1] +
                         firstMatrix(2, 0) * firstPoint[2] +
                         firstMatrix(3, 0) * firstPoint[3];

        fourthPoint[1] = firstMatrix(0, 1) * firstPoint[0] +
                         firstMatrix(1, 1) * firstPoint[1] +
                         firstMatrix(2, 1) * firstPoint[2] +
                         firstMatrix(3, 1) * firstPoint[3];

        fourthPoint[2] = firstMatrix(0, 2) * firstPoint[0] +
                         firstMatrix(1, 2) * firstPoint[1] +
                         firstMatrix(2, 2) * firstPoint[2] +
                         firstMatrix(3, 2) * firstPoint[3];

        fourthPoint[3] = firstMatrix(0, 3) * firstPoint[0] +
                         firstMatrix(1, 3) * firstPoint[1] +
                         firstMatrix(2, 3) * firstPoint[2] +
                         firstMatrix(3, 3) * firstPoint[3];

        ASSERT_TRUE(Approximate(thirdPoint, fourthPoint, 1e-02f));

        APointF seventhPoint(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        const APointF eighthPoint = firstMatrix * seventhPoint;

        const APointF ninthPoint(firstMatrix(0, 0) * seventhPoint[0] +
                                     firstMatrix(0, 1) * seventhPoint[1] +
                                     firstMatrix(0, 2) * seventhPoint[2] +
                                     firstMatrix(0, 3),

                                 firstMatrix(1, 0) * seventhPoint[0] +
                                     firstMatrix(1, 1) * seventhPoint[1] +
                                     firstMatrix(1, 2) * seventhPoint[2] +
                                     firstMatrix(1, 3),

                                 firstMatrix(2, 0) * seventhPoint[0] +
                                     firstMatrix(2, 1) * seventhPoint[1] +
                                     firstMatrix(2, 2) * seventhPoint[2] +
                                     firstMatrix(2, 3));

        ASSERT_TRUE(Approximate(eighthPoint, ninthPoint, 1e-02f));

        AVectorF firstVector(randomDistribution(generator),
                             randomDistribution(generator),
                             randomDistribution(generator));

        const AVectorF secondVector = firstMatrix * firstVector;

        const AVectorF thirdVector(firstMatrix(0, 0) * firstVector[0] +
                                       firstMatrix(0, 1) * firstVector[1] +
                                       firstMatrix(0, 2) * firstVector[2],

                                   firstMatrix(1, 0) * firstVector[0] +
                                       firstMatrix(1, 1) * firstVector[1] +
                                       firstMatrix(1, 2) * firstVector[2],

                                   firstMatrix(2, 0) * firstVector[0] +
                                       firstMatrix(2, 1) * firstVector[1] +
                                       firstMatrix(2, 2) * firstVector[2]);

        ASSERT_TRUE(Approximate(secondVector, thirdVector, 1e-02f));
    }

    vector<HomogeneousPointF> firstPointVector;
    vector<APointF> firstAPointVector;
    vector<AVectorF> firstVectorVector;

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const HomogeneousPointF fifthPoint(randomDistribution(generator),
                                           randomDistribution(generator),
                                           randomDistribution(generator),
                                           randomDistribution(generator));

        firstPointVector.push_back(fifthPoint);

        const APointF tenthPoint(randomDistribution(generator),
                                 randomDistribution(generator),
                                 randomDistribution(generator));

        firstAPointVector.push_back(tenthPoint);

        const AVectorF fourthVector(randomDistribution(generator),
                                    randomDistribution(generator),
                                    randomDistribution(generator));

        firstVectorVector.push_back(fourthVector);
    }

    MatrixF secondMatrix(randomDistribution(generator),
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

    vector<HomogeneousPointF> secondPointVector = BatchMultiply(secondMatrix, firstPointVector);

    vector<APointF> secondAPointVector = BatchMultiply(secondMatrix, firstAPointVector);

    vector<AVectorF> secondVectorVector = BatchMultiply(secondMatrix, firstVectorVector);

    for (size_t i = 0; i < secondPointVector.size(); ++i)
    {
        const HomogeneousPointF sixthPoint(secondMatrix(0, 0) * firstPointVector.at(i)[0] +
                                               secondMatrix(0, 1) * firstPointVector.at(i)[1] +
                                               secondMatrix(0, 2) * firstPointVector.at(i)[2] +
                                               secondMatrix(0, 3) * firstPointVector.at(i)[3],

                                           secondMatrix(1, 0) * firstPointVector.at(i)[0] +
                                               secondMatrix(1, 1) * firstPointVector.at(i)[1] +
                                               secondMatrix(1, 2) * firstPointVector.at(i)[2] +
                                               secondMatrix(1, 3) * firstPointVector.at(i)[3],

                                           secondMatrix(2, 0) * firstPointVector.at(i)[0] +
                                               secondMatrix(2, 1) * firstPointVector.at(i)[1] +
                                               secondMatrix(2, 2) * firstPointVector.at(i)[2] +
                                               secondMatrix(2, 3) * firstPointVector.at(i)[3],

                                           secondMatrix(3, 0) * firstPointVector.at(i)[0] +
                                               secondMatrix(3, 1) * firstPointVector.at(i)[1] +
                                               secondMatrix(3, 2) * firstPointVector.at(i)[2] +
                                               secondMatrix(3, 3) * firstPointVector.at(i)[3]);

        ASSERT_TRUE(Approximate(sixthPoint, secondPointVector.at(i), 1e-02f));

        const APointF eleventhPoint(secondMatrix(0, 0) * firstAPointVector.at(i)[0] +
                                        secondMatrix(0, 1) * firstAPointVector.at(i)[1] +
                                        secondMatrix(0, 2) * firstAPointVector.at(i)[2] +
                                        secondMatrix(0, 3),

                                    secondMatrix(1, 0) * firstAPointVector.at(i)[0] +
                                        secondMatrix(1, 1) * firstAPointVector.at(i)[1] +
                                        secondMatrix(1, 2) * firstAPointVector.at(i)[2] +
                                        secondMatrix(1, 3),

                                    secondMatrix(2, 0) * firstAPointVector.at(i)[0] +
                                        secondMatrix(2, 1) * firstAPointVector.at(i)[1] +
                                        secondMatrix(2, 2) * firstAPointVector.at(i)[2] +
                                        secondMatrix(2, 3));

        ASSERT_TRUE(Approximate(eleventhPoint, secondAPointVector.at(i), 1e-03f));

        const AVectorF fifthVector(secondMatrix(0, 0) * firstVectorVector.at(i)[0] +
                                       secondMatrix(0, 1) * firstVectorVector.at(i)[1] +
                                       secondMatrix(0, 2) * firstVectorVector.at(i)[2],

                                   secondMatrix(1, 0) * firstVectorVector.at(i)[0] +
                                       secondMatrix(1, 1) * firstVectorVector.at(i)[1] +
                                       secondMatrix(1, 2) * firstVectorVector.at(i)[2],

                                   secondMatrix(2, 0) * firstVectorVector.at(i)[0] +
                                       secondMatrix(2, 1) * firstVectorVector.at(i)[1] +
                                       secondMatrix(2, 2) * firstVectorVector.at(i)[2]);

        ASSERT_TRUE(Approximate(fifthVector, secondVectorVector.at(i), 1e-03f));
    }
}

void Mathematics::MatrixTesting::Invert3x3Test()
{
    default_random_engine generator{};
    const uniform_real<float> randomDistribution{ -10.0f, 10.0f };

    const auto aTestLoopCount = GetTestLoopCount();

    for (auto loop = 0; loop < aTestLoopCount; ++loop)
    {
        const MatrixF firstMatrix(randomDistribution(generator),
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

        const Matrix3F secondMatrix = firstMatrix.GetMatrix3();

        if (MathF::GetZeroTolerance() < secondMatrix.Determinant())
        {
            const MatrixF thirdMatrix = firstMatrix.Invert3x3();

            const Matrix3F fourthMatrix = thirdMatrix.GetMatrix3();

            const Matrix3F fifthMatrix = secondMatrix.Inverse();

            ASSERT_TRUE(Approximate(fourthMatrix, fifthMatrix, 1e-5f));
        }
    }
}
