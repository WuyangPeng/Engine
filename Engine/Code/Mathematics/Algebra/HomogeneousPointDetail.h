// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 13:05)

#ifndef MATHEMATICS_ALGEBRA_POINT_DETAIL_H
#define MATHEMATICS_ALGEBRA_POINT_DETAIL_H

#include "HomogeneousPoint.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_HOMOGENEOUS_POINT_DETAIL)

#include "System/Helper/UnicodeUsing.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <typename T>
Mathematics::HomogeneousPoint<T>
	::HomogeneousPoint() noexcept
	:m_Tuple{}
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
Mathematics::HomogeneousPoint<T>
	::HomogeneousPoint(const HomogeneousPoint& rhs)
{
	memcpy(m_Tuple, rhs.m_Tuple, GetPointByte());

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
Mathematics::HomogeneousPoint<T>
	::HomogeneousPoint(T x, T y, T z, T w)
{
	m_Tuple[0] = x;
	m_Tuple[1] = y;
	m_Tuple[2] = z;
	m_Tuple[3] = w;

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
Mathematics::HomogeneousPoint<T>
	::~HomogeneousPoint()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <typename T>
Mathematics::HomogeneousPoint<T>& Mathematics::HomogeneousPoint<T>
	::operator= (const HomogeneousPoint& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	memcpy(m_Tuple, rhs.m_Tuple, GetPointByte());

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::HomogeneousPoint<T>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename T>
const T* Mathematics::HomogeneousPoint<T>
	::GetCoordinate() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple;
}

template <typename T>
T* Mathematics::HomogeneousPoint<T>
	::GetCoordinate()
{
	MATHEMATICS_CLASS_IS_VALID_9;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(T*, GetCoordinate);
}

template <typename T>
const T& Mathematics::HomogeneousPoint<T>
	::operator[] (int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (0 <= index && index < GetPointSize())
	{
		return m_Tuple[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("À˜“˝¥ÌŒÛ£°"));
	}
}

template <typename T>
T& Mathematics::HomogeneousPoint<T>
	::operator[] (int index)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T>
T Mathematics::HomogeneousPoint<T>
	::GetX() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[0];
}

template <typename T>
void Mathematics::HomogeneousPoint<T>
	::SetX(T x)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[0] = x;
}

template <typename T>
T Mathematics::HomogeneousPoint<T>
	::GetY() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[1];
}

template <typename T>
void Mathematics::HomogeneousPoint<T>
	::SetY(T y)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[1] = y;
}

template <typename T>
T Mathematics::HomogeneousPoint<T>
	::GetZ() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[2];
}

template <typename T>
void Mathematics::HomogeneousPoint<T>
	::SetZ(T z)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[2] = z;
}

template <typename T>
T Mathematics::HomogeneousPoint<T>
	::GetW() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[3];
}

template <typename T>
void Mathematics::HomogeneousPoint<T>
	::SetW(T w)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	m_Tuple[3] = w;
}

// static
template <typename T>
int Mathematics::HomogeneousPoint<T>
	::GetPointByte()
{
	return GetPointSize() * sizeof(T);
}

template <typename T>
int Mathematics::HomogeneousPoint<T>
	::GetPointSize()
{
	return sm_PointSize;
}

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_HOMOGENEOUS_POINT_DETAIL)

template <typename T>
bool Mathematics
	::operator==(const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs)
{
	return memcmp(lhs.GetCoordinate(), rhs.GetCoordinate(), HomogeneousPoint<T>::GetPointByte()) == 0;
}

template <typename T>
bool Mathematics
	::operator<(const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs)
{
	return memcmp(lhs.GetCoordinate(), rhs.GetCoordinate(), HomogeneousPoint<T>::GetPointByte()) < 0;
}

template <typename T>
bool Mathematics
	::Approximate(const HomogeneousPoint<T>& lhs, const HomogeneousPoint<T>& rhs, const T epsilon)
{
	for (auto i = 0; i < HomogeneousPoint<T>::GetPointSize(); ++i)
	{
		if (epsilon < Math<T>::FAbs(lhs[i] - rhs[i]))
			return false;
	}

	return true;
}

#endif // MATHEMATICS_ALGEBRA_POINT_DETAIL_H