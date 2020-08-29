// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 15:21)

#ifndef MATHEMATICS_APPROXIMATION_SPHERE_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_SPHERE_FIT3_DETAIL_H

#include "QuadraticSphereFit3.h"
#include "SphereFit3.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::SphereFit3<Real>
	::SphereFit3(const std::vector<Vector3D>& points, int maxIterations, bool initialCenterIsAverage)
	:m_Sphere{}
{
	Calculate(points, maxIterations, initialCenterIsAverage);

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::SphereFit3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
const typename Mathematics::SphereFit3<Real>::Sphere3 Mathematics::SphereFit3<Real>
	::GetSphere() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Sphere;
}

template <typename Real>
void Mathematics::SphereFit3<Real>
	::Calculate(const std::vector<Vector3D>& points, int maxIterations, bool initialCenterIsAverage)
{
	auto average = GetAveragePoint(points);

	// 猜测初始中心。
	if (initialCenterIsAverage)
	{
		m_Sphere.SetSphere(average, Math<Real>::GetValue(0));
	}
	else
	{
		QuadraticSphereFit3<Real> fit3{ points };

		m_Sphere.SetSphere(fit3.GetCenter(), fit3.GetRadius());
	}

	for (auto loop = 0; loop < maxIterations; ++loop)
	{
		auto current = m_Sphere.GetCenter();

		// 更新迭代
		Iteration(points, average);

		auto circleDifference = m_Sphere.GetCenter() - current;

		if (Math<Real>::FAbs(circleDifference[0]) <= Math<Real>::GetZeroTolerance() &&
			Math<Real>::FAbs(circleDifference[1]) <= Math<Real>::GetZeroTolerance())
		{
			return;
		}

		MATHEMATICS_ASSERTION_4(loop + 1 != maxIterations, "迭代超出次数。");
	}
}

template <typename Real>
const typename Mathematics::SphereFit3<Real>::Vector3D Mathematics::SphereFit3<Real>
	::GetAveragePoint(const std::vector<Vector3D>& points)
{
	MATHEMATICS_ASSERTION_0(!points.empty(), "输入的数组大小为零！");

	// 计算数据点的平均值。
	auto average = points[0];

	auto numPoints = points.size();

	for (auto i = 1u; i < numPoints; ++i)
	{
		average += points[i];
	}

	average /= boost::numeric_cast<Real>(numPoints);

	return average;
}

template <typename Real>
void Mathematics::SphereFit3<Real>
::Iteration(const std::vector<Vector3D>& points, const Vector3D& average)
{
	auto numPoints = points.size();

	// 计算平均值L, dL/da, dL/db, dL/dc。
	auto lengthAverage = Math<Real>::GetValue(0);
	Vector3D derLenghtAverage;

	for (auto i = 0u; i < numPoints; ++i)
	{
		auto difference = points[i] - m_Sphere.GetCenter();

		auto length = Vector3DTools<Real>::VectorMagnitude(difference);
		if (Math<Real>::GetZeroTolerance() < length)
		{
			lengthAverage += length;
			derLenghtAverage -= difference / length;
		}
	}

	lengthAverage /= boost::numeric_cast<Real>(numPoints);
	derLenghtAverage /= boost::numeric_cast<Real>(numPoints);

	m_Sphere.SetSphere(average + lengthAverage * derLenghtAverage, lengthAverage);
}

#endif // MATHEMATICS_APPROXIMATION_SPHERE_FIT3_DETAIL_H

