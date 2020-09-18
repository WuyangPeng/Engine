// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 15:53)

// 4DœÚ¡ø¿‡µƒ µœ÷
#ifndef MATHEMATICS_ALGEBRA_VECTOR_4D_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_4D_DETAIL_H

#include "Vector4D.h"
#include "Vector3D.h"
#include "Vector2D.h"
#include "Vector4DTools.h"
#include "AlgebraTraits.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics::Vector4D<Real>
	::sm_Zero{ Math::GetValue(0),Math::GetValue(0),Math::GetValue(0),Math::GetValue(0) };

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics::Vector4D<Real>
	::sm_UnitX{ Math::GetValue(1), Math::GetValue(0), Math::GetValue(0), Math::GetValue(0) };

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics::Vector4D<Real>
	::sm_UnitY{ Math::GetValue(0),  Math::GetValue(1), Math::GetValue(0),Math::GetValue(0) };

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics::Vector4D<Real>
	::sm_UnitZ{ Math::GetValue(0),Math::GetValue(0),Math::GetValue(1),Math::GetValue(0) };

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics::Vector4D<Real>
	::sm_UnitW{ Math::GetValue(0),Math::GetValue(0),Math::GetValue(0),Math::GetValue(1) };

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics::Vector4D<Real>
	::sm_One{ Math::GetValue(1),Math::GetValue(1),Math::GetValue(1),Math::GetValue(1) };

template <typename Real>
Mathematics::Vector4D<Real>
	::Vector4D() noexcept
	:m_Tuple{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Vector4D<Real>
	::Vector4D(const Tuple4& tuple)
	:m_Tuple{ tuple }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Vector4D<Real>
	::Vector4D(Real x, Real y, Real z, Real w)
	:m_Tuple{ x,y,z,w }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Vector4D<Real>& Mathematics::Vector4D<Real>
	::operator=(const Tuple4& tuple)
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;

	m_Tuple = tuple;

	return *this;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector4D<Real>
	::Vector4D(const Vector2D<RhsType>& vector)
	:m_Tuple{ boost::numeric_cast<Real>(vector.GetXCoordinate()),boost::numeric_cast<Real>(vector.GetYCoordinate()),{},{} }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector4D<Real>
	::Vector4D(const Vector3D<RhsType>& vector)
	:m_Tuple{ boost::numeric_cast<Real>(vector.GetXCoordinate()),
			  boost::numeric_cast<Real>(vector.GetYCoordinate()),
			  boost::numeric_cast<Real>(vector.GetZCoordinate()),
			  Math::GetValue(0) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector4D<Real>
	::Vector4D(const Vector4D<RhsType>& vector)
	:m_Tuple{ boost::numeric_cast<Real>(vector.GetXCoordinate()),
			  boost::numeric_cast<Real>(vector.GetYCoordinate()),
			  boost::numeric_cast<Real>(vector.GetZCoordinate()),
			  boost::numeric_cast<Real>(vector.GetWCoordinate()) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector4D<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Vector4D<Real>
	::GetXCoordinate() const  
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[0];
}

template <typename Real>
Real Mathematics::Vector4D<Real>
	::GetYCoordinate() const  
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[1];
}

template <typename Real>
Real Mathematics::Vector4D<Real>
	::GetZCoordinate() const  
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[2];
}

template <typename Real>
Real Mathematics::Vector4D<Real>
	::GetWCoordinate() const  
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[3];
}

template <typename Real>
bool Mathematics::Vector4D<Real>
	::IsZero(const Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (Math::FAbs(m_Tuple[0]) <= epsilon && Math::FAbs(m_Tuple[1]) <= epsilon &&
		Math::FAbs(m_Tuple[2]) <= epsilon && Math::FAbs(m_Tuple[3]) <= epsilon)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <typename Real>
void Mathematics::Vector4D<Real>
	::ZeroOut()
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple = Tuple4{};
}

template <typename Real>
void Mathematics::Vector4D<Real>
	::SetCoordinate(Real x, Real y, Real z, Real w)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = x;
	m_Tuple[1] = y;
	m_Tuple[2] = z;
	m_Tuple[3] = w;
}

template <typename Real>
void Mathematics::Vector4D<Real>::SetCoordinate(const ArrayType& coordinate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Tuple[0] = coordinate.at(0);
    m_Tuple[1] = coordinate.at(1);
    m_Tuple[2] = coordinate.at(2);
    m_Tuple[3] = coordinate.at(3);
}

template <typename Real>
typename Mathematics::Vector4D<Real>::ArrayType Mathematics::Vector4D<Real>::GetCoordinate() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

    return ArrayType{ m_Tuple[0], m_Tuple[1], m_Tuple[2], m_Tuple[3] };
}

template <typename Real>
void Mathematics::Vector4D<Real>
	::SetXCoordinate(Real x)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = x;
}

template <typename Real>
void Mathematics::Vector4D<Real>
	::SetYCoordinate(Real y)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[1] = y;
}

template <typename Real>
void Mathematics::Vector4D<Real>
	::SetZCoordinate(Real z)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[2] = z;
}

template <typename Real>
void Mathematics::Vector4D<Real>
	::SetWCoordinate(Real w)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[3] = w;
}

template <typename Real>
void Mathematics::Vector4D<Real>
	::Normalize(const Real epsilon)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	auto length = Vector4DTools::VectorMagnitude(*this);

	if (epsilon < length)
	{
		(*this) /= length;
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "≥˝¡„¥ÌŒÛ£°");

		ZeroOut();
	}
}

template <typename Real>
void Mathematics::Vector4D<Real>
	::ProjectionNormalization(const Real epsilon)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if (epsilon <= Math::FAbs(m_Tuple[3]))
	{
		m_Tuple[0] /= m_Tuple[3];
		m_Tuple[1] /= m_Tuple[3];
		m_Tuple[2] /= m_Tuple[3];
		m_Tuple[3] = Math::GetValue(1);
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "≥˝¡„¥ÌŒÛ£°");

		ZeroOut();
	}
}

template <typename Real>
const Mathematics::Vector4D<Real> Mathematics::Vector4D<Real>
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Vector4D<Real>{-m_Tuple[0], -m_Tuple[1], -m_Tuple[2], -m_Tuple[3]};
}

template <typename Real>
const Real& Mathematics::Vector4D<Real>
	::operator[](unsigned int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(index < 4, "À˜“˝¥ÌŒÛ");

	return m_Tuple[index];
}

template <typename Real>
Real& Mathematics::Vector4D<Real>
	::operator[](unsigned int index)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(index < 4, "À˜“˝¥ÌŒÛ");

	return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Mathematics::Vector4D<Real>& Mathematics::Vector4D<Real>
	::operator+=(const ClassType& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] += rhs.m_Tuple[0];
	m_Tuple[1] += rhs.m_Tuple[1];
	m_Tuple[2] += rhs.m_Tuple[2];
	m_Tuple[3] += rhs.m_Tuple[3];

	return *this;
}

template <typename Real>
Mathematics::Vector4D<Real>& Mathematics::Vector4D<Real>
	::operator-=(const ClassType& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] -= rhs.m_Tuple[0];
	m_Tuple[1] -= rhs.m_Tuple[1];
	m_Tuple[2] -= rhs.m_Tuple[2];
	m_Tuple[3] -= rhs.m_Tuple[3];

	return *this;
}

template <typename Real>
Mathematics::Vector4D<Real>& Mathematics::Vector4D<Real>
	::operator*=(Real rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] *= rhs;
	m_Tuple[1] *= rhs;
	m_Tuple[2] *= rhs;
	m_Tuple[3] *= rhs;

	return *this;
}

template <typename Real>
Mathematics::Vector4D<Real>& Mathematics::Vector4D<Real>
	::operator/=(Real rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if (Math::GetZeroTolerance() < Math::FAbs(rhs))
	{
		m_Tuple[0] /= rhs;
		m_Tuple[1] /= rhs;
		m_Tuple[2] /= rhs;
		m_Tuple[3] /= rhs;
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "≥˝¡„¥ÌŒÛ£°");

		ZeroOut();
	}

	return *this;
}

template <typename Real>
const typename Mathematics::Vector4D<Real>::ClassType Mathematics::Vector4D<Real>
	::GetMove(Real t, const ClassType& velocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return *this + t * velocity;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_4D_DETAIL_H