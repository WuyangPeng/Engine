// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 13:23)

#ifndef MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_DETAIL_H

#include "Mathematics/MathematicsDll.h"

#include "QuadraticCircleFit2.h"
#include "CircleFit2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Vector2DToolsDetail.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::CircleFit2<Real>
	::CircleFit2(const std::vector<Vector2D>& points, int maxIterations, bool initialCenterIsAverage)
	:m_Circle{}
{
	Calculate(points, maxIterations, initialCenterIsAverage);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

// private
template <typename Real>
void Mathematics::CircleFit2<Real>
	::Calculate(const std::vector<Vector2D>& points, int maxIterations, bool initialCenterIsAverage)
{
	// 计算数据点的平均值。
	auto average = GetAveragePoint(points);

	// 猜测初始中心。
	if (initialCenterIsAverage)
	{
		m_Circle.SetCircle(average, Math<Real>::sm_Zero);
	}
	else
	{
		QuadraticCircleFit2<Real> fit2{ points };

		m_Circle.SetCircle(fit2.GetCenter(), fit2.GetRadius());
	}

	for (int loop = 0; loop < maxIterations; ++loop)
	{
		auto current = m_Circle.GetCenter();

		// 更新迭代
		Iteration(points, average);

		auto circleDifference = m_Circle.GetCenter() - current;

		if (Math<Real>::FAbs(circleDifference[0]) <= Math<Real>::sm_ZeroTolerance &&
			Math<Real>::FAbs(circleDifference[1]) <= Math<Real>::sm_ZeroTolerance)
		{
			return;
		}

		MATHEMATICS_ASSERTION_4(loop + 1 != maxIterations, "迭代超出次数。");
	}
}

template <typename Real>
const typename Mathematics::CircleFit2<Real>::Vector2D  Mathematics::CircleFit2<Real>
	::GetAveragePoint(const std::vector<Vector2D>& points)
{
	MATHEMATICS_ASSERTION_0(!points.empty(), "输入的数组大小为零！");

	auto average = points[0];

	auto numPoints = boost::numeric_cast<int>(points.size());

	for (auto i = 1; i < numPoints; ++i)
	{
		average += points[i];
	}

	average /= boost::numeric_cast<Real>(numPoints);

	return average;
}

template <typename Real>
void Mathematics::CircleFit2<Real>
	::Iteration(const std::vector<Vector2D>& points, const Vector2D& average)
{
	auto numPoints = boost::numeric_cast<int>(points.size());

	// 计算平均值L, dL/da, dL/db。
	auto lengthAverage = Math<Real>::sm_Zero;
	Vector2D derLenghtAverage;

	for (auto i = 0; i < numPoints; ++i)
	{
		auto difference = points[i] - m_Circle.GetCenter();

		auto length = Vector2DTools<Real>::VectorMagnitude(difference);
		if (Math<Real>::sm_ZeroTolerance < length)
		{
			lengthAverage += length;
			derLenghtAverage -= difference / length;
		}
	}

	lengthAverage /= boost::numeric_cast<Real>(numPoints);
	derLenghtAverage /= boost::numeric_cast<Real>(numPoints);

	m_Circle.SetCircle(average + lengthAverage * derLenghtAverage, lengthAverage);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::CircleFit2<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT                                    

template <typename Real>
typename const Mathematics::CircleFit2<Real>::Circle2
Mathematics::CircleFit2<Real>
	::GetCircle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Circle;
}

#endif // MATHEMATICS_APPROXIMATION_CIRCLE_FIT2_DETAIL_H


