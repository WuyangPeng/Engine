///	Copyright (c) 2011-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.4 (2020/11/24 12:56)

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
        // һ������ϵͳ�ľ�������ǶԳƵġ�
        explicit EigenDecompositionImpl(int size);
        explicit EigenDecompositionImpl(const Matrix2& rhs);
        explicit EigenDecompositionImpl(const Matrix3& rhs);
        explicit EigenDecompositionImpl(const VariableMatrix& rhs);

        EigenDecompositionImpl& operator=(const Matrix2& rhs);
        EigenDecompositionImpl& operator=(const Matrix3& rhs);
        EigenDecompositionImpl& operator=(const VariableMatrix& rhs);

        CLASS_INVARIANT_DECLARE;

        [[nodiscard]] int GetSize() const noexcept;

        // ��������ϵͳ�ľ���
        [[nodiscard]] const Real& operator()(int row, int column) const;
        [[nodiscard]] Real& operator()(int row, int column);

        // ���������ϵͳ��
        // ������Ҫ������ֵ�ڵ���˳���������
        // ���á�increasingSort'Ϊ'true'��
        // ��������ֵ�Եݼ�˳���������
        void Solve(bool increasingSort);

        // �õ�����������֪������ϵͳ����Ӧ�ߴ�Ӧ�õ���
        // GetEigenvector2��GetEigenvector3��
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

        // ������ٵ����ԽǾ�����ʽ
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

        // QL�㷨������ת������������������ԽǾ���
        void QLAlgorithm();
        void QLAlgorithm(int index);
        [[nodiscard]] int QLAlgorithmWithLoopTime(int totalIndex);
        [[nodiscard]] bool IsQLAlgorithmQuit(int outerIndex) const noexcept;
        void QLAlgorithmLoop(int totalIndex, int outerIndex);
        void QLAlgorithmAmendSolveMatrix(int innerIndex, Real sine, Real cosine);
        [[nodiscard]] Real GetQLAlgorithmSubdiagonalValue(int totalIndex, int outerIndex) const noexcept(g_Assert < 3 || g_MathematicsAssert < 3);

        // ��������ֵ�������С��
        void DecreasingSort();

        // ��������ֵ����С�����
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
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_IMPL_H
