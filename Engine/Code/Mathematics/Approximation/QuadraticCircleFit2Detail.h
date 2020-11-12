// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 14:58)

#ifndef MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_DETAIL_H

#include "QuadraticCircleFit2.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "Mathematics/Algebra/VariableLengthVectorDetail.h"
#include "Mathematics/NumericalAnalysis/EigenDecompositionDetail.h"

template <typename Real>
Mathematics::QuadraticCircleFit2<Real>
	::QuadraticCircleFit2(const std::vector<Vector2D>& points)
	:m_Center{}, m_Radius{}, m_EigenValue{}
{
	Calculate(points);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::QuadraticCircleFit2<Real>
	::Calculate(const std::vector<Vector2D>& points)
{
	EigenDecomposition<Real> eigenSystem{ sm_EigenSystemSize };
	// EigenDecomposition需要保证初始化每个esystem(row,col)

	auto numPoints = points.size();

	for (auto i = 0u; i < numPoints; ++i)
	{
		auto x = points[i].GetX();
		auto y = points[i].GetY();
		auto xSquare = x * x;
		auto ySquare = y * y;
		auto xMultiplyY = x * y;
		auto rSquare = xSquare + ySquare;
		auto xMultiplyRSquare = x * rSquare;
		auto yMultiplyRSquare = y * rSquare;
		auto rQuadruplicate = rSquare * rSquare;

		eigenSystem(0, 1) += x;
		eigenSystem(0, 2) += y;
		eigenSystem(0, 3) += rSquare;
		eigenSystem(1, 1) += xSquare;
		eigenSystem(1, 2) += xMultiplyY;
		eigenSystem(1, 3) += xMultiplyRSquare;
		eigenSystem(2, 2) += ySquare;
		eigenSystem(2, 3) += yMultiplyRSquare;
		eigenSystem(3, 3) += rQuadruplicate;
	}

	eigenSystem(0, 0) = static_cast<Real>(numPoints);

	for (auto row = 0; row < sm_EigenSystemSize; ++row)
	{
		for (auto column = 0; column < row; ++column)
		{
			eigenSystem(row, column) = eigenSystem(column, row);
		}
	}

	for (auto row = 0; row < sm_EigenSystemSize; ++row)
	{
		for (auto column = 0; column < sm_EigenSystemSize; ++column)
		{
			eigenSystem(row, column) /= static_cast<Real>(numPoints);
		}
	}

	eigenSystem.Solve(true);

	auto eigenVector = eigenSystem.GetEigenvector(0);
	// 当心除零
	if (Math<Real>::GetZeroTolerance() < Math<Real>::FAbs(eigenVector[3]))
	{
		auto inv = static_cast<Real>(1) / eigenVector[3];

		Real coeff[3]{ };
		for (auto row = 0; row < 3; ++row)
		{
			coeff[row] = inv * eigenVector[row];
		}

		m_Center[0] = -(static_cast<Real>(0.5) * coeff[1]);
		m_Center[1] = -(static_cast<Real>(0.5) * coeff[2]);
		m_Radius = Math<Real>::Sqrt(Math<Real>::FAbs(m_Center[0] * m_Center[0] + m_Center[1] * m_Center[1] - coeff[0]));

		// 对于精确配合，数字舍入误差可能使最小特征值仅仅略为负值。
		// 返回的绝对值，因为应用程序可能依赖的返回值是非负数。
		m_EigenValue = Math<Real>::FAbs(eigenSystem.GetEigenvalue(0));
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("除零错误！"));
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::QuadraticCircleFit2<Real>
	::IsValid() const noexcept
{
	if (Math<Real>::GetValue(0) < m_Radius && Math<Real>::GetValue(0) <= m_EigenValue)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::QuadraticCircleFit2<Real>::Vector2D Mathematics::QuadraticCircleFit2<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
Real Mathematics::QuadraticCircleFit2<Real>
	::GetRadius() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Radius;
}

template <typename Real>
Real Mathematics::QuadraticCircleFit2<Real>
	::GetEigenValue() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_EigenValue;
}

#endif // MATHEMATICS_APPROXIMATION_QUADRATIC_CIRCLE_FIT2_DETAIL_H

