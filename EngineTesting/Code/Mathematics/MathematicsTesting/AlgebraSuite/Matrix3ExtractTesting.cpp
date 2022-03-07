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
#include "Mathematics/Algebra/Vector3Tools.h"

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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
void Mathematics::Matrix3ExtractTesting
	::ExtractTest()
{
	default_random_engine generator{};
	uniform_real<double> randomDistribution{ -10.0,10.0 };
	uniform_real<double> angleDistribution(0.0, MathD::GetPI());

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D firstVector{ randomDistribution(generator),randomDistribution(generator),randomDistribution(generator) };
		firstVector.Normalize();

		double angle = angleDistribution(generator);

		Matrix3D firstMatrix(firstVector,angle);

		Matrix3ExtractD matrix3Extract = firstMatrix.ExtractAngleAxis();

		ASSERT_APPROXIMATE(matrix3Extract.GetAngle(),angle,1e-10); 

		ASSERT_TRUE(Vector3ToolsD::Approximate(matrix3Extract.GetAxis(), firstVector)); 
	}	

}

