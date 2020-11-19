// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/17 16:22)

#ifndef MATHEMATICS_CONTAINMENT_CONT_BOX2_DETAIL_H
#define MATHEMATICS_CONTAINMENT_CONT_BOX2_DETAIL_H

#include "ContBox2.h"
#include "Mathematics/Algebra/Vector2DDetail.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"
#include "Mathematics/Approximation/GaussPointsFit2Detail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::ContBox2<Real>
	::ContBox2()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::ContBox2<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

// static
template <typename Real>
typename const Mathematics::ContBox2<Real>::Box2 Mathematics::ContBox2<Real>
	::ContAlignedBox(const Points& points)
{
	auto aabb =	Vector2DTools<Real>::ComputeExtremes(points);
	auto halfDiagonal =  Math::GetRational(1,2) * (aabb.GetMaxPoint() - aabb.GetMinPoint());

	return Box2{  Math::GetRational(1,2) * (aabb.GetMinPoint() + aabb.GetMaxPoint()),
				 Vector2D::sm_UnitX, Vector2D::sm_UnitY,
				 halfDiagonal[0], halfDiagonal[1] };
}

// static
template <typename Real>
typename const Mathematics::ContBox2<Real>::Box2 Mathematics::ContBox2<Real>
	::ContOrientedBox(const Points& points)
{
	GaussPointsFit2<Real> gaussPointsFit2{ points };
	auto box = gaussPointsFit2.GetBox2();

	// 令C是包围盒中心，让U0和U1是包围盒的轴。
	// 每一个输入点的形式为X = C + y0 * U0 + y1 * U1。
	// 下面的代码计算min(y0), max(y0), min(y1)和max(y1)。
	// 然后包围盒中心被调整为 
	// C' = C + 0.5*(min(y0) + max(y0)) * U0 + 0.5 * (min(y1) + max(y1)) * U1

	std::vector<Real> firstDotCollection;
	std::vector<Real> secondDotCollection;
	firstDotCollection.reserve(points.size());
	secondDotCollection.reserve(points.size());

	for(const auto& point: points)
	{
		auto diff = point - box.GetCenter();
		 
		auto firstDot = Vector2DTools<Real>::DotProduct(diff, box.GetFirstAxis());
		firstDotCollection.push_back(firstDot);

		auto secondDot = Vector2DTools<Real>::DotProduct(diff, box.GetSecondAxis());
		secondDotCollection.push_back(secondDot);
	}

	auto firstBoundary = std::minmax_element(firstDotCollection.begin(), firstDotCollection.end());

	auto secondBoundary = std::minmax_element(secondDotCollection.begin(), secondDotCollection.end());
 
	auto center = box.GetCenter() + ( Math::GetRational(1,2) * (*firstBoundary.first + *firstBoundary.second) * box.GetFirstAxis() +
				   Math::GetRational(1,2) * (*secondBoundary.first + *secondBoundary.second) * box.GetSecondAxis());

	auto firstExtent = (*firstBoundary.second - *firstBoundary.first) *  Math::GetRational(1,2);
	auto secondExtent = (*secondBoundary.second - *secondBoundary.first) *  Math::GetRational(1,2);

	return Box2{ center, box.GetFirstAxis(), box.GetSecondAxis(), firstExtent, secondExtent };
}

// static
template <typename Real>
bool Mathematics::ContBox2<Real>
	::InBox(const Vector2D& point, const Box2& box)
{
	auto diff = point - box.GetCenter();
	auto firstCoeff = Vector2DTools<Real>::DotProduct(diff, box.GetAxis0());

	if (box.GetExtent0() + box.GetEpsilon() < firstCoeff)
		return false;

	auto secondCoeff = Vector2DTools<Real>::DotProduct(diff, box.GetAxis1());

	if (box.GetExtent1() + box.GetEpsilon() < secondCoeff)
		return false;
    
    return true;
}

// static
template <typename Real>
typename const Mathematics::ContBox2<Real>::Box2 Mathematics::ContBox2<Real>
	::MergeBoxes(const Box2& lhs, const Box2& rhs)
{
	// 在包围盒中心的第一个猜想。输入包围盒顶点投影到确定的平均包围盒的轴，
	// 此值将在后面进行更新。
	auto center =  Math::GetRational(1,2) * (lhs.GetCenter() + rhs.GetCenter());

	// 合并的包围盒的轴是输入包围盒轴的平均值。
	// 如果需要的话，第二个包围盒的轴被取负，这样它们形成与第一个包围盒的轴线为锐角。
	Vector2D firstAxis;
	if (Math<Real>::GetValue(0) <= Vector2DTools<Real>::DotProduct(lhs.GetAxis0(),rhs.GetAxis0()))
    {
		firstAxis =  Math::GetRational(1,2) * (lhs.GetAxis0() + rhs.GetAxis0());
		firstAxis.Normalize();
    }
    else
    {
		firstAxis =  Math::GetRational(1,2) * (lhs.GetAxis0() - rhs.GetAxis0());
		firstAxis.Normalize();
    }
	auto secondAxis = -Vector2DTools<Real>::GetPerp(firstAxis);

	// 项目的输入包围盒顶点到合并后的包围盒的轴。
	// 各个轴线D[i]包含当前中心C具有最小投影值min[i]和最大投影值max[i]。
	// 轴线上的相应结束点是C + min[i] * D[i]和C + max[i] * D[i]。
	// C点并不一定是任何时间间隔的中点。
	// 实际包围盒中心将从C调整为点C'是每个间隔的中点，
    //   C' = C + sum_{i=0}^1 0.5 * (min[i] + max[i]) * D[i]
    // 包围盒的范围是
    //   e[i] = 0.5 * (max[i] - min[i])
 
	auto lhsVertices = lhs.ComputeVertices();
	auto rhsVertices = rhs.ComputeVertices();

	lhsVertices.insert(lhsVertices.end(), rhsVertices.begin(), rhsVertices.end());

	std::vector<Real> firstDotCollection;
	std::vector<Real> secondDotCollection;
	firstDotCollection.reserve(lhsVertices.size());
	secondDotCollection.reserve(lhsVertices.size());

	for(const auto& point: lhsVertices)
	{
		auto diff = point - center;

		auto firstDot = Vector2DTools<Real>::DotProduct(diff, firstAxis);
		firstDotCollection.push_back(firstDot);

		auto secondDot = Vector2DTools<Real>::DotProduct(diff, secondAxis);
		secondDotCollection.push_back(secondDot);
	}

	auto firstBoundary = std::minmax_element(firstDotCollection.begin(), firstDotCollection.end());

	auto secondBoundary = std::minmax_element(secondDotCollection.begin(), secondDotCollection.end());

	// [min,max] 为合并后的包围盒的轴在坐标系中为轴对齐包围盒。
	// 更新当前包围盒中心成为新包围盒的中心。计算基于新的中心的范围。
	center +=  Math::GetRational(1,2) * (*firstBoundary.first + *firstBoundary.second) * firstAxis +
		       Math::GetRational(1,2) * (*secondBoundary.first + *secondBoundary.second) * secondAxis;

	auto firstExtent = (*firstBoundary.second - *firstBoundary.first) *  Math::GetRational(1,2);
	auto secondExtent = (*secondBoundary.second - *secondBoundary.first) *  Math::GetRational(1,2);

	return Box2{ center, firstAxis, secondAxis, firstExtent, secondExtent };
}

#endif // MATHEMATICS_CONTAINMENT_CONT_BOX2_DETAIL_H
 