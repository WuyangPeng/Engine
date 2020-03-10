// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/06 11:32)

#ifndef MATHEMATICS_OBJECTS2D_RAY2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_RAY2_DETAIL_H

#include "Ray2.h"
#include "Mathematics/Base/MathDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Ray2<Real>
	::Ray2( const Vector2D& origin, const Vector2D& direction,const Real epsilon )
	:m_Origin{ origin }, m_Direction{ direction }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ray2<Real>
	::IsValid() const noexcept
{
	if(m_Direction.IsNormalize(m_Epsilon))	
		return true;	
	else	
		return false;	
}
#endif // OPEN_CLASS_INVARIANT


template <typename Real>
typename const Mathematics::Ray2<Real>::Vector2D Mathematics::Ray2<Real>
	::GetOrigin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Origin;
}

template <typename Real>
typename const Mathematics::Ray2<Real>::Vector2D Mathematics::Ray2<Real>
	::GetDirection() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Direction;
}

template <typename Real>
const typename Mathematics::Ray2<Real>::ClassType Mathematics::Ray2<Real>
	::GetMove(Real t, const Vector2D& velocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Ray2{ m_Origin + t * velocity, m_Direction,m_Epsilon };
}

template <typename Real>
bool Mathematics
	::Approximate(const Ray2<Real>& lhs, const Ray2<Real>& rhs, const Real epsilon)
{
	return Vector2DTools<Real>::Approximate(lhs.GetOrigin(),rhs.GetOrigin(),epsilon) &&
		   Vector2DTools<Real>::Approximate(lhs.GetDirection(),rhs.GetDirection(),epsilon);
}

template <typename Real>
std::ostream&  Mathematics
	::operator<<(std::ostream& outFile, const Ray2<Real>& ray)
{
	outFile << "origin=" << ray.GetOrigin() << ",direction=" << ray.GetDirection();

	return outFile;
}
#endif // MATHEMATICS_OBJECTS2D_RAY2_DETAIL_H