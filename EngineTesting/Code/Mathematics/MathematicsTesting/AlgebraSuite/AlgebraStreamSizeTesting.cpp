// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/19 18:17)

#include "AlgebraStreamSizeTesting.h"
#include "Mathematics/Algebra/AlgebraStreamSize.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h" 

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, AlgebraStreamSizeTesting) 

void Mathematics::AlgebraStreamSizeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(StreamSizeTest); 
}

void Mathematics::AlgebraStreamSizeTesting
	::StreamSizeTest()
{
	size_t size = MATHEMATICS_STREAM_SIZE(FloatHomogeneousPoint());

	ASSERT_EQUAL(size,sizeof(float) * 4);

	size = MATHEMATICS_STREAM_SIZE(DoubleHomogeneousPoint());

	ASSERT_EQUAL(size,sizeof(double) * 4);

	size = MATHEMATICS_STREAM_SIZE(FloatVector2D());

	ASSERT_EQUAL(size,sizeof(float) * 2);

	size = MATHEMATICS_STREAM_SIZE(DoubleVector2D());

	ASSERT_EQUAL(size,sizeof(double) * 2);

	size = MATHEMATICS_STREAM_SIZE(FloatVector3D());

	ASSERT_EQUAL(size,sizeof(float) * 3);

	size = MATHEMATICS_STREAM_SIZE(DoubleVector3D());

	ASSERT_EQUAL(size,sizeof(double) * 3);

	size = MATHEMATICS_STREAM_SIZE(FloatVector4D());

	ASSERT_EQUAL(size,sizeof(float) * 4);

	size = MATHEMATICS_STREAM_SIZE(DoubleVector4D());

	ASSERT_EQUAL(size,sizeof(double) * 4);

	size = MATHEMATICS_STREAM_SIZE(FloatAVector());

	ASSERT_EQUAL(size,sizeof(float) * 3);

	size = MATHEMATICS_STREAM_SIZE(DoubleAVector());

	ASSERT_EQUAL(size,sizeof(double) * 3);

	size = MATHEMATICS_STREAM_SIZE(FloatAPoint());

	ASSERT_EQUAL(size,sizeof(float) * 3);

	size = MATHEMATICS_STREAM_SIZE(DoubleAPoint());

	ASSERT_EQUAL(size,sizeof(double) * 3);

	size = MATHEMATICS_STREAM_SIZE(FloatVariableLengthVector(7));

	ASSERT_EQUAL(size,sizeof(float) * 7 + sizeof(int));

	size = MATHEMATICS_STREAM_SIZE(DoubleVariableLengthVector(8));

	ASSERT_EQUAL(size,sizeof(double) * 8 + sizeof(int));

	size = MATHEMATICS_STREAM_SIZE(FloatPlane());

	ASSERT_EQUAL(size,sizeof(float) * 5);

	size = MATHEMATICS_STREAM_SIZE(DoublePlane());

	ASSERT_EQUAL(size,sizeof(double) * 5);

	size = MATHEMATICS_STREAM_SIZE(FloatPolynomial(7));

	ASSERT_EQUAL(size,sizeof(float) * (7 + 1) + sizeof(int));

	size = MATHEMATICS_STREAM_SIZE(DoublePolynomial(9));

	ASSERT_EQUAL(size,sizeof(double) * (9 + 1) + sizeof(int));

	size = MATHEMATICS_STREAM_SIZE(FloatMatrix2());

	ASSERT_EQUAL(size,sizeof(float) * 2 * 2);

	size = MATHEMATICS_STREAM_SIZE(DoubleMatrix2());

	ASSERT_EQUAL(size,sizeof(double) * 2 * 2);

	size = MATHEMATICS_STREAM_SIZE(FloatMatrix3());

	ASSERT_EQUAL(size,sizeof(float) * 3 * 3);

	size = MATHEMATICS_STREAM_SIZE(DoubleMatrix3());

	ASSERT_EQUAL(size,sizeof(double) * 3 * 3);

	size = MATHEMATICS_STREAM_SIZE(FloatMatrix4());

	ASSERT_EQUAL(size,sizeof(float) * 4 * 4);

	size = MATHEMATICS_STREAM_SIZE(DoubleMatrix4());

	ASSERT_EQUAL(size,sizeof(double) * 4 * 4);

	size = MATHEMATICS_STREAM_SIZE(FloatMatrix());

	ASSERT_EQUAL(size,sizeof(float) * 16);

	size = MATHEMATICS_STREAM_SIZE(DoubleMatrix());

	ASSERT_EQUAL(size,sizeof(double) * 16);

	size = MATHEMATICS_STREAM_SIZE(FloatVariableMatrix(5,7));

	ASSERT_EQUAL(size,sizeof(float) * 5 * 7 + sizeof(int) * 2);

	size = MATHEMATICS_STREAM_SIZE(DoubleVariableMatrix(6,8));

	ASSERT_EQUAL(size,sizeof(double) * 6 * 8 + sizeof(int) * 2);

	size = MATHEMATICS_STREAM_SIZE(FloatBandedMatrix(7,2,2));

	ASSERT_EQUAL(size,boost::numeric_cast<size_t>(FloatBandedMatrix(7,2,2).GetStreamSize()));

	size = MATHEMATICS_STREAM_SIZE(DoubleBandedMatrix(5,1,2));

	ASSERT_EQUAL(size, boost::numeric_cast<size_t>(DoubleBandedMatrix(5,1,2).GetStreamSize()));

	size = MATHEMATICS_STREAM_SIZE(FloatBandedMatrixSolve(3,1,1));

	ASSERT_EQUAL(size, boost::numeric_cast<size_t>(FloatBandedMatrixSolve(3,1,1).GetStreamSize()));

	size = MATHEMATICS_STREAM_SIZE(DoubleBandedMatrixSolve(7,3,5));

	ASSERT_EQUAL(size, boost::numeric_cast<size_t>(DoubleBandedMatrixSolve(7,3,5).GetStreamSize()));

	size = MATHEMATICS_STREAM_SIZE(FloatQuaternion());

	ASSERT_EQUAL(size,sizeof(float) * 4);

	size = MATHEMATICS_STREAM_SIZE(DoubleQuaternion());

	ASSERT_EQUAL(size,sizeof(double) * 4);

	size = MATHEMATICS_STREAM_SIZE(FloatAQuaternion());

	ASSERT_EQUAL(size,sizeof(float) * 4);

	size = MATHEMATICS_STREAM_SIZE(DoubleAQuaternion());

	ASSERT_EQUAL(size,sizeof(double) * 4);

	size = MATHEMATICS_STREAM_SIZE(Float1(0.0f));

	ASSERT_EQUAL(size,sizeof(float));

	size = MATHEMATICS_STREAM_SIZE(Float2(0.0f,0.0f));

	ASSERT_EQUAL(size,sizeof(float) * 2);

	size = MATHEMATICS_STREAM_SIZE(Float3(0.0f,0.0f,0.0f));

	ASSERT_EQUAL(size,sizeof(float) * 3);

	size = MATHEMATICS_STREAM_SIZE(Float4(0.0f,0.0f,0.0f,0.0f));

	ASSERT_EQUAL(size,sizeof(float) * 4);
}

