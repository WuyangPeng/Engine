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
#ifndef MATHEMATICS_ALGEBRA_BANDED_MATRIX_H
#define MATHEMATICS_ALGEBRA_BANDED_MATRIX_H

#include "Mathematics/MathematicsDll.h"

#include "AlgebraFwd.h"
#include "Flags/MatrixFlags.h"
#include "Mathematics/Base/Math.h"

#include "System/Helper/PragmaWarning/Operators.h"
#include <type_traits>
#include <vector>

namespace Mathematics
{
    template <typename Real>
    class MATHEMATICS_TEMPLATE_DEFAULT_DECLARE BandedMatrix
    {
    public:
        static_assert(std::is_arithmetic_v<Real>, "Real must be arithmetic.");

        using ClassType = BandedMatrix<Real>;
        using Math = Math<Real>;
        using VariableMatrix = VariableMatrix<Real>;
        using AlgebraTraits = AlgebraTraits<Real>;

    public:
        BandedMatrix(int size, int lowerBandsNumber, int upperBandsNumber);
        BandedMatrix(const BandedMatrix& rhs);
        ~BandedMatrix();

        BandedMatrix& operator=(const BandedMatrix& rhs);

        BandedMatrix(BandedMatrix&& rhs) = default;
        BandedMatrix& operator=(BandedMatrix&& rhs) = default;

        CLASS_INVARIANT_DECLARE;

        // ��Ա����
        int GetSize() const noexcept;
        int GetLowerBandsNumber() const noexcept;
        int GetUpperBandsNumber() const noexcept;
        int GetStreamSize() const;

        // �����С�����ԭ�����ݡ�
        void ResetSize(int size, int lowerBandsNumber, int upperBandsNumber);

        // �Խ���
        Real* GetDiagonalBand() noexcept;
        const Real* GetDiagonalBand() const noexcept;

        // ������
        // GetLowerBand(index):  0 <= index < LowerBandMax
        int GetLowerBandMax(int index) const;
        Real* GetLowerBand(int index);
        const Real* GetLowerBand(int index) const;

        // ������
        // GetUupperBand(index):  0 <= index < UpperBandMax
        int GetUpperBandMax(int index) const;
        Real* GetUpperBand(int index);
        const Real* GetUpperBand(int index) const;

        Real& operator()(int row, int column);
        const Real& operator()(int row, int column) const;

        // �����������ڳ�ʼ������
        void SetZero() noexcept;
        void SetIdentity() noexcept;

        const VariableMatrix ToVariableMatrix() const;

    private:
        void Swap(BandedMatrix& rhs) noexcept;

        void Allocate();
        void Allocate(const BandedMatrix& rhs);
        void Deallocate();

    private:
        int m_Size;
        int m_LowerBandsNumber;
        int m_UpperBandsNumber;
        Real* m_DiagonalBand;  // �Խ���
        Real** m_LowerBand;  // ������
        Real** m_UpperBand;  // ������
    };

    using BandedMatrixf = BandedMatrix<float>;
    using BandedMatrixd = BandedMatrix<double>;
}

#endif  // MATHEMATICS_ALGEBRA_BANDED_MATRIX_H
