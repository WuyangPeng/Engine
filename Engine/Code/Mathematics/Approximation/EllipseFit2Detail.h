// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 13:36)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_DETAIL_H
#define MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_DETAIL_H

#include "EllipseFit2.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix2Detail.h"
#include "Mathematics/Containment/ContBox2Detail.h"
#include "Mathematics/NumericalAnalysis/MinimizeNDetail.h"
#include "Mathematics/Distance/Distance2D/DistancePoint2Ellipse2Detail.h"

template <typename Real>
Mathematics::EllipseFit2<Real>
	::EllipseFit2(const Points& points)
	:m_Points{ points }, m_Center{}, m_Rotate{}, m_FirstExtent{}, m_SecondExtent{}, m_Exactly{}
{
	Fit2();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::EllipseFit2<Real>
	::Fit2()
{
	// 能量函数为 E : Real^5 -> Real 其中
	// V = (V0, V1, V2, V3, V4)
	//   = (D[0], D[1], U.x, U.y, atan2(Real[1][0],Real[1][1])).

	InitialGuess();

	auto angle = Math<Real>::ATan2(m_Rotate[0][1], m_Rotate[0][0]);
	auto firstExtent = m_FirstExtent * Math<Real>::FAbs(m_Rotate[0][0]) +
					   m_SecondExtent * Math<Real>::FAbs(m_Rotate[1][0]);
	auto secondExtent = m_FirstExtent * Math<Real>::FAbs(m_Rotate[0][1]) +
						m_SecondExtent * Math<Real>::FAbs(m_Rotate[1][1]);

	std::vector<Real> begin{ static_cast<Real>(0.5) * m_FirstExtent,
							 static_cast<Real>(0.5) * m_SecondExtent,
							 m_Center.GetX() - firstExtent,
							 m_Center.GetY() - secondExtent,
							 -Math<Real>::GetPI() };

	std::vector<Real> end{ static_cast<Real>(2) * m_FirstExtent,
						   static_cast<Real>(2) * m_SecondExtent,
						   m_Center.GetX() + firstExtent,
						   m_Center.GetY() + secondExtent,
						   Math<Real>::GetPI() };

	std::vector<Real> initial{ m_FirstExtent, m_SecondExtent, m_Center.GetX(),
							   m_Center.GetY(), angle };

	MinimizeN<Real, ClassType> minimizer{ 5, Energy, 8, 8, 32, this };

	auto data = minimizer.GetMinimum(begin, end, initial);

	m_Exactly = data.GetMinValue();

	const auto& minLocation = data.GetMinLocation();

	m_FirstExtent = minLocation[0];
	m_SecondExtent = minLocation[1];
	m_Center.SetCoordinate(minLocation[2], minLocation[3]);

	m_Rotate.MakeRotation(-minLocation[4]);
} 

// private
template <typename Real>
void Mathematics::EllipseFit2<Real>
	::InitialGuess()
{
	auto box = ContBox2<Real>::ContOrientedBox(m_Points);

	m_Center = box.GetCenter();
	m_Rotate[0][0] = box.GetFirstAxis().GetX();
	m_Rotate[0][1] = box.GetFirstAxis().GetY();
	m_Rotate[1][0] = box.GetSecondAxis().GetX();
	m_Rotate[1][1] = box.GetSecondAxis().GetY();
	m_FirstExtent = box.GetFirstExtent();
	m_SecondExtent = box.GetSecondExtent();
}

// static
// private
template <typename Real>
Real Mathematics::EllipseFit2<Real>
	::Energy(const std::vector<Real>& input, const ClassType* userData)
{
	const auto& self = *userData;

	// 构建旋转矩阵
	Matrix2 rotate{ -input[4] };

	Ellipse2<Real> ellipse{ Vector2D::sm_Zero, Vector2D::sm_UnitX,
							Vector2D::sm_UnitY, input[0], input[1] };

	// 变换点到中心C和旋转Real的列的坐标系统
	auto energy = Math<Real>::GetValue(0);

	auto numPoints = userData->GetNumPoint();

	for (auto i = 0; i < numPoints; ++i)
	{
		Vector2D diff{ self.GetPoint(i).GetX() - input[2],
					   self.GetPoint(i).GetY() - input[3] };

		auto point = rotate * diff;

		DistancePoint2Ellipse2<Real> distancePoint2Ellipse2{ point, ellipse };
		auto distance = distancePoint2Ellipse2.Get();

		energy += distance.GetDistance();
	}

	return energy;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::EllipseFit2<Real>
	::IsValid() const noexcept
{
	if (Math<Real>::GetValue(0) <= m_Exactly)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::EllipseFit2<Real>
	::GetExactly() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Exactly;
}

template <typename Real>
typename const Mathematics::EllipseFit2<Real>::Vector2D Mathematics::EllipseFit2<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
typename const Mathematics::EllipseFit2<Real>::Matrix2 Mathematics::EllipseFit2<Real>
	::GetRotate() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Rotate;
}

template <typename Real>
Real Mathematics::EllipseFit2<Real>
	::GetFirstExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_FirstExtent;
}

template <typename Real>
Real Mathematics::EllipseFit2<Real>
	::GetSecondExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_SecondExtent;
}

template <typename Real>
int Mathematics::EllipseFit2<Real>
	::GetNumPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Points.size());
}

template <typename Real>
typename const Mathematics::EllipseFit2<Real>::Vector2D Mathematics::EllipseFit2<Real>
	::GetPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetNumPoint(), "索引错误！");

	return m_Points[index];
}

#endif // MATHEMATICS_APPROXIMATION_ELLIPSE_FIT2_DETAIL_H
