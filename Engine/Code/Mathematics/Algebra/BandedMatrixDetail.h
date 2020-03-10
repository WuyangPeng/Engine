// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/04 19:24)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_DETAIL_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_DETAIL_H

#include "BandedMatrix.h"

#if !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BANDED_MATRIX_DETAIL)

#include "VariableMatrix.h"
#include "AlgebraTraits.h"
#include "Mathematics/Base/Math.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"

template <typename Real>
Mathematics::BandedMatrix<Real>
	::BandedMatrix( int size, int lowerBandsNumber, int upperBandsNumber )
	:m_Size{ size }, m_LowerBandsNumber{ lowerBandsNumber },
	 m_UpperBandsNumber{ upperBandsNumber }, m_DiagonalBand{ NEW1<Real>(m_Size) },
	 m_LowerBand{ 0 < m_LowerBandsNumber ? NEW1<Real*>(m_LowerBandsNumber) : nullptr },
	 m_UpperBand{ 0 < m_UpperBandsNumber ? NEW1<Real*>(m_UpperBandsNumber) : nullptr }
{
	Allocate();

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::BandedMatrix<Real>
	::Allocate()
{
	auto bytesNumber = m_Size * sizeof(Real);
	memset(m_DiagonalBand, 0, bytesNumber);
	
	for (auto i = 0; i < m_LowerBandsNumber; ++i)
	{
		auto lowerSize = m_Size - 1 - i;
		m_LowerBand[i] = NEW1<Real>(lowerSize);
		memset(m_LowerBand[i], 0, lowerSize * sizeof(Real));
	}

	for (auto i = 0; i < m_UpperBandsNumber; ++i)
	{
		auto upperSize = m_Size - 1 - i;
		m_UpperBand[i] = NEW1<Real>(upperSize);
		memset(m_UpperBand[i], 0, upperSize * sizeof(Real));
	}
}


template <typename Real>
Mathematics::BandedMatrix<Real>
	::~BandedMatrix()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;

	Deallocate();
}

// private
template <typename Real>
void Mathematics::BandedMatrix<Real>
	::Deallocate()
{
	DELETE1(m_DiagonalBand);

	if (m_LowerBand != nullptr)
	{
		for (auto i = 0; i < m_LowerBandsNumber; ++i)
		{
			DELETE1(m_LowerBand[i]);
		}

		DELETE1(m_LowerBand);
		m_LowerBand = nullptr;
	}

	if (m_UpperBand != nullptr)
	{
		for (auto i = 0; i < m_UpperBandsNumber; ++i)
		{
			DELETE1(m_UpperBand[i]);
		}

		DELETE1(m_UpperBand);
		m_UpperBand = nullptr;
	}
}

template <typename Real>
Mathematics::BandedMatrix<Real>
	::BandedMatrix( const BandedMatrix& rhs )
	:m_Size{ rhs.m_Size }, m_LowerBandsNumber{ rhs.m_LowerBandsNumber },
	 m_UpperBandsNumber{ rhs.m_UpperBandsNumber }, m_DiagonalBand{ NEW1<Real>(m_Size) },
	 m_LowerBand{ 0 < m_LowerBandsNumber ? NEW1<Real*>(m_LowerBandsNumber) : nullptr },
	 m_UpperBand{ 0 < m_UpperBandsNumber ? NEW1<Real*>(m_UpperBandsNumber) : nullptr }
{
	Allocate(rhs);

	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

// private
template <typename Real>
void Mathematics::BandedMatrix<Real>
	::Allocate( const BandedMatrix& rhs )
{
	auto bytesNumber = m_Size * sizeof(Real);
	memcpy(m_DiagonalBand, rhs.m_DiagonalBand, bytesNumber);
	
	for (auto i = 0; i < m_LowerBandsNumber; ++i)
	{	
		auto lowerSize = m_Size - 1 - i;
		m_LowerBand[i] = NEW1<Real>(lowerSize);
		memcpy(m_LowerBand[i], rhs.m_LowerBand[i], lowerSize * sizeof(Real));
	}

	for (auto i = 0; i < m_UpperBandsNumber; ++i)
	{
		auto upperSize = m_Size - 1 - i;
		m_UpperBand[i] = NEW1<Real>(upperSize);
		memcpy(m_UpperBand[i], rhs.m_UpperBand[i], upperSize * sizeof(Real));
	}
}

template <typename Real>
Mathematics::BandedMatrix<Real>& Mathematics::BandedMatrix<Real>
	::operator=( const BandedMatrix& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_1;

	BandedMatrix<Real> result{ rhs };

	Swap(result);

	return *this;
}

template <typename Real>
void Mathematics::BandedMatrix<Real>
	::Swap( BandedMatrix& rhs )
{
	std::swap(m_Size,rhs.m_Size);
	std::swap(m_LowerBandsNumber,rhs.m_LowerBandsNumber);
	std::swap(m_UpperBandsNumber,rhs.m_UpperBandsNumber);
 	std::swap(m_DiagonalBand,rhs.m_DiagonalBand);
 	std::swap(m_LowerBand,rhs.m_LowerBand);
 	std::swap(m_UpperBand,rhs.m_UpperBand);
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::BandedMatrix<Real>
	::IsValid() const noexcept
{
	if(m_Size <= 0 || m_Size <= m_LowerBandsNumber || m_Size <= m_UpperBandsNumber || m_LowerBandsNumber < 0 || m_UpperBandsNumber < 0 || m_DiagonalBand == nullptr)
	    return false;
	else if(m_LowerBandsNumber == 0 && m_LowerBand != nullptr)
		return false;
	else if(m_UpperBandsNumber == 0 && m_UpperBand != nullptr)
		return false;
	else if(m_LowerBandsNumber != 0 && m_LowerBand == nullptr)
		return false;
	else if(m_UpperBandsNumber != 0 && m_UpperBand == nullptr)
		return false;
	else
		return true;
}
#endif	// OPEN_CLASS_INVARIANT

template <typename Real>
int Mathematics::BandedMatrix<Real>
	::GetSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_Size;
}

template <typename Real>
int Mathematics::BandedMatrix<Real>
	::GetLowerBandsNumber() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_LowerBandsNumber;
}

template <typename Real>
int Mathematics::BandedMatrix<Real>
	::GetUpperBandsNumber() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_UpperBandsNumber;
}

template <typename Real>
void Mathematics::BandedMatrix<Real>
	::ResetSize(int size, int lowerBandsNumber, int upperBandsNumber)
{
	MATHEMATICS_CLASS_IS_VALID_1;

	BandedMatrix<Real> result{ size, lowerBandsNumber, upperBandsNumber };

	Swap(result);
}

template <typename Real>
int Mathematics::BandedMatrix<Real>
	::GetStreamSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	auto size = CORE_TOOLS_STREAM_SIZE(m_Size);
	size += CORE_TOOLS_STREAM_SIZE(m_LowerBandsNumber);
	size += CORE_TOOLS_STREAM_SIZE(m_UpperBandsNumber);

	size += CORE_TOOLS_STREAM_SIZE(m_DiagonalBand[0]) * m_Size;

	for (auto i = 0; i < m_LowerBandsNumber; ++i)
	{	
		auto lowerSize = m_Size - 1 - i;
		size += CORE_TOOLS_STREAM_SIZE(m_LowerBand[i][0]) * lowerSize; 
	}

	for (auto i = 0; i < m_UpperBandsNumber; ++i)
	{
		auto upperSize = m_Size - 1 - i;
		size += CORE_TOOLS_STREAM_SIZE(m_UpperBand[i][0]) * upperSize; 
	}

	return size;
}

template <typename Real>
Real* Mathematics::BandedMatrix<Real>
	::GetDiagonalBand()
{
	MATHEMATICS_CLASS_IS_VALID_1;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(Real*, GetDiagonalBand);
}

template <typename Real>
const Real* Mathematics::BandedMatrix<Real>
	::GetDiagonalBand() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;

	return m_DiagonalBand;
}

template <typename Real>
int Mathematics::BandedMatrix<Real>
	::GetLowerBandMax( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(0 <= index && index < m_LowerBandsNumber, "无效索引在 GetLBandMax\n");

	return m_Size - 1 - index;
}

template <typename Real>
Real* Mathematics::BandedMatrix<Real>
	::GetLowerBand( int index )
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_LowerBandsNumber, "无效索引在 GetLowerBand\n");
	MATHEMATICS_ASSERTION_0(m_LowerBand != nullptr,"m_LowerBand为空。");

	return  const_cast<Real*>(static_cast<const ClassType&>(*this).GetLowerBand(index));
}

template <typename Real>
const Real* Mathematics::BandedMatrix<Real>
	::GetLowerBand( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_LowerBandsNumber,"无效索引在 GetLowerBand\n");
	MATHEMATICS_ASSERTION_0(m_LowerBand != nullptr,"m_LowerBand为空。");

	return m_LowerBand[index];
}

template <typename Real>
int Mathematics::BandedMatrix<Real>
	::GetUpperBandMax( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_1(0 <= index && index < m_UpperBandsNumber,"无效索引在 GetUBandMax\n");

	return m_Size - 1 - index;
}

template <typename Real>
Real* Mathematics::BandedMatrix<Real>
	::GetUpperBand( int index )
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_UpperBandsNumber, "无效索引在 GetUpperBand\n");
	MATHEMATICS_ASSERTION_0(m_UpperBand != nullptr, "m_UpperBand为空。");

	return  const_cast<Real*>(static_cast<const ClassType&>(*this).GetUpperBand(index));
}


template <typename Real>
const Real* Mathematics::BandedMatrix<Real>
	::GetUpperBand( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= index && index < m_UpperBandsNumber, "无效索引在 GetUpperBand\n");
	MATHEMATICS_ASSERTION_0(m_UpperBand != nullptr,"m_UpperBand为空。");

	return m_UpperBand[index];
}


template <typename Real>
Real& Mathematics::BandedMatrix<Real>
	::operator()( int row, int column )
{
	MATHEMATICS_CLASS_IS_VALID_1;
	MATHEMATICS_ASSERTION_0(0 <= row && row < m_Size && 0 <= column && column < m_Size,"无效 row 或 column 在 BandedMatrix::operator\n");

	return  const_cast<Real&>(static_cast<const ClassType&>(*this)(row,column));
}

template <typename Real>
const Real& Mathematics::BandedMatrix<Real>
	::operator()( int row, int column ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(0 <= row && row < m_Size && 0 <= column && column < m_Size,"无效 row 或 column 在 BandedMatrix::operator\n");

	auto band = column - row;
	if (0 < band)
	{
		if (--band < m_UpperBandsNumber && row < m_Size - 1 - band)
		{
			return m_UpperBand[band][row];
		}
	}
	else if (band < 0)
	{
		band = -band;
		if (--band < m_LowerBandsNumber && column < m_Size - 1 - band)
		{
			return m_LowerBand[band][column];
		}
	}
	else
	{
		return m_DiagonalBand[row];
	}
	
	// CholeskyFactor函数会将s_Dummy重复赋值为0。
	static auto s_Dummy = Real{};

	MATHEMATICS_ASSERTION_1(Math::FAbs(s_Dummy) <= Math::sm_ZeroTolerance, "静态变量s_Dummy值被修改！s_Dummy值必须为零！");
	
	s_Dummy = Real{};

	return s_Dummy;
}


template <typename Real>
void Mathematics::BandedMatrix<Real>
	::SetZero()
{
	MATHEMATICS_CLASS_IS_VALID_1;

	auto bytesNumber = m_Size * sizeof(Real);
	memset(m_DiagonalBand, 0, bytesNumber);
	
	for (auto i = 0; i < m_LowerBandsNumber; ++i)
	{
		auto lowerSize = m_Size - 1 - i;
		memset(m_LowerBand[i], 0, lowerSize * sizeof(Real));
	}

	for (auto i = 0; i < m_UpperBandsNumber; ++i)
	{
		auto upperSize = m_Size - 1 - i;
		memset(m_UpperBand[i], 0, upperSize * sizeof(Real));
	}
}


template <typename Real>
void Mathematics::BandedMatrix<Real>
	::SetIdentity()
{
	MATHEMATICS_CLASS_IS_VALID_1;

	for (auto i = 0; i < m_Size; ++i)
	{
		m_DiagonalBand[i] = AlgebraTraits::UnitValue;
	}
	
	for (auto i = 0; i < m_LowerBandsNumber; ++i)
	{
		auto lowerSize = m_Size - 1 - i;
		memset(m_LowerBand[i], 0, lowerSize * sizeof(Real));
	}

	for (auto i = 0; i < m_UpperBandsNumber; ++i)
	{
		auto upperSize = m_Size - 1 - i;
		memset(m_UpperBand[i], 0, upperSize * sizeof(Real));
	}
} 

template <typename Real>
typename const Mathematics::BandedMatrix<Real>::VariableMatrix Mathematics::BandedMatrix<Real>
	::ToVariableMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;	

	VariableMatrix variableMatrix{ m_Size, m_Size };

	for (auto row = 0; row < m_Size; ++ row)
	{
		for (auto column = 0; column < m_Size; ++ column)
	    {	
	         variableMatrix(row,column) = (*this)(row,column); 
	    }
	}

	return variableMatrix;
}

#endif // !defined(MATHEMATICS_EXPORT_TEMPLATE) || defined(MATHEMATICS_INCLUDED_BANDED_MATRIX_DETAIL)

#endif // MATHEMATICS_ALGEBRA_BANDED_MATRIX_DETAIL_H

