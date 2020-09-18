// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 15:44)

// 2D向量类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_2D_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_2D_DETAIL_H

#include "Vector2D.h"
#include "Vector3D.h"
#include "Vector4D.h"
#include "Vector2DTools.h"
#include "AlgebraTraits.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2D<Real>
	::sm_Zero{ Math::GetValue(0),Math::GetValue(0) };

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2D<Real>
	::sm_UnitX{ Math::GetValue(1),Math::GetValue(0) };

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2D<Real>
	::sm_UnitY{ Math::GetValue(0),Math::GetValue(1) };

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2D<Real>
	::sm_One{ Math::GetValue(1),Math::GetValue(1) };

template <typename Real>
Mathematics::Vector2D<Real>
	::Vector2D() noexcept
	:m_Tuple{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Vector2D<Real>
	::Vector2D(const Tuple2& tuple)
	:m_Tuple{ tuple }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Vector2D<Real>
	::Vector2D(Real x, Real y) noexcept
	:m_Tuple{ x,y }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Vector2D<Real>& Mathematics::Vector2D<Real>
	::operator=(const Tuple2& tuple)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple = tuple;

	return *this;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector2D<Real>
	::Vector2D(const Vector2D<RhsType>& vector)
	:m_Tuple{ boost::numeric_cast<Real>(vector.GetXCoordinate()),boost::numeric_cast<Real>(vector.GetYCoordinate()) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector2D<Real>
	::Vector2D(const Vector3D<RhsType>& vector)
	:m_Tuple{ boost::numeric_cast<Real>(vector.GetXCoordinate()),boost::numeric_cast<Real>(vector.GetYCoordinate()) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector2D<Real>
	::Vector2D(const Vector4D<RhsType>& vector)
	:m_Tuple{ boost::numeric_cast<Real>(vector.GetXCoordinate()),boost::numeric_cast<Real>(vector.GetYCoordinate()) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector2D<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Vector2D<Real>
	::GetXCoordinate() const  
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[0];
}

template <typename Real>
Real Mathematics::Vector2D<Real>
	::GetYCoordinate() const  
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[1];
}

template <typename Real>
bool Mathematics::Vector2D<Real>
	::IsZero(const Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (Math::FAbs(m_Tuple[0]) <= epsilon && Math::FAbs(m_Tuple[1]) <= epsilon)
		return true;
	else
		return false;
}

template <typename Real>
void Mathematics::Vector2D<Real>
	::ZeroOut() noexcept
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple = Tuple2{};
}

template <typename Real>
void Mathematics::Vector2D<Real>
	::SetCoordinate(Real x, Real y)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = x;
	m_Tuple[1] = y;
}

template <typename Real>
void Mathematics::Vector2D<Real>::SetCoordinate(const ArrayType& coordinate)
{
    MATHEMATICS_CLASS_IS_VALID_9;

    m_Tuple[0] = coordinate.at(0);
    m_Tuple[1] = coordinate.at(1);
}

template <typename Real>
typename Mathematics::Vector2D<Real>::ArrayType Mathematics::Vector2D<Real>::GetCoordinate() const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return ArrayType{ m_Tuple[0], m_Tuple[1] };
}

template <typename Real>
void Mathematics::Vector2D<Real>
	::SetXCoordinate(Real x)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = x;
}

template <typename Real>
void Mathematics::Vector2D<Real>
	::SetYCoordinate(Real y)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[1] = y;
}

template <typename Real>
void Mathematics::Vector2D<Real>
	::Normalize(const Real epsilon)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	auto length = Vector2DTools::VectorMagnitude(*this);

	if (epsilon < length)
	{
		(*this) /= length;
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "除零错误！");

		ZeroOut();
	}
}

template <typename Real>
bool Mathematics::Vector2D<Real>
	::IsNormalize(const Real epsilon) const  
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto length = Vector2DTools::VectorMagnitude(*this);

	if (Math::FAbs(length - Math::GetValue(1)) <= epsilon)
		return true;
	else
		return false;
}

template <typename Real>
const Mathematics::Vector2D<Real> Mathematics::Vector2D<Real>
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return ClassType(-m_Tuple[0], -m_Tuple[1]);
}

template <typename Real>
const Real& Mathematics::Vector2D<Real>
	::operator[](unsigned int index) const
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(index < 2, "索引错误");

	return m_Tuple[index];
}

template <typename Real>
Real& Mathematics::Vector2D<Real>
	::operator[](unsigned int index)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(index < 2, "索引错误");

	return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Mathematics::Vector2D<Real>& Mathematics::Vector2D<Real>
	::operator+=(const ClassType& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] += rhs.m_Tuple[0];
	m_Tuple[1] += rhs.m_Tuple[1];

	return *this;
}

template <typename Real>
Mathematics::Vector2D<Real>& Mathematics::Vector2D<Real>
	::operator-=(const ClassType& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] -= rhs.m_Tuple[0];
	m_Tuple[1] -= rhs.m_Tuple[1];

	return *this;
}

template <typename Real>
Mathematics::Vector2D<Real>& Mathematics::Vector2D<Real>
	::operator*=(Real rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] *= rhs;
	m_Tuple[1] *= rhs;

	return *this;
}

template <typename Real>
Mathematics::Vector2D<Real>& Mathematics::Vector2D<Real>
	::operator/=(Real rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if (Math::GetZeroTolerance() < Math::FAbs(rhs))
	{
		m_Tuple[0] /= rhs;
		m_Tuple[1] /= rhs;
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "除零错误！");

		ZeroOut();
	}

	return *this;
}

template <typename Real>
typename const Mathematics::Vector2D<Real>::BarycentricCoordinates
Mathematics::Vector2D<Real>
	::GetBarycentrics(const ClassType& firstVector, const ClassType& secondVector, const ClassType& thirdVector, const Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_9;

	// 计算相对于该三角形thirdVector的向量。
	ClassType difference[3]{ firstVector - thirdVector,secondVector - thirdVector,*this - thirdVector };

	auto det = Vector2DTools::DotPerp(difference[0], difference[1]);

	if (epsilon < Math::FAbs(det))
	{
		Tuple3 bary{ Vector2DTools::DotPerp(difference[2], difference[1]) / det, Vector2DTools::DotPerp(difference[0], difference[2]) / det, Math::GetValue(0) };

		bary[2] = Math::GetValue(1) - bary[0] - bary[1];

		return BarycentricCoordinates{ true,bary };
	}
	else
	{
	#ifdef MATHEMATICS_ASSERT_ON_BARYCENTRIC2_DEGENERATE
		MATHEMATICS_ASSERTION_1(false, "输入的是退化三角形。\n");
	#endif // MATHEMATICS_ASSERT_ON_BARYCENTRIC2_DEGENERATE

		return BarycentricCoordinates{};
	}
}

template <typename Real>
const typename Mathematics::Vector2D<Real>::ClassType Mathematics::Vector2D<Real>
	::GetMove(Real t, const ClassType& velocity) const
{
	MATHEMATICS_CLASS_IS_VALID_9;

	return *this + t * velocity;
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_ALGEBRA_VECTOR_2D_DETAIL_H
