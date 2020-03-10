// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 13:18)

#ifndef MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_DETAIL_H

#include "OrthogonalLineFit3.h"
#include "Mathematics/NumericalAnalysis/LinearSystem.h" 
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h" 

#include <boost/numeric/conversion/cast.hpp>

template <typename Real>
Mathematics::OrthogonalLineFit3<Real>
	::OrthogonalLineFit3(const std::vector<Vector3D>& points)
	:m_Line{ Calculate(points) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::OrthogonalLineFit3<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT


template <typename Real>
typename Mathematics::OrthogonalLineFit3<Real>::Line3 Mathematics::OrthogonalLineFit3<Real>
	::GetLine3() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;	

	return m_Line;
}

// static
template <typename Real>
typename Mathematics::OrthogonalLineFit3<Real>::Line3  Mathematics::OrthogonalLineFit3<Real>
	::Calculate(const std::vector<Vector3D>& points)
{
	// 计算点的平均值。
	Vector3D origin; 
	for(const auto& point:points)
	{
		origin += point;
	}

	origin /= boost::numeric_cast<Real>(points.size());
	
	// 计算点的协方差矩阵。
	Real sumXX { };
	Real sumXY { };
	Real sumXZ { };
	Real sumYY { };
	Real sumYZ { };
	Real sumZZ { };	
 
	for (const auto& point : points)
	{
		auto diff = point - origin;
		sumXX += diff[0] * diff[0];
		sumXY += diff[0] * diff[1];
		sumXZ += diff[0] * diff[2];
		sumYY += diff[1] * diff[1];
		sumYZ += diff[1] * diff[2];
		sumZZ += diff[2] * diff[2];
	}
	
	sumXX /= boost::numeric_cast<Real>(points.size());
	sumXY /= boost::numeric_cast<Real>(points.size());
	sumXZ /= boost::numeric_cast<Real>(points.size());
	sumYY /= boost::numeric_cast<Real>(points.size());
	sumYZ /= boost::numeric_cast<Real>(points.size());
	sumZZ /= boost::numeric_cast<Real>(points.size());

	// 建立 eigensolver.
	EigenDecomposition<Real> eigenSystem{ 3 };
	eigenSystem(0, 0) = sumYY + sumZZ;
	eigenSystem(0, 1) = -sumXY;
	eigenSystem(0, 2) = -sumXZ;
	eigenSystem(1, 0) = eigenSystem(0, 1);
	eigenSystem(1, 1) = sumXX + sumZZ;
	eigenSystem(1, 2) = -sumYZ;
	eigenSystem(2, 0) = eigenSystem(0, 2);
	eigenSystem(2, 1) = eigenSystem(1, 2);
	eigenSystem(2, 2) = sumXX + sumYY;
	
	// 计算特征值，最小的特征是在最后的位置。
	eigenSystem.Solve(false);
	
	// 对于最佳拟合线的单位长度方向。
	auto direction = eigenSystem.GetEigenvector3(2);
	
	return Line3{ origin, direction };
}
 
#endif // MATHEMATICS_APPROXIMATION_ORTHOGONAL_LINT_FIT3_DETAIL_H
