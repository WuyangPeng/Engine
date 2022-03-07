// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 13:08)

#include "Vector3DOrthonormalBasisTesting.h"
#include "Mathematics/Algebra/Vector3OrthonormalBasisDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  
#include "Mathematics/Algebra/Vector3Tools.h"

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Vector3OrthonormalBasis<float>;
	template class Vector3OrthonormalBasis<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector3OrthonormalBasisTesting) 

void Mathematics::Vector3OrthonormalBasisTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalBasisTest); 
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
void Mathematics::Vector3OrthonormalBasisTesting
	::OrthonormalBasisTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution{ -10.0,10.0 };
	uniform_real<float> secondRandomDistribution{ -10.0f,10.0f }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector3D firstVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
			                  firstRandomDistribution(generator)); 

		Vector3F secondVector(secondRandomDistribution(generator),
			                   secondRandomDistribution(generator),
			                   secondRandomDistribution(generator));

		Vector3OrthonormalBasisD firstOrthonormalBasis(firstVector,false);

		firstVector.Normalize();

		ASSERT_TRUE(Vector3ToolsD::Approximate(firstVector,firstOrthonormalBasis.GetWVector(),1e-10)); 

		Vector3OrthonormalBasisF secondOrthonormalBasis(secondVector,false);

		secondVector.Normalize(); 

		ASSERT_TRUE(Vector3ToolsF::Approximate(secondVector,secondOrthonormalBasis.GetWVector(),1e-8f)); 
	}	
}

