// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/09 17:07)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_DETAIL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_DETAIL_H

#include "LinearSystem.h"
#include "SolveBandedDetail.h"
#include "LinearSystemInverseDetail.h"
#include "BandedMatrixInvertDetail.h"
#include "SolveSymmetricConjugateGradientDetail.h"
#include "Mathematics/Base/MathDetail.h"
#include "Mathematics/Algebra/VariableMatrixDetail.h"
#include "CoreTools/Helper/ExceptionMacro.h"
#include "CoreTools/Helper/Assertion/MathematicsCustomAssertMacro.h"
#include "CoreTools/Helper/ClassInvariant/MathematicsClassInvariantMacro.h"
#include "System/Helper/UnicodeUsing.h"

template <typename Real>
Mathematics::LinearSystem<Real>
	::LinearSystem (Real zeroTolerance)
	:m_ZeroTolerance{ zeroTolerance }
{
	MATHEMATICS_SELF_CLASS_IS_VALID_1;
}

#ifdef OPEN_CLASS_INVARIANT
template <typename Real>
bool Mathematics::LinearSystem<Real>
	::IsValid() const noexcept
{
	if (Real{} <= m_ZeroTolerance)
        return true;
    else
        return false;
}
#endif // OPEN_CLASS_INVARIANT

template <typename Real>
void Mathematics::LinearSystem<Real>
	::SetZeroTolerance(Real zeroTolerance)
{
    MATHEMATICS_CLASS_IS_VALID_1;
    
    m_ZeroTolerance = zeroTolerance;
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::Solve2( const Real matrix[2][2],const Real* inputVector,Real* outputVector ) const
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(matrix != nullptr,"matrix指针为空！");
	MATHEMATICS_ASSERTION_0(matrix[0] != nullptr, "matrix指针为空！");
	MATHEMATICS_ASSERTION_0(matrix[1] != nullptr, "matrix指针为空！");
	MATHEMATICS_ASSERTION_0(inputVector != nullptr,"inputVector指针为空！");
	MATHEMATICS_ASSERTION_0(outputVector != nullptr,"outputVector指针为空！");

	auto det = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

	if (Math<Real>::FAbs(det) <= m_ZeroTolerance)
	{
		THROW_EXCEPTION(SYSTEM_TEXT("Solve2 失败！det为0。"));
	}

	outputVector[0] = (matrix[1][1] * inputVector[0] - matrix[0][1] * inputVector[1]) / det;
	outputVector[1] = (matrix[0][0] * inputVector[1] - matrix[1][0] * inputVector[0]) / det;
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::Solve3(const Real matrix[3][3], const Real* inputVector,  Real* outputVector) const 
{
	MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(matrix != nullptr,"matrix指针为空！");
	MATHEMATICS_ASSERTION_0(matrix[0] != nullptr, "matrix指针为空！");
	MATHEMATICS_ASSERTION_0(matrix[1] != nullptr, "matrix指针为空！");
	MATHEMATICS_ASSERTION_0(matrix[2] != nullptr, "matrix指针为空！");
	MATHEMATICS_ASSERTION_0(inputVector != nullptr,"inputVector指针为空！");
	MATHEMATICS_ASSERTION_0(outputVector != nullptr,"outputVector指针为空！");

	Real invMatrix[3][3];
    invMatrix[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
    invMatrix[0][1] = matrix[0][2] * matrix[2][1] - matrix[0][1] * matrix[2][2];
    invMatrix[0][2] = matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1];
    invMatrix[1][0] = matrix[1][2] * matrix[2][0] - matrix[1][0] * matrix[2][2];
    invMatrix[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
    invMatrix[1][2] = matrix[0][2] * matrix[1][0] - matrix[0][0] * matrix[1][2];
    invMatrix[2][0] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
    invMatrix[2][1] = matrix[0][1] * matrix[2][0] - matrix[0][0] * matrix[2][1];
    invMatrix[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
	auto det = matrix[0][0] * invMatrix[0][0] + matrix[0][1] * invMatrix[1][0] + matrix[0][2] * invMatrix[2][0];
    
    if (Math<Real>::FAbs(det) <= m_ZeroTolerance)
    {
		THROW_EXCEPTION(SYSTEM_TEXT("Solve3 失败！det为0。"));
    }    
 
    for (auto row = 0; row < 3; ++row)
    {
        for (auto col = 0; col < 3; ++col)
        {
            invMatrix[row][col] /= det;
        }
    }
    
	outputVector[0] = invMatrix[0][0] * inputVector[0] + invMatrix[0][1] * inputVector[1] + invMatrix[0][2] * inputVector[2];
	outputVector[1] = invMatrix[1][0] * inputVector[0] + invMatrix[1][1] * inputVector[1] + invMatrix[1][2] * inputVector[2];
	outputVector[2] = invMatrix[2][0] * inputVector[0] + invMatrix[2][1] * inputVector[1] + invMatrix[2][2] * inputVector[2];    
} 

template <typename Real>
typename const Mathematics::LinearSystem<Real>::VariableMatrixType	Mathematics::LinearSystem<Real>
	::Inverse (const VariableMatrixType& matrix) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1; 
    MATHEMATICS_ASSERTION_1(matrix.GetRowsNumber() == matrix.GetColumnsNumber(),"矩阵必须是方阵\n");
    
	LinearSystemInverse<Real> inverse{ matrix, m_ZeroTolerance };
   
	return inverse.GetInverse();
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::Solve(const VariableMatrixType& matrix, const Real* inputVector,Real* outputVector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(inputVector != nullptr, "inputVector指针为空！");
	MATHEMATICS_ASSERTION_0(outputVector != nullptr, "outputVector指针为空！");

	LinearSystemInverse<Real> inverse{ matrix, m_ZeroTolerance, inputVector };

	int index{ 0 };
	for (auto iter = inverse.GetBegin(),  end = inverse.GetEnd(); iter != end; ++iter)
	{
		outputVector[index] = *iter;
		++index;
	}
    
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::SolveTridiagonal (int size, const Real* lower,const Real* main1,const Real* upper,const Real* right, Real* output) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;    
	MATHEMATICS_ASSERTION_0(0 < size, "传入的大小为零或负数！");
	MATHEMATICS_ASSERTION_0(lower != nullptr, "lower指针为空！");
	MATHEMATICS_ASSERTION_0(main1 != nullptr, "main指针为空！");
	MATHEMATICS_ASSERTION_0(upper != nullptr, "upper指针为空！");
	MATHEMATICS_ASSERTION_0(right != nullptr, "right指针为空！");
	MATHEMATICS_ASSERTION_0(output != nullptr, "output指针为空！");
    
	if (Math<Real>::FAbs(main1[0]) <= m_ZeroTolerance)
    {
        THROW_EXCEPTION(SYSTEM_TEXT("求解失败！"));
    }
      
	RealVector upperAmend(size - 1);
    
	auto mainAmend = main1[0];
 
    output[0] = right[0] / mainAmend;
    
    for (auto i = 0; i < size - 1; ++i)
    {
        upperAmend[i] = upper[i] / mainAmend;
		mainAmend = main1[i + 1] - lower[i] * upperAmend[i];
		if (Math<Real>::FAbs(mainAmend) <= m_ZeroTolerance)
        {
			THROW_EXCEPTION(SYSTEM_TEXT("求解失败！"));
        }
       
        output[i + 1] = (right[i + 1] - lower[i] * output[i]) / mainAmend;
    }
    
    for (auto i = size - 1; 1 <= i; --i)
    {
        output[i - 1] -= upperAmend[i - 1] * output[i];
    }  
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::SolveConstTridiagonal(int size,Real lower, Real main1, Real upper, const Real* right, Real* output) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(right != nullptr, "right指针为空！");
	MATHEMATICS_ASSERTION_0(output != nullptr, "output指针为空！");
    
	if (Math<Real>::FAbs(main1) <= m_ZeroTolerance)
    {
		THROW_EXCEPTION(SYSTEM_TEXT("求解失败！"));
    }
     
	RealVector upperAmend(size - 1);
	auto mainAmend = main1;

    output[0] = right[0] / mainAmend;
    
    for (auto i = 0; i < size - 1; ++i)
    {
        upperAmend[i] = upper / mainAmend;
		mainAmend = main1 - lower * upperAmend[i];
		if (Math<Real>::FAbs(mainAmend) <= m_ZeroTolerance)
        {
			THROW_EXCEPTION(SYSTEM_TEXT("求解失败！"));
        }
       
        output[i + 1] = (right[i + 1] - lower * output[i]) / mainAmend;
    }
    
    for (auto i = size - 1; 1 <= i; --i)
    {
        output[i - 1] -= upperAmend[i - 1] * output[i];
    }    
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::SolveSymmetricConjugateGradient (const VariableMatrixType& matrix, const Real* inputVector, Real* outputVector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
	MATHEMATICS_ASSERTION_0(inputVector != nullptr, "inputVector指针为空！");
	MATHEMATICS_ASSERTION_0(outputVector != nullptr, "outputVector指针为空！");
    
    // 基于由Golum和Van Loan的“矩阵计算”算法。
    MATHEMATICS_ASSERTION_1(matrix.GetRowsNumber() == matrix.GetColumnsNumber(), "矩阵必须是方阵\n");
    
	Mathematics::SolveSymmetricConjugateGradient<Real, VariableMatrix> solve{ matrix,inputVector,m_ZeroTolerance };

	auto index = 0;
	for (auto iter = solve.GetBegin(), end = solve.GetEnd(); iter != end; ++iter)
	{
		outputVector[index] = *iter;
		++index;
	}
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::SolveSymmetricConjugateGradient(const SparseMatrixType& matrix, const Real* inputVector, Real* outputVector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
    // 基于由Golum和Van Loan的“矩阵计算”算法。
	MATHEMATICS_ASSERTION_1(matrix.GetRowsNumber() == matrix.GetColumnsNumber(), "矩阵必须是方阵\n");
    
	Mathematics::SolveSymmetricConjugateGradient<Real, SparseMatrix> solve{ matrix,inputVector,m_ZeroTolerance };

	auto index = 0;
	for (auto iter = solve.GetBegin(), end = solve.GetEnd(); iter != end; ++iter)
	{
		outputVector[index] = *iter;
		++index;
	}	
}

template <typename Real>
void Mathematics::LinearSystem<Real>
	::SolveBanded (const BandedMatrix& matrix, const Real* inputVector, Real* outputVector) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
	Mathematics::SolveBanded<Real>	solve{ matrix, inputVector, m_ZeroTolerance };

	int index{ 0 };
	for (auto iter = solve.GetBegin(), end = solve.GetEnd(); iter != end; ++iter)
	{
		outputVector[index] = *iter;
		++index;
	}
}

template <typename Real>
typename const Mathematics::LinearSystem<Real>::VariableMatrixType Mathematics::LinearSystem<Real>
	::Invert (const BandedMatrix& matrix) const
{
    MATHEMATICS_CLASS_IS_VALID_CONST_1;
    
	Mathematics::BandedMatrixInvert<Real> invert{ matrix, m_ZeroTolerance };

	return invert.GetInvert();
}
 
#endif // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_DETAIL_H
 