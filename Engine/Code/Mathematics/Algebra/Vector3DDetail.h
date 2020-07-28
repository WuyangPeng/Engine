// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 15:49)

// 3D向量类的实现
#ifndef MATHEMATICS_ALGEBRA_VECTOR_3D_DETAIL_H
#define MATHEMATICS_ALGEBRA_VECTOR_3D_DETAIL_H

#include "Vector3D.h"
#include "Vector2D.h"
#include "Vector4D.h"
#include "Vector3DTools.h"
#include "AlgebraTraits.h"
#include "BarycentricCoordinatesDetail.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"

#include "System/Helper/PragmaWarning.h"
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3D<Real>
	::sm_Zero{ Math::sm_Zero,Math::sm_Zero,Math::sm_Zero };

#include STSTEM_WARNING_POP

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3D<Real>
	::sm_UnitX{ Math::sm_One, Math::sm_Zero, Math::sm_Zero };

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3D<Real>
	::sm_UnitY{ Math::sm_Zero,Math::sm_One,Math::sm_Zero };

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3D<Real>
	::sm_UnitZ{ Math::sm_Zero,Math::sm_Zero,Math::sm_One };

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3D<Real>
	::sm_One{ Math::sm_One,Math::sm_One,Math::sm_One };

template <typename Real>
Mathematics::Vector3D<Real>
	::Vector3D() noexcept
	:m_Tuple{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Vector3D<Real>
	::Vector3D(const Tuple3& tuple)
	:m_Tuple{ tuple }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Vector3D<Real>
	::Vector3D(Real x, Real y, Real z)
	:m_Tuple{ x,y,z }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
Mathematics::Vector3D<Real>& Mathematics::Vector3D<Real>
	::operator=(const Tuple3& tuple)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple = tuple;

	return *this;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector3D<Real>
	::Vector3D(const Vector2D<RhsType>& vector)
	:m_Tuple{ boost::numeric_cast<Real>(vector.GetXCoordinate()), boost::numeric_cast<Real>(vector.GetYCoordinate()),Math::sm_Zero }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector3D<Real>
	::Vector3D(const Vector3D<RhsType>& vector)
	:m_Tuple{ boost::numeric_cast<Real>(vector.GetXCoordinate()),boost::numeric_cast<Real>(vector.GetYCoordinate()), boost::numeric_cast<Real>(vector.GetZCoordinate()) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename Real>
template <typename RhsType>
Mathematics::Vector3D<Real>
	::Vector3D(const Vector4D<RhsType>& vector)
	:m_Tuple{ boost::numeric_cast<Real>(vector.GetXCoordinate()),boost::numeric_cast<Real>(vector.GetYCoordinate()),boost::numeric_cast<Real>(vector.GetZCoordinate()) }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::Vector3D<Real>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
Real Mathematics::Vector3D<Real>
	::GetXCoordinate() const  
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[0];
}

template <typename Real>
Real Mathematics::Vector3D<Real>
	::GetYCoordinate() const  
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[1];
}

template <typename Real>
Real Mathematics::Vector3D<Real>
	::GetZCoordinate() const  
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[2];
}

template <typename Real>
bool Mathematics::Vector3D<Real>
	::IsZero(const Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (Math::FAbs(m_Tuple[0]) <= epsilon && Math::FAbs(m_Tuple[1]) <= epsilon && Math::FAbs(m_Tuple[2]) <= epsilon)
		return true;
	else
		return false;
}

template <typename Real>
void Mathematics::Vector3D<Real>
	::ZeroOut()
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple = Tuple3{};
}

template <typename Real>
void Mathematics::Vector3D<Real>
	::SetCoordinate(Real x, Real y, Real z)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = x;
	m_Tuple[1] = y;
	m_Tuple[2] = z;
}

template <typename Real>
void Mathematics::Vector3D<Real>
	::SetXCoordinate(Real x)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = x;
}

template <typename Real>
void Mathematics::Vector3D<Real>
	::SetYCoordinate(Real y)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[1] = y;
}

template <typename Real>
void Mathematics::Vector3D<Real>
	::SetZCoordinate(Real z)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[2] = z;
}

template <typename Real>
void Mathematics::Vector3D<Real>
	::Normalize(const Real epsilon)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	auto length = Vector3DTools::VectorMagnitude(*this);

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
bool Mathematics::Vector3D<Real>
	::IsNormalize(const Real epsilon) const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	auto length = Vector3DTools::VectorMagnitude(*this);

	if (Math::FAbs(length - Math::sm_One) <= epsilon)
		return true;
	else
		return false;
}

template <typename Real>
const Mathematics::Vector3D<Real> Mathematics::Vector3D<Real>
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return Vector3D<Real>{ -m_Tuple[0], -m_Tuple[1], -m_Tuple[2] };
}

template <typename Real>
const Real& Mathematics::Vector3D<Real>
	::operator[](unsigned int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;
	MATHEMATICS_ASSERTION_0(index < 3, "索引错误");

	return m_Tuple[index];
}

template <typename Real>
Real& Mathematics::Vector3D<Real>
	::operator[](unsigned int index)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(index < 3, "索引错误");

	return OPERATOR_SQUARE_BRACKETS(Real, index);
}

template <typename Real>
Mathematics::Vector3D<Real>& Mathematics::Vector3D<Real>
	::operator+=(const ClassType& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] += rhs.m_Tuple[0];
	m_Tuple[1] += rhs.m_Tuple[1];
	m_Tuple[2] += rhs.m_Tuple[2];

	return *this;
}

template <typename Real>
Mathematics::Vector3D<Real>& Mathematics::Vector3D<Real>
	::operator-=(const ClassType& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] -= rhs.m_Tuple[0];
	m_Tuple[1] -= rhs.m_Tuple[1];
	m_Tuple[2] -= rhs.m_Tuple[2];

	return *this;
}

template <typename Real>
Mathematics::Vector3D<Real>& Mathematics::Vector3D<Real>
	::operator*=(Real rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] *= rhs;
	m_Tuple[1] *= rhs;
	m_Tuple[2] *= rhs;

	return *this;
}

template <typename Real>
Mathematics::Vector3D<Real>& Mathematics::Vector3D<Real>
	::operator/=(Real rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	if (Math::sm_ZeroTolerance < Math::FAbs(rhs))
	{
		m_Tuple[0] /= rhs;
		m_Tuple[1] /= rhs;
		m_Tuple[2] /= rhs;
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "除零错误！");

		ZeroOut();
	}

	return *this;
}

template <typename Real>
typename const Mathematics::Vector3D<Real>::BarycentricCoordinates Mathematics::Vector3D<Real>
	::GetBarycentrics(const ClassType& firstVector, const ClassType& secondVector, const ClassType& thirdVector,
					  const ClassType& fourthVector, const Real epsilon) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	// 计算相对于该正四面体fourthVector的向量。
	ClassType difference[4]{ firstVector - fourthVector, secondVector - fourthVector,thirdVector - fourthVector,*this - fourthVector };

	auto det = Vector3DTools::ScalarTripleProduct(difference[1], difference[2], difference[0]);

	auto e1CrossE2 = Vector3DTools::CrossProduct(difference[1], difference[2]);
	auto e2CrossE0 = Vector3DTools::CrossProduct(difference[2], difference[0]);
	auto e0CrossE1 = Vector3DTools::CrossProduct(difference[0], difference[1]);

	if (epsilon < Math::FAbs(det))
	{
		Tuple4 bary{ Vector3DTools::DotProduct(difference[3],e1CrossE2) / det,
					 Vector3DTools::DotProduct(difference[3],e2CrossE0) / det,
					 Vector3DTools::DotProduct(difference[3],e0CrossE1) / det,
					 Math::sm_Zero };

		bary[3] = Math::sm_One - bary[0] - bary[1] - bary[2];

		return BarycentricCoordinates{ true,bary };
	}
	else
	{
	#ifdef MATHEMATICS_ASSERT_ON_BARYCENTRIC3_DEGENERATE
		MATHEMATICS_ASSERTION_1(false, "输入的是退化正四面体。\n");
	#endif // MATHEMATICS_ASSERT_ON_BARYCENTRIC3_DEGENERATE

		return BarycentricCoordinates{};
	}
}

template <typename Real>
typename const Mathematics::Vector3D<Real>::ClassType Mathematics::Vector3D<Real>
	::GetMove(Real t, const ClassType& velocity) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return *this + t * velocity;
}

#endif // MATHEMATICS_ALGEBRA_VECTOR_3D_DETAIL_H