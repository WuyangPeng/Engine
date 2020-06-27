// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 13:58)

#ifndef MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_DETAIL_H

#include "GaussPointsFit3.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h" 

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::GaussPointsFit3<Real>
	::GaussPointsFit3(const std::vector<Vector3D>& points)
	:m_Box{ Calculate(points) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::GaussPointsFit3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::GaussPointsFit3<Real>::Box3 Mathematics::GaussPointsFit3<Real>
	::GetBox3() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Box;
}

template <typename Real>
typename Mathematics::GaussPointsFit3<Real>::Box3 Mathematics::GaussPointsFit3<Real>
	::Calculate(const std::vector<Vector3D>& points)
{
	auto numPoints = points.size();

	// 计算点的平均值。
	Vector3D center;
	for (const auto& point : points)
	{
		center += point;
	}

	center /= static_cast<Real>(numPoints);

	// 计算点的协方差矩阵。
	auto sumXX = Math<Real>::sm_Zero;
	auto sumXY = Math<Real>::sm_Zero;
	auto sumYY = Math<Real>::sm_Zero;
	auto sumXZ = Math<Real>::sm_Zero;
	auto sumYZ = Math<Real>::sm_Zero;
	auto sumZZ = Math<Real>::sm_Zero;

	for (const auto& point : points)
	{
		auto diff = point - center;
		sumXX += diff[0] * diff[0];
		sumXY += diff[0] * diff[1];
		sumXZ += diff[0] * diff[2];
		sumYY += diff[1] * diff[1];
		sumYZ += diff[1] * diff[2];
		sumZZ += diff[2] * diff[2];
	}

	sumXX /= boost::numeric_cast<Real>(points.size());
	sumXY /= boost::numeric_cast<Real>(points.size());
	sumYY /= boost::numeric_cast<Real>(points.size());
	sumXZ /= boost::numeric_cast<Real>(points.size());
	sumYZ /= boost::numeric_cast<Real>(points.size());
	sumZZ /= boost::numeric_cast<Real>(points.size());

	// 建立 eigensolver.
	EigenDecomposition<Real> eigenSystem{ 3 };

	eigenSystem(0, 0) = sumXX;
	eigenSystem(0, 1) = sumXY;
	eigenSystem(0, 2) = sumXZ;
	eigenSystem(1, 0) = sumXY;
	eigenSystem(1, 1) = sumYY;
	eigenSystem(1, 2) = sumYZ;
	eigenSystem(2, 0) = sumXZ;
	eigenSystem(2, 1) = sumYZ;
	eigenSystem(2, 2) = sumZZ;

	eigenSystem.Solve(true);

	Real extent[3]{};
	Vector3D axis[3];

	for (auto i = 0; i < 3; ++i)
	{
		extent[i] = eigenSystem.GetEigenvalue(i);
		axis[i] = eigenSystem.GetEigenvector3(i);
	}

	return Box3{ center, axis[0], axis[1], axis[2], extent[0], extent[1], extent[2] };
}

#endif // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT3_DETAIL_H
