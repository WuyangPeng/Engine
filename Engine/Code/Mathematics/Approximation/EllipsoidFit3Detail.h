// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/23 13:53)

#ifndef MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_DETAIL_H

#include "EllipsoidFit3.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "Mathematics/Algebra/Matrix3Detail.h"
#include "Mathematics/Containment/ContBox3Detail.h"
#include "Mathematics/NumericalAnalysis/MinimizeNDetail.h"
#include "Mathematics/Distance/Distance3D/DistancePoint3Ellipsoid3Detail.h"

template <typename Real>
Mathematics::EllipsoidFit3<Real>
	::EllipsoidFit3(const Points& points)
	:m_Points{ points }, m_Center{}, m_Rotate{}, m_FirstExtent{},
	 m_SecondExtent{}, m_ThirdExtent{}, m_Exactly{}
{
	Fit3();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::EllipsoidFit3<Real>
	::Fit3()
{
	// 能量函数为 E : Real^9 -> Real  其中
	// V = (V0,V1,V2,V3,V4,V5,V6,V7,V8)
	//   = (D[0],D[1],D[2],U.X(),U,y,U.Z(),A0,A1,A2)。
	// 对于真正分散的数据，你可能需要一个搜索函数

	InitialGuess();

	auto angle = MatrixToAngles(m_Rotate);

	std::vector<Real> extent{ m_FirstExtent * Math<Real>::FAbs(m_Rotate[0][0]) + m_SecondExtent * Math<Real>::FAbs(m_Rotate[0][1]) + m_ThirdExtent * Math<Real>::FAbs(m_Rotate[0][2]),
							  m_FirstExtent * Math<Real>::FAbs(m_Rotate[1][0]) + m_SecondExtent * Math<Real>::FAbs(m_Rotate[1][1]) + m_ThirdExtent * Math<Real>::FAbs(m_Rotate[1][2]),
							  m_FirstExtent * Math<Real>::FAbs(m_Rotate[2][0]) + m_SecondExtent * Math<Real>::FAbs(m_Rotate[2][1]) + m_ThirdExtent * Math<Real>::FAbs(m_Rotate[2][2]) };

	std::vector<Real> begin{ static_cast<Real>(0.5) * m_FirstExtent,static_cast<Real>(0.5) * m_SecondExtent,static_cast<Real>(0.5) * m_ThirdExtent,
							 m_Center.GetX() - extent[0], m_Center.GetY() - extent[1], m_Center.GetZ() - extent[2],
							 -Math<Real>::GetPI(), Math<Real>::GetValue(0), Math<Real>::GetValue(0) };

	std::vector<Real> end{ static_cast<Real>(2) * m_FirstExtent, static_cast<Real>(2) * m_SecondExtent,static_cast<Real>(2) * m_ThirdExtent,
						   m_Center.GetX() + extent[0], m_Center.GetY() + extent[1], m_Center.GetZ() + extent[2],
						   Math<Real>::GetPI(), Math<Real>::GetPI(), Math<Real>::GetPI() };

	std::vector<Real> initial{ m_FirstExtent, m_SecondExtent,m_ThirdExtent, m_Center.GetX(), m_Center.GetY(),
							   m_Center.GetZ(), angle[0],  angle[1],  angle[2] };

	MinimizeN<Real, ClassType> minimizer{ 9, Energy, 8, 8, 32, this };
	auto data = minimizer.GetMinimum(begin, end, initial);
	m_Exactly = data.GetMinValue();

	m_FirstExtent = data.GetMinLocation(0);
	m_SecondExtent = data.GetMinLocation(1);
	m_ThirdExtent = data.GetMinLocation(2);
	m_Center.SetCoordinate(data.GetMinLocation(3), data.GetMinLocation(4), data.GetMinLocation(5));

	angle[0] = data.GetMinLocation(6);
	angle[1] = data.GetMinLocation(7);
	angle[2] = data.GetMinLocation(8);

	m_Rotate = AnglesToMatrix(angle);
}

// private
template <typename Real>
void Mathematics::EllipsoidFit3<Real>
	::InitialGuess()
{
	auto box = ContBox3<Real>::ContOrientedBox(m_Points);

	m_Center = box.GetCenter();
	m_Rotate[0][0] = box.GetFirstAxis().GetX();
	m_Rotate[0][1] = box.GetFirstAxis().GetY();
	m_Rotate[0][2] = box.GetFirstAxis().GetZ();
	m_Rotate[1][0] = box.GetSecondAxis().GetX();
	m_Rotate[1][1] = box.GetSecondAxis().GetY();
	m_Rotate[1][2] = box.GetSecondAxis().GetZ();
	m_Rotate[2][0] = box.GetThirdAxis().GetX();
	m_Rotate[2][1] = box.GetThirdAxis().GetY();
	m_Rotate[2][2] = box.GetThirdAxis().GetZ();
	m_FirstExtent = box.GetFirstExtent();
	m_SecondExtent = box.GetSecondExtent();
	m_ThirdExtent = box.GetThirdExtent();
}

// private
// static
template <typename Real>
Real Mathematics::EllipsoidFit3<Real>
	::Energy(const std::vector<Real>& input, const ClassType* userData)
{
	const auto& self = *userData;

	// 构建旋转矩阵
	Angle angle{ input[6], input[7], input[8] };
	auto rotate = AnglesToMatrix(angle);

	// 均匀缩放程度，以保持合理的浮点值距离计算。
	auto maxValue = input[0];
	if (maxValue < input[1])
	{
		maxValue = input[1];
	}
	if (maxValue < input[2])
	{
		maxValue = input[2];
	}

	Ellipsoid3<Real> ellipsoid{ Vector3D::sm_Zero, Vector3D::sm_UnitX, Vector3D::sm_UnitY, Vector3D::sm_UnitZ, input[0] / maxValue, input[1] / maxValue, input[2] / maxValue };

	// 变换点到中心C和旋转Real的列的坐标系统
	auto energy = Math<Real>::GetValue(0);

	auto numPoints = userData->GetNumPoint();

	for (auto i = 0; i < numPoints; ++i)
	{
		Vector3D diff{ self.GetPoint(i).GetX() - input[3],
					   self.GetPoint(i).GetY() - input[4],
					   self.GetPoint(i).GetZ() - input[5] };

		auto point = rotate * diff / maxValue;

		DistancePoint3Ellipsoid3<Real> distancePoint3Ellipsoid3{ point, ellipsoid };
		auto distance = distancePoint3Ellipsoid3.Get();

		energy += distance.GetDistance() * maxValue;
	}

	return energy;
}

template <typename Real>
typename const Mathematics::EllipsoidFit3<Real>::Angle Mathematics::EllipsoidFit3<Real>
	::MatrixToAngles(const Matrix3& rotate)
{
	// 旋转轴 = (cos(a0)sin(a1),sin(a0)sin(a1),cos(a1))
	// a0 在 [-pi,pi], a1 在 [0,pi], a2 在 [0,pi]

	auto extract = rotate.ExtractAngleAxis();
	auto axis = extract.GetAxis();
	Angle angle(3);
	angle[2] = extract.GetAngle();

	if (static_cast<Real>(-1) < axis.GetZ())
	{
		if (axis.GetZ() < static_cast<Real>(1))
		{
			angle[0] = Math<Real>::ATan2(axis.GetY(), axis.GetX());
			angle[1] = Math<Real>::ACos(axis.GetZ());
		}
		else
		{
			angle[0] = Math<Real>::GetValue(0);
			angle[1] = Math<Real>::GetValue(0);
		}
	}
	else
	{
		angle[0] = Math<Real>::GetValue(0);
		angle[1] = Math<Real>::GetPI();
	}

	return angle;
}

template <typename Real>
typename const Mathematics::EllipsoidFit3<Real>::Matrix3 Mathematics::EllipsoidFit3<Real>
	::AnglesToMatrix(const Angle& angle)
{
	// 旋转轴 = (cos(a0)sin(a1),sin(a0)sin(a1),cos(a1))
	// a0 在  [-pi,pi], a1 在 [0,pi], a2 在 [0,pi]

	auto cs0 = Math<Real>::Cos(angle[0]);
	auto sn0 = Math<Real>::Sin(angle[0]);
	auto cs1 = Math<Real>::Cos(angle[1]);
	auto sn1 = Math<Real>::Sin(angle[1]);
	Vector3D axis{ cs0 * sn1, sn0 * sn1, cs1 };

	return Matrix3{ axis, angle[2] };
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::EllipsoidFit3<Real>
	::IsValid() const noexcept
{
	if (Math<Real>::GetValue(0) <= m_Exactly)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>
	::GetExactly() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Exactly;
}

template <typename Real>
typename const Mathematics::EllipsoidFit3<Real>::Vector3D Mathematics::EllipsoidFit3<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
typename const Mathematics::EllipsoidFit3<Real>::Matrix3 Mathematics::EllipsoidFit3<Real>
	::GetRotate() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Rotate;
}

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>
	::GetFirstExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_FirstExtent;
}

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>
	::GetSecondExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_SecondExtent;
}

template <typename Real>
Real Mathematics::EllipsoidFit3<Real>
	::GetThirdExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_ThirdExtent;
}

template <typename Real>
int Mathematics::EllipsoidFit3<Real>
	::GetNumPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return boost::numeric_cast<int>(m_Points.size());
}

template <typename Real>
typename const Mathematics::EllipsoidFit3<Real>::Vector3D Mathematics::EllipsoidFit3<Real>
	::GetPoint(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < GetNumPoint(), "索引错误！");

	return m_Points[index];
}

#endif // MATHEMATICS_APPROXIMATION_ELLIPSOID_FIT3_DETAIL_H
