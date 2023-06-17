///	Copyright (c) 2010-2023
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.9.0.12 (2023/06/09 11:15)

#include "AlgebraStreamSizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/UnitTestSuite/UnitTestDetail.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"

Mathematics::AlgebraStreamSizeTesting::AlgebraStreamSizeTesting(const OStreamShared& streamShared)
    : ParentType{ streamShared }
{
    MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

CLASS_INVARIANT_PARENT_IS_VALID_DEFINE(Mathematics, AlgebraStreamSizeTesting)

void Mathematics::AlgebraStreamSizeTesting::DoRunUnitTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(MainTest);
}

void Mathematics::AlgebraStreamSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StreamSizeTest);
}

void Mathematics::AlgebraStreamSizeTesting::StreamSizeTest()
{
    auto size = boost::numeric_cast<size_t>(Mathematics::GetStreamSize(HomogeneousPointF()));

    ASSERT_EQUAL(size, sizeof(float) * 4);

    size = Mathematics::GetStreamSize(HomogeneousPointD());

    ASSERT_EQUAL(size, sizeof(double) * 4);

    size = Mathematics::GetStreamSize(Vector2F());

    ASSERT_EQUAL(size, sizeof(float) * 2);

    size = Mathematics::GetStreamSize(Vector2D());

    ASSERT_EQUAL(size, sizeof(double) * 2);

    size = Mathematics::GetStreamSize(Vector3F());

    ASSERT_EQUAL(size, sizeof(float) * 3);

    size = Mathematics::GetStreamSize(Vector3D());

    ASSERT_EQUAL(size, sizeof(double) * 3);

    size = Mathematics::GetStreamSize(Vector4F());

    ASSERT_EQUAL(size, sizeof(float) * 4);

    size = Mathematics::GetStreamSize(Vector4D());

    ASSERT_EQUAL(size, sizeof(double) * 4);

    size = Mathematics::GetStreamSize(AVectorF());

    ASSERT_EQUAL(size, sizeof(float) * 3);

    size = Mathematics::GetStreamSize(AVectorD());

    ASSERT_EQUAL(size, sizeof(double) * 3);

    size = Mathematics::GetStreamSize(APointF());

    ASSERT_EQUAL(size, sizeof(float) * 3);

    size = Mathematics::GetStreamSize(APointD());

    ASSERT_EQUAL(size, sizeof(double) * 3);

    size = Mathematics::GetStreamSize(VariableLengthVectorF(7));

    ASSERT_EQUAL(size, sizeof(float) * 7 + sizeof(int));

    size = Mathematics::GetStreamSize(VariableLengthVectorD(8));

    ASSERT_EQUAL(size, sizeof(double) * 8 + sizeof(int));

    size = Mathematics::GetStreamSize(PlaneF());

    ASSERT_EQUAL(size, sizeof(float) * 5);

    size = Mathematics::GetStreamSize(PlaneD());

    ASSERT_EQUAL(size, sizeof(double) * 5);

    size = Mathematics::GetStreamSize(PolynomialF(7));

    ASSERT_EQUAL(size, sizeof(float) * (7 + 1) + sizeof(int));

    size = Mathematics::GetStreamSize(PolynomialD(9));

    ASSERT_EQUAL(size, sizeof(double) * (9 + 1) + sizeof(int));

    size = Mathematics::GetStreamSize(Matrix2F());

    ASSERT_EQUAL(size, sizeof(float) * 2 * 2);

    size = Mathematics::GetStreamSize(Matrix2D());

    ASSERT_EQUAL(size, sizeof(double) * 2 * 2);

    size = Mathematics::GetStreamSize(Matrix3F());

    ASSERT_EQUAL(size, sizeof(float) * 3 * 3);

    size = Mathematics::GetStreamSize(Matrix3D());

    ASSERT_EQUAL(size, sizeof(double) * 3 * 3);

    size = Mathematics::GetStreamSize(Matrix4F());

    ASSERT_EQUAL(size, sizeof(float) * 4 * 4);

    size = Mathematics::GetStreamSize(Matrix4D());

    ASSERT_EQUAL(size, sizeof(double) * 4 * 4);

    size = Mathematics::GetStreamSize(MatrixF());

    ASSERT_EQUAL(size, sizeof(float) * 16);

    size = Mathematics::GetStreamSize(MatrixD());

    ASSERT_EQUAL(size, sizeof(double) * 16);

    size = Mathematics::GetStreamSize(VariableMatrixF(5, 7));

    ASSERT_EQUAL(size, sizeof(float) * 5 * 7 + sizeof(int) * 2);

    size = Mathematics::GetStreamSize(VariableMatrixD(6, 8));

    ASSERT_EQUAL(size, sizeof(double) * 6 * 8 + sizeof(int) * 2);

    size = Mathematics::GetStreamSize(BandedMatrixF(7, 2, 2));

    ASSERT_EQUAL(size, boost::numeric_cast<size_t>(BandedMatrixF(7, 2, 2).GetStreamSize()));

    size = Mathematics::GetStreamSize(BandedMatrixD(5, 1, 2));

    ASSERT_EQUAL(size, boost::numeric_cast<size_t>(BandedMatrixD(5, 1, 2).GetStreamSize()));

    size = Mathematics::GetStreamSize(BandedMatrixSolveF(3, 1, 1));

    ASSERT_EQUAL(size, boost::numeric_cast<size_t>(BandedMatrixSolveF(3, 1, 1).GetStreamSize()));

    size = Mathematics::GetStreamSize(BandedMatrixSolveD(7, 3, 5));

    ASSERT_EQUAL(size, boost::numeric_cast<size_t>(BandedMatrixSolveD(7, 3, 5).GetStreamSize()));

    size = Mathematics::GetStreamSize(QuaternionF());

    ASSERT_EQUAL(size, sizeof(float) * 4);

    size = Mathematics::GetStreamSize(QuaternionD());

    ASSERT_EQUAL(size, sizeof(double) * 4);

    size = Mathematics::GetStreamSize(AQuaternionF());

    ASSERT_EQUAL(size, sizeof(float) * 4);

    size = Mathematics::GetStreamSize(AQuaternionD());

    ASSERT_EQUAL(size, sizeof(double) * 4);

    size = Mathematics::GetStreamSize(Float1(0.0f));

    ASSERT_EQUAL(size, sizeof(float));

    size = Mathematics::GetStreamSize(Float2(0.0f, 0.0f));

    ASSERT_EQUAL(size, sizeof(float) * 2);

    size = Mathematics::GetStreamSize(Float3(0.0f, 0.0f, 0.0f));

    ASSERT_EQUAL(size, sizeof(float) * 3);

    size = Mathematics::GetStreamSize(Float4(0.0f, 0.0f, 0.0f, 0.0f));

    ASSERT_EQUAL(size, sizeof(float) * 4);
}
