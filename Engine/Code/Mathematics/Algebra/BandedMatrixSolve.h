// Copyright (c) 2011-2020
// Threading Core Render Engine
// ���ߣ������������ʶ���������
//
// ����汾��0.0.2.5 (2020/03/19 10:10)

// ��ν�Ĵ�״���󼴣��ھ���A�У�
// ���еķ���Ԫ�ض������������Խ���Ϊ���ĵĴ�״�����С�
// �� a11 a12 0   0   0   0
//    a21 a22 a23 0   0   0
//    a31 a32 a33 a34 0   0
//    0   a42 a43 a44 a45 0
//    0   0   a53 a54 a55 a56
//    0   0   0   a64 a65 a66
#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "BandedMatrix.h"
#include "Flags/MatrixFlags.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class BandedMatrixSolve
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BandedMatrixSolve<Real>;
        using Math = Math<Real>;
        using BandedMatrix = BandedMatrix<Real>;
        using VariableLengthVector = VariableLengthVector<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using AlgebraTraits = AlgebraTraits<Real>;

    public:
        BandedMatrixSolve(int size, int lowerBandsNumber, int upperBandsNumber, const Real epsilon = Math::GetZeroTolerance());
        BandedMatrixSolve(const BandedMatrixSolve& rhs);
        ~BandedMatrixSolve();

        BandedMatrixSolve& operator=(const BandedMatrixSolve& rhs);

#ifdef OPEN_CLASS_INVARIANT
        CLASS_INVARIANT_DECLARE;
        bool IsSolveValid() const;
        Real GetProduct(const BandedMatrix& upperBandedMatrix, const BandedMatrix& lowerBandedMatrix, int row, int column) const;
#endif  // OPEN_CLASS_INVARIANT

        // ��Ա����
        int GetSize() const noexcept;
        int GetLowerBandsNumber() const noexcept;
        int GetUpperBandsNumber() const noexcept;
        int GetStreamSize() const;
        BandedMatrixSolveFlags GetSolve() const;
        void SetEpsilon(Real epsilon);
        Real GetEpsilon() const noexcept;

        // �����С�����ԭ�����ݡ�
        void ResetSize(int size, int lowerBandsNumber, int upperBandsNumber, const Real epsilon = Math::GetZeroTolerance());

        // �Խ���
        Real* GetDiagonalBand() noexcept;
        const Real* GetDiagonalBand() const noexcept;
        std::vector<Real> GetDiagonalBandValue() const;

        // ������
        // GetLowerBand(index):  0 <= index < LowerBandMax
        int GetLowerBandMax(int index) const;
        Real* GetLowerBand(int index);
        const Real* GetLowerBand(int index) const;
        std::vector<Real> GetLowerBandValue(int index) const;

        // ������
        // GetUupperBand(index):  0 <= index < UpperBandMax
        int GetUpperBandMax(int index) const;
        Real* GetUpperBand(int index);
        const Real* GetUpperBand(int index) const;
        std::vector<Real> GetUpperBandValue(int index) const;

        Real& operator()(int row, int column);
        const Real& operator()(int row, int column) const;

        // �����������ڳ�ʼ������
        void SetZero();
        void SetIdentity();

        // ����״�����ϵ��AΪA = L * L^T��
        // ����L�������Ǿ���L^T��һ�������Ǿ��󣩡�
        // ����һ��LU�ֽ⣬����A���ȶ����������A * X = B��
        // �����ӷֽ���ʧ��ʱ������false����L�ǲ�����ģ���
        // ����ɹ�������Cholesky�ֽ⡣
        // ��L��A�������ǲ��ֺ�L^ T��A�������ǲ��֣�
        bool CholeskyFactor();

        // �������ϵͳA * X = B������A��һ��NxN�Ĵ�״����
        // B��һ��Nx1��ʸ����δ֪��X��Ҳ��Nx1��
        // ����������vector��B��
        // X�����㲢�����ء�
        // ���ҽ�����һ���������ʱ������ֵ����Ч�ģ�
        // ������׳��쳣��
        // ����ɹ�������Cholesky�ֽ⡣
        // ��L��A�������ǲ��ֺ�L^ T��A�������ǲ��֣�
        const VariableLengthVector SolveSystem(const VariableLengthVector& vector);

        // �������ϵͳA * X= B������A��һ��NxN�Ĵ�״����
        // B��һ��NxM�ľ���δ֪��X��Ҳ��NxM��
        // ����������matrix��B��
        // X�����㲢�����ء�
        // ���ҽ�����һ���������ʱ������ֵ����Ч�ģ�
        // ������׳��쳣��
        // ����ɹ�������Cholesky�ֽ⡣
        // ��L��A�������ǲ��ֺ�L^ T��A�������ǲ��֣�
        const VariableMatrix SolveSystem(const VariableMatrix& matrix);

        const VariableMatrix ToInputVariableMatrix() const;
        const VariableMatrix ToCholeskyVariableMatrix() const;

    private:
        // ����ϵͳΪL * U * X = B������A = L * U��U = L^T��
        // ���ٵ�U * X = L^{-1} * B������ֵ��Ч���ҽ��������ɹ���
        const VariableLengthVector SolveLower(const VariableLengthVector& dataVector) const;

        // ����ϵͳΪU * X = L^{-1} * B��
        // ���ٵ� X = U^{-1} * L^{-1} * B��
        // ����ֵ��Ч���ҽ��������ɹ���
        const VariableLengthVector SolveUpper(const VariableLengthVector& dataVector) const;

        // ����ϵͳΪL * U * X = B������A = L * U��U = L^T��
        // ���ٵ�U * X = L^{-1} * B������ֵ��Ч���ҽ��������ɹ���
        const VariableMatrix SolveLower(const VariableMatrix& dataMatrix) const;

        // ����ϵͳΪU * X = L^{-1} * B��
        // ���ٵ� X = U^{-1} * L^{-1} * B��
        // ����ֵ��Ч���ҽ��������ɹ���
        const VariableMatrix SolveUpper(const VariableMatrix& dataMatrix) const;

    private:
        BandedMatrix m_Input;
        BandedMatrix m_Cholesky;
        BandedMatrixSolveFlags m_Solve;
        Real m_Epsilon;
    };

    using BandedMatrixSolvef = BandedMatrixSolve<float>;
    using BandedMatrixSolved = BandedMatrixSolve<double>;
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_SOLVE_H
