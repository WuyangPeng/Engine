// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 17:38)

#ifndef MATHEMATICS_OBJECTS3D_ELLIPSE3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_ELLIPSE3_DETAIL_H

#include "Ellipse3.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Ellipse3<Real>
	::Ellipse3(const Vector3D& center, const Vector3D& normal, const Vector3D& major, const Vector3D& minor,
			   Real majorLength, Real minorLength, const Real epsilon)
	:m_Center{ center }, m_Normal{ normal }, m_Major{ major }, m_Minor{ minor },
	 m_MajorLength{ majorLength }, m_MinorLength{ minorLength }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Ellipse3<Real>
	::IsValid() const noexcept
{
	if (m_Normal.IsNormalize(m_Epsilon) && m_Major.IsNormalize(m_Epsilon) && m_Minor.IsNormalize(m_Epsilon) &&
		Math::sm_Zero <= m_MajorLength && Math::sm_Zero <= m_MinorLength)
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
typename const Mathematics::Ellipse3<Real>::Vector3D Mathematics::Ellipse3<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
typename const Mathematics::Ellipse3<Real>::Vector3D Mathematics::Ellipse3<Real>
	::GetNormal() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Normal;
}

template <typename Real>
typename const Mathematics::Ellipse3<Real>::Vector3D Mathematics::Ellipse3<Real>
	::GetMajor() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Major;
}

template <typename Real>
typename const Mathematics::Ellipse3<Real>::Vector3D Mathematics::Ellipse3<Real>
	::GetMinor() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Minor;
}

template <typename Real>
Real Mathematics::Ellipse3<Real>
	::GetMajorLength() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MajorLength;
}

template <typename Real>
Real Mathematics::Ellipse3<Real>
	::GetMinorLength() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MinorLength;
}

#endif // MATHEMATICS_OBJECTS3D_ELLIPSE3_DETAIL_H