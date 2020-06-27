// Copyright (c) 2011-2020
// Threading Core Render Engine
// ◊˜’ﬂ£∫≈ÌŒ‰—Ù£¨≈ÌÍ ∂˜£¨≈ÌÍ ‘Û
// 
// “˝«Ê∞Ê±æ£∫0.0.2.5 (2020/03/20 10:20)

#ifndef MATHEMATICS_RATIONAL_RATIONAL_VECTOR_DETAIL_H
#define MATHEMATICS_RATIONAL_RATIONAL_VECTOR_DETAIL_H

#include "RationalVector.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>
	::RationalVector()
{
	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] = Rational(0);
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>
	::RationalVector(const RationalVector& rhs)
{
	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] = rhs.m_Tuple[i];
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>& Mathematics::RationalVector<VectorSize, IntSize>
	::operator=(const RationalVector& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] = rhs.m_Tuple[i];
	}

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <int VectorSize, int IntSize>
bool Mathematics::RationalVector<VectorSize, IntSize>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT

template <int VectorSize, int IntSize>
typename const Mathematics::RationalVector<VectorSize, IntSize>::Rational& Mathematics::RationalVector<VectorSize, IntSize>
	::operator[](int index) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	if (0 <= index && index < VectorSize)
	{
		return m_Tuple[index];
	}
	else
	{
		THROW_EXCEPTION(SYSTEM_TEXT("À˜“˝¥ÌŒÛ£°"));
	}
}

template <int VectorSize, int IntSize>
typename Mathematics::RationalVector<VectorSize, IntSize>::Rational& Mathematics::RationalVector<VectorSize, IntSize>
	::operator[](int index)
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(0 <= index && index < VectorSize, "À˜“˝¥ÌŒÛ£°");

	return OPERATOR_SQUARE_BRACKETS(Rational, index);
}

template <int VectorSize, int IntSize>
const Mathematics::RationalVector<VectorSize, IntSize> Mathematics::RationalVector<VectorSize, IntSize>
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	RationalVector negative;
	for (auto i = 0; i < VectorSize; ++i)
	{
		negative.m_Tuple[i] = -m_Tuple[i];
	}
	return negative;
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>& Mathematics::RationalVector<VectorSize, IntSize>
	::operator+=(const RationalVector& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] += rhs.m_Tuple[i];
	}

	return *this;
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>& Mathematics::RationalVector<VectorSize, IntSize>
	::operator-=(const RationalVector& rhs)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] -= rhs.m_Tuple[i];
	}

	return *this;
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>& Mathematics::RationalVector<VectorSize, IntSize>
	::operator*=(const Rational& scalar)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] *= scalar;
	}

	return *this;
}

template <int VectorSize, int IntSize>
Mathematics::RationalVector<VectorSize, IntSize>& Mathematics::RationalVector<VectorSize, IntSize>
	::operator/=(const Rational& scalar)
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] /= scalar;
	}

	return *this;
}

template <int VectorSize, int IntSize>
typename Mathematics::RationalVector<VectorSize, IntSize>::Rational Mathematics::RationalVector<VectorSize, IntSize>
	::SquaredLength() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	Rational squaredLength{ 0 };
	for (auto i = 0; i < VectorSize; ++i)
	{
		squaredLength += m_Tuple[i] * m_Tuple[i];
	}

	return squaredLength;
}

template <int VectorSize, int IntSize>
Mathematics::SignRational<IntSize> Mathematics
	::Dot(const RationalVector<VectorSize, IntSize>& lhs, const RationalVector<VectorSize, IntSize>& rhs)
{
	SignRational<IntSize> dot{ 0 };
	for (auto i = 0; i < VectorSize; ++i)
	{
		dot += lhs[i] * rhs[i];
	}

	return dot;
}

template <int VectorSize, int IntSize>
bool Mathematics
	::operator==(const RationalVector<VectorSize, IntSize>& lhs, const RationalVector<VectorSize, IntSize>& rhs)
{
	for (auto i = 0; i < VectorSize; ++i)
	{
		if (lhs[i] != rhs[i])
		{
			return false;
		}
	}
	return true;
}

template <int VectorSize, int IntSize>
bool Mathematics
	::operator<(const RationalVector<VectorSize, IntSize>& lhs, const RationalVector<VectorSize, IntSize>& rhs)
{
	for (auto i = 0; i < VectorSize; ++i)
	{
		if (lhs[i] < rhs[i])
		{
			return true;
		}
		else if (rhs[i] < lhs[i])
		{
			return false;
		}
	}

	return false;
}

template <int VectorSize, int IntSize>
std::ostream& Mathematics
	::operator<<(std::ostream& os, const RationalVector<VectorSize, IntSize>& rhs)
{
	for (auto i = 0; i < VectorSize; ++i)
	{
		os << rhs[i] << " ";
	}

	return os;
}

#endif // MATHEMATICS_RATIONAL_RATIONAL_VECTOR_DETAIL_H
