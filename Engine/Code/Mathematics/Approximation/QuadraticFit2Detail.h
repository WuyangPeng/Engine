// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 14:59)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_FIT2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_FIT2_DETAIL_H

#include "QuadraticFit2.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
Mathematics::QuadraticFit2<Real>
	::QuadraticFit2(const std::vector<Vector2D>& points)
	:m_Coeff{}, m_EigenValue{}
{
	Calculate(points);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::QuadraticFit2<Real>
	::Calculate(const std::vector<Vector2D>& points)
{
	EigenDecomposition<Real> eigenSystem{ sm_EigenSystemSize };
	// EigenDecomposition需要保证初始化每个esystem(row,col)

	auto numPoints = points.size();

	for (auto i = 0u; i < numPoints; ++i)
	{
		auto x = points[i].GetXCoordinate();
		auto y = points[i].GetYCoordinate();
		auto xSquare = x * x;
		auto ySquare = y * y;
		auto xMultiplyY = x * y;
		auto xCube = x * xSquare;
		auto xMultiplyYSquare = x * ySquare;
		auto xSquareMultiplyY = x * xMultiplyY;
		auto yCube = y * ySquare;
		auto xQuadruplicate = x * xCube;
		auto xSquareMultiplyYSquare = x * xMultiplyYSquare;
		auto xCubeMultiplyY = x * xSquareMultiplyY;
		auto yQuadruplicate = y * yCube;
		auto xMultiplyYCube = x * yCube;

		eigenSystem(0, 1) += x;
		eigenSystem(0, 2) += y;
		eigenSystem(0, 3) += xSquare;
		eigenSystem(0, 4) += ySquare;
		eigenSystem(0, 5) += xMultiplyY;
		eigenSystem(1, 3) += xCube;
		eigenSystem(1, 4) += xMultiplyYSquare;
		eigenSystem(1, 5) += xSquareMultiplyY;
		eigenSystem(2, 4) += yCube;
		eigenSystem(3, 3) += xQuadruplicate;
		eigenSystem(3, 4) += xSquareMultiplyYSquare;
		eigenSystem(3, 5) += xCubeMultiplyY;
		eigenSystem(4, 4) += yQuadruplicate;
		eigenSystem(4, 5) += xMultiplyYCube;
	}

	eigenSystem(0, 0) = boost::numeric_cast<Real>(numPoints);
	eigenSystem(1, 1) = eigenSystem(0, 3);
	eigenSystem(1, 2) = eigenSystem(0, 5);
	eigenSystem(2, 2) = eigenSystem(0, 4);
	eigenSystem(2, 3) = eigenSystem(1, 5);
	eigenSystem(2, 5) = eigenSystem(1, 4);
	eigenSystem(5, 5) = eigenSystem(3, 4);

	for (auto row = 0; row < sm_EigenSystemSize; ++row)
	{
		for (auto col = 0; col < row; ++col)
		{
			eigenSystem(row, col) = eigenSystem(col, row);
		}
	}

	for (auto row = 0; row < sm_EigenSystemSize; ++row)
	{
		for (auto col = 0; col < sm_EigenSystemSize; ++col)
		{
			eigenSystem(row, col) /= boost::numeric_cast<Real>(numPoints);
		}
	}

	eigenSystem.Solve(true);

	m_Coeff = eigenSystem.GetEigenvector(0);

	// 对于精确配合，数字舍入误差可能使最小特征值仅仅略为负值。
	// 返回的绝对值，因为应用程序可能依赖的返回值是非负数。
	m_EigenValue = Math<Real>::FAbs(eigenSystem.GetEigenvalue(0));
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::QuadraticFit2<Real>
	::IsValid() const noexcept
{
	if (Math<Real>::sm_Zero <= m_EigenValue)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::QuadraticFit2<Real>::VariableLengthVector Mathematics::QuadraticFit2<Real>
	::GetCoeff() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Coeff;
}

template <typename Real>
Real Mathematics::QuadraticFit2<Real>
	::GetEigenValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_EigenValue;
}

#endif // MATHEMATICS_APPROXIMATION_QUADRATIC_FIT2_DETAIL_H
