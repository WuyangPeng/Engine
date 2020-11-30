///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	作者：彭武阳，彭晔恩，彭晔泽
///	联系作者：94458936@qq.com
///
///	标准：std:c++17
///	引擎版本：0.5.2.4 (2020/11/24 12:56)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_IMPL_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_IMPL_H

#include "Mathematics/MathematicsDll.h"

#include "Mathematics/Algebra/Matrix2.h"
#include "Mathematics/Algebra/Matrix3.h"
#include "Mathematics/Algebra/VariableLengthVector.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Algebra/Vector2D.h"
#include "Mathematics/Algebra/Vector3D.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_HIDDEN_DECLARE EigenDecompositionImpl final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = EigenDecompositionImpl<Real>;
        using Math = Math<Real>;
        using Matrix2 = Matrix2<Real>;
        using Matrix3 = Matrix3<Real>;
        using Vector2D = Vector2D<Real>;
        using Vector3D = Vector3D<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;

    public:
        // 一个特征系统的矩阵必须是对称的。
        explicit EigenDecompositionImpl(int size);
        explicit EigenDecompositionImpl(const Matrix2& rhs);
        explicit EigenDecompositionImpl(const Matrix3& rhs);
        explicit EigenDecompositionImpl(const VariableMatrix& rhs);

        EigenDecompositionImpl& operator=(const Matrix2& rhs);
        EigenDecompositionImpl& operator=(const Matrix3& rhs);
        EigenDecompositionImpl& operator=(const VariableMatrix& rhs);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetSize() const noexcept;

        // 设置特征系统的矩阵。
        [[nodiscard]] const Real& operator()(int row, int column) const;
        [[nodiscard]] Real& operator()(int row, int column);

        // 解这个特征系统。
        // 当你想要的特征值在递增顺序进行排序，
        // 设置“increasingSort'为'true'，
        // 否则，特征值以递减顺序进行排序。
        void Solve(bool increasingSort);

        // 得到结果。如果你知道特征系统的相应尺寸应该调用
        // GetEigenvector2和GetEigenvector3。
        [[nodiscard]] Real GetEigenvalue(int index) const;
        [[nodiscard]] const Vector2D GetEigenvector2(int index) const;
        [[nodiscard]] const Matrix2 GetEigenvectors2() const;
        [[nodiscard]] const Vector3D GetEigenvector3(int index) const;
        [[nodiscard]] const Matrix3 GetEigenvectors3() const;
        [[nodiscard]] const VariableLengthVector GetEigenvector(int index) const;
        [[nodiscard]] const VariableMatrix GetEigenvectors() const;

    private:
        void Swap(EigenDecompositionImpl& rhs) noexcept;

        void GuaranteeRotation();

        // 矩阵减少到三对角矩阵形式
        void Tridiagonal2();
        void Tridiagonal3();
        void TridiagonalN();

        void Step1();
        void Step2();
        void Step3() noexcept;
        void TridiagonalNInLoop(int index);
        [[nodiscard]] Real GetScale(int index) const;
        void CalculateDiagonal(int index, Real scale);
        void CalculateSubdiagonal(int index);

        // QL算法隐含的转换。这个函数调用三对角矩阵。
        void QLAlgorithm();
        void QLAlgorithm(int index);
        [[nodiscard]] int QLAlgorithmWithLoopTime(int totalIndex);
        [[nodiscard]] bool IsQLAlgorithmQuit(int outerIndex) const noexcept;
        void QLAlgorithmLoop(int totalIndex, int outerIndex);
        void QLAlgorithmAmendSolveMatrix(int innerIndex, Real sine, Real cosine);
        [[nodiscard]] Real GetQLAlgorithmSubdiagonalValue(int totalIndex, int outerIndex) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // 排序特征值从最大到最小。
        void DecreasingSort();

        // 排序特征值从最小到最大。
        void IncreasingSort();

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

        // 奇数大小的矩阵，Householder矩阵减少奇数涉及反射。
        // 这些乘积是一个反射。
        // QL算法用来进一步降低旋转。
        // 最后的正交矩阵，其列是特征向量的一种体现，所以它的行列式是-1。
        // 对于偶数大小矩阵，Householder矩阵减少偶数涉及反射。
        // 这些乘积是一个旋转。
        // 最后的正交矩阵的行列式是+1。
        // 这需要一个很多特征分解算法想要一个旋转矩阵。
        // 我们要保证是这种情况，那么m_Rotation会自动跟踪。
        // DecrSort和IncrSort问题进一步复杂化，因为他们交换了正交矩阵的列，
        // 造成矩阵旋转和反射之间切换。
        // 值m_Rotation必须相应地切换。

        bool m_IsRotation;
        bool m_Solve;
    }; 
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_IMPL_H
