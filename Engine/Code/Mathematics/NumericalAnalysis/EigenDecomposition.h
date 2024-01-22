/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.4 (2024/01/12 13:46)

#ifndef MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_H
#define MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_H

#include "Mathematics/MathematicsDll.h"

#include "CoreTools/Helper/ExportMacro.h"
#include "Mathematics/Algebra/AlgebraFwd.h"
#include "Mathematics/Algebra/VariableMatrix.h"
#include "Mathematics/Base/MathDetail.h"

#include <vector>

namespace Mathematics
{
    template <typename Real>
    class EigenDecomposition final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = EigenDecomposition<Real>;

        using Math = Math<Real>;
        using Matrix2 = Matrix2<Real>;
        using Matrix3 = Matrix3<Real>;
        using Vector2 = Vector2<Real>;
        using Vector3 = Vector3<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;

    public:
        // һ������ϵͳ�ľ�������ǶԳƵġ�
        explicit EigenDecomposition(int size);
        explicit EigenDecomposition(const Matrix2& rhs);
        explicit EigenDecomposition(const Matrix3& rhs);
        explicit EigenDecomposition(const VariableMatrix& rhs);

        EigenDecomposition& operator=(const Matrix2& rhs);
        EigenDecomposition& operator=(const Matrix3& rhs);
        EigenDecomposition& operator=(const VariableMatrix& rhs);

        CLASS_INVARIANT_DECLARE;

        NODISCARD int GetSize() const noexcept;

        // ��������ϵͳ�ľ���
        NODISCARD const Real& operator()(int row, int column) const;
        NODISCARD Real& operator()(int row, int column);

        // ���������ϵͳ��
        // ������Ҫ������ֵ�ڵ���˳���������
        // ���á�increasingSort'Ϊ'true'��
        // ��������ֵ�Եݼ�˳���������
        void Solve(bool increasingSort);

        // �õ�����������֪������ϵͳ����Ӧ�ߴ�Ӧ�õ���
        // GetEigenvector2��GetEigenvector3��
        NODISCARD Real GetEigenvalue(int index) const;
        NODISCARD Vector2 GetEigenvector2(int index) const;
        NODISCARD Matrix2 GetEigenvectors2() const;
        NODISCARD Vector3 GetEigenvector3(int index) const;
        NODISCARD Matrix3 GetEigenvectors3() const;
        NODISCARD VariableLengthVector GetEigenvector(int index) const;
        NODISCARD VariableMatrix GetEigenvectors() const;

    private:
        void Swap(EigenDecomposition& rhs) noexcept;

        void GuaranteeRotation();

        // ������ٵ����ԽǾ�����ʽ
        void Tridiagonal2();
        void Tridiagonal3();
        void TridiagonalN();

        void Step1();
        void Step2();
        void Step3();
        void TridiagonalNInLoop(int index);
        NODISCARD Real GetScale(int index) const;
        void CalculateDiagonal(int index, Real scale);
        void CalculateSubdiagonal(int index);

        // QL�㷨������ת������������������ԽǾ���
        void QLAlgorithm();
        void QLAlgorithm(int index);
        NODISCARD int QLAlgorithmWithLoopTime(int totalIndex);
        NODISCARD bool IsQLAlgorithmQuit(int outerIndex) const;
        void QLAlgorithmLoop(int totalIndex, int outerIndex);
        void QLAlgorithmAmendSolveMatrix(int innerIndex, Real sine, Real cosine);
        NODISCARD Real GetQLAlgorithmSubDiagonalValue(int totalIndex, int outerIndex) const;

        // ��������ֵ�������С��
        void DecreasingSort();

        // ��������ֵ����С�����
        void IncreasingSort();

    private:
        using Diagonal = std::vector<Real>;
        using Subdiagonal = std::vector<Real>;

    private:
        static constexpr auto maxIter = 32;

        int size;
        VariableMatrix matrix;
        VariableMatrix solveMatrix;
        Diagonal diagonal;
        Subdiagonal subdiagonal;

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

        bool isRotation;
        bool solve;
    };

    using EigenDecompositionF = EigenDecomposition<float>;
    using EigenDecompositionD = EigenDecomposition<double>;
}

#endif  // MATHEMATICS_NUMERICAL_ANALYSIS_EIGEN_DECOMPOSITION_H
