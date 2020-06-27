// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 17:45)

#ifndef MATHEMATICS_OBJECTS3D_RECTANGLE3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_RECTANGLE3_DETAIL_H

#include "Rectangle3.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Rectangle3<Real>
	::Rectangle3(const Vector3D& center, const Vector3D& axis0, const Vector3D& axis1, Real extent0, Real extent1, const Real epsilon)
	:m_Center{ center }, m_Epsilon{ epsilon }
{
	m_Axis[0] = axis0;
	m_Axis[1] = axis1;
	m_Extent[0] = extent0;
	m_Extent[1] = extent1;

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Rectangle3<Real>
	::IsValid() const noexcept
{
	if (m_Axis[0].IsNormalize(m_Epsilon) && m_Axis[1].IsNormalize(m_Epsilon) &&
		-m_Epsilon < m_Extent[0] && -m_Epsilon < m_Extent[1])
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
typename const Mathematics::Rectangle3<Real>::Vector3D Mathematics::Rectangle3<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
typename const Mathematics::Rectangle3<Real>::Vector3D Mathematics::Rectangle3<Real>
	::GetFirstAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis[0];
}

template <typename Real>
typename const Mathematics::Rectangle3<Real>::Vector3D	Mathematics::Rectangle3<Real>
	::GetSecondAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis[1];
}

template <typename Real>
const typename Mathematics::Rectangle3<Real>::Vector3D Mathematics::Rectangle3<Real>
	::GetAxis(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (0 <= index && index < 2)
	{
		return m_Axis[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"));
	}
}

template <typename Real>
Real Mathematics::Rectangle3<Real>
	::GetExtent(int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	if (0 <= index && index < 2)
	{
		return m_Extent[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("索引错误！"));
	}
}

template <typename Real>
Real Mathematics::Rectangle3<Real>
	::GetFirstExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent[0];
}

template <typename Real>
Real Mathematics::Rectangle3<Real>
	::GetSecondExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent[1];
}

template <typename Real>
const std::vector<typename Mathematics::Rectangle3<Real>::Vector3D> Mathematics::Rectangle3<Real>
	::ComputeVertices() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto extAxis0 = m_Axis[0] * m_Extent[0];
	auto extAxis1 = m_Axis[1] * m_Extent[1];

	std::vector<Vector3D> vertex{ m_Center - extAxis0 - extAxis1 ,m_Center + extAxis0 - extAxis1 ,m_Center + extAxis0 + extAxis1 ,m_Center - extAxis0 + extAxis1 };

	MATHEMATICS_ASSERTION_1(vertex.size() == 4, "返回的数组大小错误！");

	return vertex;
}

template <typename Real>
typename const Mathematics::Rectangle3<Real>::Vector3D Mathematics::Rectangle3<Real>
	::GetPPCorner() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center + m_Extent[0] * m_Axis[0] + m_Extent[1] * m_Axis[1];
}

template <typename Real>
typename const Mathematics::Rectangle3<Real>::Vector3D Mathematics::Rectangle3<Real>
	::GetPMCorner() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center + m_Extent[0] * m_Axis[0] - m_Extent[1] * m_Axis[1];
}

template <typename Real>
typename const Mathematics::Rectangle3<Real>::Vector3D Mathematics::Rectangle3<Real>
	::GetMPCorner() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center - m_Extent[0] * m_Axis[0] + m_Extent[1] * m_Axis[1];
}

template <typename Real>
typename const Mathematics::Rectangle3<Real>::Vector3D Mathematics::Rectangle3<Real>
	::GetMMCorner() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center - m_Extent[0] * m_Axis[0] - m_Extent[1] * m_Axis[1];
}

#endif // MATHEMATICS_OBJECTS3D_RECTANGLE3_DETAIL_H

