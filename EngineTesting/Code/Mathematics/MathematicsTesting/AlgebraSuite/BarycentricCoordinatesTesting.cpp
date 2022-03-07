// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/21 15:16)

#include "BarycentricCoordinatesTesting.h"
#include "Mathematics/Algebra/BarycentricCoordinatesDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

namespace Mathematics
{
	template class BarycentricCoordinates<float,3>;
	template class BarycentricCoordinates<double,3>;
	template class BarycentricCoordinates<float,4>;
	template class BarycentricCoordinates<double,4>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics,BarycentricCoordinatesTesting) 

void Mathematics::BarycentricCoordinatesTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BarycentricCoordinates3DTest); 
	ASSERT_NOT_THROW_EXCEPTION_0(BarycentricCoordinates4DTest);
}
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26446)
void Mathematics::BarycentricCoordinatesTesting
	::BarycentricCoordinates3DTest()
{
	BarycentricCoordinates<float,3> firstBarycentricCoordinates;

	ASSERT_FALSE(firstBarycentricCoordinates.IsBarycentricCoordinatesValid());

	BarycentricCoordinates<double, 3> secondBarycentricCoordinates{ true, BarycentricCoordinates<double,3>::Tuple(0.1,0.4,0.5) };

	ASSERT_APPROXIMATE(secondBarycentricCoordinates[0],0.1,1e-10);
	ASSERT_APPROXIMATE(secondBarycentricCoordinates[1],0.4,1e-10);
	ASSERT_APPROXIMATE(secondBarycentricCoordinates[2],0.5,1e-10);

}

void Mathematics::BarycentricCoordinatesTesting
	::BarycentricCoordinates4DTest()
{
	BarycentricCoordinates<double,4> firstBarycentricCoordinates;

	ASSERT_FALSE(firstBarycentricCoordinates.IsBarycentricCoordinatesValid());

	BarycentricCoordinates<float, 4> secondBarycentricCoordinates{ true,BarycentricCoordinates<float,4>::Tuple(0.1f,0.4f,0.3f,0.2f) };

	ASSERT_APPROXIMATE(secondBarycentricCoordinates[0],0.1f,1e-8f);
	ASSERT_APPROXIMATE(secondBarycentricCoordinates[1],0.4f,1e-8f);
	ASSERT_APPROXIMATE(secondBarycentricCoordinates[2],0.3f,1e-8f);	 
	ASSERT_APPROXIMATE(secondBarycentricCoordinates[3],0.2f,1e-8f);
}

