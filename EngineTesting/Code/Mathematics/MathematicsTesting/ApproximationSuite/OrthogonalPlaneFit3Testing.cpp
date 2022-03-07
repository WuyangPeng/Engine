// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 11:14)

#include "OrthogonalPlaneFit3Testing.h"
#include "Mathematics/Algebra/Vector2ToolsDetail.h"
#include "Mathematics/Approximation/OrthogonalPlaneFit3Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/NumericalAnalysis/EigenDecomposition.h"

using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class OrthogonalPlaneFit3<float>;
	template class OrthogonalPlaneFit3<double>;
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26440)
#include SYSTEM_WARNING_DISABLE(26446)
UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, OrthogonalPlaneFit3Testing) 

void Mathematics::OrthogonalPlaneFit3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::OrthogonalPlaneFit3Testing
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

		OrthogonalPlaneFit3D orthogonalPlaneFit(vertices);
		 
		Vector3D origin;
		 
		for (int i = 0; i < size; i++)
		{
			origin += vertices[i];
		}

		origin /= static_cast<double>(size);	

		double sumXX = 0.0;
		double sumXY = 0.0;
		double sumXZ = 0.0;
		double sumYY = 0.0;
		double sumYZ = 0.0;
		double sumZZ = 0.0;

		for (int i = 0; i < size; ++i)
		{
			Vector3D diff = vertices[i] - origin;
			sumXX += diff[0] * diff[0];
			sumXY += diff[0] * diff[1];
			sumXZ += diff[0] * diff[2];
			sumYY += diff[1] * diff[1];
			sumYZ += diff[1] * diff[2];
			sumZZ += diff[2] * diff[2];
		}

		sumXX /= static_cast<double>(size);
		sumXY /= static_cast<double>(size);
		sumXZ /= static_cast<double>(size);
		sumYY /= static_cast<double>(size);
		sumYZ /= static_cast<double>(size);
		sumZZ /= static_cast<double>(size);

		EigenDecompositionD esystem(3);
		esystem(0, 0) = sumXX;
		esystem(0, 1) = sumXY;
		esystem(0, 2) = sumXZ;
		esystem(1, 0) = sumXY;
		esystem(1, 1) = sumYY;
		esystem(1, 2) = sumYZ;
		esystem(2, 0) = sumXZ;
		esystem(2, 1) = sumYZ;
		esystem(2, 2) = sumZZ;
	
		esystem.Solve(false);

		Vector3D normal = esystem.GetEigenvector3(2);

		Plane3D plane(normal, origin);

		ASSERT_APPROXIMATE(plane.GetConstant(), orthogonalPlaneFit.GetPlane3().GetConstant(), 1e-10);
		ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, plane.GetNormal(), orthogonalPlaneFit.GetPlane3().GetNormal(), 1e-10);
	}
}

