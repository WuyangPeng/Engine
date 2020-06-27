// Copyright (c) 2011-2020
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.2.5 (2020/03/19 14:06)

#ifndef MATHEMATICS_ALGEBRA_PLANE_DETAIL_H
#define MATHEMATICS_ALGEBRA_PLANE_DETAIL_H

#include "Plane.h"
#include "AVector.h"
#include "APoint.h"
#include "AlgebraTraits.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::Plane<T>
	::Plane(const T epsilon)
	:m_Tuple{ Math::sm_One, Math::sm_Zero, Math::sm_Zero, Math::sm_Zero }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>
	::Plane(T normalX, T normalY, T normalZ, T constant, const T epsilon)
	:m_Tuple{ normalX,normalY,normalZ,-constant }, m_Epsilon{ epsilon }
{
	Normalize();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>
	::Plane(const AVector& normal, T constant, const T epsilon)
	:m_Tuple{ normal[0],normal[1],normal[2],-constant }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>
	::Plane(const AVector& normal, const APoint& point, const T epsilon)
	:m_Tuple{ normal[0],normal[1],normal[2],-Dot(point,normal) }, m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>
	::Plane(const APoint& lhs, const APoint& mhs, const APoint& rhs, const T epsilon)
	:m_Tuple{}, m_Epsilon{ epsilon }
{
	auto edge1 = mhs - lhs;
	auto edge2 = rhs - lhs;
	auto normal = UnitCross(edge1, edge2, m_Epsilon);
	m_Tuple[0] = normal[0];
	m_Tuple[1] = normal[1];
	m_Tuple[2] = normal[2];
	m_Tuple[3] = -Dot(lhs, normal);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::Plane<T>
	::Plane(const HomogeneousPoint& tuple, const T epsilon)
	:m_Tuple{ tuple }, m_Epsilon{ epsilon }
{
	Normalize();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename T>
void Mathematics::Plane<T>
	::Normalize()
{
	auto length = Math::Sqrt(m_Tuple[0] * m_Tuple[0] + m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2]);

	if (m_Epsilon < length)
	{
		m_Tuple[0] /= length;
		m_Tuple[1] /= length;
		m_Tuple[2] /= length;
		m_Tuple[3] /= length;
	}
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::Plane<T>
	::IsValid() const noexcept
{
	if (Math::Sqrt(m_Tuple[0] * m_Tuple[0] + m_Tuple[1] * m_Tuple[1] + m_Tuple[2] * m_Tuple[2]) - Math::sm_One <= m_Epsilon)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename T>
const Mathematics::HomogeneousPoint<T> Mathematics::Plane<T>
	::GetHomogeneousPoint() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Tuple;
}

template <typename T>
const T* Mathematics::Plane<T>
	::GetElements() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Tuple.GetCoordinate();
}

template <typename T>
T* Mathematics::Plane<T>
	::GetElements()
{
	MATHEMATICS_CLASS_IS_VALID_1;

	return m_Tuple.GetCoordinate();
}

template <typename T>
const T& Mathematics::Plane<T>
	::operator[](int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Tuple[index];
}

template <typename T>
T& Mathematics::Plane<T>
	::operator[](int index)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T>
void Mathematics::Plane<T>
	::SetNormal(const AVector& normal)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	MATHEMATICS_ASSERTION_1(normal.IsNormalize(m_Epsilon), "传入的向量不是单位向量！");

	m_Tuple[0] = normal[0];
	m_Tuple[1] = normal[1];
	m_Tuple[2] = normal[2];
}

template <typename T>
void Mathematics::Plane<T>
	::SetConstant(T constant)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Tuple[3] = -constant;
}

template <typename T>
void Mathematics::Plane<T>
	::SetEpsilon(T epsilon)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_Epsilon = epsilon;
}

template <typename T>
T Mathematics::Plane<T>
	::GetEpsilon() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Epsilon;
}

template <typename T>
const Mathematics::AVector<T> Mathematics::Plane<T>
	::GetNormal() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return AVector{ m_Tuple[0], m_Tuple[1], m_Tuple[2] };
}

template <typename T>
T Mathematics::Plane<T>
	::GetConstant() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return -m_Tuple[3];
}

template <typename T>
T Mathematics::Plane<T>
	::DistanceTo(const APoint& point) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Tuple[0] * point[0] + m_Tuple[1] * point[1] + m_Tuple[2] * point[2] + m_Tuple[3];
}

template <typename T>
Mathematics::NumericalValueSymbol Mathematics::Plane<T>
	::WhichSide(const APoint& point) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto distance = DistanceTo(point);

	if (distance < -m_Epsilon)
	{
		return NumericalValueSymbol::Negative;
	}
	else if (m_Epsilon < distance)
	{
		return NumericalValueSymbol::Positive;
	}
	else
	{
		return NumericalValueSymbol::Zero;
	}
}

template <typename T>
bool Mathematics
	::operator==(const Plane<T>& lhs, const Plane<T>& rhs)
{
	return memcmp(&lhs[0], &rhs[0], 4 * sizeof(T)) == 0;
}

template <typename T>
bool Mathematics
	::operator<(const Plane<T>& lhs, const Plane<T>& rhs)
{
	return memcmp(&lhs[0], &rhs[0], 4 * sizeof(T)) < 0;
}

template <typename T>
bool Mathematics
	::Approximate(const Plane<T>& lhs, const Plane<T>& rhs, const T epsilon)
{
	if (Approximate(lhs.GetNormal(), rhs.GetNormal(), epsilon) && Math<T>::Approximate(lhs.GetConstant(), rhs.GetConstant(), epsilon))
		return true;
	else
		return false;
}

template <typename T>
bool Mathematics
	::Approximate(const Plane<T>& lhs, const Plane<T>& rhs)
{
	return Approximate(lhs, rhs, Math<T>::sm_ZeroTolerance);
}

#endif // MATHEMATICS_ALGEBRA_PLANE_DETAIL_H

