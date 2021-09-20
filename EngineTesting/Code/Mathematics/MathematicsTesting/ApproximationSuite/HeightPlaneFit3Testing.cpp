// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 11:09)

#include "HeightPlaneFit3Testing.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Approximation/HeightPlaneFit3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class HeightPlaneFit3<float>;
	template class HeightPlaneFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, HeightPlaneFit3Testing) 

void Mathematics::HeightPlaneFit3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::HeightPlaneFit3Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(10, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector3D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(DoubleVector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		DoubleHeightPlaneFit3 heightPlaneFit3(vertices);

		double sumX = 0.0;
		double sumY = 0.0;
		double sumZ = 0.0;
		double sumXX = 0.0;
		double sumXY = 0.0;
		double sumXZ = 0.0;
		double sumYY = 0.0;
		double sumYZ = 0.0;	 

		for (int i = 0; i < size; ++i)
		{
			sumX += vertices[i][0];
			sumY += vertices[i][1];
			sumZ += vertices[i][2];
			sumXX += vertices[i][0] * vertices[i][0];
			sumXY += vertices[i][0] * vertices[i][1];
			sumXZ += vertices[i][0] * vertices[i][2];
			sumYY += vertices[i][1] * vertices[i][1];
			sumYZ += vertices[i][1] * vertices[i][2];
		}

		double matrix[3][3] =
		{
			{ sumXX, sumXY, sumX },
			{ sumXY, sumYY, sumY },
			{ sumX, sumY, static_cast<double>(size) }
		};

		double input[3] =
		{
			sumXZ,
			sumYZ,
			sumZ
		};

		double output[3] { 0.0, 0.0, 0.0 };

// 		LinearSystem<double>().Solve3(matrix, input, output);
// 
// 		ASSERT_APPROXIMATE(heightPlaneFit3.GetCoeffA(), output[0], 1e-10);
// 		ASSERT_APPROXIMATE(heightPlaneFit3.GetCoeffB(), output[1], 1e-10);
// 		ASSERT_APPROXIMATE(heightPlaneFit3.GetCoeffC(), output[2], 1e-10);
	}
}

