// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 10:16)

#ifndef MATHEMATICS_OBJECTS3D_TORUS3_DETAIL_H
#define MATHEMATICS_OBJECTS3D_TORUS3_DETAIL_H

#include "Torus3.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_TORUS3_DETAIL)

#include "Torus3ParametersDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename Real>
Mathematics::Torus3<Real>
	::Torus3( Real outerRadius, Real innerRadius )
	:m_OuterRadius{ outerRadius }, m_InnerRadius{ innerRadius }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Torus3<Real>
	::IsValid() const noexcept
{
	if(Real{} < m_InnerRadius && m_InnerRadius < m_OuterRadius)
	    return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Torus3<Real>
	::GetOuterRadius() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_OuterRadius;
}

template <typename Real>
Real Mathematics::Torus3<Real>
	::GetInnerRadius() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_InnerRadius;
}


template <typename Real>
typename const Mathematics::Torus3<Real>::Vector3D Mathematics::Torus3<Real>
	::GetPosition( Real s, Real t ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(Real{} <= s && s <= static_cast<Real>(1) && Real {} <= t && t <= static_cast<Real>(1), "s和t必须在0和1之间");

	auto twoPiS = Math::sm_TwoPI * s;
	auto twoPiT = Math::sm_TwoPI * t;
	auto cosTwoPiS = Math::Cos(twoPiS);
	auto sinTwoPiS = Math::Sin(twoPiS);
	auto cosTwoPiT = Math::Cos(twoPiT);
	auto sinTwoPiT = Math::Sin(twoPiT);
	auto maxRadius = m_OuterRadius + m_InnerRadius * cosTwoPiT;

	return Vector3D{ maxRadius * cosTwoPiS,maxRadius * sinTwoPiS,m_InnerRadius * sinTwoPiT };

}

template <typename Real>
typename const Mathematics::Torus3<Real>::Vector3D Mathematics::Torus3<Real>
	::GetNormal( Real s, Real t ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(Real{} <= s && s <= static_cast<Real>(1) && Real {} <= t && t <= static_cast<Real>(1), "s和t必须在0和1之间");

	auto twoPiS = Math::sm_TwoPI * s;
	auto cosTwoPiS = Math::Cos(twoPiS);
	auto sinTwoPiS = Math::Sin(twoPiS);
	auto position = GetPosition(s, t);

	Vector3D normal{ position.GetXCoordinate() - m_OuterRadius * cosTwoPiS,
					 position.GetYCoordinate() - m_OuterRadius * sinTwoPiS,
					 position.GetZCoordinate() };
	normal.Normalize();

	return normal;
}


template <typename Real>
typename const Mathematics::Torus3<Real>::Torus3Parameters Mathematics::Torus3<Real>
	::GetParameters( const Vector3D& position ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto radius = Math::Sqrt(position.GetXCoordinate() * position.GetXCoordinate() + position.GetYCoordinate() * position.GetYCoordinate());

	Real s { };

	if (Math::sm_ZeroTolerance < radius)
	{
		auto angle = Math::ATan2(position.GetYCoordinate(),  position.GetXCoordinate());
		if (Real{} <= angle)
		{
			s = angle * Math::sm_InverseTwoPI;
		}
		else
		{
			s = static_cast<Real>(1) + angle * Math::sm_InverseTwoPI;
		}
	}

	auto diff = radius - m_OuterRadius;

	Real t { };

	if (Math::FAbs(diff) < Math::sm_ZeroTolerance &&  Math::FAbs(position.GetZCoordinate()) < Math::sm_ZeroTolerance)
	{
		t = Real{ };
	}
	else
	{
		auto angle = Math::ATan2(position.GetZCoordinate(), diff);
		if (Real{} <= angle)
		{
			t = angle * Math::sm_InverseTwoPI;			
		}
		else
		{
			t = static_cast<Real>(1) + angle * Math::sm_InverseTwoPI;			
		}
	}

	return Torus3Parameters(s,t);
}

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_TORUS3_DETAIL)

#endif // MATHEMATICS_OBJECTS3D_TORUS3_DETAIL_H

