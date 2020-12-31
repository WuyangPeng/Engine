///	Copyright (c) 2010-2020
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.5.2.2 (2020/11/05 15:27)

/// ��ν�Ĵ�״���󼴣��ھ���A�У�
/// ���еķ���Ԫ�ض������������Խ���Ϊ���ĵĴ�״�����С�
/// �� a11 a12 0   0   0   0
///    a21 a22 a23 0   0   0
///    a31 a32 a33 a34 0   0
///    0   a42 a43 a44 a45 0
///    0   0   a53 a54 a55 a56
///    0   0   0   a64 a65 a66
#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "BandedMatrix.h"

#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BandedMatrixSolve final
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BandedMatrixSolve<Real>;
        using Math = Math<Real>;
        using BandedMatrix = BandedMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using ContainerType = std::vector<Real>;

    public:
        BandedMatrixSolve(int size, int lowerBandsNumber, int upperBandsNumber, const Real epsilon = Math::GetZeroTolerance());

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_DECLARE;
        [[nodiscard]] bool IsSolveValid() const;
        [[nodiscard]] Real GetProduct(const BandedMatrix& upperBandedMatrix, const BandedMatrix& lowerBandedMatrix, int row, int column) const;
#endif  // OPEN_CLASS_INVARIANT

        // ��Ա����
        [[nodiscard]] int GetSize() const;
        [[nodiscard]] int GetLowerBandsNumber() const;
        [[nodiscard]] int GetUpperBandsNumber() const;
        [[nodiscard]] int GetStreamSize() const;
        [[nodiscard]] BandedMatrixSolveFlags GetSolve() const noexcept;
        void SetEpsilon(Real epsilon) noexcept;
        [[nodiscard]] Real GetEpsilon() const noexcept;

        // �����С�����ԭ�����ݡ�
        void ResetSize(int size, int lowerBandsNumber, int upperBandsNumber, const Real epsilon = Math::GetZeroTolerance());

        // �Խ���
        [[nodiscard]] ContainerType GetDiagonalBand() const;
        void SetDiagonalBand(const ContainerType& diagonalBand);

        // ������
        // GetLowerBand(index):  0 <= index < LowerBandMax
        [[nodiscard]] int GetLowerBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] ContainerType GetLowerBand(int index) const;
        void SetLowerBand(int index, const ContainerType& lowerBand);

        // ������
        // GetUupperBand(index):  0 <= index < UpperBandMax
        [[nodiscard]] int GetUpperBandMax(int index) const noexcept(g_Assert < 1 || g_MathematicsAssert < 1);
        [[nodiscard]] ContainerType GetUpperBand(int index) const;
        void SetUpperBand(int index, const ContainerType& upperBand);

        [[nodiscard]] Real& operator()(int row, int column);
        [[nodiscard]] const Real& operator()(int row, int column) const;

        // �����������ڳ�ʼ������
        void SetZero();
        void SetIdentity();

        /// ����״�����ϵ��AΪA = L * L^T������L�������Ǿ���L^T��һ�������Ǿ��󣩡�
        /// ����һ��LU�ֽ⣬����A���ȶ����������A * X = B��
        /// �����ӷֽ���ʧ��ʱ������false����L�ǲ�����ģ���
        /// ����ɹ�������Cholesky�ֽ⡣��L��A�������ǲ��ֺ�L^ T��A�������ǲ��֣�
        [[nodiscard]] bool CholeskyFactor();

        /// �������ϵͳA * X = B������A��һ��NxN�Ĵ�״����B��һ��Nx1��ʸ����δ֪��X��Ҳ��Nx1��
        /// ����������vector��B��X�����㲢�����ء�
        /// ���ҽ�����һ���������ʱ������ֵ����Ч�ģ�������׳��쳣��
        /// ����ɹ�������Cholesky�ֽ⡣��L��A�������ǲ��ֺ�L^ T��A�������ǲ��֣�
        [[nodiscard]] const VariableLengthVector SolveSystem(const VariableLengthVector& vector);

        /// �������ϵͳA * X= B������A��һ��NxN�Ĵ�״����B��һ��NxM�ľ���δ֪��X��Ҳ��NxM��
        /// ����������matrix��B��X�����㲢�����ء�
        /// ���ҽ�����һ���������ʱ������ֵ����Ч�ģ�������׳��쳣��
        /// ����ɹ�������Cholesky�ֽ⡣��L��A�������ǲ��ֺ�L^ T��A�������ǲ��֣�
        [[nodiscard]] const VariableMatrix SolveSystem(const VariableMatrix& matrix);

        [[nodiscard]] const VariableMatrix ToInputVariableMatrix() const;
        [[nodiscard]] const VariableMatrix ToCholeskyVariableMatrix() const;

    private:
        /// ����ϵͳΪL * U * X = B������A = L * U��U = L^T��
        /// ���ٵ�U * X = L^{-1} * B������ֵ��Ч���ҽ��������ɹ���
        [[nodiscard]] const VariableLengthVector SolveLower(const VariableLengthVector& vector) const;

        /// ����ϵͳΪU * X = L^{-1} * B�����ٵ� X = U^{-1} * L^{-1} * B��
        /// ����ֵ��Ч���ҽ��������ɹ���
        [[nodiscard]] const VariableLengthVector SolveUpper(const VariableLengthVector& vector) const;

        /// ����ϵͳΪL * U * X = B������A = L * U��U = L^T��
        /// ���ٵ�U * X = L^{-1} * B������ֵ��Ч���ҽ��������ɹ���
        [[nodiscard]] const VariableMatrix SolveLower(const VariableMatrix& matrix) const;

        /// ����ϵͳΪU * X = L^{-1} * B�����ٵ� X = U^{-1} * L^{-1} * B��
        /// ����ֵ��Ч���ҽ��������ɹ���
        [[nodiscard]] const VariableMatrix SolveUpper(const VariableMatrix& matrix) const;

    private:
        BandedMatrix m_Input;
        BandedMatrix m_Cholesky;
        BandedMatrixSolveFlags m_Solve;
        Real m_Epsilon;
    };

    using FloatBandedMatrixSolve = BandedMatrixSolve<float>;
    using DoubleBandedMatrixSolve = BandedMatrixSolve<double>;
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_H
