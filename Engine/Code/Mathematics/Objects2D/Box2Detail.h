// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 16:50)

#ifndef MATHEMATICS_OBJECTS2D_BOX2_DETAIL_H
#define MATHEMATICS_OBJECTS2D_BOX2_DETAIL_H

#include "Box2.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <iostream>

template <typename Real>
Mathematics::Box2<Real>
	::Box2(const Vector2D& center, const Vector2D& firstAxis, const Vector2D& secondAxis, const Real firstExtent, const Real secondExtent, const Real epsilon)
	:m_Center{ center }, m_Epsilon{ epsilon }
{
	m_Axis[0] = firstAxis;
	m_Axis[1] = secondAxis;
	m_Extent[0] = firstExtent;
	m_Extent[1] = secondExtent;

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename Real>
Mathematics::Box2<Real>
	::Box2()
	:m_Center{}, m_Epsilon{}
{
	m_Extent[0] = Math::GetValue(0);
	m_Extent[1] = Math::GetValue(0);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Box2<Real>
	::IsValid() const noexcept
{
	if (m_Axis[0].IsNormalize(m_Epsilon) && m_Axis[1].IsNormalize(m_Epsilon) &&
		-m_Epsilon <= m_Extent[0] && -m_Epsilon <= m_Extent[1])
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
const std::vector<typename Mathematics::Box2<Real>::Vector2D> Mathematics::Box2<Real>
	::ComputeVertices() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto extAxis0 = m_Axis[0] * m_Extent[0];
	auto extAxis1 = m_Axis[1] * m_Extent[1];

	std::vector<Vector2D> vertex{ m_Center - extAxis0 - extAxis1 ,m_Center + extAxis0 - extAxis1,
								  m_Center + extAxis0 + extAxis1 ,m_Center - extAxis0 + extAxis1 };

	return vertex;
}

template <typename Real>
const typename Mathematics::Box2<Real>::Vector2D Mathematics::Box2<Real>
	::GetCenter() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Center;
}

template <typename Real>
const typename Mathematics::Box2<Real>::Vector2D Mathematics::Box2<Real>
	::GetFirstAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis[0];
}

template <typename Real>
const typename Mathematics::Box2<Real>::Vector2D Mathematics::Box2<Real>
	::GetSecondAxis() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Axis[1];
}

template <typename Real>
Real Mathematics::Box2<Real>
	::GetFirstExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent[0];
}

template <typename Real>
Real Mathematics::Box2<Real>
	::GetSecondExtent() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Extent[1];
}

template <typename Real>
Real Mathematics::Box2<Real>
	::GetEpsilon() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Epsilon;
}

template <typename Real>
const Mathematics::Box2<Real> Mathematics::Box2<Real>
	::GetMove(Real t, const Vector2D& velocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return ClassType{ m_Center * t + velocity, m_Axis[0], m_Axis[1], m_Extent[0], m_Extent[1], m_Epsilon };
}

template <typename Real>
bool Mathematics
	::Approximate(const Box2<Real>& lhs, const Box2<Real>& rhs, const Real epsilon)
{
	return Vector2DTools<Real>::Approximate(lhs.GetCenter(), rhs.GetCenter(), epsilon) &&
		   Vector2DTools<Real>::Approximate(lhs.GetFirstAxis(), rhs.GetFirstAxis(), epsilon) &&
		   Vector2DTools<Real>::Approximate(lhs.GetSecondAxis(), rhs.GetSecondAxis(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetFirstExtent(), rhs.GetFirstExtent(), epsilon) &&
		   Math<Real>::Approximate(lhs.GetSecondExtent(), rhs.GetSecondExtent(), epsilon);
}

template <typename Real>
std::ostream& Mathematics
	::operator<<(std::ostream& outFile, const Box2<Real>& box)
{
	outFile << "center=" << box.GetCenter() << ",axis0=" << box.GetFirstAxis()
		    << ",axis1=" << box.GetSecondAxis() << "extent0=" << box.GetFirstExtent()
		    << "extent1=" << box.GetSecondExtent();

	return outFile;
}

#endif // MATHEMATICS_OBJECTS2D_BOX2_DETAIL_H

