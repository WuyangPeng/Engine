// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/24 16:59)

#ifndef MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_DETAIL_H
#define MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_DETAIL_H

#include "IntersectorLine3Triangle3Data.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::IntersectorLine3Triangle3Data<Real>
	::IntersectorLine3Triangle3Data(const Line3& line, const Triangle3& triangle)
	:m_Line{ line }, m_Triangle{ triangle }, m_Origin{}, m_Edge1{}, m_Edge2{}, m_Normal{}, m_DirectionDotNormal{}
{
	CalculateDirectionDotNormal();

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
} 

template <typename Real>
void Mathematics::IntersectorLine3Triangle3Data<Real>
	::CalculateDirectionDotNormal()
{
	// 计算原点、边和法线的偏移量。
	m_Origin = m_Line.GetOrigin() - m_Triangle.GetVertex(0);
	m_Edge1 = m_Triangle.GetVertex(1) - m_Triangle.GetVertex(0);
	m_Edge2 = m_Triangle.GetVertex(2) - m_Triangle.GetVertex(0);
	m_Normal = Vector3DTools::CrossProduct(m_Edge1, m_Edge2);

	// 求解 Q + t * D = b1 * E1 + b2 * E2 
	// (其中Q = m_OriginDifference, D = 线的Direction,
	// E1 = m_Edge1, E2 = m_Edge2, N = Cross(E1,E2)) 对
	//   |Dot(D,N)| * b1 = sign(Dot(D,N)) * Dot(D,Cross(Q,E2))
	//   |Dot(D,N)| * b2 = sign(Dot(D,N)) * Dot(D,Cross(E1,Q))
	//   |Dot(D,N)| * t = -sign(Dot(D,N)) * Dot(Q,N)
	m_DirectionDotNormal = Vector3DTools::DotProduct(m_Line.GetDirection(), m_Normal);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::IntersectorLine3Triangle3Data<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename Real>
const Mathematics::Line3<Real> Mathematics::IntersectorLine3Triangle3Data<Real>
	::GetLine() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Line;
}

template <typename Real>
const Mathematics::Triangle3<Real> Mathematics::IntersectorLine3Triangle3Data<Real>
	::GetTriangle() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Triangle;
}

template <typename Real>
Real Mathematics::IntersectorLine3Triangle3Data<Real>::GetDirectionDotNormal() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_DirectionDotNormal;
}

template <typename Real>
Mathematics::Vector3D<Real> Mathematics::IntersectorLine3Triangle3Data<Real>
	::GetOriginCrossEdge2() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Vector3DTools::CrossProduct(m_Origin, m_Edge2);
}

template <typename Real>
Mathematics::Vector3D<Real> Mathematics::IntersectorLine3Triangle3Data<Real>::GetEdge1CrossOrigin() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Vector3DTools::CrossProduct(m_Edge1, m_Origin);
}

template <typename Real>
Real Mathematics::IntersectorLine3Triangle3Data<Real>::GetOriginDotNormal() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Vector3DTools::DotProduct(m_Origin, m_Normal);
}

#endif // MATHEMATICS_INTERSECTION_INTERSECTOR_LINE3_TRIANGLE3_DATA_DETAIL_H