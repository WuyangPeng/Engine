// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 17:41)

#ifndef MATHEMATICS_OBJECTS3D_FRUSTUM3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_FRUSTUM3_DETAIL_H

#include "Frustum3.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Frustum3<Real>
	::Frustum3(const Vector3D& origin, const Vector3D& directionVector, const Vector3D& upVector, const Vector3D& rightVector, Real directionMin,
			   Real directionMax, Real upBound, Real rightBound, const Real epsilon)
	:m_Origin{ origin }, m_DirectionVector{ directionVector }, m_UpVector{ upVector }, m_RightVector{ rightVector },
	 m_DirectionMin{ directionMin }, m_DirectionMax{ directionMax }, m_UpBound{ upBound }, m_RightBound{ rightBound },
	 m_DirectionRatio{ directionMax / directionMin }, m_MTwoUF{ static_cast<Real>(-2) * upBound * directionMax }, m_MTwoRF{ static_cast<Real>(-2) * rightBound * directionMax }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Frustum3<Real>
	::IsValid() const noexcept
{
	if (m_DirectionVector.IsNormalize(m_Epsilon) && m_UpVector.IsNormalize(m_Epsilon) && m_RightVector.IsNormalize(m_Epsilon) &&
		Math::sm_Zero < m_DirectionMin && m_DirectionMin < m_DirectionMax && Math::sm_Zero < m_RightBound && Math::sm_Zero < m_UpBound)
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
typename const Mathematics::Frustum3<Real>::Vector3D Mathematics::Frustum3<Real>
	::GetOrigin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Origin;
}

template <typename Real>
typename const Mathematics::Frustum3<Real>::Vector3D Mathematics::Frustum3<Real>
	::GetDirectionVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_DirectionVector;
}

template <typename Real>
typename const Mathematics::Frustum3<Real>::Vector3D  Mathematics::Frustum3<Real>
	::GetUpVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_UpVector;
}

template <typename Real>
typename const Mathematics::Frustum3<Real>::Vector3D  Mathematics::Frustum3<Real>
	::GetRightVector() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RightVector;
}

template <typename Real>
Real Mathematics::Frustum3<Real>
	::GetDirectionMin() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_DirectionMin;
}

template <typename Real>
Real Mathematics::Frustum3<Real>
	::GetDirectionMax() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_DirectionMax;
}

template <typename Real>
Real Mathematics::Frustum3<Real>
	::GetUpBound() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_UpBound;
}

template <typename Real>
Real Mathematics::Frustum3<Real>
	::GetRightBound() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_RightBound;
}

template <typename Real>
Real Mathematics::Frustum3<Real>
	::GetDirectionRatio() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_DirectionRatio;
}

template <typename Real>
Real Mathematics::Frustum3<Real>
	::GetMTwoUF() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MTwoUF;
}

template <typename Real>
Real Mathematics::Frustum3<Real>
	::GetMTwoRF() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_MTwoRF;
}

template <typename Real>
const std::vector<typename Mathematics::Frustum3<Real>::Vector3D> Mathematics::Frustum3<Real>
	::ComputeVertices() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto directionScaled = m_DirectionMin * m_DirectionVector;
	auto upScaled = m_UpBound * m_UpVector;
	auto rightScaled = m_RightBound * m_RightVector;

	std::vector<Vector3D> vertex(8);

	vertex[0] = directionScaled - upScaled - rightScaled;
	vertex[1] = directionScaled - upScaled + rightScaled;
	vertex[2] = directionScaled + upScaled + rightScaled;
	vertex[3] = directionScaled + upScaled - rightScaled;

	for (auto i = 0; i < 4; ++i)
	{
		auto temp1 = m_DirectionRatio * vertex[i];
		auto temp2 = m_Origin + temp1;
		auto temp = i + 4;
		vertex[temp] = temp2;
		vertex[i] += m_Origin;
	}

	return vertex;
}

// private
template <typename Real>
void Mathematics::Frustum3<Real>
	::Update()
{
	m_DirectionRatio = m_DirectionMax / m_DirectionMin;
	m_MTwoUF = static_cast<Real>(-2) * m_UpBound * m_DirectionMax;
	m_MTwoRF = static_cast<Real>(-2) * m_RightBound * m_DirectionMax;
}

#endif // MATHEMATICS_OBJECTS3D_FRUSTUM3_DETAIL_H

