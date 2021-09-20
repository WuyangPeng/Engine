// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 13:08)

#include "Vector3DOrthonormalBasisTesting.h"
#include "Mathematics/Algebra/Vector3DOrthonormalBasisDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  
#include "Mathematics/Algebra/Vector3DTools.h"

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Vector3DOrthonormalBasis<float>;
	template class Vector3DOrthonormalBasis<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector3DOrthonormalBasisTesting) 

void Mathematics::Vector3DOrthonormalBasisTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalBasisTest); 
}

void Mathematics::Vector3DOrthonormalBasisTesting
	::OrthonormalBasisTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution{ -10.0,10.0 };
	uniform_real<float> secondRandomDistribution{ -10.0f,10.0f }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D firstVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
			                  firstRandomDistribution(generator)); 

		FloatVector3D secondVector(secondRandomDistribution(generator),
			                   secondRandomDistribution(generator),
			                   secondRandomDistribution(generator));

		DoubleVector3DOrthonormalBasis firstOrthonormalBasis(firstVector,false);

		firstVector.Normalize();

		ASSERT_TRUE(DoubleVector3DTools::Approximate(firstVector,firstOrthonormalBasis.GetWVector(),1e-10)); 

		FloatVector3DOrthonormalBasis secondOrthonormalBasis(secondVector,false);

		secondVector.Normalize(); 

		ASSERT_TRUE(FloatVector3DTools::Approximate(secondVector,secondOrthonormalBasis.GetWVector(),1e-8f)); 
	}	
}

