/// Copyright (c) 2010-2024
/// Threading Core Render Engine
///
/// ���ߣ������������ʶ���������
/// ��ϵ���ߣ�94458936@qq.com
///
/// ��׼��std:c++20
/// �汾��1.0.0.5 (2024/02/18 13:34)

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

#include <vector>

namespace Mathematics
{
    template <typename Real>
    requires std::is_arithmetic_v<Real>
    class BandedMatrixSolve final
    {
    public:
        using ClassType = BandedMatrixSolve<Real>;

        using MathType = Math<Real>;
        using BandedMatrixType = BandedMatrix<Real>;
        using VariableMatrixType = VariableMatrix<Real>;
        using VariableLengthVectorType = VariableLengthVector<Real>;
        using ContainerType = std::vector<Real>;

    public:
        BandedMatrixSolve(int size, int lowerBandsNumber, int upperBandsNumber, Real epsilon = MathType::GetZeroTolerance());

        CLASS_INVARIANT_DECLARE;

#ifdef OPEN_CLASS_INVARIANT

        NODISCARD bool IsSolveValid() const;
        NODISCARD Real GetProduct(const BandedMatrixType& upperBandedMatrix, const BandedMatrixType& lowerBandedMatrix, int row, int column) const;

#endif  // OPEN_CLASS_INVARIANT

        /// ��Ա����
        NODISCARD int GetSize() const;
        NODISCARD int GetLowerBandsNumber() const;
        NODISCARD int GetUpperBandsNumber() const;
        NODISCARD int GetStreamSize() const;
        NODISCARD BandedMatrixSolveFlags GetSolve() const noexcept;
        NODISCARD Real GetEpsilon() const noexcept;

        /// �����С�����ԭ�����ݡ�
        void ResetSize(int size, int lowerBandsNumber, int upperBandsNumber, Real aEpsilon = MathType::GetZeroTolerance());

        /// �Խ���
        NODISCARD ContainerType GetDiagonalBand() const;
        void SetDiagonalBand(const ContainerType& diagonalBand);

        /// ������
        /// GetLowerBand(index):  0 <= index < LowerBandMax
        NODISCARD int GetLowerBandMax(int index) const noexcept(gAssert < 1 || gMathematicsAssert < 1);
        NODISCARD ContainerType GetLowerBand(int index) const;
        void SetLowerBand(int index, const ContainerType& lowerBand);

        /// ������
        /// GetUpperBand(index):  0 <= index < UpperBandMax
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
        NODISCARD VariableLengthVectorType SolveSystem(const VariableLengthVectorType& vector);

        /// �������ϵͳA * X= B������A��һ��NxN�Ĵ�״����B��һ��NxM�ľ���δ֪��X��Ҳ��NxM��
        /// ����������matrix��B��X�����㲢�����ء�
        /// ���ҽ�����һ���������ʱ������ֵ����Ч�ģ�������׳��쳣��
        /// ����ɹ�������Cholesky�ֽ⡣��L��A�������ǲ��ֺ�L^ T��A�������ǲ��֣�
        ///
        /// RowMajor���������ģ�����ָ���Ĵ洢˳��
        template <bool RowMajor = true>
        NODISCARD VariableMatrixType SolveSystem(const VariableMatrixType& matrix);

        NODISCARD VariableMatrixType ToInputVariableMatrix() const;
        NODISCARD VariableMatrixType ToCholeskyVariableMatrix() const;

    private:
        /// ����ϵͳΪL * U * X = B������A = L * U��U = L^T��
        /// ���ٵ�U * X = L^{-1} * B������ֵ��Ч���ҽ��������ɹ���
        NODISCARD VariableLengthVectorType SolveLower(const VariableLengthVectorType& vector) const;

        /// ����ϵͳΪU * X = L^{-1} * B�����ٵ� X = U^{-1} * L^{-1} * B��
        /// ����ֵ��Ч���ҽ��������ɹ���
        NODISCARD VariableLengthVectorType SolveUpper(const VariableLengthVectorType& vector) const;

        /// ����ϵͳΪL * U * X = B������A = L * U��U = L^T��
        /// ���ٵ�U * X = L^{-1} * B������ֵ��Ч���ҽ��������ɹ���
        template <bool RowMajor>
        NODISCARD VariableMatrixType SolveLower(const VariableMatrixType& matrix) const;

        /// ����ϵͳΪU * X = L^{-1} * B�����ٵ� X = U^{-1} * L^{-1} * B��
        /// ����ֵ��Ч���ҽ��������ɹ���
        template <bool RowMajor>
        NODISCARD VariableMatrixType SolveUpper(const VariableMatrixType& matrix) const;

    private:
        BandedMatrixType input;
        BandedMatrixType cholesky;
        BandedMatrixSolveFlags solve;
        Real epsilon;
    };

    using BandedMatrixSolveF = BandedMatrixSolve<float>;
    using BandedMatrixSolveD = BandedMatrixSolve<double>;
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_H
