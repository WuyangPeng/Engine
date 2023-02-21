///	Copyright (c) 2010-2022
///	Threading Core Render Engine
///
///	���ߣ������������ʶ���������
///	��ϵ���ߣ�94458936@qq.com
///
///	��׼��std:c++17
///	����汾��0.8.0.2 (2022/02/08 11:51)

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
    class BandedMatrixSolve final
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

        CLASS_INVARIANT_DECLARE;

#ifdef OPEN_CLASS_INVARIANT
        NODISCARD bool IsSolveValid() const;
        NODISCARD Real GetProduct(const BandedMatrix& upperBandedMatrix, const BandedMatrix& lowerBandedMatrix, int row, int column) const;
#endif  // OPEN_CLASS_INVARIANT

        // ��Ա����
        NODISCARD int GetSize() const;
        NODISCARD int GetLowerBandsNumber() const;
        NODISCARD int GetUpperBandsNumber() const;
        NODISCARD int GetStreamSize() const;
        NODISCARD BandedMatrixSolveFlags GetSolve() const noexcept;
        void SetEpsilon(Real newEpsilon) noexcept;
        NODISCARD Real GetEpsilon() const noexcept;

        // �����С�����ԭ�����ݡ�
        void ResetSize(int size, int lowerBandsNumber, int upperBandsNumber, const Real newEpsilon = Math::GetZeroTolerance());

        // �Խ���
        NODISCARD ContainerType GetDiagonalBand() const;
        void SetDiagonalBand(const ContainerType& diagonalBand);

        // ������
        // GetLowerBand(index):  0 <= index < LowerBandMax
        NODISCARD int GetLowerBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD ContainerType GetLowerBand(int index) const;
        void SetLowerBand(int index, const ContainerType& lowerBand);

        // ������
        // GetUupperBand(index):  0 <= index < UpperBandMax
        NODISCARD int GetUpperBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD ContainerType GetUpperBand(int index) const;
        void SetUpperBand(int index, const ContainerType& upperBand);

        NODISCARD Real& operator()(int row, int column);
        NODISCARD const Real& operator()(int row, int column) const;

        // �����������ڳ�ʼ������
        void SetZero();
        void SetIdentity();

        /// ����״�����ϵ��AΪA = L * L^T������L�������Ǿ���L^T��һ�������Ǿ��󣩡�
        /// ����һ��LU�ֽ⣬����A���ȶ����������A * X = B��
        /// �����ӷֽ���ʧ��ʱ������false����L�ǲ�����ģ���
        /// ����ɹ�������Cholesky�ֽ⡣��L��A�������ǲ��ֺ�L^ T��A�������ǲ��֣�
        NODISCARD bool CholeskyFactor();

        /// �������ϵͳA * X = B������A��һ��NxN�Ĵ�״����B��һ��Nx1��ʸ����δ֪��X��Ҳ��Nx1��
        /// ����������vector��B��X�����㲢�����ء�
        /// ���ҽ�����һ���������ʱ������ֵ����Ч�ģ�������׳��쳣��
        /// ����ɹ�������Cholesky�ֽ⡣��L��A�������ǲ��ֺ�L^ T��A�������ǲ��֣�
        NODISCARD VariableLengthVector SolveSystem(const VariableLengthVector& vector);

        /// �������ϵͳA * X= B������A��һ��NxN�Ĵ�״����B��һ��NxM�ľ���δ֪��X��Ҳ��NxM��
        /// ����������matrix��B��X�����㲢�����ء�
        /// ���ҽ�����һ���������ʱ������ֵ����Ч�ģ�������׳��쳣��
        /// ����ɹ�������Cholesky�ֽ⡣��L��A�������ǲ��ֺ�L^ T��A�������ǲ��֣�
        NODISCARD VariableMatrix SolveSystem(const VariableMatrix& matrix);

        NODISCARD VariableMatrix ToInputVariableMatrix() const;
        NODISCARD VariableMatrix ToCholeskyVariableMatrix() const;

    private:
        /// ����ϵͳΪL * U * X = B������A = L * U��U = L^T��
        /// ���ٵ�U * X = L^{-1} * B������ֵ��Ч���ҽ��������ɹ���
        NODISCARD VariableLengthVector SolveLower(const VariableLengthVector& vector) const;

        /// ����ϵͳΪU * X = L^{-1} * B�����ٵ� X = U^{-1} * L^{-1} * B��
        /// ����ֵ��Ч���ҽ��������ɹ���
        NODISCARD VariableLengthVector SolveUpper(const VariableLengthVector& vector) const;

        /// ����ϵͳΪL * U * X = B������A = L * U��U = L^T��
        /// ���ٵ�U * X = L^{-1} * B������ֵ��Ч���ҽ��������ɹ���
        NODISCARD VariableMatrix SolveLower(const VariableMatrix& matrix) const;

        /// ����ϵͳΪU * X = L^{-1} * B�����ٵ� X = U^{-1} * L^{-1} * B��
        /// ����ֵ��Ч���ҽ��������ɹ���
        NODISCARD VariableMatrix SolveUpper(const VariableMatrix& matrix) const;

    private:
        BandedMatrix input;
        BandedMatrix cholesky;
        BandedMatrixSolveFlags solve;
        Real epsilon;
    };

    using BandedMatrixSolveF = BandedMatrixSolve<float>;
    using BandedMatrixSolveD = BandedMatrixSolve<double>;
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_H
