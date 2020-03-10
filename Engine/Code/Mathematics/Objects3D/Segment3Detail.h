// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 10:12)

#ifndef MATHEMATICS_OBJECTS3D_SEGMENT3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_SEGMENT3_DETAIL_H

#include "Segment3.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Segment3<Real>
	::Segment3( const Vector3D& beginPoint, const Vector3D& endPoint ,const Real epsilon)
	:m_BeginPoint{ beginPoint }, m_EndPoint{ endPoint }, m_Center{ static_cast<Real>(0.5) * (m_BeginPoint + m_EndPoint) },
	 m_Direction{ m_EndPoint - m_BeginPoint }, m_Extent{ Vector3DTools::VectorMagnitude(m_Direction) / static_cast<Real>(2) }, m_Epsilon{ epsilon }
{
	m_Direction.Normalize(m_Epsilon);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;	
}


template <typename Real>
Mathematics::Segment3<Real>
	::Segment3(Real extent, const Vector3D& center,const Vector3D& direction,const Real epsilon )
	:m_BeginPoint{ center - extent * direction },m_EndPoint{ center + extent * direction },m_Center{ center },
	 m_Direction{ direction },m_Extent{ extent },m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;	
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Segment3<Real>
	::IsValid() const noexcept
{
	if(m_Direction.IsNormalize(m_Epsilon) && 
	   Vector3DTools::Approximate(m_BeginPoint,m_Center - m_Extent * m_Direction,m_Epsilon) && 
	   Vector3DTools::Approximate(m_EndPoint,m_Center + m_Extent * m_Direction, m_Epsilon) &&
	   Vector3DTools::Approximate(m_Center,static_cast<Real>(0.5) * (m_BeginPoint + m_EndPoint),m_Epsilon))
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
typename const Mathematics::Segment3<Real>::Vector3D Mathematics::Segment3<Real>
	::GetBeginPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_BeginPoint;
}

template <typename Real>
typename const Mathematics::Segment3<Real>::Vector3D Mathematics::Segment3<Real>
	::GetEndPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_EndPoint;
}

template <typename Real>
typename const Mathematics::Segment3<Real>::Vector3D Mathematics::Segment3<Real>
	::GetCenterPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
typename const Mathematics::Segment3<Real>::Vector3D Mathematics::Segment3<Real>
	::GetDirection() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Direction;
}


template <typename Real>
Real Mathematics::Segment3<Real>
	::GetExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent;
}

// private
template <typename Real>
void Mathematics::Segment3<Real>
	::ComputeCenterDirectionExtent()
{
	m_Center = static_cast<Real>(0.5) * (m_BeginPoint + m_EndPoint);
	m_Direction = m_EndPoint - m_BeginPoint;
	m_Extent = Vector3DTools::VectorMagnitude(m_Direction) / static_cast<Real>(2);

	m_Direction.Normalize(m_Epsilon);
}

// private
template <typename Real>
void Mathematics::Segment3<Real>
	::ComputeEndPoints()
{
	m_BeginPoint = m_Center - m_Extent * m_Direction;
	m_EndPoint = m_Center + m_Extent * m_Direction;
}


template <typename Real>
const typename Mathematics::Segment3<Real>::ClassType Mathematics::Segment3<Real>
	::GetMove( Real t, const Vector3D& velocity ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ClassType{ m_Extent,m_Center + t * velocity, m_Direction,m_Epsilon };
}

template <typename Real>
bool Mathematics
	::Approximate(const Segment3<Real>& lhs, const Segment3<Real>& rhs, const Real epsilon)
{
	return Vector3DTools<Real>::Approximate(lhs.GetCenterPoint(),rhs.GetCenterPoint(),epsilon) &&
		   Vector3DTools<Real>::Approximate(lhs.GetDirection(),rhs.GetDirection(),epsilon) &&
		   Math<Real>::Approximate(lhs.GetExtent(),rhs.GetExtent(),epsilon);
}

template <typename Real>
std::ostream&  Mathematics
	::operator<<(std::ostream& outFile, const Segment3<Real>& segment)
{
	outFile << "origin=" << segment.GetCenterPoint() << ",direction=" << segment.GetDirection()
		    << ",extent=" << segment.GetExtent() << ",beginPoint=" << segment.GetBeginPoint()
			<< ",endPoint=" << segment.GetEndPoint();

	return outFile;
}
#endif // MATHEMATICS_OBJECTS3D_SEGMENT3_DETAIL_H



