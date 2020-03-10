// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/05 09:55)

#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_DETAIL_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_DETAIL_H

#include "BandedMatrixSolve.h"
#include "AlgebraTraits.h"
#include "VariableMatrix.h"
#include "BandedMatrixDetail.h"
#include "VariableLengthVector.h"
#include "Mathematics/Base/Math.h"
#include "CoreTools/Helper/MemoryMacro.h"
#include "CoreTools/Helper/StreamMacro.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/MemberFunctionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "CoreTools/ObjectSystems/StreamSize.h"
#include "CoreTools/ObjectSystems/StreamDetail.h"
#include "CoreTools/ObjectSystems/ObjectInterface.h"

template <typename Real>
Mathematics::BandedMatrixSolve<Real>
	::BandedMatrixSolve( int size, int lowerBandsNumber,int upperBandsNumber, const Real epsilon)
	:m_Input{ size,lowerBandsNumber,upperBandsNumber },
	 m_Cholesky{ size,lowerBandsNumber,upperBandsNumber },
	 m_Solve{ BandedMatrixSolveFlags::Unsolved },
	 m_Epsilon{ epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_6;
}

template <typename Real>
Mathematics::BandedMatrixSolve<Real>
	::~BandedMatrixSolve()
{
	MATHEMATICS_SELF_CLASS_IS_VALID_6;
}

template <typename Real>
Mathematics::BandedMatrixSolve<Real>
	::BandedMatrixSolve( const BandedMatrixSolve& rhs )
	:m_Input{ rhs.m_Input },
	 m_Cholesky{ rhs.m_Cholesky },
	 m_Solve{ rhs.m_Solve },
	 m_Epsilon{ rhs.m_Epsilon }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_6;
}

template <typename Real>
Mathematics::BandedMatrixSolve<Real>& Mathematics::BandedMatrixSolve<Real>
	::operator=( const BandedMatrixSolve& rhs )
{
	MATHEMATICS_CLASS_IS_VALID_6;

	m_Input = rhs.m_Input;
	m_Cholesky = rhs.m_Cholesky;
	m_Solve = rhs.m_Solve;
	m_Epsilon = rhs.m_Epsilon;

	return *this;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::BandedMatrixSolve<Real>
	::IsValid() const noexcept 
{
	try
	{
		if (m_Input.GetSize() != m_Cholesky.GetSize())
			return false;
		else if (m_Input.GetUpperBandsNumber() != m_Cholesky.GetUpperBandsNumber())
			return false;
		else if (m_Input.GetLowerBandsNumber() != m_Cholesky.GetLowerBandsNumber())
			return false;
		else if (m_Solve != BandedMatrixSolveFlags::Succeed)
			return true;
		else
			return IsSolveValid();
	}
	catch (...)
	{
		return false;
	}
}

template <typename Real>
bool Mathematics::BandedMatrixSolve<Real>
	::IsSolveValid() const  
{
	BandedMatrix upperBandedMatrix{ m_Cholesky };

     // 下三角置零
	 for (auto i = 0; i < upperBandedMatrix.GetUpperBandsNumber(); ++i)
	 {	
		 auto lowerSize = upperBandedMatrix.GetSize() - 1 - i;
		 memset(upperBandedMatrix.GetLowerBand(i), 0, lowerSize * sizeof(Real));
	 }

     BandedMatrix lowerBandedMatrix(m_Cholesky);

     // 上三角置零
     for (int i = 0; i < lowerBandedMatrix.GetLowerBandsNumber(); ++i)
     {	
		 int upperSize = lowerBandedMatrix.GetSize() - 1 - i;
		 memset(lowerBandedMatrix.GetUpperBand(i), 0, upperSize * sizeof(Real));
     }

     for (auto row = 0; row < m_Input.GetSize(); ++ row)
     {
		 for (auto column = 0; column < m_Input.GetSize(); ++ column)
	     {				
			 if(!Math::Approximate(m_Input(row, column),GetProduct(upperBandedMatrix,lowerBandedMatrix,row,column),m_Epsilon))
	         {	
                 return false;
	         }
	     }
     }

     return true;
}

template <typename Real>
Real Mathematics::BandedMatrixSolve<Real>
	::GetProduct(const BandedMatrix& upperBandedMatrix,const BandedMatrix& lowerBandedMatrix,int row,int column) const  
{
     Real sum { };
     for (auto index = 0; index < upperBandedMatrix.GetSize(); ++ index)
     {	 
		 sum += lowerBandedMatrix(row, index) * upperBandedMatrix(index, column);	 
     }

     return sum;
}

#endif	// OPEN_CLASS_INVARIANT


template <typename Real>
int Mathematics::BandedMatrixSolve<Real>
	::GetSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_6;

	return m_Input.GetSize();
}

template <typename Real>
int Mathematics::BandedMatrixSolve<Real>
	::GetLowerBandsNumber() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_6;

	return m_Input.GetLowerBandsNumber();
}

template <typename Real>
int Mathematics::BandedMatrixSolve<Real>
	::GetUpperBandsNumber() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_6;

	return m_Input.GetUpperBandsNumber();
}

template <typename Real>
Mathematics::BandedMatrixSolveFlags Mathematics::BandedMatrixSolve<Real>
	::GetSolve() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_6;

	return m_Solve;
}

template <typename Real>
int Mathematics::BandedMatrixSolve<Real>
	::GetStreamSize() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_6;

	auto size = m_Input.GetStreamSize();
	size += CORE_TOOLS_STREAM_SIZE(m_Epsilon);

	return size;
}

template <typename Real>
void Mathematics::BandedMatrixSolve<Real>
	::SetEpsilon( Real epsilon )
{
	MATHEMATICS_CLASS_IS_VALID_6;

	m_Epsilon = epsilon;
	m_Solve = BandedMatrixSolveFlags::Unsolved;
}

template <typename Real>
Real Mathematics::BandedMatrixSolve<Real>
	::GetEpsilon() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_6;

	return m_Epsilon;
}

template <typename Real>
void Mathematics::BandedMatrixSolve<Real>
	::ResetSize(int size, int lowerBandsNumber,int upperBandsNumber,const Real epsilon)
{
	MATHEMATICS_CLASS_IS_VALID_6;

	m_Input.ResetSize(size, lowerBandsNumber, upperBandsNumber);
	m_Cholesky.ResetSize(size, lowerBandsNumber, upperBandsNumber);
	m_Solve = BandedMatrixSolveFlags::Unsolved;
	m_Epsilon = epsilon;	
}

template <typename Real>
Real* Mathematics::BandedMatrixSolve<Real>
	::GetDiagonalBand()
{
	MATHEMATICS_CLASS_IS_VALID_6;

	m_Solve = BandedMatrixSolveFlags::Unsolved;

	return NON_CONST_MEMBER_CALL_CONST_MEMBER(Real*, GetDiagonalBand);
}

template <typename Real>
const Real* Mathematics::BandedMatrixSolve<Real>
	::GetDiagonalBand() const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_6;

	return m_Input.GetDiagonalBand();
}

template <typename Real>
int Mathematics::BandedMatrixSolve<Real>
	::GetLowerBandMax( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_6;

	return m_Input.GetLowerBandMax(index);
}

template <typename Real>
Real* Mathematics::BandedMatrixSolve<Real>
	::GetLowerBand( int index )
{
	MATHEMATICS_CLASS_IS_VALID_6;

	m_Solve = BandedMatrixSolveFlags::Unsolved;

	return  const_cast<Real*>(static_cast<const ClassType&>(*this).GetLowerBand(index));
}

template <typename Real>
const Real* Mathematics::BandedMatrixSolve<Real>
	::GetLowerBand( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_6;

	return m_Input.GetLowerBand(index);
}

template <typename Real>
int Mathematics::BandedMatrixSolve<Real>
	::GetUpperBandMax( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_6;

	return m_Input.GetUpperBandMax(index);
}

template <typename Real>
Real* Mathematics::BandedMatrixSolve<Real>
	::GetUpperBand( int index )
{
	MATHEMATICS_CLASS_IS_VALID_6;
	
	m_Solve = BandedMatrixSolveFlags::Unsolved;

	return  const_cast<Real*>(static_cast<const ClassType&>(*this).GetUpperBand(index));
}

template <typename Real>
const Real* Mathematics::BandedMatrixSolve<Real>
	::GetUpperBand( int index ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_6;

	return m_Input.GetUpperBand(index);
}

template <typename Real>
Real& Mathematics::BandedMatrixSolve<Real>
	::operator()( int row, int column )
{
	MATHEMATICS_CLASS_IS_VALID_6;

	m_Solve = BandedMatrixSolveFlags::Unsolved;

	return  const_cast<Real&>(static_cast<const ClassType&>(*this)(row,column));
}

template <typename Real>
const Real& Mathematics::BandedMatrixSolve<Real>
	::operator()( int row, int column ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_6;

	return m_Input(row,column);
}

template <typename Real>
void Mathematics::BandedMatrixSolve<Real>
	::SetZero()
{
	MATHEMATICS_CLASS_IS_VALID_6;

	m_Solve = BandedMatrixSolveFlags::Unsolved;

	m_Input.SetZero();
}

template <typename Real>
void Mathematics::BandedMatrixSolve<Real>
	::SetIdentity()
{
	MATHEMATICS_CLASS_IS_VALID_6;

	m_Solve = BandedMatrixSolveFlags::Unsolved;

	m_Input.SetIdentity();
}

template <typename Real>
typename const Mathematics::BandedMatrixSolve<Real>::VariableMatrix Mathematics::BandedMatrixSolve<Real>
	::ToInputVariableMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_6;

	return m_Input.ToVariableMatrix();
}

template <typename Real>
typename const Mathematics::BandedMatrixSolve<Real>::VariableMatrix Mathematics::BandedMatrixSolve<Real>
	::ToCholeskyVariableMatrix() const
{
	MATHEMATICS_CLASS_IS_VALID_6;

	return m_Cholesky.ToVariableMatrix();
}

template <typename Real>
bool Mathematics::BandedMatrixSolve<Real>
	::CholeskyFactor()
{
	MATHEMATICS_CLASS_IS_VALID_6;
	MATHEMATICS_ASSERTION_1(m_Input.GetLowerBandsNumber() == m_Input.GetUpperBandsNumber(),"Bands 必须相等在 CholeskyFactor\n");
    
	if(m_Solve == BandedMatrixSolveFlags::Unsolved)
	{
		m_Cholesky = m_Input;
		auto size = GetSize();
		auto sizeMinusOne = size - 1;
		auto lowerBandsNumber = GetLowerBandsNumber();

		for (auto index = 0; index < size; ++index)
		{
			// 每次开始遍历的最小列数。（至少从0开始）
			auto minColumn = index - lowerBandsNumber;
			if (minColumn < 0)
			{
				minColumn = 0;
			}

			// 从最小列数遍历到索引数
			for (auto column = minColumn; column < index; ++column)
			{
				auto maxColumn = column + lowerBandsNumber;
				if (sizeMinusOne < maxColumn)
				{
					maxColumn = sizeMinusOne;
				}

				for (auto k = index; k <= maxColumn; ++k)
				{
					m_Cholesky(k,index) -= m_Cholesky(index,column) *  m_Cholesky(k,column);
				}
			}

			// 遍历到的最大列数，（至多为总大小减1）
			auto maxColumn = index + lowerBandsNumber;
			if (sizeMinusOne < maxColumn)
			{
				maxColumn = sizeMinusOne;
			}

			// 将下三角矩阵的值复制到上三角矩阵
			for (auto k = 0; k < index; ++k)
			{
				m_Cholesky(k,index) = m_Cholesky(index,k);			
			}

			auto diagonal = m_Cholesky(index,index);
			if (diagonal <= Real{})
			{
				m_Solve = BandedMatrixSolveFlags::Failure;	

				return false;
			}

			auto invSqrt = Math::InvSqrt(diagonal);
			for (auto k = index; k <= maxColumn; ++k)
			{
				m_Cholesky(k,index) *= invSqrt;		
			}		
		}

		m_Solve = BandedMatrixSolveFlags::Succeed;
	}	

	return true;
}

template <typename Real>
typename const Mathematics::BandedMatrixSolve<Real>::VariableLengthVector Mathematics::BandedMatrixSolve<Real>
	::SolveSystem( const VariableLengthVector& vector )
{
	MATHEMATICS_CLASS_IS_VALID_6;
	MATHEMATICS_ASSERTION_1(vector.GetSize() == GetSize(),"矩阵和向量大小不相等");

	if(!CholeskyFactor())
	{
	     THROW_EXCEPTION(SYSTEM_TEXT("因子分解失败在SolveSystem！"));
	}
	
	auto solveLowerVector = SolveLower(vector);

	return SolveUpper(solveLowerVector);
}


template <typename Real>
typename const Mathematics::BandedMatrixSolve<Real>::VariableLengthVector Mathematics::BandedMatrixSolve<Real>
	::SolveLower( const VariableLengthVector& dataVector ) const
{
	VariableLengthVector result{ dataVector };

	auto size = GetSize();

	for (auto row = 0; row < size; ++row)
	{
		auto lowerRR = m_Cholesky(row,row);
		if (Math::FAbs(lowerRR) < m_Epsilon)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("因子分解失败在SolveLower！"));
		}

		for (auto column = 0; column < row; ++column)
		{
			auto lowerRC = m_Cholesky(row,column);
			result[row] -= lowerRC * result[column];
		}

		result[row] /= lowerRR;
	}

	return result;
}


template <typename Real>
typename const Mathematics::BandedMatrixSolve<Real>::VariableLengthVector Mathematics::BandedMatrixSolve<Real>
	::SolveUpper( const VariableLengthVector& dataVector ) const
{
	VariableLengthVector result{ dataVector };

	auto size = GetSize();

	for (auto row = size - 1; 0 <= row; --row)
	{
		auto upperRR = m_Cholesky(row,row);
		if (Math::FAbs(upperRR) < m_Epsilon)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("因子分解失败在SolveUpper！"));
		}

		for (auto column = row + 1; column < size; ++column)
		{
			auto upperRC = m_Cholesky(row,column);
			result[row] -= upperRC * result[column];
		}

		result[row] /= upperRR;
	}

	return result;
}


template <typename Real>
typename const Mathematics::BandedMatrixSolve<Real>::VariableMatrix Mathematics::BandedMatrixSolve<Real>
	::SolveSystem( const VariableMatrix& matrix )
{
	MATHEMATICS_CLASS_IS_VALID_6;
	MATHEMATICS_ASSERTION_1(matrix.GetColumnsNumber() == GetSize() && matrix.GetRowsNumber() == GetSize(),"矩阵大小不相等");

	if(!CholeskyFactor())
	{
	     THROW_EXCEPTION(SYSTEM_TEXT("因子分解失败在SolveSystem！"));
	}

	auto solveLowerMatrix = SolveLower(matrix);

	return SolveUpper(solveLowerMatrix);
}

template <typename Real>
typename const Mathematics::BandedMatrixSolve<Real>::VariableMatrix Mathematics::BandedMatrixSolve<Real>
	::SolveLower( const VariableMatrix& dataMatrix ) const
{
	VariableMatrix result{ dataMatrix };

	auto size = GetSize();

	for (auto row = 0; row < size; ++row)
	{
		auto lowerRR = m_Cholesky(row,row);
		if (Math::FAbs(lowerRR) < m_Epsilon)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("因子分解失败在SolveLower！"));
		}

		for (auto column = 0; column < row; ++column)
		{
			auto lowerRC = m_Cholesky(row,column);
			for (auto bCol = 0; bCol < result.GetColumnsNumber(); ++bCol)
			{
				result[row][bCol] -= lowerRC * result[column][bCol];
			}
		}

		auto inverse = AlgebraTraits::UnitValue / lowerRR;
		for (auto bCol = 0; bCol < result.GetColumnsNumber(); ++bCol)
		{
			result[row][bCol] *= inverse;
		}
	}

	return result;
}


template <typename Real>
typename const Mathematics::BandedMatrixSolve<Real>::VariableMatrix Mathematics::BandedMatrixSolve<Real>
	::SolveUpper( const VariableMatrix& dataMatrix ) const
{
	VariableMatrix result{ dataMatrix };

	for (auto row = GetSize() - 1;0 <= row; --row)
	{
		auto upperRR = m_Cholesky(row,row);
		if (Math::FAbs(upperRR) < m_Epsilon)
		{
			THROW_EXCEPTION(SYSTEM_TEXT("因子分解失败在SolveUpper！"));
		}

		for (auto column = row + 1; column < GetSize(); ++column)
		{
			auto upperRC = m_Cholesky(row,column);
			for (auto bCol = 0; bCol < dataMatrix.GetColumnsNumber(); ++bCol)
			{
				result[row][bCol] -= upperRC * result[column][bCol];
			}
		}

		auto inverse = AlgebraTraits::UnitValue / upperRR;
		for (auto bCol = 0; bCol < result.GetColumnsNumber(); ++bCol)
		{
			result[row][bCol] *= inverse;
		}
	}

	return result;
}

#endif // MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_DETAIL_H

