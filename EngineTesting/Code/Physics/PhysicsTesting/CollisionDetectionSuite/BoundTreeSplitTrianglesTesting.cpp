///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++20
///	引擎测试版本：0.8.0.9 (2022/06/20 22:44)

#include "BoundTreeSplitTrianglesTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/APointDetail.h"
#include "Mathematics/Algebra/AVectorDetail.h"
#include "Mathematics/Algebra/HomogeneousPointDetail.h"
#include "Physics/CollisionDetection/BoundTreeProjectionInfo.h"
#include "Physics/CollisionDetection/BoundTreeSplitTriangles.h"

#include <random>
#include <vector>

using std::vector;

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Physics, BoundTreeSplitTrianglesTesting)

void Physics::BoundTreeSplitTrianglesTesting::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(InitTest);
}

void Physics::BoundTreeSplitTrianglesTesting::InitTest()
{
    std::default_random_engine generator;
    const std::uniform_real<float> firstRandomDistribution(-100.0f, 100.0f);
    const std::uniform_int<> secondRandomDistribution(5, 15);

    for (int loop = 0; loop < GetTestLoopCount(); ++loop)
    {
        BoundTreeSplitTriangles::Centroids centroids;

        const int centroidsSize = secondRandomDistribution(generator);

        for (int i = 0; i < centroidsSize; ++i)
        {
            centroids.push_back(BoundTreeSplitTriangles::APoint(firstRandomDistribution(generator),
                                                                firstRandomDistribution(generator),
                                                                firstRandomDistribution(generator)));
        }

        BoundTreeSplitTriangles::Split split;

        const int inSplitSize = secondRandomDistribution(generator);
        const std::uniform_int<> thirdRandomDistribution(0, centroidsSize - 1);

        for (int i = 0; i < inSplitSize; ++i)
        {
            split.push_back(thirdRandomDistribution(generator));
        }

        const BoundTreeSplitTriangles::APoint origin(firstRandomDistribution(generator),
                                                     firstRandomDistribution(generator),
                                                     firstRandomDistribution(generator));
        const BoundTreeSplitTriangles::AVector direction(firstRandomDistribution(generator),
                                                         firstRandomDistribution(generator),
                                                         firstRandomDistribution(generator));

        BoundTreeSplitTriangles firstBoundTreeSplitTriangles(centroids, 0, inSplitSize - 1,
                                                             split, origin, direction);

        ASSERT_EQUAL(firstBoundTreeSplitTriangles.GetFirstOutSplitIndex(), (inSplitSize - 1) / 2);
        ASSERT_EQUAL(firstBoundTreeSplitTriangles.GetSecondOutSplitIndex(), (inSplitSize - 1) / 2 + 1);

        vector<BoundTreeProjectionInfo> info;

        for (int i = 0; i <= inSplitSize - 1; ++i)
        {
            const int triangle = split.at(i);
            const BoundTreeSplitTriangles::AVector difference = centroids.at(triangle) - origin;
            info.push_back(BoundTreeProjectionInfo(triangle, Dot(direction, difference)));
        }

        sort(info.begin(), info.end());
        const int median = (inSplitSize - 1) / 2;

        BoundTreeSplitTriangles::Split outSplit(split.size());

        int index0 = -1;
        for (int i = 0; i <= median; ++i)
        {
            outSplit.at(++index0) = info.at(i).GetTriangle();
        }

        int index1 = inSplitSize;
        for (int i = median + 1; i < inSplitSize; ++i)
        {
            outSplit.at(--index1) = info.at(i).GetTriangle();
        }

        ASSERT_EQUAL(outSplit, firstBoundTreeSplitTriangles.GetOutSplit());

        BoundTreeSplitTriangles secondBoundTreeSplitTriangles(centroids, 0, index0, outSplit, origin, direction);

        ASSERT_EQUAL(secondBoundTreeSplitTriangles.GetFirstOutSplitIndex(), index0 / 2);
        ASSERT_EQUAL(secondBoundTreeSplitTriangles.GetSecondOutSplitIndex(), index0 / 2 + 1);
    }
}
