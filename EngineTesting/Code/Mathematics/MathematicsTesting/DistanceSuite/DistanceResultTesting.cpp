// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê≤‚ ‘∞Ê±æ£∫0.0.0.2 (2019/08/29 17:54)

#include "DistanceResultTesting.h"
#include "Mathematics/Distance/DistanceResultDetail.h" 
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/AssertMacro.h"
#include "CoreTools/Helper/ClassInvariantMacro.h"

using std::vector;

namespace Mathematics
{
	template class DistanceResult<float,FloatVector2D>;
	template class DistanceResult<double,DoubleVector2D>; 
	template class DistanceResult<float, FloatVector3D>;
	template class DistanceResult<double, DoubleVector3D>;
}

UNIT_TEST_SUBCLASS_COMPLETE_DEFINE(Mathematics, DistanceResultTesting) 

void Mathematics::DistanceResultTesting
	::MainTest()
{
	ASSERT_NOT_THROW_EXCEPTION_0(BaseTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ContactTimeTest);
	ASSERT_NOT_THROW_EXCEPTION_0(ClosestPointsTest);
	ASSERT_NOT_THROW_EXCEPTION_0(MultipleClosestPointsTest);
}

void Mathematics::DistanceResultTesting
	::BaseTest()
{
	DoubleDistanceResult2 distanceResult(3.0);

	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 3.0, 1e-10);
	ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 0.0, 1e-10);
	ASSERT_EQUAL(distanceResult.GetLhsClosestPointSize(), 0);
	ASSERT_EQUAL(distanceResult.GetRhsClosestPointSize(), 0);

	DoubleDistanceResult2 copyDistanceResult(distanceResult);

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

	copyDistanceResult.SetSqrtDistance();
	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 7.0, 1e-10);
	ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), DoubleMath::Sqrt(3.0), 1e-10);

	distanceResult.Set(3.0, 5.1);
	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 3.0, 1e-10);
	ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 5.1, 1e-10);
}

void Mathematics::DistanceResultTesting
	::ContactTimeTest()
{
	FloatDistanceResult2 distanceResult(2.0f,5.1f);

	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 2.0f, 1e-8f);
	ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 5.1f, 1e-8f);
	ASSERT_EQUAL(distanceResult.GetLhsClosestPointSize(), 0);
	ASSERT_EQUAL(distanceResult.GetRhsClosestPointSize(), 0);

	FloatDistanceResult2 copyDistanceResult(distanceResult);

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

	copyDistanceResult.SetSqrtDistance();
	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 2.0f, 1e-8f);
	ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), FloatMath::Sqrt(3.2f), 1e-8f);

	distanceResult.Set(3.0f, 5.1f);
	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 3.0f, 1e-8f);
	ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 5.1f, 1e-8f);
}

void Mathematics::DistanceResultTesting
	::ClosestPointsTest()
{
	FloatDistanceResult3 distanceResult(1.0f, 3.1f,FloatVector3D::GetUnitX(),FloatVector3D::GetUnitY());

	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 1.0f, 1e-8f);
	ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 3.1f, 1e-8f);
	ASSERT_EQUAL(distanceResult.GetLhsClosestPointSize(), 1);
	ASSERT_EQUAL(distanceResult.GetRhsClosestPointSize(), 1);
	ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector3DTools::Approximate, distanceResult.GetLhsClosestPoint(),FloatVector3D::GetUnitX(),1e-8f);
	ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector3DTools::Approximate, distanceResult.GetRhsClosestPoint(),FloatVector3D::GetUnitY(),1e-8f);
	ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector3DTools::Approximate, distanceResult.GetLhsClosestPoint(0),FloatVector3D::GetUnitX(),1e-8f);
	ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector3DTools::Approximate, distanceResult.GetRhsClosestPoint(0),FloatVector3D::GetUnitY(),1e-8f);

	FloatDistanceResult3 copyDistanceResult(distanceResult);

	ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), 1.0f, 1e-8f);
	ASSERT_APPROXIMATE(copyDistanceResult.GetContactTime(), 3.1f, 1e-8f);
	ASSERT_EQUAL(copyDistanceResult.GetLhsClosestPointSize(), 1);
	ASSERT_EQUAL(copyDistanceResult.GetRhsClosestPointSize(), 1);
	ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector3DTools::Approximate, copyDistanceResult.GetLhsClosestPoint(),FloatVector3D::GetUnitX(),1e-8f);
	ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector3DTools::Approximate, copyDistanceResult.GetRhsClosestPoint(),FloatVector3D::GetUnitY(),1e-8f);
	ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector3DTools::Approximate, copyDistanceResult.GetLhsClosestPoint(0),FloatVector3D::GetUnitX(),1e-8f);
	ASSERT_APPROXIMATE_USE_FUNCTION(FloatVector3DTools::Approximate, copyDistanceResult.GetRhsClosestPoint(0),FloatVector3D::GetUnitY(),1e-8f);

	copyDistanceResult.SetDistance(3.2f);
	ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), 3.2f, 1e-8f);
	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 1.0f, 1e-8f);

	distanceResult.SetContactTime(8.1f);
	ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 8.1f, 1e-8f);
	ASSERT_APPROXIMATE(copyDistanceResult.GetContactTime(), 3.1f, 1e-8f);

	copyDistanceResult.SetSqrtDistance();
	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 1.0f, 1e-8f);
	ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), FloatMath::Sqrt(3.2f), 1e-8f);

	distanceResult.Set(3.0f, 5.1f);
	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 3.0f, 1e-8f);
	ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 5.1f, 1e-8f);
}

void Mathematics::DistanceResultTesting
	::MultipleClosestPointsTest()
{
	vector<DoubleVector3D> lhsPoint;
	lhsPoint.push_back(FloatVector3D::GetUnitX());
	lhsPoint.push_back(FloatVector3D::GetUnitZ());

	vector<DoubleVector3D> rhsPoint;
	rhsPoint.push_back(FloatVector3D::GetUnitZ());
	rhsPoint.push_back(FloatVector3D::GetUnitY());

	DoubleDistanceResult3 distanceResult(6.9, 4.2, lhsPoint, rhsPoint);

	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 6.9, 1e-10);
	ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 4.2, 1e-10);
	ASSERT_EQUAL(distanceResult.GetLhsClosestPointSize(), 2);
	ASSERT_EQUAL(distanceResult.GetRhsClosestPointSize(), 2);
	ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, distanceResult.GetLhsClosestPoint(),FloatVector3D::GetUnitX(),1e-10);
	ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, distanceResult.GetRhsClosestPoint(),FloatVector3D::GetUnitZ(),1e-10);
	ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, distanceResult.GetLhsClosestPoint(0),FloatVector3D::GetUnitX(),1e-10);
	ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, distanceResult.GetRhsClosestPoint(0),FloatVector3D::GetUnitZ(),1e-10);
	ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, distanceResult.GetLhsClosestPoint(1),FloatVector3D::GetUnitZ(),1e-10);
	ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, distanceResult.GetRhsClosestPoint(1),FloatVector3D::GetUnitY(),1e-10);

	DoubleDistanceResult3 copyDistanceResult(16.9, 14.2, rhsPoint, lhsPoint);
	copyDistanceResult = distanceResult;

	ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), 6.9, 1e-10);
	ASSERT_APPROXIMATE(copyDistanceResult.GetContactTime(), 4.2, 1e-10);
	ASSERT_EQUAL(copyDistanceResult.GetLhsClosestPointSize(), 2);
	ASSERT_EQUAL(copyDistanceResult.GetRhsClosestPointSize(), 2);
	ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, copyDistanceResult.GetLhsClosestPoint(),FloatVector3D::GetUnitX(),1e-10);
	ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, copyDistanceResult.GetRhsClosestPoint(),FloatVector3D::GetUnitZ(),1e-10);
	ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, copyDistanceResult.GetLhsClosestPoint(0),FloatVector3D::GetUnitX(),1e-10);
	ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, copyDistanceResult.GetRhsClosestPoint(0),FloatVector3D::GetUnitZ(),1e-10);
	ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, copyDistanceResult.GetLhsClosestPoint(1),FloatVector3D::GetUnitZ(),1e-10);
	ASSERT_APPROXIMATE_USE_FUNCTION(DoubleVector3DTools::Approximate, copyDistanceResult.GetRhsClosestPoint(1),FloatVector3D::GetUnitY(),1e-10);

	distanceResult.SetDistance(7.0);
	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 7.0, 1e-10);
	ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), 6.9, 1e-10);

	copyDistanceResult.SetContactTime(8.1);
	ASSERT_APPROXIMATE(copyDistanceResult.GetContactTime(), 8.1, 1e-10);
	ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 4.2, 1e-10);

	copyDistanceResult.SetSqrtDistance();
	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 7.0, 1e-10);
	ASSERT_APPROXIMATE(copyDistanceResult.GetDistance(), DoubleMath::Sqrt(6.9), 1e-10);

	distanceResult.Set(3.0, 5.1);
	ASSERT_APPROXIMATE(distanceResult.GetDistance(), 3.0, 1e-10);
	ASSERT_APPROXIMATE(distanceResult.GetContactTime(), 5.1, 1e-10);
}





