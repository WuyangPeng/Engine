// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 13:03)

#ifndef MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_DETAIL_H

#include "GaussPointsFit2.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <boost/numeric/conversion/cast.hpp>

template <typename Real>
Mathematics::GaussPointsFit2<Real>
	::GaussPointsFit2(const std::vector<Vector2D>& points)
	:m_Box{ Calculate(points) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::GaussPointsFit2<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename Mathematics::GaussPointsFit2<Real>::Box2 Mathematics::GaussPointsFit2<Real>
	::GetBox2() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Box;
}

template <typename Real>
typename Mathematics::GaussPointsFit2<Real>::Box2 Mathematics::GaussPointsFit2<Real>
	::Calculate(const std::vector<Vector2D>& points)
{
	auto numPoints = boost::numeric_cast<int>(points.size());

    // 计算点的平均值。
	Vector2D center;
	for(const auto& point: points)
	{
		center += point;
	}

	center /= static_cast<Real>(numPoints);

    // 计算点的协方差矩阵。
	Real sumXX { };
	Real sumXY { };
	Real sumYY { };
	for (const auto& point: points)
	{
		auto diff = point - center;
		sumXX += diff[0] * diff[0];
		sumXY += diff[0] * diff[1];
		sumYY += diff[1] * diff[1];
	}

	sumXX /= static_cast<Real>(points.size());
	sumXY /= static_cast<Real>(points.size());
	sumYY /= static_cast<Real>(points.size());

    // 建立 eigensolver.
	EigenDecomposition<Real> eigenSystem{ 2 };

    eigenSystem(0,0) = sumXX;
    eigenSystem(0,1) = sumXY;
    eigenSystem(1,0) = sumXY;
    eigenSystem(1,1) = sumYY;

    eigenSystem.Solve(true);

	Real extent[2]{};
	Vector2D axis[2]{};

    for (auto i = 0; i < 2; ++i)
    {
		extent[i] = eigenSystem.GetEigenvalue(i);
		axis[i] = eigenSystem.GetEigenvector2(i);
    }

	return Box2{ center, axis[0], axis[1], extent[0], extent[1] };
}

#endif // MATHEMATICS_APPROXIMATION_GAUSS_POINTS_FIT2_DETAIL_H
 