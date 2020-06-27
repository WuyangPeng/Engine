// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.2.5 (2020/03/20 12:48)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H

#include "Mathematics/MathematicsDll.h"

#include "SparseMatrix.h"
#include "Mathematics/Base/Math.h"
#include "Mathematics/Algebra/BandedMatrix.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

#include <map>

namespace Mathematics
{
	template <typename Real>
	class LinearSystem
	{
	public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

		using ClassType = LinearSystem<Real>;
		using RealVector = std::vector<Real>;
		using VariableMatrixType = VariableMatrix<Real>;
		using SparseMatrixType = SparseMatrix<Real>;
		using VariableLengthVector = VariableLengthVector<Real>;
		using BandedMatrix = BandedMatrix<Real>;
		using Math = Math<Real>;

	public:
		explicit LinearSystem(Real zeroTolerance = Math::sm_ZeroTolerance);

		CLASS_INVARIANT_DECLARE;

		void SetZeroTolerance(Real zeroTolerance);

		// 2��2��3x3ϵͳ�������˸�˹��Ԫ�Ŀ�����

		// ���뱣֤matrix��СΪ2x2�Ķ�ά���顣
		// inputVector��outputVectorΪ��СΪ2��һά���顣
		void Solve2(const Real matrix[2][2], const Real* inputVector, Real* outputVector) const;

		// ���뱣֤matrix��СΪ3x3�Ķ�ά���顣
		// inputVector��outputVectorΪ��СΪ3��һά���顣
		void Solve3(const Real matrix[3][3], const Real* inputVector, Real* outputVector) const;

		// ����:
		//     matrix[iSize][iSize], ���� matrix[row][col]
		// ���:
		//     �������ʧ���׳��쳣�����򷵻������
		const VariableMatrixType Inverse(const VariableMatrixType& matrix) const;

		// ����:
		//     A[iSize][iSize] ϵ���������� A[row][col]
		//     B[iSize] ����, ���� B[row]
		// ���:
		//     �������ʧ���׳��쳣�����򷵻�X[iSize]��
		//     X[iSize] �ǽ�X �� AX = B

		// ���뱣֤inputVector��outputVector��СΪiSize��һά���顣
		void Solve(const VariableMatrixType& matrix, const Real* inputVector, Real* outputVector) const;

		// ����:
		//     ���������ԽǾ���
		//     �¶Խ��� lower[size - 1]
		//     ���Խ��� main[size]
		//     �϶Խ��� upper[size - 1]
		//     ���ֱ� right[size]
		// ���:
		//     ���ʧ���׳��쳣�����򷵻�U[size]���ǽ⡣

		// ���뱣֤lower��upper��СΪsize - 1��һά���顣
		// main��right��output��СΪsize��һά���顣
		void SolveTridiagonal(int size, const Real* lower, const Real* main1, const Real* upper, const Real* right, Real* output) const;

		// ����:
		//     ���������ԽǾ���
		//     �¶Խ����ǳ���lower
		//     ���Խ����ǳ���main
		//     �϶Խ����ǳ���upper
		//     ���ֱ� right[size]
		// ���:
		//     ���ʧ���׳��쳣�����򷵻�U[size]���ǽ⡣

		// ���뱣֤right��output��СΪsize��һά���顣
		void SolveConstTridiagonal(int size, Real lower, Real main1, Real upper, const Real* right, Real* output) const;

		// ����������ù����ݶȷ���
		// ����:
		//    A[size][size] Symmetrix�������� A[row][col]
		//    B[size] ����, ���� B[row]
		// ���:
		//    X[size] �ǽ� x Ϊ Ax = B

		// ���뱣֤inputVector��outputVectorΪ��СΪsize��һά���顣
		void  SolveSymmetricConjugateGradient(const VariableMatrixType& matrix, const Real* inputVector, Real* outputVector) const;

		// ϡ��Գƾ������ݶȷ���
		// ����:
		// ��Symmetrix����matrix�ķ�����Ŀ�洢��һ��ӳ�䣬�����(i,j)����ֵ��ʵ����
		// һ��(i,j)Ϊ���������е�ֵ��λ�á�
		// ֻ��(i,j) ��(j,i)Ӧ��ţ���Ϊmatrix�ǶԳƵġ�
		// �ô���ٶ���֪����ô����matrix.
		// ��ʸ��vector���洢Ϊ����ֵ�����顣
		// ���:
		//    X[size] �ǽ� x Ϊ Ax = B

		// ���뱣֤inputVector��outputVectorΪ��СΪsize��һά���顣
		void SolveSymmetricConjugateGradient(const SparseMatrixType& matrix, const Real* inputVector, Real* outputVector) const;


		// ����״����ϵͳ��
		// ����:
		//     matrix, һ����״����
		//     vector[size] ����,���� vector[row]
		// ���:
		//     ���ʧ���׳��쳣��
		//     ����X[size] �ǽ� X �� AX = B

		// ���뱣֤inputVector��outputVectorΪ��СΪsize��һά���顣
		void SolveBanded(const BandedMatrix& matrix, const Real* inputVector, Real* outputVector) const;

		// ���״�������
		// ����:
		//     matrix, ��״����
		// ���:
		//     ����ʧ���׳��쳣�����򷵻������   
		const VariableMatrixType Invert(const BandedMatrix& matrix) const;

	private:
		// ����ϵͳ����ݲ
		// Ĭ�� = Math<Real>::sm_ZeroTolerance
		Real m_ZeroTolerance;
	};

	using LinearSystemf = LinearSystem<float>;
	using LinearSystemd = LinearSystem<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_LINEAR_SYSTEM_H
