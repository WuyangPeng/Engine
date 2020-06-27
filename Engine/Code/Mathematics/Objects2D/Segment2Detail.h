// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 16:56)

#ifndef MATHEMATICS_OBJECTS2D_SEGMENT2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_SEGMENT2_DETAIL_H

#include "Segment2.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Segment2<Real>
	::Segment2(const Vector2D& beginPoint, const Vector2D& endPoint, const Real epsilon)
	:m_BeginPoint{ beginPoint }, m_EndPoint{ endPoint }, m_Center{ static_cast<Real>(0.5) * (m_BeginPoint + m_EndPoint) },
	 m_Direction{ m_EndPoint - m_BeginPoint }, m_Extent{ Vector2DTools::VectorMagnitude(m_Direction) / static_cast<Real>(2) }, m_Epsilon{ epsilon }
{
	m_Direction.Normalize(m_Epsilon);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Segment2<Real>
	::Segment2(Real extent, const Vector2D& center, const Vector2D& direction, const Real epsilon)
	:m_BeginPoint{ center - extent * direction }, m_EndPoint{ center + extent * direction }, m_Center{ center },
	 m_Direction{ direction }, m_Extent{ extent }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Segment2<Real>
	::IsValid() const noexcept
{
	if (m_Direction.IsNormalize(m_Epsilon) &&
		Vector2DTools::Approximate(m_BeginPoint, m_Center - m_Extent * m_Direction, m_Epsilon) &&
		Vector2DTools::Approximate(m_EndPoint, m_Center + m_Extent * m_Direction, m_Epsilon) &&
		Vector2DTools::Approximate(m_Center, static_cast<Real>(0.5) * (m_BeginPoint + m_EndPoint), m_Epsilon))
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
typename const Mathematics::Segment2<Real>::Vector2D Mathematics::Segment2<Real>
	::GetBeginPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_BeginPoint;
}

template <typename Real>
typename const Mathematics::Segment2<Real>::Vector2D Mathematics::Segment2<Real>
	::GetEndPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_EndPoint;
}

template <typename Real>
typename const Mathematics::Segment2<Real>::Vector2D Mathematics::Segment2<Real>
	::GetCenterPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
typename const Mathematics::Segment2<Real>::Vector2D Mathematics::Segment2<Real>
	::GetDirection() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Direction;
}

template <typename Real>
Real Mathematics::Segment2<Real>
	::GetExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent;
}

// private
template <typename Real>
void Mathematics::Segment2<Real>
	::ComputeCenterDirectionExtent()
{
	m_Center = static_cast<Real>(0.5) * (m_BeginPoint + m_EndPoint);
	m_Direction = m_EndPoint - m_BeginPoint;
	m_Extent = Vector2DTools::VectorMagnitude(m_Direction) / static_cast<Real>(2);

	m_Direction.Normalize(m_Epsilon);
}

// private
template <typename Real>
void Mathematics::Segment2<Real>
	::ComputeEndPoints()
{
	m_BeginPoint = m_Center - m_Extent * m_Direction;
	m_EndPoint = m_Center + m_Extent * m_Direction;
}

template <typename Real>
const typename Mathematics::Segment2<Real>::ClassType Mathematics::Segment2<Real>
	::GetMove(Real t, const Vector2D& velocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ClassType{ m_Extent,m_Center + t * velocity, m_Direction,m_Epsilon };
}

template <typename Real>
bool Mathematics
	::Approximate(const Segment2<Real>& lhs, const Segment2<Real>& rhs, const Real epsilon)
{
	return Vector2DTools<Real>::Approximate(lhs.GetCenterPoint(), rhs.GetCenterPoint(), epsilon) &&
		   Vector2DTools<Real>::Approximate(lhs.GetDirection(), rhs.GetDirection(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetExtent(), rhs.GetExtent(), epsilon);
}

template <typename Real>
std::ostream& Mathematics
	::operator<<(std::ostream& outFile, const Segment2<Real>& segment)
{
	outFile << "origin=" << segment.GetCenterPoint() << ",direction=" << segment.GetDirection()
		    << ",extent=" << segment.GetExtent() << ",beginPoint=" << segment.GetBeginPoint()
		    << ",endPoint=" << segment.GetEndPoint();

	return outFile;
}
#endif // MATHEMATICS_OBJECTS2D_SEGMENT2_DETAIL_H

