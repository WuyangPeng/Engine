// Copyright (c) 2011-2019
// Threading Core Render Engine
// ���ߣ������������ʶ���������
// 
// ����汾��0.0.0.2 (2019/07/08 16:29)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/VariableLengthVector.h"

namespace Mathematics
{    
    template <typename Real>
    class SingularValueDecomposition
    {
    public:
		static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = SingularValueDecomposition<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        
    public:    
		// ����ֵ�ֽ⣬M = L * D * Transpose(Real)��
		// ����L��Real��������D�ǶԽǾ�����Խ����ǷǸ�����
		// �۲�MΪm��n�������� m >= nʱ��L��m��m��Real��n��n��D��m��n;
		// ��M��D������ͬ�Ĵ�С������һ�������Ρ�
        explicit SingularValueDecomposition (const VariableMatrix& matrix);
        
        CLASS_INVARIANT_DECLARE;
        
        const VariableMatrix GetLeftMatrix() const;
        const VariableMatrix GetDiagonalMatrix() const;
        const VariableMatrix GetRightTransposeMatrix() const;
        
    private:
        void Calculate(const VariableMatrix& matrix);
        
		// ����VʹV[0] = 1����(I - 2 * V * V^T / V^T * V) * X����һ������ȫ���㡣����V��
        static const VariableLengthVector HouseholderVector (const VariableLengthVector& vector);
		
        // ���� A Ϊ (I - 2 * V * V^T / V^T * V) * A.
        static void HouseholderPremultiply (const VariableLengthVector& vector,VariableMatrix& matrix);
   
        // ���� A Ϊ A * (I - 2 * V * V^T / V^T * V).
        static void HouseholderPostmultiply (const VariableLengthVector& vector,VariableMatrix& matrix);
      
		// ����A = Q * Real��Q��������Real�������ǡ�
        void HouseholderQR ();
        
    private:
        VariableMatrix m_Left;
        VariableMatrix m_Diagonal;
        VariableMatrix m_RightTranspose;
    };
    
    using SingularValueDecompositionf = SingularValueDecomposition<float>;
    using SingularValueDecompositiond = SingularValueDecomposition<double>;
}

#endif // MATHEMATICS_NUMERICAL_ANALYSIS_SINGULAR_VALUE_DECOMPOSITION_H
