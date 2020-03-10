// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/10 11:30)

#ifndef MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_DETAIL_H
#define MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_DETAIL_H

#include "CylinderFit3.h"
#include "OrthogonalLineFit3Detail.h"
#include "CylinderFit3UpdateDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Objects2D/Line2Detail.h"
#include "Mathematics/Algebra/Vector3DDetail.h"
#include "Mathematics/Algebra/Vector3DToolsDetail.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <algorithm>

template <typename Real>
Mathematics::CylinderFit3<Real>
	::CylinderFit3( const Points& points,const Real epsilon )
	:m_Center{}, m_Axis{}, m_Radius{},m_Height{}, m_Exactly{ Math::sm_MaxReal },m_InputsAreInitialGuess{ false },m_Epsilon{ epsilon }
{
	Fit3(points);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::CylinderFit3<Real>
	::CylinderFit3( const Points& points,const Vector3D& guessCenter,const Vector3D& guessAxis,const Real epsilon )
	:m_Center{ guessCenter }, m_Axis{ guessAxis }, m_Radius{}, m_Height{}, m_Exactly{ Math::sm_MaxReal }, m_InputsAreInitialGuess{ true }, m_Epsilon{ epsilon }
{
	Fit3(points);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::CylinderFit3<Real>
	::Fit3( const Points& points )
{	
	InitialGuess(points);
	Update(points);
	auto average = ComputeHeight(points);
	ComputeCenter(average);
}

// private
template <typename Real>
void Mathematics::CylinderFit3<Real>
	::InitialGuess( const Points& points )
{
	if (!m_InputsAreInitialGuess)
	{
		// 找到适合该数据的最小二乘线，并用它作为圆柱体轴的初始猜测。
		OrthogonalLineFit3<Real> orthogonalLineFit3{ points };
		
		auto line = orthogonalLineFit3.GetLine3();
		m_Center = line.GetOrigin();
		m_Axis = line.GetDirection();
	}
}

// private
template <typename Real>
void Mathematics::CylinderFit3<Real>
	::Update( const Points& points )
{
	const int maxLoopTime = 8;

	CylinderFit3Update<Real> update{ points,m_Center,m_Axis,m_Epsilon };
	update.Update(maxLoopTime);

	m_Radius = Math::InvSqrt(update.GetInverseRadiusSqrare());
	m_Center = update.GetCenter();	 
	m_Axis = update.GetAxis();

	m_Exactly = update.GetExactly();
}

// private
template <typename Real>
Real Mathematics::CylinderFit3<Real>
	::ComputeHeight(const Points& points)
{
	// 项目点拟合到轴确定圆柱体沿轴的幅度。
	std::vector<Real> dotCollection;
	dotCollection.reserve(points.size());
	for(const auto& point: points)
	{
		auto dot = Vector3DTools<Real>::DotProduct(m_Axis, point - m_Center);
		dotCollection.push_back(dot);
	}

 	auto boundary = std::minmax_element(dotCollection.begin(), dotCollection.end());
	 
	// 计算高度。调整中心点到项目幅度中点
	m_Height = *boundary.second - *boundary.first;

	return *boundary.first + *boundary.second;
}

// private
template <typename Real>
void Mathematics::CylinderFit3<Real>
	::ComputeCenter(Real average)
{
	m_Center += static_cast<Real>(0.5) * average * m_Axis;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::CylinderFit3<Real>
	::IsValid() const noexcept
{
	if (Real{} <= m_Radius && Real{} <= m_Height && Real{} <= m_Exactly && Real{} <= m_Epsilon &&  m_Axis.IsNormalize(m_Epsilon))
	{
		return true;
	}
	else
	{
		return false;
	}
}
#endif // OPEN_CLASS_INVARIANT


template <typename Real>
Real Mathematics::CylinderFit3<Real>
	::GetExactly() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Exactly;
}

template <typename Real>
typename const Mathematics::CylinderFit3<Real>::Vector3D Mathematics::CylinderFit3<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
typename const Mathematics::CylinderFit3<Real>::Vector3D Mathematics::CylinderFit3<Real>
	::GetAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis;
}

template <typename Real>
Real Mathematics::CylinderFit3<Real>
	::GetRadius() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Radius;
}

template <typename Real>
Real Mathematics::CylinderFit3<Real>
	::GetHeight() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Height;
}

#endif // MATHEMATICS_APPROXIMATION_CYLINDER_FIT3_DETAIL_H

