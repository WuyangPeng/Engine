// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 13:12)

#include "Vector3DOrthonormalizeTesting.h"
#include "Mathematics/Algebra/Vector3DOrthonormalizeDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  
#include "Mathematics/Algebra/Vector3DTools.h"

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Vector3DOrthonormalize<float>;
	template class Vector3DOrthonormalize<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector3DOrthonormalizeTesting) 

void Mathematics::Vector3DOrthonormalizeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalizeTest); 
}

void Mathematics::Vector3DOrthonormalizeTesting
	::OrthonormalizeTest()
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
		DoubleVector3D secondVector(firstRandomDistribution(generator),
			                   firstRandomDistribution(generator),
			                   firstRandomDistribution(generator));
		DoubleVector3D thirdVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
			                  firstRandomDistribution(generator));

		FloatVector3D fourthVector(secondRandomDistribution(generator),
			                   secondRandomDistribution(generator),
			                   secondRandomDistribution(generator));
		FloatVector3D fifthVector(secondRandomDistribution(generator),
			                  secondRandomDistribution(generator),
			                  secondRandomDistribution(generator));
		FloatVector3D sixthVector(secondRandomDistribution(generator),
			                  secondRandomDistribution(generator),
			                  secondRandomDistribution(generator));

		DoubleVector3DOrthonormalize firstOrthonormalize(firstVector,secondVector,thirdVector,1e-10);

		firstVector.Normalize();
		double dot0 = DoubleVector3DTools::DotProduct(firstVector, secondVector); 
		secondVector -= firstVector * dot0;
		secondVector.Normalize();
		dot0 = DoubleVector3DTools::DotProduct(firstVector, thirdVector); 
		thirdVector -= firstVector * dot0;
		dot0 = DoubleVector3DTools::DotProduct(secondVector, thirdVector); 
		thirdVector -= secondVector * dot0;
		thirdVector.Normalize();

		ASSERT_TRUE(DoubleVector3DTools::Approximate(firstVector,firstOrthonormalize.GetUVector(),1e-10));

		ASSERT_TRUE(DoubleVector3DTools::Approximate(secondVector,firstOrthonormalize.GetVVector(),1e-10));

		ASSERT_TRUE(DoubleVector3DTools::Approximate(thirdVector,firstOrthonormalize.GetWVector(),1e-10));

		FloatVector3DOrthonormalize secondOrthonormalize(fourthVector, fifthVector,sixthVector,1e-4f);

		fourthVector.Normalize();
		float dot1 = FloatVector3DTools::DotProduct(fourthVector, fifthVector); 
		fifthVector -= fourthVector * dot1;
		fifthVector.Normalize();

		dot1 = FloatVector3DTools::DotProduct(fourthVector, sixthVector); 
		sixthVector -= fourthVector * dot1;
		dot1 = FloatVector3DTools::DotProduct(fifthVector, sixthVector); 
		sixthVector -= fifthVector * dot1;
		sixthVector.Normalize();

		ASSERT_TRUE(FloatVector3DTools::Approximate(fourthVector,secondOrthonormalize.GetUVector(),1e-8f));

		ASSERT_TRUE(FloatVector3DTools::Approximate(fifthVector,secondOrthonormalize.GetVVector(),1e-8f));
		
		ASSERT_TRUE(FloatVector3DTools::Approximate(sixthVector,secondOrthonormalize.GetWVector(),1e-4f));
	}
}

