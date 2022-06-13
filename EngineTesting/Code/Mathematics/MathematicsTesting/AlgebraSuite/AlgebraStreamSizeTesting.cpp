///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.8 (2022/06/08 18:30)

#include "AlgebraStreamSizeTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, AlgebraStreamSizeTesting)

void Mathematics::AlgebraStreamSizeTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(StreamSizeTest);
}

void Mathematics::AlgebraStreamSizeTesting::StreamSizeTest()
{
    size_t size = MATHEMATICS_STREAM_SIZE(HomogeneousPointF());

    ASSERT_EQUAL(size, sizeof(float) * 4);

    size = MATHEMATICS_STREAM_SIZE(HomogeneousPointD());

    ASSERT_EQUAL(size, sizeof(double) * 4);

    size = MATHEMATICS_STREAM_SIZE(Vector2F());

    ASSERT_EQUAL(size, sizeof(float) * 2);

    size = MATHEMATICS_STREAM_SIZE(Vector2D());

    ASSERT_EQUAL(size, sizeof(double) * 2);

    size = MATHEMATICS_STREAM_SIZE(Vector3F());

    ASSERT_EQUAL(size, sizeof(float) * 3);

    size = MATHEMATICS_STREAM_SIZE(Vector3D());

    ASSERT_EQUAL(size, sizeof(double) * 3);

    size = MATHEMATICS_STREAM_SIZE(Vector4F());

    ASSERT_EQUAL(size, sizeof(float) * 4);

    size = MATHEMATICS_STREAM_SIZE(Vector4D());

    ASSERT_EQUAL(size, sizeof(double) * 4);

    size = MATHEMATICS_STREAM_SIZE(AVectorF());

    ASSERT_EQUAL(size, sizeof(float) * 3);

    size = MATHEMATICS_STREAM_SIZE(AVectorD());

    ASSERT_EQUAL(size, sizeof(double) * 3);

    size = MATHEMATICS_STREAM_SIZE(APointF());

    ASSERT_EQUAL(size, sizeof(float) * 3);

    size = MATHEMATICS_STREAM_SIZE(APointD());

    ASSERT_EQUAL(size, sizeof(double) * 3);

    size = MATHEMATICS_STREAM_SIZE(VariableLengthVectorF(7));

    ASSERT_EQUAL(size, sizeof(float) * 7 + sizeof(int));

    size = MATHEMATICS_STREAM_SIZE(VariableLengthVectorD(8));

    ASSERT_EQUAL(size, sizeof(double) * 8 + sizeof(int));

    size = MATHEMATICS_STREAM_SIZE(PlaneF());

    ASSERT_EQUAL(size, sizeof(float) * 5);

    size = MATHEMATICS_STREAM_SIZE(PlaneD());

    ASSERT_EQUAL(size, sizeof(double) * 5);

    size = MATHEMATICS_STREAM_SIZE(PolynomialF(7));

    ASSERT_EQUAL(size, sizeof(float) * (7 + 1) + sizeof(int));

    size = MATHEMATICS_STREAM_SIZE(PolynomialD(9));

    ASSERT_EQUAL(size, sizeof(double) * (9 + 1) + sizeof(int));

    size = MATHEMATICS_STREAM_SIZE(Matrix2F());

    ASSERT_EQUAL(size, sizeof(float) * 2 * 2);

    size = MATHEMATICS_STREAM_SIZE(Matrix2D());

    ASSERT_EQUAL(size, sizeof(double) * 2 * 2);

    size = MATHEMATICS_STREAM_SIZE(Matrix3F());

    ASSERT_EQUAL(size, sizeof(float) * 3 * 3);

    size = MATHEMATICS_STREAM_SIZE(Matrix3D());

    ASSERT_EQUAL(size, sizeof(double) * 3 * 3);

    size = MATHEMATICS_STREAM_SIZE(Matrix4F());

    ASSERT_EQUAL(size, sizeof(float) * 4 * 4);

    size = MATHEMATICS_STREAM_SIZE(Matrix4D());

    ASSERT_EQUAL(size, sizeof(double) * 4 * 4);

    size = MATHEMATICS_STREAM_SIZE(MatrixF());

    ASSERT_EQUAL(size, sizeof(float) * 16);

    size = MATHEMATICS_STREAM_SIZE(MatrixD());

    ASSERT_EQUAL(size, sizeof(double) * 16);

    size = MATHEMATICS_STREAM_SIZE(VariableMatrixF(5, 7));

    ASSERT_EQUAL(size, sizeof(float) * 5 * 7 + sizeof(int) * 2);

    size = MATHEMATICS_STREAM_SIZE(VariableMatrixD(6, 8));

    ASSERT_EQUAL(size, sizeof(double) * 6 * 8 + sizeof(int) * 2);

    size = MATHEMATICS_STREAM_SIZE(BandedMatrixF(7, 2, 2));

    ASSERT_EQUAL(size, boost::numeric_cast<size_t>(BandedMatrixF(7, 2, 2).GetStreamSize()));

    size = MATHEMATICS_STREAM_SIZE(BandedMatrixD(5, 1, 2));

    ASSERT_EQUAL(size, boost::numeric_cast<size_t>(BandedMatrixD(5, 1, 2).GetStreamSize()));

    size = MATHEMATICS_STREAM_SIZE(BandedMatrixSolveF(3, 1, 1));

    ASSERT_EQUAL(size, boost::numeric_cast<size_t>(BandedMatrixSolveF(3, 1, 1).GetStreamSize()));

    size = MATHEMATICS_STREAM_SIZE(BandedMatrixSolveD(7, 3, 5));

    ASSERT_EQUAL(size, boost::numeric_cast<size_t>(BandedMatrixSolveD(7, 3, 5).GetStreamSize()));

    size = MATHEMATICS_STREAM_SIZE(QuaternionF());

    ASSERT_EQUAL(size, sizeof(float) * 4);

    size = MATHEMATICS_STREAM_SIZE(QuaternionD());

    ASSERT_EQUAL(size, sizeof(double) * 4);

    size = MATHEMATICS_STREAM_SIZE(AQuaternionF());

    ASSERT_EQUAL(size, sizeof(float) * 4);

    size = MATHEMATICS_STREAM_SIZE(AQuaternionD());

    ASSERT_EQUAL(size, sizeof(double) * 4);

    size = MATHEMATICS_STREAM_SIZE(Float1(0.0f));

    ASSERT_EQUAL(size, sizeof(float));

    size = MATHEMATICS_STREAM_SIZE(Float2(0.0f, 0.0f));

    ASSERT_EQUAL(size, sizeof(float) * 2);

    size = MATHEMATICS_STREAM_SIZE(Float3(0.0f, 0.0f, 0.0f));

    ASSERT_EQUAL(size, sizeof(float) * 3);

    size = MATHEMATICS_STREAM_SIZE(Float4(0.0f, 0.0f, 0.0f, 0.0f));

    ASSERT_EQUAL(size, sizeof(float) * 4);
}
