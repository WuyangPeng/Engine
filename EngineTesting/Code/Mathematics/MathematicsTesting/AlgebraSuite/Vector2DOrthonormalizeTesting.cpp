// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 11:07)

#include "Vector2DOrthonormalizeTesting.h"
#include "Mathematics/Algebra/Vector2OrthonormalizeDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  
#include "Mathematics/Algebra/Vector2Tools.h"

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Vector2Orthonormalize<float>;
	template class Vector2Orthonormalize<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector2OrthonormalizeTesting) 

void Mathematics::Vector2OrthonormalizeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalizeTest); 
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
void Mathematics::Vector2OrthonormalizeTesting
	::OrthonormalizeTest()
{
	default_random_engine generator{};

	uniform_real<double> firstRandomDistribution{ -10.0,10.0 };
	uniform_real<float> secondRandomDistribution{ -10.0f,10.0f };

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		Vector2 firstVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator));
		Vector2 secondVector(firstRandomDistribution(generator),
			                   firstRandomDistribution(generator));


		Vector2F thirdVector(secondRandomDistribution(generator),
			                  secondRandomDistribution(generator));
		Vector2F fourthVector(secondRandomDistribution(generator),
			                   secondRandomDistribution(generator));

		Vector2OrthonormalizeD firstOrthonormalize(firstVector,secondVector,1e-10);

		firstVector.Normalize();
		double dot0 = Vector2ToolsD::DotProduct(firstVector, secondVector); 
		secondVector -= firstVector * dot0;
		secondVector.Normalize();

		ASSERT_TRUE(Vector2ToolsD::Approximate(firstVector,firstOrthonormalize.GetUVector(),1e-10));

		ASSERT_TRUE(Vector2ToolsD::Approximate(secondVector,firstOrthonormalize.GetVVector(),1e-10));

		Vector2OrthonormalizeF secondOrthonormalize(thirdVector, fourthVector,1e-5f);

		thirdVector.Normalize();
		float dot1 = Vector2ToolsF::DotProduct(thirdVector, fourthVector); 
		fourthVector -= thirdVector * dot1;
		fourthVector.Normalize();

		ASSERT_TRUE(Vector2ToolsF::Approximate(thirdVector,secondOrthonormalize.GetUVector(),1e-8f));

		ASSERT_TRUE(Vector2ToolsF::Approximate(fourthVector,secondOrthonormalize.GetVVector(),1e-8f));
	}
}

