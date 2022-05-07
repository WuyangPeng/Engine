// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.3 (2019/09/09 16:44)

#include "BoundTreeSplitTrianglesTesting.h"
#include "Physics/CollisionDetection/BoundTreeSplitTriangles.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Physics/CollisionDetection/BoundTreeProjectionInfo.h"

#include <random> 
#include <vector>
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26435)
#include SYSTEM_WARNING_DISABLE(26496)
#include SYSTEM_WARNING_DISABLE(26498)
#include SYSTEM_WARNING_DISABLE(26429)
#include SYSTEM_WARNING_DISABLE(26446)
#include SYSTEM_WARNING_DISABLE(26451)
#include SYSTEM_WARNING_DISABLE(26490)
using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Physics, BoundTreeSplitTrianglesTesting) 

void Physics::BoundTreeSplitTrianglesTesting
	::MainTest()
{ 
	ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}
 
void Physics::BoundTreeSplitTrianglesTesting
	::InitTest()
{
	std::default_random_engine generator;
	std::uniform_real<float> firstRandomDistribution(-100.0f,100.0f);
	std::uniform_int<> secondRandomDistribution(5, 15);

	for (int loop = 0; loop < GetTestLoopCount(); ++loop)
	{
		BoundTreeSplitTriangles::Centroids centroids;

		int centroidsSize = secondRandomDistribution(generator);

		for (int i = 0; i < centroidsSize; ++i)
		{
			centroids.push_back(BoundTreeSplitTriangles::APoint(firstRandomDistribution(generator),
				                                                firstRandomDistribution(generator),
																firstRandomDistribution(generator)));
		}

		BoundTreeSplitTriangles::Split split;
		 
		int inSplitSize = secondRandomDistribution(generator);
		std::uniform_int<> thirdRandomDistribution(0, centroidsSize - 1);

		for (int i = 0; i < inSplitSize; ++i)
		{
			split.push_back(thirdRandomDistribution(generator));
		}

		BoundTreeSplitTriangles::APoint origin(firstRandomDistribution(generator),
											   firstRandomDistribution(generator),
											   firstRandomDistribution(generator));
		BoundTreeSplitTriangles::AVector direction(firstRandomDistribution(generator),
												   firstRandomDistribution(generator),
												   firstRandomDistribution(generator));

		BoundTreeSplitTriangles firstBoundTreeSplitTriangles(centroids, 0, inSplitSize - 1,
															 split, origin, direction);

		ASSERT_EQUAL(firstBoundTreeSplitTriangles.GetFirstOutSplitIndex(), (inSplitSize - 1) / 2);
		ASSERT_EQUAL(firstBoundTreeSplitTriangles.GetSecondOutSplitIndex(), (inSplitSize - 1) / 2 + 1);


		vector<BoundTreeProjectionInfo> info;

		for (int i = 0; i <= inSplitSize - 1; ++i)
		{
			int triangle = split[i];
			BoundTreeSplitTriangles::AVector difference = centroids[triangle] - origin;
			info.push_back(BoundTreeProjectionInfo(triangle, Dot(direction, difference)));
		}
	  
		sort(info.begin(), info.end());
		int median = (inSplitSize - 1) / 2;

		BoundTreeSplitTriangles::Split outSplit(split.size());

		int index0 = -1;
		for (int i = 0; i <= median; ++i)
		{
			outSplit[++index0] = info[i].GetTriangle();
		}

		int index1 = inSplitSize;
		for (int i = median + 1; i < inSplitSize; ++i)
		{
			outSplit[--index1] = info[i].GetTriangle();
		}

		ASSERT_EQUAL(outSplit, firstBoundTreeSplitTriangles.GetOutSplit());

		BoundTreeSplitTriangles secondBoundTreeSplitTriangles(centroids,0 , index0,
															  outSplit, origin, direction);

		ASSERT_EQUAL(secondBoundTreeSplitTriangles.GetFirstOutSplitIndex(), index0 / 2);
		ASSERT_EQUAL(secondBoundTreeSplitTriangles.GetSecondOutSplitIndex(), index0 / 2 + 1);
	}
}
 