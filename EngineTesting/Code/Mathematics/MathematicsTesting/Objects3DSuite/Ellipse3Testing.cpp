// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/22 16:56)

#include "Ellipse3Testing.h"
#include "Mathematics/Objects3D/Ellipse3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
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
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26490)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26472)
#include SYSTEM_WARNING_DISABLE(26475)
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
		Vector3D center(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		Vector3D normal(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		Vector3D major(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));

		Vector3D minor(firstRandomDistribution(generator),
			             firstRandomDistribution(generator),
						 firstRandomDistribution(generator));
		
		double majorLength = Vector3ToolsD::GetLength(major);
		double minorLength = Vector3ToolsD::GetLength(minor);

		normal.Normalize();
		major.Normalize();
		minor.Normalize();

		Vector3ToolsD::Vector3Orthonormalize orthonormalize = Vector3ToolsD::Orthonormalize(major,minor,normal);

		Ellipse3D ellipse(center, orthonormalize.GetUVector(), orthonormalize.GetVVector(), orthonormalize.GetWVector(), majorLength, minorLength);

		ASSERT_TRUE(Vector3ToolsD::Approximate(center,ellipse.GetCenter()));
		ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetUVector(),ellipse.GetNormal()));
		ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetVVector(),ellipse.GetMajor()));
		ASSERT_TRUE(Vector3ToolsD::Approximate(orthonormalize.GetWVector(),ellipse.GetMinor()));
		ASSERT_APPROXIMATE(majorLength,ellipse.GetMajorLength(),1e-10);
		ASSERT_APPROXIMATE(minorLength,ellipse.GetMinorLength(),1e-10);
	}
}

