// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 15:48)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector3D.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class EigenDecomposition
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = EigenDecomposition<Real>;
        using Matrix2 = Matrix2<Real>;
        using Matrix3 = Matrix3<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector3D = Vector3D<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        
    public:
        // һ������ϵͳ�ľ�������ǶԳƵġ�
        explicit EigenDecomposition (int size);
        explicit EigenDecomposition (const Matrix2& rhs);
        explicit EigenDecomposition (const Matrix3& rhs);
        explicit EigenDecomposition (const VariableMatrix& rhs);
        EigenDecomposition (const EigenDecomposition& rhs);
        ~EigenDecomposition ();
   
        EigenDecomposition& operator= (const Matrix2& rhs);
        EigenDecomposition& operator= (const Matrix3& rhs);
        EigenDecomposition& operator= (const VariableMatrix& rhs);
        EigenDecomposition& operator= (const EigenDecomposition& rhs);
        
		CLASS_INVARIANT_DECLARE;

		int GetSize() const;
        
        // ��������ϵͳ�ľ���
		const Real& operator() (int row, int column) const;
        Real& operator() (int row, int column);

        // ���������ϵͳ��
        // ������Ҫ������ֵ�ڵ���˳���������
		// ���á�increasingSort'Ϊ'true'��
        // ��������ֵ�Եݼ�˳���������
        void Solve (bool increasingSort);
  
        // �õ�����������֪������ϵͳ����Ӧ�ߴ�Ӧ�õ���
        // GetEigenvector2��GetEigenvector3��
        Real GetEigenvalue (int index) const;
        const Vector2D GetEigenvector2 (int index) const;
        const Matrix2 GetEigenvectors2 () const;
        const Vector3D GetEigenvector3 (int index) const;
        const Matrix3 GetEigenvectors3 () const;
        const VariableLengthVector GetEigenvector (int index) const;
        const VariableMatrix GetEigenvectors () const;

    private:
        void Swap(EigenDecomposition& rhs);
        
        void GuaranteeRotation ();
        
        // ������ٵ����ԽǾ�����ʽ
        void Tridiagonal2 ();
        void Tridiagonal3 ();
        void TridiagonalN ();

		void FirstStep();
		void SecondStep();
		void ThirdStep();
		void TridiagonalNInLoop(int index);
		Real GetScale(int index) const;
		void CalculateDiagonal(int index, Real scale);
		void CalculateSubdiagonal(int index);

        // QL�㷨������ת������������������ԽǾ���
        void QLAlgorithm ();
		void QLAlgorithm(int index);
		int QLAlgorithmWithLoopTime(int totalIndex);
		bool IsQLAlgorithmQuit(int outerIndex) const;
		void QLAlgorithmLoop(int totalIndex, int outerIndex);
		void QLAlgorithmAmendSolveMatrix(int innerIndex, Real sine, Real cosine);
		Real GetQLAlgorithmSubdiagonalValue(int totalIndex, int outerIndex) const;

        // ��������ֵ�������С��
        void DecreasingSort ();
        
        // ��������ֵ����С�����
        void IncreasingSort ();

	private:
		using Diagonal = std::vector<Real>;
		using Subdiagonal = std::vector<Real>;
        
    private:      
		static constexpr auto sm_MaxIter = 32;

        int m_Size;
        VariableMatrix m_Matrix;
		VariableMatrix m_SolveMatrix;
		Diagonal m_Diagonal;
		Subdiagonal m_Subdiagonal;

		// ������С�ľ���Householder������������漰���䡣
		// ��Щ�˻���һ�����䡣
		// QL�㷨������һ��������ת��
		// ����������������������������һ�����֣�������������ʽ��-1��
		// ����ż����С����Householder�������ż���漰���䡣
		// ��Щ�˻���һ����ת��	
		// �����������������ʽ��+1��
		// ����Ҫһ���ܶ������ֽ��㷨��Ҫһ����ת����
		// ����Ҫ��֤�������������ôm_Rotation���Զ����١�
		// DecrSort��IncrSort�����һ�����ӻ�����Ϊ���ǽ���������������У�
		// ��ɾ�����ת�ͷ���֮���л���
		// ֵm_Rotation������Ӧ���л���  
  
        bool m_IsRotation;
        bool m_Solve;
    };

    using EigenDecompositionf = EigenDecomposition<float>;
    using EigenDecompositiond = EigenDecomposition<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_H
