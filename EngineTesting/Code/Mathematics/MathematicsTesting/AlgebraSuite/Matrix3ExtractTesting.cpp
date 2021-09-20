// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 16:01)

#include "Matrix3ExtractTesting.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Algebra/Matrix3ExtractDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/Algebra/Vector3DTools.h"

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Matrix3Extract<float>;
	template class Matrix3Extract<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Matrix3ExtractTesting) 

void Mathematics::Matrix3ExtractTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(ExtractTest); 
}

void Mathematics::Matrix3ExtractTesting
	::ExtractTest()
{
	default_random_engine generator{};
	uniform_real<double> randomDistribution{ -10.0,10.0 };
	uniform_real<double> angleDistribution(0.0, DoubleMath::GetPI());

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D firstVector{ randomDistribution(generator),randomDistribution(generator),randomDistribution(generator) };
		firstVector.Normalize();

		double angle = angleDistribution(generator);

		DoubleMatrix3 firstMatrix(firstVector,angle);

		DoubleMatrix3Extract matrix3Extract = firstMatrix.ExtractAngleAxis();

		ASSERT_APPROXIMATE(matrix3Extract.GetAngle(),angle,1e-10); 

		ASSERT_TRUE(DoubleVector3DTools::Approximate(matrix3Extract.GetAxis(), firstVector)); 
	}	

}

