// Copyright (c) 2011-2019
// Threading Core Render Engine
// 作者：彭武阳，彭晔恩，彭晔泽
// 
// 引擎版本：0.0.0.2 (2019/07/08 16:29)

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
		// 奇异值分解，M = L * D * Transpose(Real)，
		// 其中L和Real是正交和D是对角矩阵，其对角项是非负数。
		// 观察M为m乘n矩阵，其中 m >= n时，L是m乘m，Real是n乘n和D是m乘n;
		// 即M和D具有相同的大小，但不一定正方形。
        explicit SingularValueDecomposition (const VariableMatrix& matrix);
        
        CLASS_INVARIANT_DECLARE;
        
        const VariableMatrix GetLeftMatrix() const;
        const VariableMatrix GetDiagonalMatrix() const;
        const VariableMatrix GetRightTransposeMatrix() const;
        
    private:
        void Calculate(const VariableMatrix& matrix);
        
		// 计算V使V[0] = 1，和(I - 2 * V * V^T / V^T * V) * X除第一部分外全是零。返回V。
        static const VariableLengthVector HouseholderVector (const VariableLengthVector& vector);
		
        // 覆盖 A 为 (I - 2 * V * V^T / V^T * V) * A.
        static void HouseholderPremultiply (const VariableLengthVector& vector,VariableMatrix& matrix);
   
        // 覆盖 A 为 A * (I - 2 * V * V^T / V^T * V).
        static void HouseholderPostmultiply (const VariableLengthVector& vector,VariableMatrix& matrix);
      
		// 因子A = Q * Real，Q是正交和Real是上三角。
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
