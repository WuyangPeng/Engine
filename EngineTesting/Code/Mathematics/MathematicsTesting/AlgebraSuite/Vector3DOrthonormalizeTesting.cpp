// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ������԰汾��0.0.0.2 (2019/08/22 13:12)

#include "Vector3DOrthonormalizeTesting.h"
#include "Mathematics/Algebra/Vector3OrthonormalizeDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random>  
#include "Mathematics/Algebra/Vector3Tools.h"

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Vector3Orthonormalize<float>;
	template class Vector3Orthonormalize<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,Vector3OrthonormalizeTesting) 

void Mathematics::Vector3OrthonormalizeTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(OrthonormalizeTest); 
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
void Mathematics::Vector3OrthonormalizeTesting
	::OrthonormalizeTest()
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
		Vector3D secondVector(firstRandomDistribution(generator),
			                   firstRandomDistribution(generator),
			                   firstRandomDistribution(generator));
		Vector3D thirdVector(firstRandomDistribution(generator),
			                  firstRandomDistribution(generator),
			                  firstRandomDistribution(generator));

		Vector3F fourthVector(secondRandomDistribution(generator),
			                   secondRandomDistribution(generator),
			                   secondRandomDistribution(generator));
		Vector3F fifthVector(secondRandomDistribution(generator),
			                  secondRandomDistribution(generator),
			                  secondRandomDistribution(generator));
		Vector3F sixthVector(secondRandomDistribution(generator),
			                  secondRandomDistribution(generator),
			                  secondRandomDistribution(generator));

		Vector3OrthonormalizeD firstOrthonormalize(firstVector,secondVector,thirdVector,1e-10);

		firstVector.Normalize();
		double dot0 = Vector3ToolsD::DotProduct(firstVector, secondVector); 
		secondVector -= firstVector * dot0;
		secondVector.Normalize();
		dot0 = Vector3ToolsD::DotProduct(firstVector, thirdVector); 
		thirdVector -= firstVector * dot0;
		dot0 = Vector3ToolsD::DotProduct(secondVector, thirdVector); 
		thirdVector -= secondVector * dot0;
		thirdVector.Normalize();

		ASSERT_TRUE(Vector3ToolsD::Approximate(firstVector,firstOrthonormalize.GetUVector(),1e-10));

		ASSERT_TRUE(Vector3ToolsD::Approximate(secondVector,firstOrthonormalize.GetVVector(),1e-10));

		ASSERT_TRUE(Vector3ToolsD::Approximate(thirdVector,firstOrthonormalize.GetWVector(),1e-10));

		Vector3OrthonormalizeF secondOrthonormalize(fourthVector, fifthVector,sixthVector,1e-4f);

		fourthVector.Normalize();
		float dot1 = Vector3ToolsF::DotProduct(fourthVector, fifthVector); 
		fifthVector -= fourthVector * dot1;
		fifthVector.Normalize();

		dot1 = Vector3ToolsF::DotProduct(fourthVector, sixthVector); 
		sixthVector -= fourthVector * dot1;
		dot1 = Vector3ToolsF::DotProduct(fifthVector, sixthVector); 
		sixthVector -= fifthVector * dot1;
		sixthVector.Normalize();

		ASSERT_TRUE(Vector3ToolsF::Approximate(fourthVector,secondOrthonormalize.GetUVector(),1e-8f));

		ASSERT_TRUE(Vector3ToolsF::Approximate(fifthVector,secondOrthonormalize.GetVVector(),1e-8f));
		
		ASSERT_TRUE(Vector3ToolsF::Approximate(sixthVector,secondOrthonormalize.GetWVector(),1e-4f));
	}
}
