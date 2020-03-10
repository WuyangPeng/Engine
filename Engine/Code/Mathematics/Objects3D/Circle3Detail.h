// Copyright (c) 2011-2019
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.0.2 (2019/07/08 09:30)

#ifndef MATHEMATICS_OBJECTS3D_CIRCLE3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_CIRCLE3_DETAIL_H

#include "Circle3.h"
#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/Vector3DTools.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Circle3<Real>
	::Circle3( const Vector3D& center, const Vector3D& direction0,const Vector3D& direction1, const Vector3D& normal,const Real radius , const Real epsilon)
	:m_Center{ center }, m_Direction0{ direction0 }, m_Direction1{ direction1 }, m_Normal{ normal }, m_Radius{ radius }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Circle3<Real>
	::IsValid() const noexcept
{
	if(Vector3DTools::Approximate(Vector3DTools::CrossProduct(m_Direction0,m_Direction1),m_Normal, m_Epsilon) &&
	   Vector3DTools::Approximate(Vector3DTools::CrossProduct(m_Direction1,m_Normal),m_Direction0, m_Epsilon) &&
	   Vector3DTools::Approximate(Vector3DTools::CrossProduct(m_Normal,m_Direction0),m_Direction1, m_Epsilon))
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
typename const Mathematics::Circle3<Real>::Vector3D Mathematics::Circle3<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}


template <typename Real>
typename const Mathematics::Circle3<Real>::Vector3D Mathematics::Circle3<Real>
	::GetDirection0() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Direction0;
}

template <typename Real>
typename const Mathematics::Circle3<Real>::Vector3D Mathematics::Circle3<Real>
	::GetDirection1() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Direction1;
}

template <typename Real>
typename const Mathematics::Circle3<Real>::Vector3D Mathematics::Circle3<Real>
	::GetNormal() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Normal;
}

template <typename Real>
Real Mathematics::Circle3<Real>
	::GetRadius() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Radius;
}

template <typename Real>
const Mathematics::Circle3<Real> Mathematics::Circle3<Real>
	::GetMove(Real t, const Vector3D& velocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ClassType{ m_Center * t + velocity, m_Direction0, m_Direction1, m_Normal,m_Radius, m_Epsilon };
}

template <typename Real>
bool Mathematics
	::Approximate(const Circle3<Real>& lhs, const Circle3<Real>& rhs, const Real epsilon)
{
	return Vector3DTools<Real>::Approximate(lhs.GetCenter(),rhs.GetCenter(),epsilon) &&
		   Vector3DTools<Real>::Approximate(lhs.GetDirection0(),rhs.GetDirection0(),epsilon) &&
		   Vector3DTools<Real>::Approximate(lhs.GetDirection1(), rhs.GetDirection1(), epsilon) &&
		   Vector3DTools<Real>::Approximate(lhs.GetNormal(), rhs.GetNormal(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetRadius(), rhs.GetRadius(), epsilon);
}

template <typename Real>
std::ostream& Mathematics
	::operator<<(std::ostream& outFile, const Circle3<Real>& circle)
{
	outFile << "center=" << circle.GetCenter() << ",direction0=" << circle.GetDirection0()
		    << ",direction1=" << circle.GetDirection1() << ",normal=" << circle.GetNormal() 
			<< "radius=" << circle.GetRadius();

	return outFile;
}
#endif // MATHEMATICS_OBJECTS3D_CIRCLE3_DETAIL_H
