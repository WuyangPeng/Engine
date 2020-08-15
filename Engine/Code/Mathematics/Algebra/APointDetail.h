// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/19 11:34)

#ifndef MATHEMATICS_ALGEBRA_A_POINT_DETAIL_H
#define MATHEMATICS_ALGEBRA_A_POINT_DETAIL_H

#include "APoint.h"
#include "AVector.h"
#include "Vector3D.h"
#include "AlgebraTraits.h"
#include "Mathematics/Base/Float3.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include "System/Helper/PragmaWarning/NumericCast.h"
#include "System/Helper/PragmaWarning.h" 
#include STSTEM_WARNING_PUSH
#include SYSTEM_WARNING_DISABLE(26426)
template <typename T>
const Mathematics::APoint<T> Mathematics::APoint<T>
	::sm_Origin{ Math::sm_Zero,Math::sm_Zero,Math::sm_Zero };

template <typename T>
Mathematics::APoint<T>
	::APoint() noexcept
	:m_HomogeneousPoint{ Math::sm_Zero,Math::sm_Zero,Math::sm_Zero,Math::sm_One }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::APoint<T>
::APoint(T x, T y, T z) noexcept
	:m_HomogeneousPoint{ x,y,z,Math::sm_One }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::APoint<T>
	::APoint(const Float3& tuple)
	:m_HomogeneousPoint{ tuple.GetFirstValue(),tuple.GetSecondValue(),tuple.GetThirdValue(),Math::sm_One }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

template <typename T>
Mathematics::APoint<T>
	::APoint(const Vector3D& rhs)
	:m_HomogeneousPoint{ rhs.GetXCoordinate(),rhs.GetYCoordinate(),rhs.GetZCoordinate(),Math::sm_One }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename T>
bool Mathematics::APoint<T>
	::IsValid() const noexcept
{
	if (Math::FAbs(m_HomogeneousPoint.GetW() - Math::sm_One) <= Math::sm_Epsilon)
		return true;
	else
		return false;
}
#endif // OPEN_CLASS_INVARIANT	

template <typename T>
const Mathematics::Float3 Mathematics::APoint<T>
	::GetFloat3() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Float3{ boost::numeric_cast<float>(m_HomogeneousPoint.GetX()),boost::numeric_cast<float>(m_HomogeneousPoint.GetY()),boost::numeric_cast<float>(m_HomogeneousPoint.GetZ()) };
}

template <typename T>
const Mathematics::Vector3D<T>Mathematics::APoint<T>
	::GetVector3D() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return Vector3D{ m_HomogeneousPoint.GetX(),m_HomogeneousPoint.GetY(),m_HomogeneousPoint.GetZ() };
}

template <typename T>
const Mathematics::HomogeneousPoint<T> Mathematics::APoint<T>
	::GetHomogeneousPoint() const noexcept
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_HomogeneousPoint;
}

template <typename T>
const T& Mathematics::APoint<T>
	::operator[](int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 3, "À˜“˝¥ÌŒÛ£°");

	return m_HomogeneousPoint[index];
}

template <typename T>
T& Mathematics::APoint<T>
	::operator[](int index)
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < 3, "À˜“˝¥ÌŒÛ£°");

	return OPERATOR_SQUARE_BRACKETS(T, index);
}

template <typename T>
Mathematics::APoint<T>& Mathematics::APoint<T>
	::operator+=(const AVector& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_HomogeneousPoint[0] += rhs[0];
	m_HomogeneousPoint[1] += rhs[1];
	m_HomogeneousPoint[2] += rhs[2];

	return *this;
}

template <typename T>
Mathematics::APoint<T>& Mathematics::APoint<T>
	::operator-=(const AVector& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_HomogeneousPoint[0] -= rhs[0];
	m_HomogeneousPoint[1] -= rhs[1];
	m_HomogeneousPoint[2] -= rhs[2];

	return *this;
}

template <typename T>
Mathematics::APoint<T>& Mathematics::APoint<T>
	::operator+=(const ClassType& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_HomogeneousPoint[0] += rhs[0];
	m_HomogeneousPoint[1] += rhs[1];
	m_HomogeneousPoint[2] += rhs[2];

	return *this;
}

template <typename T>
Mathematics::APoint<T>& Mathematics::APoint<T>
	::operator-=(const ClassType& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_HomogeneousPoint[0] -= rhs[0];
	m_HomogeneousPoint[1] -= rhs[1];
	m_HomogeneousPoint[2] -= rhs[2];

	return *this;
}

template <typename T>
Mathematics::APoint<T>& Mathematics::APoint<T>
	::operator*=(T scalar)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	m_HomogeneousPoint[0] *= scalar;
	m_HomogeneousPoint[1] *= scalar;
	m_HomogeneousPoint[2] *= scalar;

	return *this;
}

template <typename T>
Mathematics::APoint<T>& Mathematics::APoint<T>
	::operator/=(T scalar)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	if (Math::sm_ZeroTolerance < Math::FAbs(scalar))
	{
		m_HomogeneousPoint[0] /= scalar;
		m_HomogeneousPoint[1] /= scalar;
		m_HomogeneousPoint[2] /= scalar;
	}
	else
	{
		MATHEMATICS_ASSERTION_1(false, "≥˝¡„¥ÌŒÛ£°");

		m_HomogeneousPoint[0] = Math::sm_MaxReal;
		m_HomogeneousPoint[1] = Math::sm_MaxReal;
		m_HomogeneousPoint[2] = Math::sm_MaxReal;
	}

	return *this;
}

template <typename T>
const Mathematics::APoint<T> Mathematics::APoint<T>
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return APoint{ -m_HomogeneousPoint[0],-m_HomogeneousPoint[1],-m_HomogeneousPoint[2] };
}

template <typename T>
const Mathematics::AVector<T> Mathematics
	::operator-(const APoint<T>& lhs, const APoint<T>& rhs)
{
	return AVector<T>{ lhs[0] - rhs[0], lhs[1] - rhs[1], lhs[2] - rhs[2] };
}

template <typename T>
const Mathematics::APoint<T> Mathematics
	::operator+(const APoint<T>& lhs, const AVector<T>& rhs)
{
	APoint<T> result{ lhs };

	result += rhs;

	return result;
}

template <typename T>
const Mathematics::APoint<T> Mathematics
	::operator-(const APoint<T>& lhs, const AVector<T>& rhs)
{
	APoint<T> result{ lhs };

	result -= rhs;

	return result;
}

template <typename T>
const Mathematics::APoint<T> Mathematics
	::operator+(const APoint<T>& lhs, const APoint<T>& rhs)
{
	APoint<T> result{ lhs };

	result += rhs;

	return result;
}

template <typename T>
const Mathematics::APoint<T> Mathematics
	::operator*(const APoint<T>& lhs, T scalar)
{
	APoint<T> result{ lhs };

	result *= scalar;

	return result;
}

template <typename T>
const Mathematics::APoint<T> Mathematics
	::operator/(const APoint<T>& lhs, T scalar)
{
	APoint<T> result{ lhs };

	result /= scalar;

	return result;
}

template <typename T>
const Mathematics::APoint<T> Mathematics
	::operator*(T scalar, const APoint<T>& rhs)
{
	return rhs * scalar;
}

template <typename T>
T Mathematics
	::Dot(const APoint<T>& lhs, const AVector<T>& rhs)
{
	return lhs[0] * rhs[0] + lhs[1] * rhs[1] + lhs[2] * rhs[2];
}

template <typename T>
bool Mathematics
	::Approximate(const APoint<T>& lhs, const APoint<T>& rhs, const T epsilon)
{
	return Math<T>::FAbs(lhs[0] - rhs[0]) <= epsilon && Math<T>::FAbs(lhs[1] - rhs[1]) <= epsilon && Math<T>::FAbs(lhs[2] - rhs[2]) <= epsilon;
}

template <typename T>
bool Mathematics
	::Approximate(const APoint<T>& lhs, const APoint<T>& rhs)
{
	return Approximate(lhs, rhs, Math<T>::sm_ZeroTolerance);
}

template <typename T>
std::ostream& Mathematics
	::operator<<(std::ostream& outFile, const APoint<T>& point)
{
	outFile << point[0] << "°°" << point[1] << "°°" << point[2];

	return outFile;
}
#include STSTEM_WARNING_POP
#endif // MATHEMATICS_ALGEBRA_A_POINT_DETAIL_H
