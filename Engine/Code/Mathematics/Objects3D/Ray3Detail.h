// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 10:09)

#ifndef MATHEMATICS_OBJECTS3D_RAY3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_RAY3_DETAIL_H

#include "Ray3.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Ray3<Real>
	::Ray3( const Vector3D& origin, const Vector3D& direction,const Real epsilon )
	:m_Origin{ origin }, m_Direction{ direction }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ray3<Real>
	::IsValid() const noexcept
{
	if(m_Direction.IsNormalize(m_Epsilon))
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT


template <typename Real>
typename const Mathematics::Ray3<Real>::Vector3D Mathematics::Ray3<Real>
	::GetOrigin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Origin;
}

template <typename Real>
typename const Mathematics::Ray3<Real>::Vector3D Mathematics::Ray3<Real>
	::GetDirection() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Direction;
}


template <typename Real>
const typename Mathematics::Ray3<Real>::ClassType Mathematics::Ray3<Real>
	::GetMove(Real t, const Vector3D& velocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Ray3{ m_Origin + t * velocity, m_Direction, m_Epsilon };
}

template <typename Real>
bool Mathematics
	::Approximate(const Ray3<Real>& lhs, const Ray3<Real>& rhs, const Real epsilon)
{
	return Vector3DTools<Real>::Approximate(lhs.GetOrigin(),rhs.GetOrigin(),epsilon) &&
		   Vector3DTools<Real>::Approximate(lhs.GetDirection(),rhs.GetDirection(),epsilon);
}

template <typename Real>
std::ostream&  Mathematics
	::operator<<(std::ostream& outFile, const Ray3<Real>& ray)
{
	outFile << "origin=" << ray.GetOrigin() << ",direction=" << ray.GetDirection();

	return outFile;
}
#endif // MATHEMATICS_OBJECTS3D_RAY3_DETAIL_H