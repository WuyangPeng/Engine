// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/28 14:44)

#include "QueryDotToolsTesting.h"
#include "Mathematics/Query/QueryDotToolsDetail.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Algebra/Vector4DDetail.h"
#include "Mathematics/Algebra/Matrix4Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class QueryDotTools<double>;
	template class QueryDotTools<float>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, QueryDotToolsTesting) 

void Mathematics::QueryDotToolsTesting
	::MainTest()
{
	 ASSERT_NOT_THROW_EXCEPTION_0(DotTest);
	 ASSERT_NOT_THROW_EXCEPTION_0(Det2Test);
	 ASSERT_NOT_THROW_EXCEPTION_0(Det3Test);
}

void Mathematics::QueryDotToolsTesting
	::DotTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D firstVector(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D secondVector(firstRandomDistribution(generator), firstRandomDistribution(generator));

		ASSERT_APPROXIMATE(DoubleVector2DTools::DotProduct(firstVector,secondVector),
			               DoubleQueryDotTools::Dot(firstVector[0],firstVector[1],secondVector[0],secondVector[1]),1e-8f);

		DoubleVector3D thirdVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector3D fourthVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

		ASSERT_APPROXIMATE(DoubleVector3DTools::DotProduct(thirdVector, fourthVector),DoubleQueryDotTools::Dot(thirdVector[0], thirdVector[1], thirdVector[2],fourthVector[0], fourthVector[1], fourthVector[2]), 1e-8f);
	}
}

void Mathematics::QueryDotToolsTesting
	::Det2Test()
{
	default_random_engine generator;
	uniform_real<float> firstRandomDistribution(-100.0f, 100.0f);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector2D firstVector(firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector2D secondVector(firstRandomDistribution(generator), firstRandomDistribution(generator));

		ASSERT_APPROXIMATE(DoubleVector2DTools::DotPerp(firstVector,secondVector), DoubleQueryDotTools::Det2(firstVector[0],firstVector[1],secondVector[0],secondVector[1]),1e-8f);
	
	}
}

void Mathematics::QueryDotToolsTesting
	::Det3Test()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D firstVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector3D secondVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector3D thirdVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

		ASSERT_APPROXIMATE(DoubleVector3DTools::ScalarTripleProduct(firstVector, secondVector, thirdVector),
			               DoubleQueryDotTools::Det3(firstVector[0],firstVector[1],firstVector[2], secondVector[0],secondVector[1],secondVector[2], thirdVector[0], thirdVector[1], thirdVector[2]), 1e-8f);

		DoubleVector4D fourthVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector4D fifthVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector4D sixthVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));
		DoubleVector4D seventhVector(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator));

		DoubleMatrix4 matrix(fourthVector[0], fourthVector[1], fourthVector[2], fourthVector[3] , 
			            fifthVector[0], fifthVector[1], fifthVector[2], fifthVector[3] , 
						sixthVector[0], sixthVector[1], sixthVector[2], sixthVector[3],
						seventhVector[0], seventhVector[1], seventhVector[2], seventhVector[3]);

		ASSERT_APPROXIMATE(matrix.Determinant(),
						   DoubleQueryDotTools::Det4(fourthVector[0], fourthVector[1], fourthVector[2], fourthVector[3],
			                                    fifthVector[0], fifthVector[1], fifthVector[2], fifthVector[3],
												sixthVector[0], sixthVector[1], sixthVector[2], sixthVector[3],
												seventhVector[0], seventhVector[1], seventhVector[2], seventhVector[3]), 1e-6);
	}
}

