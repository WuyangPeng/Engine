// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
//
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 17:54)

#include "DistanceResultTesting.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2Detail.h"
#include "Mathematics/Algebra/Vector3Detail.h"
#include "Mathematics/Algebra/Vector3ToolsDetail.h"
#include "Mathematics/Distance/DistanceResultDetail.h"

using std::vector;

namespace Mathematics
{
    template class DistanceResult<float, Vector2F>;
    template class DistanceResult<double, Vector2D>;
    template class DistanceResult<float, Vector3F>;
    template class DistanceResult<double, Vector3D>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceResultTesting)

void Mathematics::DistanceResultTesting ::MainTest()
{
    ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ContactTimeTest);
    ASSERT_NOT_THROW_EXCEPTION_0(ClosestPointsTest);
    ASSERT_NOT_THROW_EXCEPTION_0(MultipleClosestPointsTest);
}

void Mathematics::DistanceResultTesting ::BaseTest()
{
    DistanceResult2D distanceResult(3.0);

    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 0.0, 1e-10);
    ASSERT_EQUAL(distanceResult.GetLhsClosestPointSize(), 0);
    ASSERT_EQUAL(distanceResult.GetRhsClosestPointSize(), 0);

    DistanceResult2D copyDistanceResult(distanceResult);

    ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(copyDistanceResult.GetContactTime(), 0.0, 1e-10);
    ASSERT_EQUAL(copyDistanceResult.GetLhsClosestPointSize(), 0);
    ASSERT_EQUAL(copyDistanceResult.GetRhsClosestPointSize(), 0);

    distanceResult.SetDistance(7.0);
    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 7.0, 1e-10);
    ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), 3.0, 1e-10);

    copyDistanceResult.SetContactTime(8.1);
    ASSERT_APPROXIMATE(copyDistanceResult.GetContactTime(), 8.1, 1e-10);
    ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 0.0, 1e-10);

    copyDistanceResult.SetSqrtDistance(copyDistanceResult.GetDistance());
    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 7.0, 1e-10);
    ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), MathD::Sqrt(3.0), 1e-10);

    distanceResult.Set(3.0, 5.1);
    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 5.1, 1e-10);
}

void Mathematics::DistanceResultTesting ::ContactTimeTest()
{
    DistanceResult2F distanceResult(2.0f, 5.1f);

    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 5.1f, 1e-8f);
    ASSERT_EQUAL(distanceResult.GetLhsClosestPointSize(), 0);
    ASSERT_EQUAL(distanceResult.GetRhsClosestPointSize(), 0);

    DistanceResult2F copyDistanceResult(distanceResult);

    ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(copyDistanceResult.GetContactTime(), 5.1f, 1e-8f);
    ASSERT_EQUAL(copyDistanceResult.GetLhsClosestPointSize(), 0);
    ASSERT_EQUAL(copyDistanceResult.GetRhsClosestPointSize(), 0);

    copyDistanceResult.SetDistance(3.2f);
    ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), 3.2f, 1e-8f);
    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 2.0f, 1e-8f);

    distanceResult.SetContactTime(8.1f);
    ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 8.1f, 1e-8f);
    ASSERT_APPROXIMATE(copyDistanceResult.GetContactTime(), 5.1f, 1e-8f);

    copyDistanceResult.SetSqrtDistance(copyDistanceResult.GetDistance());
    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 2.0f, 1e-8f);
    ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), MathF::Sqrt(3.2f), 1e-8f);

    distanceResult.Set(3.0f, 5.1f);
    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 5.1f, 1e-8f);
}

void Mathematics::DistanceResultTesting ::ClosestPointsTest()
{
    DistanceResult3F distanceResult(1.0f, 3.1f, Vector3F::GetUnitX(), Vector3F::GetUnitY());

    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 3.1f, 1e-8f);
    ASSERT_EQUAL(distanceResult.GetLhsClosestPointSize(), 1);
    ASSERT_EQUAL(distanceResult.GetRhsClosestPointSize(), 1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsF::Approximate, distanceResult.GetLhsClosestPoint(), Vector3F::GetUnitX(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsF::Approximate, distanceResult.GetRhsClosestPoint(), Vector3F::GetUnitY(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsF::Approximate, distanceResult.GetLhsClosestPoint(0), Vector3F::GetUnitX(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsF::Approximate, distanceResult.GetRhsClosestPoint(0), Vector3F::GetUnitY(), 1e-8f);

    DistanceResult3F copyDistanceResult(distanceResult);

    ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(copyDistanceResult.GetContactTime(), 3.1f, 1e-8f);
    ASSERT_EQUAL(copyDistanceResult.GetLhsClosestPointSize(), 1);
    ASSERT_EQUAL(copyDistanceResult.GetRhsClosestPointSize(), 1);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsF::Approximate, copyDistanceResult.GetLhsClosestPoint(), Vector3F::GetUnitX(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsF::Approximate, copyDistanceResult.GetRhsClosestPoint(), Vector3F::GetUnitY(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsF::Approximate, copyDistanceResult.GetLhsClosestPoint(0), Vector3F::GetUnitX(), 1e-8f);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsF::Approximate, copyDistanceResult.GetRhsClosestPoint(0), Vector3F::GetUnitY(), 1e-8f);

    copyDistanceResult.SetDistance(3.2f);
    ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), 3.2f, 1e-8f);
    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 1.0f, 1e-8f);

    distanceResult.SetContactTime(8.1f);
    ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 8.1f, 1e-8f);
    ASSERT_APPROXIMATE(copyDistanceResult.GetContactTime(), 3.1f, 1e-8f);

    copyDistanceResult.SetSqrtDistance(copyDistanceResult.GetDistance());
    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 1.0f, 1e-8f);
    ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), MathF::Sqrt(3.2f), 1e-8f);

    distanceResult.Set(3.0f, 5.1f);
    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 3.0f, 1e-8f);
    ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 5.1f, 1e-8f);
}

void Mathematics::DistanceResultTesting ::MultipleClosestPointsTest()
{
    vector<Vector3D> lhsPoint;
    lhsPoint.push_back(Vector3F::GetUnitX());
    lhsPoint.push_back(Vector3F::GetUnitZ());

    vector<Vector3D> rhsPoint;
    rhsPoint.push_back(Vector3F::GetUnitZ());
    rhsPoint.push_back(Vector3F::GetUnitY());

    DistanceResult3D distanceResult(6.9, 4.2, lhsPoint, rhsPoint);

    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 6.9, 1e-10);
    ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 4.2, 1e-10);
    ASSERT_EQUAL(distanceResult.GetLhsClosestPointSize(), 2);
    ASSERT_EQUAL(distanceResult.GetRhsClosestPointSize(), 2);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, distanceResult.GetLhsClosestPoint(), Vector3F::GetUnitX(), 1e-10);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, distanceResult.GetRhsClosestPoint(), Vector3F::GetUnitZ(), 1e-10);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, distanceResult.GetLhsClosestPoint(0), Vector3F::GetUnitX(), 1e-10);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, distanceResult.GetRhsClosestPoint(0), Vector3F::GetUnitZ(), 1e-10);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, distanceResult.GetLhsClosestPoint(1), Vector3F::GetUnitZ(), 1e-10);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, distanceResult.GetRhsClosestPoint(1), Vector3F::GetUnitY(), 1e-10);

    DistanceResult3D copyDistanceResult(16.9, 14.2, rhsPoint, lhsPoint);
    copyDistanceResult = distanceResult;

    ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), 6.9, 1e-10);
    ASSERT_APPROXIMATE(copyDistanceResult.GetContactTime(), 4.2, 1e-10);
    ASSERT_EQUAL(copyDistanceResult.GetLhsClosestPointSize(), 2);
    ASSERT_EQUAL(copyDistanceResult.GetRhsClosestPointSize(), 2);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, copyDistanceResult.GetLhsClosestPoint(), Vector3F::GetUnitX(), 1e-10);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, copyDistanceResult.GetRhsClosestPoint(), Vector3F::GetUnitZ(), 1e-10);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, copyDistanceResult.GetLhsClosestPoint(0), Vector3F::GetUnitX(), 1e-10);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, copyDistanceResult.GetRhsClosestPoint(0), Vector3F::GetUnitZ(), 1e-10);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, copyDistanceResult.GetLhsClosestPoint(1), Vector3F::GetUnitZ(), 1e-10);
    ASSERT_APPROXIMATE_USE_FUNCTION(Vector3ToolsD::Approximate, copyDistanceResult.GetRhsClosestPoint(1), Vector3F::GetUnitY(), 1e-10);

    distanceResult.SetDistance(7.0);
    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 7.0, 1e-10);
    ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), 6.9, 1e-10);

    copyDistanceResult.SetContactTime(8.1);
    ASSERT_APPROXIMATE(copyDistanceResult.GetContactTime(), 8.1, 1e-10);
    ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 4.2, 1e-10);

    copyDistanceResult.SetSqrtDistance(copyDistanceResult.GetDistance());
    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 7.0, 1e-10);
    ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), MathD::Sqrt(6.9), 1e-10);

    distanceResult.Set(3.0, 5.1);
    ASSERT_APPROXIMATE(distanceResult.GetDistance(), 3.0, 1e-10);
    ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 5.1, 1e-10);
}
