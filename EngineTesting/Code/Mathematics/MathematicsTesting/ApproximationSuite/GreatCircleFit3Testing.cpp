// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 10:42)

#include "GreatCircleFit3Testing.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "Mathematics/Objects3D/Ellipsoid3Detail.h"
#include "Mathematics/Approximation/GreatCircleFit3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/NumericalAnalysis/EigenDecomposition.h"

using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class GreatCircleFit3<float>;
	template class GreatCircleFit3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, GreatCircleFit3Testing) 

void Mathematics::GreatCircleFit3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::GreatCircleFit3Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(0.0, 100.0);
	uniform_int<> secondRandomDistribution(5, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector3D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(DoubleVector3D(firstRandomDistribution(generator), firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		double sumXX = 0.0;
		double sumXY = 0.0;
		double sumXZ = 0.0;
		double sumYY = 0.0;
		double sumYZ = 0.0;
		double sumZZ = 0.0;
	 
		for (int i = 0; i < size; ++i)
		{
			DoubleVector3D diff = vertices[i];

			sumXX += diff[0] * diff[0];
			sumXY += diff[0] * diff[1];
			sumXZ += diff[0] * diff[2];
			sumYY += diff[1] * diff[1];
			sumYZ += diff[1] * diff[2];
			sumZZ += diff[2] * diff[2];
		}

		sumXX /= size;
		sumXY /= size;
		sumXZ /= size;
		sumYY /= size;
		sumYZ /= size;
		sumZZ /= size;
		 
		DoubleEigenDecomposition eigenSystem(3);
		eigenSystem(0, 0) = sumXX;
		eigenSystem(0, 1) = sumXY;
		eigenSystem(0, 2) = sumXZ;
		eigenSystem(1, 0) = eigenSystem(0, 1);
		eigenSystem(1, 1) = sumYY;
		eigenSystem(1, 2) = sumYZ;
		eigenSystem(2, 0) = eigenSystem(0, 2);
		eigenSystem(2, 1) = eigenSystem(1, 2);
		eigenSystem(2, 2) = sumZZ;

 
		eigenSystem.Solve(false);

		DoubleGreatCircleFit3 greatCircleFit3(vertices);

		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, eigenSystem.GetEigenvector3(2), greatCircleFit3.GetNormal(), 1e-10);
	 
	}
}

