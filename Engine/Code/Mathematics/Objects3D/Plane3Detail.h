// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 10:04)

#ifndef MATHEMATICS_OBJECTS3D_PLANE3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_PLANE3_DETAIL_H

#include "Plane3.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Plane3<Real>
	::Plane3( const Vector3D& normal, Real constant ,const Real epsilon)
	:m_Normal{ normal }, m_Constant{ constant }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Plane3<Real>
	::Plane3()
	:m_Normal{ Vector3D::sm_UnitX }, m_Constant{}, m_Epsilon{ Math::sm_ZeroTolerance }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}


template <typename Real>
Mathematics::Plane3<Real>
	::Plane3( const Vector3D& normal, const Vector3D& point ,const Real epsilon)
	:m_Normal{ normal },m_Constant{ Vector3DTools::DotProduct(normal,point) },m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}


template <typename Real>
Mathematics::Plane3<Real>
	::Plane3(const Triangle3& triangle,const Real epsilon)
	:m_Normal{}, m_Constant{}, m_Epsilon{ epsilon }
{
	auto edge1 = triangle.GetVertex(1) - triangle.GetVertex(0);
	auto edge2 = triangle.GetVertex(2) - triangle.GetVertex(0);
	m_Normal = Vector3DTools::UnitCrossProduct(edge1,edge2);
	m_Constant = Vector3DTools::DotProduct(m_Normal, triangle.GetVertex(0));

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Plane3<Real>
	::Plane3( const Vector3D& firstPoint, const Vector3D& secondPoint,const Vector3D& thirdPoint,const Real epsilon )
	:m_Normal{}, m_Constant{}, m_Epsilon{ epsilon }
{
	auto edge1 = secondPoint - firstPoint;
	auto edge2 = thirdPoint - firstPoint;
	m_Normal = Vector3DTools::UnitCrossProduct(edge1,edge2);
	m_Constant = Vector3DTools::DotProduct(m_Normal,firstPoint);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Plane3<Real>
	::IsValid() const noexcept
{
	if(m_Normal.IsNormalize(m_Epsilon))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
typename const Mathematics::Plane3<Real>::Vector3D Mathematics::Plane3<Real>
	::GetNormal() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Normal;
}

template <typename Real>
Real Mathematics::Plane3<Real>
	::GetConstant() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Constant;
}


template <typename Real>
Real Mathematics::Plane3<Real>
	::DistanceTo( const Vector3D& point ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	
	return Vector3DTools::DotProduct(m_Normal,point) - m_Constant;
}

template <typename Real>
Mathematics::NumericalValueSymbol Mathematics::Plane3<Real>
	::WhichSide( const Vector3D& point ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto distance = DistanceTo(point);

	if (distance < -m_Epsilon)
	{
		return NumericalValueSymbol::Negative;
	}
	else if (m_Epsilon < distance)
	{
		return NumericalValueSymbol::Positive;
	}
	else
	{
		return NumericalValueSymbol::Zero;
	}
}

#endif // MATHEMATICS_OBJECTS3D_PLANE3_DETAIL_H

