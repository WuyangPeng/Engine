// Copyright (c) 2011-2019
// Threading Core Render Engine
// ×÷Õß£ºÅíÎäÑô£¬ÅíêÊ¶÷£¬ÅíêÊÔó
// 
// ÒýÇæ°æ±¾£º0.0.0.2 (2019/07/08 11:32)

#ifndef MATHEMATICS_RATIONAL_INT64_VECTOR_DETAIL_H
#define MATHEMATICS_RATIONAL_INT64_VECTOR_DETAIL_H

#include "Int64Vector.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"

#include <iostream>

template <int VectorSize>
Mathematics::Int64Vector<VectorSize>
	::Int64Vector()
{
	for(auto i = 0;i < VectorSize;++i)
	{
		m_Tuple[i] = 0;
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int VectorSize>
Mathematics::Int64Vector<VectorSize>
	::Int64Vector( const Int64Vector& rhs )
{
	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] = rhs.m_Tuple[i];
	}

	MATHEMATICS_SELF_CLASS_IS_VALID_9;
}

template <int VectorSize>
Mathematics::Int64Vector<VectorSize>& Mathematics::Int64Vector<VectorSize>
	::operator=( const Int64Vector& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] = rhs.m_Tuple[i];
	}

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <int VectorSize>
bool Mathematics::Int64Vector<VectorSize>
	::IsValid() const noexcept
{
	return true;
}
#endif // OPEN_CLASS_INVARIANT


template <int VectorSize>
const int64_t& Mathematics::Int64Vector<VectorSize>
	::operator[]( int index ) const
{
	MATHEMATICS_ASSERTION_0(0 <= index && index < VectorSize,"Ë÷Òý´íÎó£¡");
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	return m_Tuple[index];
}


template <int VectorSize>
int64_t& Mathematics::Int64Vector<VectorSize>
	::operator[]( int index )
{
	MATHEMATICS_ASSERTION_0(0 <= index && index < VectorSize, "Ë÷Òý´íÎó£¡");
	MATHEMATICS_CLASS_IS_VALID_9;

	return OPERATOR_SQUARE_BRACKETS(int64_t,index);
}


template <int VectorSize>
const Mathematics::Int64Vector<VectorSize> 	Mathematics::Int64Vector<VectorSize>
	::operator-() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	Int64Vector<VectorSize> negative;
	for (auto i = 0; i < VectorSize; ++i)
	{
		negative.m_Tuple[i] = -m_Tuple[i];
	}

	return negative;
}


template <int VectorSize>
Mathematics::Int64Vector<VectorSize>& Mathematics::Int64Vector<VectorSize>
	::operator+=( const Int64Vector& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] += rhs.m_Tuple[i];
	}

	return *this;
}

template <int VectorSize>
Mathematics::Int64Vector<VectorSize>& Mathematics::Int64Vector<VectorSize>
	::operator-=( const Int64Vector& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] -= rhs.m_Tuple[i];
	}

	return *this;
}


template <int VectorSize>
Mathematics::Int64Vector<VectorSize>& Mathematics::Int64Vector<VectorSize>
	::operator*=( const int64_t& scalar )
{
	MATHEMATICS_CLASS_IS_VALID_9;

	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] *= scalar;
	}

	return *this;
}

template <int VectorSize>
Mathematics::Int64Vector<VectorSize>& Mathematics::Int64Vector<VectorSize>
	::operator/=( const int64_t& scalar )
{
	MATHEMATICS_CLASS_IS_VALID_9;
	MATHEMATICS_ASSERTION_0(scalar != 0, "³ýÊý²»ÄÜÎªÁã\n");

	for (auto i = 0; i < VectorSize; ++i)
	{
		m_Tuple[i] /= scalar;
	}

	return *this;
}

template <int VectorSize>
int64_t Mathematics::Int64Vector<VectorSize>
	::SquaredLength() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_9;

	int64_t squaredLength{ 0 };
	for (auto i = 0; i < VectorSize; ++i)
	{
		squaredLength += m_Tuple[i] * m_Tuple[i];
	}
	return squaredLength;
}


template <int VectorSize>
bool Mathematics
	::operator==( const Int64Vector<VectorSize>& lhs, const Int64Vector<VectorSize>& rhs )
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

template <int VectorSize>
bool Mathematics
	::operator<( const Int64Vector<VectorSize>& lhs, const Int64Vector<VectorSize>& rhs )
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


template <int VectorSize>
int64_t Mathematics
	::Dot( const Int64Vector<VectorSize>& lhs, const Int64Vector<VectorSize>& rhs )
{
	int64_t dot{ 0 };
	for (auto i = 0; i < VectorSize; ++i)
	{
		dot += lhs[i] * rhs[i];
	}
	return dot;
}

template <int VectorSize>
std::ostream& Mathematics
	::operator<<(std::ostream& os, const Int64Vector<VectorSize>& rhs) 
{
	for (auto i = 0; i < VectorSize; ++i)
	{
		os << rhs[i] << " ";
	}

	return os;
}

#endif // MATHEMATICS_RATIONAL_INT64_VECTOR_DETAIL_H
