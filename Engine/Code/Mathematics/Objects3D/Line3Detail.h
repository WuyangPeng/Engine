// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 17:42)

#ifndef MATHEMATICS_OBJECTS3D_LINE3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_LINE3_DETAIL_H

#include "Line3.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Line3<Real>::Line3(const Vector3D& origin, const Vector3D& direction, const Real epsilon) noexcept
    : m_Origin{ origin }, m_Direction{ direction }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Line3<Real>
	::IsValid() const noexcept
{
	try
    {
        if (m_Direction.IsNormalize(m_Epsilon))
            return true;
        else
            return false;
	}
	catch (...)
	{
            return false;
	}

}
#endif // OPEN_CLASS_INVARIANT


template <typename Real>
typename const Mathematics::Line3<Real>::Vector3D Mathematics::Line3<Real>::GetOrigin() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Origin;
}

template <typename Real>
typename const Mathematics::Line3<Real>::Vector3D Mathematics::Line3<Real>
	::GetDirection() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Direction;
}

template <typename Real>
const typename Mathematics::Line3<Real>::ClassType Mathematics::Line3<Real>
	::GetMove(Real t, const Vector3D& velocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Line3{ m_Origin + t * velocity, m_Direction, m_Epsilon };
}

template <typename Real>
bool Mathematics
	::Approximate(const Line3<Real>& lhs, const Line3<Real>& rhs, const Real epsilon)
{
	return Vector3DTools<Real>::Approximate(lhs.GetOrigin(), rhs.GetOrigin(), epsilon) &&
		   Vector3DTools<Real>::Approximate(lhs.GetDirection(), rhs.GetDirection(), epsilon);
}

template <typename Real>
std::ostream&  Mathematics
	::operator<<(std::ostream& outFile, const Line3<Real>& line)
{
	outFile << "origin=" << line.GetOrigin() << ",direction=" << line.GetDirection();

	return outFile;
}

#endif // MATHEMATICS_OBJECTS3D_LINE3_DETAIL_H

