// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 11:19)

#include "ParaboloidFit3Testing.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Approximation/ParaboloidFit3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class ParaboloidFit3<float>;
	template class ParaboloidFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, ParaboloidFit3Testing) 

void Mathematics::ParaboloidFit3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
void Mathematics::ParaboloidFit3Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(10, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<Vector3D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(Vector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		ParaboloidFit3D paraboloidFit3(vertices);

		ASSERT_TRUE(paraboloidFit3.GetIsFitSuccess());

		VariableLengthVectorD variableLengthVector = paraboloidFit3.GetCoeff();

		for (int i = 0; i < size; ++i)		
		{ 
			double value = variableLengthVector[0] * vertices[i].GetX() * vertices[i].GetX() +
				           variableLengthVector[1] * vertices[i].GetX() * vertices[i].GetY() +
						   variableLengthVector[2] * vertices[i].GetY() * vertices[i].GetY() +
						   variableLengthVector[3] * vertices[i].GetX() +
						   variableLengthVector[4] * vertices[i].GetY() + variableLengthVector[5];

			ASSERT_TRUE(MathD::FAbs(value - vertices[i].GetZ()) <= 200.0f);
		}
 
	}
}

