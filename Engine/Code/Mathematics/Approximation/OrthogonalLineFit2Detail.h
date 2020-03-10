// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// Copyright (c) 2011-2017
//
// 引擎版本：1.0.0.0 (2017/12/01 21:06)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_DETAIL_H

#include "OrthogonalLineFit2.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h" 
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename Real>
Mathematics::OrthogonalLineFit2<Real>
	::OrthogonalLineFit2(const std::vector<Vector2D>& points)
	:m_Line{ Calculate(points) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::OrthogonalLineFit2<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT


template <typename Real>
typename Mathematics::OrthogonalLineFit2<Real>::Line2 Mathematics::OrthogonalLineFit2<Real>
	::GetLine2() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;	

	return m_Line;
}

// static
template <typename Real>
typename Mathematics::OrthogonalLineFit2<Real>::Line2  Mathematics::OrthogonalLineFit2<Real>
	::Calculate(const std::vector<Vector2D>& points)
{
	// 计算点的平均值。
	Vector2D origin; 
	for(const auto& point:points)
	{
		origin += point;
	}

	origin /= boost::numeric_cast<Real>(points.size());
	
	// 计算点的协方差矩阵。
	Real sumXX { };
	Real sumXY { };
	Real sumYY { };
	for (const auto& point : points)
	{
		auto diff = point - origin;
		sumXX += diff[0] * diff[0];
		sumXY += diff[0] * diff[1];
		sumYY += diff[1] * diff[1];
	}
	
	sumXX /= boost::numeric_cast<Real>(points.size());
	sumXY /= boost::numeric_cast<Real>(points.size());
	sumYY /= boost::numeric_cast<Real>(points.size());
	
	// 建立 eigensolver.
	EigenDecomposition<Real> eigenSystem{ 2 };
	eigenSystem(0, 0) = sumYY;
	eigenSystem(0, 1) = -sumXY;
	eigenSystem(1, 0) = -sumXY;
	eigenSystem(1, 1) = sumXX;
	
	// 计算特征值，最小的特征是在最后的位置。
	eigenSystem.Solve(false);
	
	// 对于最佳拟合线的单位长度方向。
	auto direction = eigenSystem.GetEigenvector2(1);
	
	return Line2{ origin, direction };
}
 
#endif // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT2_DETAIL_H
