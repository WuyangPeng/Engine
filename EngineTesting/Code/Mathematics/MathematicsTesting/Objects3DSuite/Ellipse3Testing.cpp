// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 16:56)

#include "Ellipse3Testing.h"
#include "Mathematics/Objects3D/Ellipse3Detail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

#include <random> 

using std::uniform_real;
using std::default_random_engine;

namespace Mathematics
{
	template class Ellipse3<float>;
	template class Ellipse3<double>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, Ellipse3Testing) 

void Mathematics::Ellipse3Testing
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(EllipseTest);
}

void Mathematics::Ellipse3Testing
	::EllipseTest()
{ 
	default_random_engine generator{};
	uniform_real<double> firstRandomDistribution{ -100.0,100.0 }; 

	const auto testLoopCount = GetTestLoopCount();

	for (auto loop = 0; loop < testLoopCount; ++loop)
	{
		DoubleVector3D center(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		DoubleVector3D normal(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		DoubleVector3D major(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		DoubleVector3D minor(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));
		
		double majorLength = DoubleVector3DTools::VectorMagnitude(major);
		double minorLength = DoubleVector3DTools::VectorMagnitude(minor);

		normal.Normalize();
		major.Normalize();
		minor.Normalize();

		DoubleVector3DTools::Vector3DOrthonormalize orthonormalize = DoubleVector3DTools::Orthonormalize(major,minor,normal);

		DoubleEllipse3 ellipse(center, orthonormalize.GetUVector(), orthonormalize.GetVVector(), orthonormalize.GetWVector(), majorLength, minorLength);

		ASSERT_TRUE(DoubleVector3DTools::Approximate(center,ellipse.GetCenter()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(orthonormalize.GetUVector(),ellipse.GetNormal()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(orthonormalize.GetVVector(),ellipse.GetMajor()));
		ASSERT_TRUE(DoubleVector3DTools::Approximate(orthonormalize.GetWVector(),ellipse.GetMinor()));
		ASSERT_APPROXIMATE(majorLength,ellipse.GetMajorLength(),1e-10);
		ASSERT_APPROXIMATE(minorLength,ellipse.GetMinorLength(),1e-10);
	}
}

