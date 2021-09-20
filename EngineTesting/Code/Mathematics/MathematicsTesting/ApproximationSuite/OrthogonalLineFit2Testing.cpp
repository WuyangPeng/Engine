// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 11:13)

#include "OrthogonalLineFit2Testing.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Approximation/OrthogonalLineFit2Detail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 
#include "Mathematics/NumericalAnalysis/EigenDecomposition.h"

using std::uniform_real;
using std::uniform_int;
using std::default_random_engine;

namespace Mathematics
{
	template class OrthogonalLineFit2<float>;
	template class OrthogonalLineFit2<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, OrthogonalLineFit2Testing) 

void Mathematics::OrthogonalLineFit2Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(FitTest);
}

void Mathematics::OrthogonalLineFit2Testing
	::FitTest()
{
	default_random_engine generator;
	uniform_real<double> firstRandomDistribution(-100.0, 100.0);
	uniform_int<> secondRandomDistribution(10, 50);

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		std::vector<DoubleVector2D> vertices;
		int size = secondRandomDistribution(generator);

		for (int i = 0; i < size; ++i)
		{
			vertices.push_back(DoubleVector2D(firstRandomDistribution(generator), firstRandomDistribution(generator)));
		}

		DoubleOrthogonalLineFit2 orthogonalLineFit2(vertices);

	 	DoubleVector2D origin;
		for (int i = 0; i < size; ++i)
		{
			origin += vertices[i];
		}

		origin /= static_cast<double>(size);

		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, orthogonalLineFit2.GetLine2().GetOrigin(), origin, 1e-10);
	
		double sumXX = 0.0;
		double sumXY = 0.0;
		double sumYY = 0.0;
		for (int i = 0; i < size; ++i)
		{
			DoubleVector2D diff = vertices[i] - origin;
			sumXX += diff[0] * diff[0];
			sumXY += diff[0] * diff[1];
			sumYY += diff[1] * diff[1];
		}
		
		sumXX /= static_cast<double>(size);
		sumXY /= static_cast<double>(size);
		sumYY /= static_cast<double>(size);

   
		DoubleEigenDecomposition esystem(2);
		esystem(0,0) = sumYY;
		esystem(0,1) = -sumXY;
		esystem(1,0) = -sumXY;
		esystem(1,1) = sumXX;
 
		esystem.Solve(false);

		ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector2DTools::Approximate, orthogonalLineFit2.GetLine2().GetDirection(), esystem.GetEigenvector2(1), 1e-10);	
	}
}

